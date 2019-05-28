#include "Process.hpp"

Process::Process()
{
	this->IsBoEInjected = FALSE;
	this->ParentProcessID = 0;
	this->ProcessID = 0;
	this->ProcessHandle = 0;
	this->ProcName = "PathOfExile_x64.exe";
}

VOID Process::SetProcessID(DWORD ProcID)
{
	if (ProcID >= 0 && ProcID <= 65535)
		this->ProcessID = ProcID;	
}

VOID Process::SetParentProcessID(DWORD ParentID)
{
	if (ParentID != 0 && ParentID != -1)
	{
		this->ParentProcessID = ParentID;
	}
}

VOID Process::SetProcessName(LPSTR ProcName)
{
	if (ProcName == NULL)
		return;
}

VOID Process::SetMainWindowHWND(HWND hwnd)
{

}

VOID Process::SetWindowTitle(LPSTR Title)
{
	
	//todo: get process main hwnd
//	if (!SetWindowTextA())
}

VOID Process::SetInjected(BOOL IsInjected)
{
	this->IsBoEInjected = IsInjected;
}

VOID Process::SetPrivileges()
{

}

BOOL Process::SetProcessHandle(HANDLE h)
{
	if (h == INVALID_HANDLE_VALUE || h == NULL)
	{
		return FALSE;
	}

	this->ProcessHandle = h;
	return TRUE;
}

VOID Process::EnableDebugPrivilges()
{
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkp;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = luid;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(hToken, false, &tkp, sizeof(tkp), NULL, NULL);

	CloseHandle(hToken);
}

BOOL Process::ListModules(DWORD dwPID)
{
	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me32;

	// Take a snapshot of all modules in the specified process.
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	if (hModuleSnap == INVALID_HANDLE_VALUE)
	{
		PrintError(TEXT("CreateToolhelp32Snapshot (of modules)"));
		return(FALSE);
	}

	me32.dwSize = sizeof(MODULEENTRY32);

	// Retrieve information about the first module
	if (!Module32First(hModuleSnap, &me32))
	{
		PrintError(TEXT("Module32First"));  // show cause of failure
		CloseHandle(hModuleSnap);           // clean the snapshot object
		return(FALSE);
	}

	// Walk the module list of the process, display information about each module
	do
	{
		_tprintf(TEXT("\n\n   MODULE NAME:     %s"), me32.szModule);
		_tprintf(TEXT("\n     Executable     = %s"), me32.szExePath);
		_tprintf(TEXT("\n     Process ID     = 0x%08X"), me32.th32ProcessID);
		_tprintf(TEXT("\n     Ref count (g)  = 0x%04X"), me32.GlblcntUsage);
		_tprintf(TEXT("\n     Ref count (p)  = 0x%04X"), me32.ProccntUsage);
		_tprintf(TEXT("\n     Base address   = 0x%08X"), (DWORD)me32.modBaseAddr);
		_tprintf(TEXT("\n     Base size      = %d"), me32.modBaseSize);

	} while (Module32Next(hModuleSnap, &me32));

	CloseHandle(hModuleSnap);
	return(TRUE);
}

BOOL Process::ListThreads(DWORD dwOwnerPID)
{
	HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
	THREADENTRY32 te32;

	// Take a snapshot of all running threads  
	hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hThreadSnap == INVALID_HANDLE_VALUE)
		return(FALSE);

	te32.dwSize = sizeof(THREADENTRY32);

	// Retrieve information about the first thread, exit if unsuccessful
	if (!Thread32First(hThreadSnap, &te32))
	{
		PrintError(TEXT("Thread32First")); // show cause of failure
		CloseHandle(hThreadSnap);          // clean the snapshot object
		return(FALSE);
	}

	//Walk the thread list of the system,
	do
	{
		if (te32.th32OwnerProcessID == dwOwnerPID)
		{
			_tprintf(TEXT("\n\n     THREAD ID      = 0x%08X"), te32.th32ThreadID);
			_tprintf(TEXT("\n     Base priority  = %d"), te32.tpBasePri);
			_tprintf(TEXT("\n     Delta priority = %d"), te32.tpDeltaPri);
			_tprintf(TEXT("\n"));
		}
	} while (Thread32Next(hThreadSnap, &te32));

	CloseHandle(hThreadSnap);
	return(TRUE);
}

BOOL Process::ChangeWindowTitle(std::string Title)
{
	EnumWindows(Process::EnumWindowsCallback, reinterpret_cast<LPARAM>(this));
	SetWindowTextA(this->MainHWND, Title.c_str());
	return TRUE;
}


BOOL CALLBACK Process::EnumWindowsCallback(HWND hwnd, LPARAM lParam) //lparam = thisptr
{
	Process* p = reinterpret_cast<Process*>(lParam);

	DWORD lpdwProcessId;
	GetWindowThreadProcessId(hwnd, &lpdwProcessId);
	if (lpdwProcessId == p->GetProcessID())
	{
		p->MainHWND = hwnd;
		return FALSE; //stop enumeration
	}

	return TRUE;
}