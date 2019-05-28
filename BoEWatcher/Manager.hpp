#pragma once
#include "Launcher.hpp"
#include <list>
#include <tlhelp32.h>
#include <tchar.h>

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
	
	BOOL ListProcessModules(DWORD dwPID);
	BOOL ListProcessThreads(DWORD dwOwnerPID); //probably above 2 can go into the respective process class.
	std::list<DWORD>* GetAllProcessIDs();
	
	static VOID MonitorProcesses(); //Thread func
};