#pragma once
#include "Launcher.hpp"
#include <list>
#include <tlhelp32.h>
#include <tchar.h>

//Should be a singleton class instance
class Manager
{
private:
	std::list<Launcher*> *LauncherList;

	HANDLE MonitorThread;
public:
	Manager::Manager();
	
	BOOL StartMonitor();
	BOOL AddAccount(Launcher* L);

	HANDLE GetMonitorThread() { return this->MonitorThread; }
	BOOL SetMonitorThread(HANDLE Thread) { if (Thread != INVALID_HANDLE_VALUE) this->MonitorThread = Thread; }
	
	std::list<DWORD>* GetAllProcessIDs();
	
	static VOID MonitorProcesses(); //Thread func
};