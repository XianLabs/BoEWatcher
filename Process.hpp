#pragma once
#include "Account.hpp"
#include <Winternl.h>

class Process
{
private:

	HANDLE ProcessHandle;
	HWND MainHWND;
	DWORD ProcessID;
	DWORD ParentProcessID;
	LPSTR ProcName;
	LPSTR WindowName; //Account Name. 
	BOOL IsBoEInjected;
	DWORD PrivilegeLevel;

	typedef struct _PEB 
	{
		UCHAR InheritedAddressSpace;
		UCHAR ReadImageFileExecOptions;
		UCHAR BeingDebugged;
		UCHAR Spare;
		PVOID Mutant;
		PVOID ImageBaseAddress;
		struct PEB_LDR_DATA *Ldr;
		PRTL_USER_PROCESS_PARAMETERS ProcessParameters; //winternal.h
		PVOID SubSystemData;
		PVOID ProcessHeap;
		PVOID FastPebLock;
		PVOID FastPebLockRoutine;
		PVOID FastPebUnlockRoutine;
		ULONG EnvironmentUpdateCount;
		PVOID* KernelCallbackTable;
		PVOID EventLogSection;
		PVOID EventLog;
		PVOID FreeList;
		ULONG TlsExpansionCounter;
		PVOID TlsBitmap;
		ULONG TlsBitmapBits[0x2];
		PVOID ReadOnlySharedMemoryBase;
		PVOID ReadOnlySharedMemoryHeap;
		PVOID* ReadOnlyStaticServerData;
		PVOID AnsiCodePageData;
		PVOID OemCodePageData;
		PVOID UnicodeCaseTableData;
		ULONG NumberOfProcessors;
		ULONG NtGlobalFlag;
		UCHAR Spare2[0x4];
		ULARGE_INTEGER CriticalSectionTimeout;
		ULONG HeapSegmentReserve;
		ULONG HeapSegmentCommit;
		ULONG HeapDeCommitTotalFreeThreshold;
		ULONG HeapDeCommitFreeBlockThreshold;
		ULONG NumberOfHeaps;
		ULONG MaximumNumberOfHeaps;
		PVOID** ProcessHeaps;
		PVOID GdiSharedHandleTable;
		PVOID ProcessStarterHelper; //PPS_POST_PREOCESS_INIT_ROUTINE?
		PVOID GdiDCAttributeList;
		PVOID LoaderLock;
		ULONG OSMajorVersion;
		ULONG OSMinorVersion;
		ULONG OSBuildNumber;
		ULONG OSPlatformId;
		ULONG ImageSubSystem;
		ULONG ImageSubSystemMajorVersion;
		ULONG ImageSubSystemMinorVersion;
		ULONG GdiHandleBuffer[0x22];
		PVOID ProcessWindowStation;
	} MYPEB, *PMYPEB;

public:

	Process();

	HANDLE GetProcessHandle() { return this->ProcessHandle; }
	DWORD GetProcessID() { return this->ProcessID; }
	DWORD GetParentProcessID() { return this->ParentProcessID; }
	LPSTR GetProcessName() { return this->ProcName; }
	LPSTR GetWindowName() { return this->WindowName; }
	DWORD GetPrivilegeLevel() { return this->PrivilegeLevel; }
	BOOL IsInjected() { return this->IsBoEInjected; }
	
	VOID SetMainHWND(HWND hwnd) { this->MainHWND = hwnd; }
	HWND GetProcessMainWindow() { return this->MainHWND; }

	//Todo: Make some of these bools
	VOID SetMainWindowHWND(HWND hwnd);
	VOID SetProcessID(DWORD ProcID);
	VOID SetParentProcessID(DWORD ParentID);
	VOID SetProcessName(LPSTR ProcName);
	VOID SetWindowTitle(LPSTR Title);
	VOID SetInjected(BOOL IsInjected);
	VOID SetPrivileges();
	BOOL SetProcessHandle(HANDLE h);

	VOID EnableDebugPrivilges();
	BOOL ListModules(DWORD ProcID);
	BOOL ListThreads(DWORD dwOwnerPID);

	VOID KillProcess();

	BOOL ChangeWindowTitle(std::string Title);
	static BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lparam);

	inline PPEB GetPEB() { return (PPEB)__readgsqword(0x60); }
};