#pragma once
#include "Defines.hpp"

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

	std::string GetAccountName() { return this->AccountName; }
	std::string GetPassword() { return this->Password; }
	std::string GetCharacterName() { return this->CharacterName; }

	BOOL SetAccountName(std::string Name);
	BOOL SetPassword(std::string Name);
	BOOL SetCharacterName(std::string Name);

	GameStatus GetAccountStatus() { return this->Status; }
	VOID SetAccountStatus(GameStatus Status) { this->Status = Status; }
};