#include "Manager.hpp"

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
	if (this->LauncherList->size() <= 0)
	{
		return FALSE;
	}

	this->MonitorThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)this->MonitorProcesses, 0, 0, 0);

	return TRUE;
}

VOID Manager::MonitorProcesses()
{
	while (this->LauncherList->size() > 0)
	{
		for (int i = 0; i < this->LauncherList->size(); i++)
		{

		}
	}
}