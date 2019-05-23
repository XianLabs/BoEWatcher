#include "Process.hpp"

Process::Process()
{


}

VOID Process::SetProcessID(DWORD ProcID)
{
	if (ProcID != 0 && ProcID != -1)
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

VOID Process::SetWindowName(LPSTR Title)
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