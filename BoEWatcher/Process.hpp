#pragma once
#include "Account.hpp"

class Process
{
private:

	HANDLE ProcessHandle;
	HWND MainHWND;
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
	
	VOID SetMainHWND(HWND hwnd) { this->MainHWND = hwnd; }
	HWND GetProcessMainWindow() { return this->MainHWND; }

	//Todo: Make some of these bools
	VOID SetMainWindowHWND(HWND hwnd);
	VOID SetProcessID(DWORD ProcID);
	VOID SetParentProcessID(DWORD ParentID);
	VOID SetProcessName(LPSTR ProcName);
	VOID SetWindowTitle(LPSTR Title);
	VOID SetInjected(BOOL IsInjected);
	VOID SetPrivileges();
	BOOL SetProcessHandle(HANDLE h);

	VOID EnableDebugPrivilges();
	BOOL ListModules(DWORD ProcID);
	BOOL ListThreads(DWORD dwOwnerPID);

	BOOL ChangeWindowTitle(std::string Title);
	static BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lparam);
};