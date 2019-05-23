#include "Launcher.hpp"

Launcher::Launcher()
{
	this->Proc = new Process();
	this->Acct = new Account();
	this->IsLaunched = FALSE;
}

VOID Launcher::SetBotArguments(std::string Args)
{

}

VOID Launcher::SetLaunchArguments(std::string Args)
{
	this->LaunchArguments = Args;
}

BOOL Launcher::LaunchProcess()
{
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFOA siStartInfo;
	BOOL bSuccess = FALSE;

	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);

	bSuccess = CreateProcessA("PathOfExile_x64.exe",
		(LPSTR)this->GetLaunchArguments().c_str(),     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&piProcInfo);  // receives PROCESS_INFORMATION 

	if (!bSuccess)
		return FALSE;

	this->Proc = new Process();
	this->Proc->SetProcessID(piProcInfo.dwProcessId);
	this->Proc->SetProcessHandle(piProcInfo.hProcess);
	this->Proc->SetParentProcessID(GetCurrentProcessId());

	HANDLE ProcessThread = piProcInfo.hThread;

	this->IsLaunched = TRUE;
	return TRUE;
}

