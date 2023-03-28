/***************************************************************************************
* AUTHOR : 愣头青
* DATE   : 2019-11-30
****************************************************************************************/

#ifndef CXX_LTQ_H
#define CXX_LTQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ntddk.h>
#include <devioctl.h>
#include "load.h"

ULONG64 Lock;
  typedef struct
  {
    ULONG64 uPid;
    ULONG64 Dst;
    ULONG64 uSize;
	ULONG64 key;
  }READ_WRITE_INFO, *PREAD_WRITE_INFO;

  typedef struct
  {
    ULONG64 uPid;
    ULONG64 uBase;
  }GET_MODULE_INFO, *PGET_MODULE_INFO;


typedef struct _KAPC_STATE {
  LIST_ENTRY ApcListHead[MaximumMode];
  struct _KPROCESS *Process;
  BOOLEAN KernelApcInProgress;
  BOOLEAN KernelApcPending;
  BOOLEAN UserApcPending;
} KAPC_STATE, *PKAPC_STATE, *PRKAPC_STATE;

typedef struct
{
  short uMinute;
  short uSecond;
  int   bRet;
}CHECKM, *PCHECKM;

typedef struct
{
  ULONG64 uBaseAddr;
  ULONG64 uBaseSize;
}MODULE_INFO, *PMODULE_INFO;

typedef struct _KLDR_DATA_TABLE_ENTRY
{
  LIST_ENTRY InLoadOrderLinks;
  PVOID ExceptionTable;
  ULONG ExceptionTableSize;
  ULONG padding;// on IA64
  PVOID GpValue;
  PVOID NonPagedDebugInfo;//PNON_PAGED_DEBUG_INFO NonPagedDebugInfo;
  PVOID DllBase;
  PVOID EntryPoint;
  ULONG SizeOfImage;
  ULONG unknow;
  UNICODE_STRING FullDllName;
  UNICODE_STRING BaseDllName;
  ULONG Flags;
  USHORT LoadCount;
  USHORT __Unused5;
  PVOID SectionPointer;
  ULONG CheckSum;
  // ULONG padding on IA64
  PVOID LoadedImports;
  PVOID PatchInformation;
} KLDR_DATA_TABLE_ENTRY, *PKLDR_DATA_TABLE_ENTRY;

