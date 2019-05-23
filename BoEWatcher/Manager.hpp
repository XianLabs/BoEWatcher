#pragma once
#include "Launcher.hpp"
#include <list>

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

	VOID MonitorProcesses(); //Thread func
};