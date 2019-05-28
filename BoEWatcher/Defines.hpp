#pragma once
#include <Windows.h>
#include <tchar.h>
#include <string>
#include <tlhelp32.h>

enum WorldRegions
{
	WASHINGTON,
	TEXAS,
	CALIFORNIA,
	AMSTERDAM,
	LONDON,
	FRANKFURT,
	MILAN,
	SINGAPORE,
	AUSTRALIA,
	SAOPAULO,
	PARIS,
	MOSCOW,
	JAPAN
};

enum GameStatus
{
	STATUS_IDLE,
	STATUS_BOTTING,
	STATUS_DISCONNECTED,
	STATUS_TRADING
};

static VOID PrintError(TCHAR* msg)
{
	DWORD eNum;
	TCHAR sysMsg[256];
	TCHAR* p;

	eNum = GetLastError();
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, eNum, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), sysMsg, 256, NULL);

	// Trim the end of the line and terminate it with a null
	p = sysMsg;
	while ((*p > 31) || (*p == 9))
		++p;
	do { *p-- = 0; } while ((p >= sysMsg) &&
		((*p == '.') || (*p < 33)));

	_tprintf(TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg);
}