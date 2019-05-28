#include "Injector.hpp"

BOOL Injector::Inject(DWORD pID, const char * DLL_NAME)
{
	HANDLE Proc;
	char buf[50] = { 0 };
	LPVOID RemoteString, LoadLibAddy;

	if (!pID)
		return false;

	Proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
	if (!Proc)
		return FALSE;
	
	LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");

	// Allocate space in the process for our DLL 
	RemoteString = (LPVOID)VirtualAllocEx(Proc, NULL, strlen(DLL_NAME), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	// Write the string name of our DLL in the memory allocated 
	WriteProcessMemory(Proc, (LPVOID)RemoteString, DLL_NAME, strlen(DLL_NAME), NULL);

	// Load our DLL 
	CreateRemoteThread(Proc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddy, (LPVOID)RemoteString, NULL, NULL);

	CloseHandle(Proc);
	return FALSE;
}

DWORD Injector::GetTargetThreadIDFromProcName(const wchar_t * ProcName)
{
	PROCESSENTRY32 pe;
	HANDLE thSnapShot;
	BOOL retval, ProcFound = false;
	int injected = 0;
	thSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (thSnapShot == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"Error: Unable <strong class=\"highlight\">to</strong> create toolhelp snapshot!",0,0);
		return false;
	}

	pe.dwSize = sizeof(PROCESSENTRY32);

	retval = Process32First(thSnapShot, &pe);
	while (retval)
	{
		if (StrStrIW(pe.szExeFile, ProcName) != NULL)
		{
			char buf[MAX_PATH] = { 0 };
			GetFullPathNameA("BoE.dll", MAX_PATH, buf, NULL);
			Inject(pe.th32ProcessID, buf);
			//return pe.th32ProcessID;
			injected = 1;
		}
		retval = Process32Next(thSnapShot, &pe);
	}
	return injected;

}