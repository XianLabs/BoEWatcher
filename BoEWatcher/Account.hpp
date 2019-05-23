#pragma once
#include "Defines.hpp"
#include <Windows.h>
#include <string>

class Account
{
private:
	std::string AccountName;
	std::string Password;
	std::string CharacterName;
	WorldRegions Realm;

	GameStatus Status;

	std::string BotProfilePath;

public:
	Account();

	std::string GetAccountName();
	std::string GetPassword();
	std::string GetCharacterName();

	BOOL SetAccountName(std::string Name);
	BOOL SetPassword(std::string Name);
	BOOL SetCharacterName(std::string Name);

	GameStatus GetAccountStatus() { return this->Status; }
	VOID SetAccountStatus(GameStatus Status) { this->Status = Status; }
};