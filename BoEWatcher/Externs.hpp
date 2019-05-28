#pragma once
#include <Windows.h>

__declspec(dllimport) UINT32 GetAccountLevel();
__declspec(dllimport) UINT32 GetBotStatus(); //change to enum
__declspec(dllimport) CHAR* GetArea();