typedef struct _RTL_PROCESS_MODULE_INFORMATION {
  HANDLE Section;                 // Not filled in
  PVOID MappedBase;
  PVOID ImageBase;
  ULONG ImageSize;
  ULONG Flags;
  USHORT LoadOrderIndex;
  USHORT InitOrderIndex;
  USHORT LoadCount;
  USHORT OffsetToFileName;
  UCHAR  FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION, *PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES {
  ULONG NumberOfModules;
  RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES, *PRTL_PROCESS_MODULES;

typedef enum _SYSTEM_INFORMATION_CLASS {
  SystemBasicInformation,
  SystemProcessorInformation,             // obsolete...delete
  SystemPerformanceInformation,
  SystemTimeOfDayInformation,
  SystemPathInformation,
  SystemProcessInformation,
  SystemCallCountInformation,
  SystemDeviceInformation,
  SystemProcessorPerformanceInformation,
  SystemFlagsInformation,
  SystemCallTimeInformation,
  SystemModuleInformation,
  SystemLocksInformation,
  SystemStackTraceInformation,
  SystemPagedPoolInformation,
  SystemNonPagedPoolInformation,
  SystemHandleInformation,
  SystemObjectInformation,
  SystemPageFileInformation,
  SystemVdmInstemulInformation,
  SystemVdmBopInformation,
  SystemFileCacheInformation,
  SystemPoolTagInformation,
  SystemInterruptInformation,
  SystemDpcBehaviorInformation,
  SystemFullMemoryInformation,
  SystemLoadGdiDriverInformation,
  SystemUnloadGdiDriverInformation,
  SystemTimeAdjustmentInformation,
  SystemSummaryMemoryInformation,
  SystemMirrorMemoryInformation,
  SystemPerformanceTraceInformation,
  SystemObsolete0,
  SystemExceptionInformation,
  SystemCrashDumpStateInformation,
  SystemKernelDebuggerInformation,
  SystemContextSwitchInformation,
  SystemRegistryQuotaInformation,
  SystemExtendServiceTableInformation,
  SystemPrioritySeperation,
  SystemVerifierAddDriverInformation,
  SystemVerifierRemoveDriverInformation,
  SystemProcessorIdleInformation,
  SystemLegacyDriverInformation,
  SystemCurrentTimeZoneInformation,
  SystemLookasideInformation,
  SystemTimeSlipNotification,
  SystemSessionCreate,
  SystemSessionDetach,
  SystemSessionInformation,
  SystemRangeStartInformation,
  SystemVerifierInformation,
  SystemVerifierThunkExtend,
  SystemSessionProcessInformation,
  SystemLoadGdiDriverInSystemSpace,
  SystemNumaProcessorMap,
  SystemPrefetcherInformation,
  SystemExtendedProcessInformation,
  SystemRecommendedSharedDataAlignment,
  SystemComPlusPackage,
  SystemNumaAvailableMemory,
  SystemProcessorPowerInformation,
  SystemEmulationBasicInformation,
  SystemEmulationProcessorInformation,
  SystemExtendedHandleInformation,
  SystemLostDelayedWriteInformation,
  SystemBigPoolInformation,
  SystemSessionPoolTagInformation,
  SystemSessionMappedViewInformation,
  SystemHotpatchInformation,
  SystemObjectSecurityMode,
  SystemWatchdogTimerHandler,
  SystemWatchdogTimerInformation,
  SystemLogicalProcessorInformation,
  SystemWow64SharedInformation,
  SystemRegisterFirmwareTableInformationHandler,
  SystemFirmwareTableInformation,
  SystemModuleInformationEx,
  SystemVerifierTriageInformation,
  SystemSuperfetchInformation,
  SystemMemoryListInformation,
  SystemFileCacheInformationEx,
  MaxSystemInfoClass  // MaxSystemInfoClass should always be the last enum
} SYSTEM_INFORMATION_CLASS;


/////////////////////////////////////////////////////////////////////////
//PE
/////////////////////////////////////////////////////////////////////////
typedef struct _IMAGE_DOS_HEADER
{										// DOS .EXE header
  USHORT   e_magic;                     // Magic number
  USHORT   e_cblp;                      // Bytes on last page of file
  USHORT   e_cp;                        // Pages in file
  USHORT   e_crlc;                      // Relocations
  USHORT   e_cparhdr;                   // Size of header in paragraphs
  USHORT   e_minalloc;                  // Minimum extra paragraphs needed
  USHORT   e_maxalloc;                  // Maximum extra paragraphs needed
  USHORT   e_ss;                        // Initial (relative) SS value
  USHORT   e_sp;                        // Initial SP value
  USHORT   e_csum;                      // Checksum
  USHORT   e_ip;                        // Initial IP value
  USHORT   e_cs;                        // Initial (relative) CS value
  USHORT   e_lfarlc;                    // File address of relocation table
  USHORT   e_ovno;                      // Overlay number
  USHORT   e_res[4];                    // Reserved USHORTs
  USHORT   e_oemid;                     // OEM identifier (for e_oeminfo)
  USHORT   e_oeminfo;                   // OEM information; e_oemid specific
  USHORT   e_res2[10];                  // Reserved USHORTs
  LONG   e_lfanew;                    // File address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY
{
  ULONG   VirtualAddress;
  ULONG   Size;
} IMAGE_DATA_DIRECTORY,
*PIMAGE_DATA_DIRECTORY;

#define IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _IMAGE_SECTION_HEADER
{
  UCHAR    Name[IMAGE_SIZEOF_SHORT_NAME];
  union {
    ULONG   PhysicalAddress;
    ULONG   VirtualSize;
  } Misc;
  ULONG   VirtualAddress;
  ULONG   SizeOfRawData;
  ULONG   PointerToRawData;
  ULONG   PointerToRelocations;
  ULONG   PointerToLinenumbers;
  USHORT   NumberOfRelocations;
  USHORT   NumberOfLinenumbers;
  ULONG   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;


#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16
typedef struct _IMAGE_FILE_HEADER
{
  USHORT    Machine;
  USHORT    NumberOfSections;
  ULONG   TimeDateStamp;
  ULONG   PointerToSymbolTable;
  ULONG   NumberOfSymbols;
  USHORT    SizeOfOptionalHeader;
  USHORT    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

typedef struct _IMAGE_OPTIONAL_HEADER64 {
  USHORT        Magic;
  UCHAR        MajorLinkerVersion;
  UCHAR        MinorLinkerVersion;
  ULONG       SizeOfCode;
  ULONG       SizeOfInitializedData;
  ULONG       SizeOfUninitializedData;
  ULONG       AddressOfEntryPoint;
  ULONG       BaseOfCode;
  ULONGLONG   ImageBase;
  ULONG       SectionAlignment;
  ULONG       FileAlignment;
  USHORT        MajorOperatingSystemVersion;
  USHORT        MinorOperatingSystemVersion;
  USHORT        MajorImageVersion;
  USHORT        MinorImageVersion;
  USHORT        MajorSubsystemVersion;
  USHORT        MinorSubsystemVersion;
  ULONG       Win32VersionValue;
  ULONG       SizeOfImage;
  ULONG       SizeOfHeaders;
  ULONG       CheckSum;
  USHORT        Subsystem;
  USHORT        DllCharacteristics;
  ULONGLONG   SizeOfStackReserve;
  ULONGLONG   SizeOfStackCommit;
  ULONGLONG   SizeOfHeapReserve;
  ULONGLONG   SizeOfHeapCommit;
  ULONG       LoaderFlags;
  ULONG       NumberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

typedef struct _IMAGE_NT_HEADERS64 {
  ULONG Signature;
  IMAGE_FILE_HEADER FileHeader;
  IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;


//定义数据结构
typedef struct _PEB32 {
	UCHAR InheritedAddressSpace;
	UCHAR ReadImageFileExecOptions;
	UCHAR BeingDebugged;
	UCHAR Spare;
	ULONG Mutant;
	ULONG ImageBaseAddress;
	ULONG/*PPEB_LDR_DATA32*/ Ldr;
} PEB32, *PPEB32;

typedef struct _PEB64 {
	UCHAR InheritedAddressSpace;
	UCHAR ReadImageFileExecOptions;
	UCHAR BeingDebugged;
	UCHAR Spare;
	UCHAR Padding0[4];
	ULONG64 Mutant;
	ULONG64 ImageBaseAddress;
	ULONG64/*PPEB_LDR_DATA64*/ Ldr;
} PEB64, *PPEB64;


typedef struct _LDR_DATA_TABLE_ENTRY32 {
	LIST_ENTRY32 InLoadOrderLinks;
	LIST_ENTRY32 InMemoryOrderLinks;
	LIST_ENTRY32 InInitializationOrderLinks;
	ULONG DllBase;
	ULONG EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING32 FullDllName;
	UNICODE_STRING32 BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT TlsIndex;
	LIST_ENTRY32 HashLinks;
	ULONG SectionPointer;
	ULONG CheckSum;
	ULONG TimeDateStamp;
	ULONG LoadedImports;
	ULONG EntryPointActivationContext;
	ULONG PatchInformation;
	LIST_ENTRY32 ForwarderLinks;
	LIST_ENTRY32 ServiceTagLinks;
	LIST_ENTRY32 StaticLinks;
	ULONG ContextInformation;
	ULONG OriginalBase;
	LARGE_INTEGER LoadTime;
} LDR_DATA_TABLE_ENTRY32, *PLDR_DATA_TABLE_ENTRY32;

typedef struct _LDR_DATA_TABLE_ENTRY64 {
	LIST_ENTRY64 InLoadOrderLinks;
	LIST_ENTRY64 InMemoryOrderLinks;
	LIST_ENTRY64 InInitializationOrderLinks;
	ULONG64 DllBase;
	ULONG64 EntryPoint;
	ULONG64 SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT TlsIndex;
	LIST_ENTRY64 HashLinks;
	ULONG64 SectionPointer;
	ULONG64 CheckSum;
	ULONG64 TimeDateStamp;
	ULONG64 LoadedImports;
	ULONG64 EntryPointActivationContext;
	ULONG64 PatchInformation;
	LIST_ENTRY64 ForwarderLinks;
	LIST_ENTRY64 ServiceTagLinks;
	LIST_ENTRY64 StaticLinks;
	ULONG64 ContextInformation;
	ULONG64 OriginalBase;
	LARGE_INTEGER LoadTime;
} LDR_DATA_TABLE_ENTRY64, *PLDR_DATA_TABLE_ENTRY64;


typedef struct _PEB_LDR_DATA32 {
	ULONG Length;
	UCHAR Initialized;
	ULONG SsHandle;
	LIST_ENTRY32 InLoadOrderModuleList;
	LIST_ENTRY32 InMemoryOrderModuleList;
	LIST_ENTRY32 InInitializationOrderModuleList;
	ULONG EntryInProgress;
} PEB_LDR_DATA32, *PPEB_LDR_DATA32;

typedef struct _PEB_LDR_DATA64 {
	ULONG Length;
	UCHAR Initialized;
	ULONG64 SsHandle;
	LIST_ENTRY64 InLoadOrderModuleList;
	LIST_ENTRY64 InMemoryOrderModuleList;
	LIST_ENTRY64 InInitializationOrderModuleList;
	ULONG64 EntryInProgress;
} PEB_LDR_DATA64, *PPEB_LDR_DATA64;









//////////////////////////////////////////////////////////////////////////
NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObj, IN PUNICODE_STRING pRegistryString);
VOID DriverUnload(IN PDRIVER_OBJECT pDriverObj);
NTSTATUS DispatchCreate(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);
NTSTATUS DispatchClose(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);
NTSTATUS DispatchDeviceControl(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);
NTSTATUS DispatchCommon (IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);

//////////////////////////////////////////////////////////////////////////
BOOLEAN RemoveSystemModule(PDRIVER_OBJECT pDriverObj);
typedef VOID(*pMiProcessLoaderEntry)(IN PKLDR_DATA_TABLE_ENTRY DataTableEntry, IN LOGICAL Insert);
pMiProcessLoaderEntry GetMiProcessLoaderEntryAddr();
BOOLEAN GetTargetModuleInfo(PMODULE_INFO pModuleInfo, char *szModuleName);
//////////////////////////////////////////////////////////////////////////
#ifdef ALLOC_PRAGMA
    // Allow the DriverEntry routine to be discarded once initialization is completed
#pragma alloc_text(INIT, DriverEntry)
    // 
#pragma alloc_text(PAGE, DriverUnload)
#pragma alloc_text(PAGE, DispatchCreate)
#pragma alloc_text(PAGE, DispatchClose)
#pragma alloc_text(PAGE, DispatchDeviceControl)
#pragma alloc_text(PAGE, DispatchCommon)
#endif // ALLOC_PRAGMA

//////////////////////////////////////////////////////////////////////////

//
// TODO: Add your module declarations here
NTSTATUS PsLookupProcessByProcessId(HANDLE ProcessId, PEPROCESS *Process);
PVOID PsGetProcessSectionBaseAddress(PEPROCESS Process);
VOID KeStackAttachProcess(PRKPROCESS Process, PRKAPC_STATE ApcState);
VOID KeUnstackDetachProcess(PRKAPC_STATE ApcState);
NTKERNELAPI PPEB64		PsGetProcessPeb(_In_ PEPROCESS Process);
NTKERNELAPI PPEB32		PsGetProcessWow64Process(_In_ PEPROCESS  Process);

VOID _disable (VOID);
VOID _enable(VOID);
ULONG64 __readcr0 (VOID);
VOID __writecr0(ULONG64 Data);
NTSYSAPI NTSTATUS NTAPI ZwQuerySystemInformation( ULONG SystemInformationClass, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);


//MEMORY_INFORMATION_CLASS定义  
typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation,          //内存基本信息  
	MemoryWorkingSetInformation,       //工作集信息  
	MemoryMappedFilenameInformation    //内存映射文件名信息  

} MEMORY_INFORMATION_CLASS;

NTSYSAPI
NTSTATUS
NTAPI
ZwAllocateVirtualMemory(
	_In_		HANDLE		ProcessHandle,
	_Inout_		PVOID		*BaseAddress,
	_In_		ULONG_PTR	ZeroBits,
	_Inout_		PSIZE_T		RegionSize,
	_In_		ULONG		AllocationType,
	_In_		ULONG		Protect
);

int GetLock();

#ifdef __cplusplus
}
#endif
//////////////////////////////////////////////////////////////////////////

#endif	//CXX_LTQ_H
/* EOF */
