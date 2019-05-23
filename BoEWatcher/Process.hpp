#pragma once
#include "Account.hpp"

class Process
{
private:

	HANDLE ProcessHandle;

	DWORD ProcessID;
	DWORD ParentProcessID;
	LPSTR ProcName;
	LPSTR WindowName; //Account Name. 
	BOOL IsBoEInjected;
	DWORD PrivilegeLevel;

public:
	Process();

	HANDLE GetProcessHandle() { return this->ProcessHandle; }
	DWORD GetProcessID() { return this->ProcessID; }
	DWORD GetParentProcessID() { return this->ParentProcessID; }
	LPSTR GetProcessName() { return this->ProcName; }
	LPSTR GetWindowName() { return this->WindowName; }
	DWORD GetPrivilegeLevel() { return this->PrivilegeLevel; }
	BOOL IsInjected() { return this->IsBoEInjected; }
	
	//Todo: Make some of these bools
	VOID SetMainWindowHWND(HWND hwnd);
	VOID SetProcessID(DWORD ProcID);
	VOID SetParentProcessID(DWORD ParentID);
	VOID SetProcessName(LPSTR ProcName);
	VOID SetWindowName(LPSTR Title);
	VOID SetInjected(BOOL IsInjected);
	VOID SetPrivileges();
	BOOL SetProcessHandle(HANDLE h);
};