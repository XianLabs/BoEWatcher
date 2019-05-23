#pragma once
#include "Process.hpp"

class Launcher
{
	private:
		
		Process* Proc;
		Account* Acct;

		std::string LaunchArguments;
		std::string BotArguments;

		BOOL IsLaunched;

	
	public:
		Launcher();

		VOID SetBotArguments(std::string Args);
		VOID SetLaunchArguments(std::string Args);
		VOID SetProcessLaunched(BOOL Launched) { this->IsLaunched = Launched; }

		BOOL IsProcessLaunched() { return this->IsLaunched; }
		std::string GetBotArguments() { return this->BotArguments; }
		std::string GetLaunchArguments() { return this->LaunchArguments; }
		Process* GetProcess() { return this->Proc; }
		Account* GetAccount() { return this->Acct; }

		BOOL LaunchProcess();
};

