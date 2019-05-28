#pragma once
#include <Windows.h>
#include <tlhelp32.h> 
#include <shlwapi.h> 
#include <conio.h> 
#include <string>
#include <stdio.h> 
#include <Shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")

class Injector
{
public:

	static DWORD GetTargetThreadIDFromProcName(const wchar_t * ProcName);
	static BOOL Inject(DWORD pID, const char * DLL_NAME);
};