#include "Account.hpp"

Account::Account()
{
	this->Status = GameStatus::STATUS_IDLE;
}

BOOL Account::SetAccountName(std::string Name)
{
	this->AccountName = std::string(Name);
	return TRUE;
}

BOOL Account::SetPassword(std::string pw)
{
	this->Password = std::string(pw);
	return TRUE;
}

BOOL Account::SetCharacterName(std::string Name)
{
	this->CharacterName = std::string(Name);
	return TRUE;
}