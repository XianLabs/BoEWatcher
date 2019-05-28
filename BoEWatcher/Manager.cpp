#include "Manager.hpp"

extern Manager* Watcher;

Manager::Manager()
{
	this->LauncherList = new std::list<Launcher*>();
	this->MonitorThread = NULL;

}

BOOL Manager::AddAccount(Launcher* L)
{
	if (!L->IsProcessLaunched())
		return FALSE;

	this->LauncherList->push_front(L);
	return TRUE;
}

BOOL Manager::StartMonitor()
{
	if (this->LauncherList->size() <= 0) //Somehow started monitor with an empty account list. 
		return FALSE;
	
	if (this->MonitorThread == NULL)
	{
		this->MonitorThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Manager::MonitorProcesses, 0, 0, 0);
		return TRUE;
	}
	
	return FALSE;
}

std::list<DWORD>* Manager::GetAllProcessIDs()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	std::list<DWORD>* ProcIDList = new std::list<DWORD>();

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		PrintError(TEXT("CreateToolhelp32Snapshot (of processes)"));
		return(NULL);
	}

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(hProcessSnap, &pe32))
	{
		PrintError(TEXT("Process32First")); // show cause of failure
		CloseHandle(hProcessSnap);          // clean the snapshot object
		return(NULL);
	}

	//Walk processes
	do
	{
		// Retrieve the priority class.
		dwPriorityClass = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
		if (hProcess == NULL && wcscmp(pe32.szExeFile, L"PathOfExile_x64.exe") == 0)
			PrintError(TEXT("OpenProcess"));
		else
		{
			dwPriorityClass = GetPriorityClass(hProcess);
			if (!dwPriorityClass && wcscmp(pe32.szExeFile, L"PathOfExile_x64.exe") == 0)
				PrintError(TEXT("GetPriorityClass"));
			CloseHandle(hProcess);
		}

		if (wcscmp(pe32.szExeFile, L"PathOfExile_x64.exe") == 0) //get window text also?		
			ProcIDList->push_back(pe32.th32ProcessID);
		
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return(ProcIDList);
}

VOID Manager::MonitorProcesses()
{
	while (Watcher->LauncherList->size() > 0)
	{
		std::list<DWORD>* ProcessList = Watcher->GetAllProcessIDs();

		if (ProcessList == NULL)
		{
			printf("Couldn't fetch process list. Make sure BoEWatcher.exe is in admin mode. Last error: %d\n", GetLastError());
			return;
		}

		std::list<Launcher*>::const_iterator iterator;

		for (iterator = Watcher->LauncherList->begin(); iterator != Watcher->LauncherList->end(); ++iterator) //many to many relationship
		{
			BOOL Found = FALSE;

			std::list<DWORD>::const_iterator procIDiterator;

			for (procIDiterator = ProcessList->begin(); procIDiterator != ProcessList->end(); ++procIDiterator)
				if (iterator._Ptr->_Myval->GetProcess()->GetProcessID() == procIDiterator._Ptr->_Myval)			
					Found = TRUE;
				
			if (!Found) //Respawn process
			{
				printf("Could not find process %d, launching new PoE Instance...\n", iterator._Ptr->_Myval->GetProcess()->GetProcessID());
				iterator._Ptr->_Myval->SetProcessLaunched(FALSE);
				if (!iterator._Ptr->_Myval->LaunchProcess())
				{
					printf("Failed to re-launch process with account name: %s\n", "Replace this later!");
				}
			}
		}

		Sleep(3000);

		delete ProcessList;
	}
}