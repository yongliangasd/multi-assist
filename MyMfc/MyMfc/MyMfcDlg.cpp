﻿
// MyMfcDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MyMfc.h"
#include "MyMfcDlg.h"
#include "afxdialogex.h"
#include<io.h>
#include"resource.h"
#include <winsvc.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框





class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyMfcDlg 对话框



CMyMfcDlg::CMyMfcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMFC_DIALOG, pParent)
	, code(_T("19028"))
	, 伤害(_T("500"))
	, 伤害1(_T("9999999"))
	, 方式(_T("31"))
	, 技能代码(_T("70023"))
	, 技能伤害(_T("9999999"))
	, 技能频率(_T("500"))
	, 技能大小(_T("1"))
	, 自定义(_T("19028"))
	, 技能个数(_T("5"))
	, 倍功伤害(_T("9999999"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);








	//机制初始化

	
	商店机制 = 0x14B476868, 喇叭公告 = 0x1446458E0;
	最大疲劳 = 0x14B714C40, 最小疲劳 = 0x14B714C38;
	解密机制 = 0x14B7746A0; 评分CALL = 0X145741310;
	按键机制 = 0x14B869F50;
	 人物机制 = 0x14B714B30, 物品CALL = 0x1308;
	 特效机制 = 0x1462B5CC0, 特效缓冲CALL = 0x14003B930;
	 特效释放CALL = 0x143165060, BUFF参数1 = 0x14315F9B0;
	 BUFF参数2 = 0x143156460;  坐标CALL偏移 = 0x1B0;
	 类型偏移 = 0X124, X坐标 = 0x350, 方向偏移 = 0x138, 首地址 = 0x178, 尾地址 = 0x180, 地图偏移 = 0x150;
	 阵营偏移 = 0xDB8, 游戏状态 = 0x14B34D104; 是否开门 = 0x20C; 代码偏移 = 0X7C0; 名称偏移 = 0x7C8;
	 载火判断 = 0x1DD0; 门型偏移 = 0x148; 房间编号 = 0x14B476858; 时间机制 = 0x20A050; GM加速 = 0x143F36320, 无敌偏移 = 0x1090;
	 释放CALL = 0X143CF2090; 血量偏移 = 0x5030, 空白地址 = 0X13FCC04C0; 技能CALL = 0X143F1B930; HOOK伤害 = 0x1441DAE83;

	 钩子上侧 = 0x14544E60A, 钩子下侧 = 0x14544E5DC, 钩子左侧 = 0x14544E5A7, 钩子右侧 = 0x14544E57E;








}

void CMyMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON2, pButton);
	DDX_Text(pDX, IDC_EDIT1, code);
	DDX_Text(pDX, IDC_EDIT3, 伤害);
	DDX_Text(pDX, IDC_EDIT2, 伤害1);
	DDX_Text(pDX, IDC_EDIT4, 方式);
	DDX_Control(pDX, IDC_COMBO1, 全屏模式);
	DDX_Text(pDX, IDC_EDIT5, 技能代码);
	DDX_Text(pDX, IDC_EDIT6, 技能伤害);
	DDX_Text(pDX, IDC_EDIT7, 技能频率);
	DDX_Text(pDX, IDC_EDIT8, 技能大小);
	DDX_Text(pDX, IDC_EDIT9, 自定义);
	DDX_Text(pDX, IDC_EDIT10, 技能个数);
	DDX_Text(pDX, IDC_EDIT11, 倍功伤害);
}

BEGIN_MESSAGE_MAP(CMyMfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyMfcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyMfcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyMfcDlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_COMMAND(ID_32772, &CMyMfcDlg::On32772)
	ON_WM_KEYDOWN()
	ON_WM_HOTKEY()
	ON_BN_CLICKED(IDC_CHECK1, &CMyMfcDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CMyMfcDlg 消息处理程序
typedef enum _THREADINFOCLASS
{
	ThreadBasicInformation,
	ThreadTimes,
	ThreadPriority,
	ThreadBasePriority,
	ThreadAffinityMask,
	ThreadImpersonationToken,
	ThreadDescriptorTableEntry,
	ThreadEnableAlignmentFaultFixup,
	ThreadEventPair_Reusable,
	ThreadQuerySetWin32StartAddress,
	ThreadZeroTlsCell,
	ThreadPerformanceCount,
	ThreadAmILastThread,
	ThreadIdealProcessor,
	ThreadPriorityBoost,
	ThreadSetTlsArrayAddress,
	ThreadIsIoPending,
	ThreadHideFromDebugger,
	ThreadBreakOnTermination,
	MaxThreadInfoClass
}THREADINFOCLASS;
typedef struct _CLIENT_ID
{
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
}CLIENT_ID;
typedef struct _THREAD_BASIC_INFORMATION
{
	LONG ExitStatus;
	PVOID TebBaseAddress;
	CLIENT_ID ClientId;
	LONG AffinityMask;
	LONG Priority;
	LONG BasePriority;
}THREAD_BASIC_INFORMATION, * PTHREAD_BASIC_INFORMATION;


extern "C" LONG(__stdcall * ZwQueryInformationThread)(
	IN HANDLE ThreadHandle,
	IN THREADINFOCLASS ThreadInformationClass,
	OUT PVOID ThreadInformation,
	IN ULONG ThreadInformationLength,
	OUT PULONG ReturnLength OPTIONAL
	) = NULL;
LONG(__stdcall* _NtReadVirtualMemory)(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	OUT PVOID Buffer,
	IN SIZE_T NumberOfBytesToRead,
	OUT PSIZE_T NumberOfBytesRead
	);


LONG(__stdcall* _NtWriteVirtualMemory)(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	OUT PVOID Buffer,
	IN SIZE_T NumberOfBytesToRead,
	OUT PSIZE_T NumberOfBytesRead
	);


int CMyMfcDlg::ReadLONG(__int64 内存地址)
{
	__int64 Ret = 0;  DWORD 保护属性;
	VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 8, PAGE_EXECUTE_READWRITE, &保护属性);

	(FARPROC&)_NtReadVirtualMemory = ::GetProcAddress(GetModuleHandle("ntdll.dll"), "NtReadVirtualMemory");

	_NtReadVirtualMemory(Game_Handle, (PVOID)内存地址, &Ret, 8, 0);
	VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 8, 保护属性, &保护属性);
	return Ret;
}

int CMyMfcDlg::ReadINT(__int64 内存地址)
{
	int Ret = 0;  DWORD 保护属性;
	VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 4, PAGE_EXECUTE_READWRITE, &保护属性);
	(FARPROC&)_NtReadVirtualMemory = ::GetProcAddress(GetModuleHandle("ntdll.dll"), "NtReadVirtualMemory");

	printf("地址：%p\n", _NtReadVirtualMemory);
	_NtReadVirtualMemory(Game_Handle, (PVOID)内存地址, &Ret, 4, 0);
	VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	return Ret;
}

bool CMyMfcDlg::WriteINT(int 内存地址, __int64 Ret)
{
	  DWORD 保护属性;
	VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 4, PAGE_EXECUTE_READWRITE, &保护属性);
	(FARPROC&)_NtWriteVirtualMemory = ::GetProcAddress(GetModuleHandle("ntdll.dll"), "NtWriteVirtualMemory");

	printf("地址：%p\n", _NtWriteVirtualMemory);
	if (_NtWriteVirtualMemory(Game_Handle, (PVOID)内存地址, &Ret, 4, 0) == true)
	{

		return true;
		VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	}
	VirtualProtectEx(Game_Handle, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	return false;
}


///写到文件
void CMyMfcDlg::Resourceloading(LPCSTR FileName, DWORD ID, LPCSTR type)
{


	HANDLE hFile;

	HINSTANCE hinst = NULL;

	HRSRC hrsrc = FindResourceA(hinst, MAKEINTRESOURCE(ID), type);
	if (!hrsrc)
		return;
	DWORD dwSize = SizeofResource(hinst, hrsrc);
	if (!dwSize)
		return;

	HGLOBAL hGlobal = LoadResource(hinst, hrsrc);
	if (!hGlobal)
		return;

	//LPVOID pBuff = LockResource(hGlobal);
	//if (!pBuff)
	//	AfxMessageBox("锁定资源失败！");



	hFile = CreateFile(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

	if (hFile == NULL)
		return;

	if (_access(FileName, 0) != -1)
	{
		WriteFile(hFile, (LPCVOID)LockResource(hGlobal), dwSize, &dwSize, NULL);


		SetFileAttributes(FileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);

		CloseHandle(hFile);
	}



	FreeResource(hGlobal);


}

// 0 加载服务    1 启动服务    2 停止服务    3 删除服务
BOOL SystemServiceOperate(char *lpszDriverPath, int iOperateType)
{
	BOOL bRet = TRUE;
	char szName[MAX_PATH] = { 0 };
	::lstrcpy(szName, lpszDriverPath);
	// 过滤掉文件目录，获取文件名
	::PathStripPath(szName);
	SC_HANDLE shOSCM = NULL, shCS = NULL;
	SERVICE_STATUS ss;
	DWORD dwErrorCode = 0;
	BOOL bSuccess = FALSE;
	// 打开服务控制管理器数据库
	shOSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!shOSCM)
	{
	printf("OpenSCManager");
		return FALSE;
	}
	if (0 != iOperateType)
	{
		// 打开一个已经存在的服务
		shCS = OpenService(shOSCM, szName, SERVICE_ALL_ACCESS);
		if (!shCS)
		{
		printf("OpenService");
			::CloseServiceHandle(shOSCM);
			shOSCM = NULL;
			return FALSE;
		}
	}
	switch (iOperateType)
	{
	case 0:
	{
			  // 创建服务
			  // SERVICE_AUTO_START   随系统自动启动
			  // SERVICE_DEMAND_START 手动启动
			  shCS = ::CreateService(shOSCM, szName, szName,
				  SERVICE_ALL_ACCESS,
				  SERVICE_KERNEL_DRIVER,
				  SERVICE_DEMAND_START,
				  SERVICE_ERROR_NORMAL,
				  lpszDriverPath, NULL, NULL, NULL, NULL, NULL);
			  if (!shCS)
			  {
				  printf("CreateService");
				  bRet = FALSE;
			  }
			  break;
	}
	case 1:
	{
			  // 启动服务
			  if (!::StartService(shCS, 0, NULL))
			  {
				  printf("StartService");
				  bRet = FALSE;
			  }
			  break;
	}
	case 2:
	{
			  // 停止服务
			  if (!::ControlService(shCS, SERVICE_CONTROL_STOP, &ss))
			  {
				  printf("ControlService");
				  bRet = FALSE;
			  }
			  break;
	}
	case 3:
	{
			  // 删除服务
			  if (!::DeleteService(shCS))
			  {
				  printf("DeleteService");
				  bRet = FALSE;
			  }
			  break;
	}
	default:
		break;
	}
	// 关闭句柄
	if (shCS)
	{
		::CloseServiceHandle(shCS);
		shCS = NULL;
	}
	if (shOSCM)
	{
		::CloseServiceHandle(shOSCM);
		shOSCM = NULL;
	}
	return bRet;
}


// 安装驱动
BOOL CMyMfcDlg::installDvr(CONST CHAR drvPath[50], CONST CHAR serviceName[20]) {

	// 打开服务控制管理器数据库
	SC_HANDLE schSCManager = OpenSCManager(
		NULL,                   // 目标计算机的名称,NULL：连接本地计算机上的服务控制管理器
		NULL,                   // 服务控制管理器数据库的名称，NULL：打开 SERVICES_ACTIVE_DATABASE 数据库
		SC_MANAGER_ALL_ACCESS   // 所有权限
		);
	if (schSCManager == NULL) {
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	// 创建服务对象，添加至服务控制管理器数据库
	SC_HANDLE schService = CreateService(
		schSCManager,               // 服务控件管理器数据库的句柄
		serviceName,                // 要安装的服务的名称
		serviceName,                // 用户界面程序用来标识服务的显示名称
		SERVICE_ALL_ACCESS,         // 对服务的访问权限：所有全权限
		SERVICE_KERNEL_DRIVER,      // 服务类型：驱动服务
		SERVICE_DEMAND_START,       // 服务启动选项：进程调用 StartService 时启动
		SERVICE_ERROR_IGNORE,       // 如果无法启动：忽略错误继续运行
		drvPath,                    // 驱动文件绝对路径，如果包含空格需要多加双引号
		NULL,                       // 服务所属的负载订购组：服务不属于某个组
		NULL,                       // 接收订购组唯一标记值：不接收
		NULL,                       // 服务加载顺序数组：服务没有依赖项
		NULL,                       // 运行服务的账户名：使用 LocalSystem 账户
		NULL                        // LocalSystem 账户密码
		);
	if (schService == NULL) {
		CloseServiceHandle(schService);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	CloseServiceHandle(schService);
	CloseServiceHandle(schSCManager);
	return TRUE;
}

// 启动服务
BOOL CMyMfcDlg::startDvr(CONST CHAR serviceName[20]) {

	// 打开服务控制管理器数据库
	SC_HANDLE schSCManager = OpenSCManager(
		NULL,                   // 目标计算机的名称,NULL：连接本地计算机上的服务控制管理器
		NULL,                   // 服务控制管理器数据库的名称，NULL：打开 SERVICES_ACTIVE_DATABASE 数据库
		SC_MANAGER_ALL_ACCESS   // 所有权限
		);
	if (schSCManager == NULL) {
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	// 打开服务
	SC_HANDLE hs = OpenService(
		schSCManager,           // 服务控件管理器数据库的句柄
		serviceName,            // 要打开的服务名
		SERVICE_ALL_ACCESS      // 服务访问权限：所有权限
		);
	if (hs == NULL) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	if (StartService(hs, 0, 0) == 0) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}


	CloseServiceHandle(hs);
	CloseServiceHandle(schSCManager);
	return TRUE;
}

// 停止服务
BOOL CMyMfcDlg::stopDvr(CONST CHAR serviceName[20]) {

	// 打开服务控制管理器数据库
	SC_HANDLE schSCManager = OpenSCManager(
		NULL,                   // 目标计算机的名称,NULL：连接本地计算机上的服务控制管理器
		NULL,                   // 服务控制管理器数据库的名称，NULL：打开 SERVICES_ACTIVE_DATABASE 数据库
		SC_MANAGER_ALL_ACCESS   // 所有权限
		);
	if (schSCManager == NULL) {
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	// 打开服务
	SC_HANDLE hs = OpenService(
		schSCManager,           // 服务控件管理器数据库的句柄
		serviceName,            // 要打开的服务名
		SERVICE_ALL_ACCESS      // 服务访问权限：所有权限
		);
	if (hs == NULL) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	// 如果服务正在运行
	SERVICE_STATUS status;
	if (QueryServiceStatus(hs, &status) == 0) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	if (status.dwCurrentState != SERVICE_STOPPED &&
		status.dwCurrentState != SERVICE_STOP_PENDING
		) {
		// 发送关闭服务请求
		if (ControlService(
			hs,                         // 服务句柄
			SERVICE_CONTROL_STOP,       // 控制码：通知服务应该停止
			&status                     // 接收最新的服务状态信息
			) == 0) {
			CloseServiceHandle(hs);
			CloseServiceHandle(schSCManager);
			return FALSE;
		}

		// 判断超时
		INT timeOut = 0;
		while (status.dwCurrentState != SERVICE_STOPPED){
			timeOut++;
			QueryServiceStatus(hs, &status);
			Sleep(50);
		}
		if (timeOut > 80) {
			CloseServiceHandle(hs);
			CloseServiceHandle(schSCManager);
			return FALSE;
		}
	}

	CloseServiceHandle(hs);
	CloseServiceHandle(schSCManager);
	return TRUE;
}

// 卸载驱动
BOOL CMyMfcDlg::unloadDvr(CONST CHAR serviceName[20]) {

	// 打开服务控制管理器数据库
	SC_HANDLE schSCManager = OpenSCManager(
		NULL,                   // 目标计算机的名称,NULL：连接本地计算机上的服务控制管理器
		NULL,                   // 服务控制管理器数据库的名称，NULL：打开 SERVICES_ACTIVE_DATABASE 数据库
		SC_MANAGER_ALL_ACCESS   // 所有权限
		);
	if (schSCManager == NULL) {
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	// 打开服务
	SC_HANDLE hs = OpenService(
		schSCManager,           // 服务控件管理器数据库的句柄
		serviceName,            // 要打开的服务名
		SERVICE_ALL_ACCESS      // 服务访问权限：所有权限
		);
	if (hs == NULL) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	// 删除服务
	if (DeleteService(hs) == 0) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}

	CloseServiceHandle(hs);
	CloseServiceHandle(schSCManager);
	return TRUE;
}

short CMyMfcDlg::Readshort(__int64 Address)
{

	HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);

	DWORD 保护属性;
	VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 2, PAGE_EXECUTE_READWRITE, &保护属性);

	int Ret = 0;
	if (::ReadProcessMemory(ProcessHandle, (void*)Address, &Ret, 2, 0) == true)
	{
		//printf("读游戏内存成功\n");
		VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 2, 保护属性, &保护属性);
		return Ret;
	}
	else
	{
		//printf("读取游戏内存失败\n");
		VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 2, 保护属性, &保护属性);
		return 0;
	}


}

DWORD CMyMfcDlg::Readint(__int64 Address)
{

	HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);

	DWORD 保护属性;
	VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, PAGE_EXECUTE_READWRITE, &保护属性);

	int Ret = 0 ;
	if (::ReadProcessMemory(ProcessHandle , (void*)Address, &Ret, 4, 0) == true)
	{
		//printf("读游戏内存成功\n");
		VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
		return Ret;
	}
	else
	{
		//printf("读取游戏内存失败\n");
		VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
		return 0;
	}
		

}



float CMyMfcDlg::Readflaot(__int64 Address)
{

	HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);

	DWORD 保护属性;
	VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 4, PAGE_EXECUTE_READWRITE, &保护属性);

	float Ret = 0;
	if (::ReadProcessMemory(ProcessHandle, (void*)Address, &Ret, 4, 0) == true)
	{
		//printf("读游戏内存成功\n");
		VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
		return Ret;
	}
	else
	{
		//printf("读取游戏内存失败\n");
		VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
		return 0;
	}


}

bool CMyMfcDlg::Writeint(__int64 Address, int data)
{


	HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);



	DWORD 保护属性;
	VirtualProtectEx(ProcessHandle, reinterpret_cast<LPVOID>(Address), 4, PAGE_EXECUTE_READWRITE, &保护属性);
	if (::WriteProcessMemory(ProcessHandle , (void*)Address, &data, 4, 0) == true)
	{
		//printf("写游戏内存成功\n");
		VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
		return true;
	}
	else
	{
		//printf("写游戏内存失败\n");
		return false;
		VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
	}

}
bool CMyMfcDlg::Writefloat(__int64 Address, float data)
{
	HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);

	DWORD 保护属性;
	VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, PAGE_EXECUTE_READWRITE, &保护属性);
	if (::WriteProcessMemory(ProcessHandle , (void*)Address, &data, 4, 0) == true)
	{

		VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
		return true;
	}
		
	else
	{
		//printf("写游戏浮点数内存失败\n");
		return false;
		VirtualProtectEx(ProcessHandle , reinterpret_cast<LPVOID>(Address), 4, 保护属性, &保护属性);
	}
	
}

__int64 CMyMfcDlg::GetProcessModule(DWORD Pid, char Name[])
{

	MODULEENTRY32 module = { 0 };

	__int64 temp = 0;

	HANDLE hModuleSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, Pid);
	HANDLE modules = 0;
	if (hModuleSnap != 0)
	{
		module.dwSize = sizeof(MODULEENTRY32);

		modules = (HANDLE)Module32First(hModuleSnap, &module);

		while (modules != 0)
		{
			if (_strcmpi(module.szModule, Name) == 0)
			{
				CloseHandle(hModuleSnap);

				temp = (__int64)module.modBaseAddr;
				return temp;
			}

			modules = (HANDLE)Module32Next(hModuleSnap, &module);
		}
		CloseHandle(hModuleSnap);
	}

	return -1;
}


//装载NT驱动程序
BOOL LoadNTDriver(char* lpszDriverName, char* lpszDriverPath)
{
	char szDriverImagePath[256];
	//得到完整的驱动路径
	GetFullPathName(lpszDriverPath, 256, szDriverImagePath, NULL);

	BOOL bRet = FALSE;

	SC_HANDLE hServiceMgr = NULL;//SCM管理器的句柄
	SC_HANDLE hServiceDDK = NULL;//NT驱动程序的服务句柄

	//打开服务控制管理器
	hServiceMgr = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (hServiceMgr == NULL)
	{
		//OpenSCManager失败
		printf("OpenSCManager() Faild %d ! \n", GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	else
	{
		//OpenSCManager成功
			printf("OpenSCManager() ok ! \n");
	}

	//创建驱动所对应的服务
	hServiceDDK = CreateService(hServiceMgr,
		lpszDriverName, //驱动程序的在注册表中的名字 
		lpszDriverName, // 注册表驱动程序的 DisplayName 值 
		SERVICE_ALL_ACCESS, // 加载驱动程序的访问权限 
		SERVICE_KERNEL_DRIVER,// 表示加载的服务是驱动程序 
		SERVICE_DEMAND_START, // 注册表驱动程序的 Start 值 
		SERVICE_ERROR_IGNORE, // 注册表驱动程序的 ErrorControl 值 
		szDriverImagePath, // 注册表驱动程序的 ImagePath 值 
		NULL,
		NULL,
		NULL,
		NULL,
		NULL);

	DWORD dwRtn;
	//判断服务是否失败
	if (hServiceDDK == NULL)
	{
		dwRtn = GetLastError();
		if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_EXISTS)
		{
			//由于其他原因创建服务失败
			printf("CrateService() Faild %d ! \n", dwRtn);
			bRet = FALSE;
			goto BeforeLeave;
		}
		else
		{
			//服务创建失败，是由于服务已经创立过
			printf("CrateService() Faild Service is ERROR_IO_PENDING or ERROR_SERVICE_EXISTS! \n");
		}

		// 驱动程序已经加载，只需要打开 
		hServiceDDK = OpenService(hServiceMgr, lpszDriverName, SERVICE_ALL_ACCESS);
		if (hServiceDDK == NULL)
		{
			//如果打开服务也失败，则意味错误
			dwRtn = GetLastError();
			printf("OpenService() Faild %d ! \n", dwRtn);
			bRet = FALSE;
			goto BeforeLeave;
		}
		else
		{
			printf("OpenService() ok ! \n");
		}
	}
	else
	{
		printf("CrateService() ok ! \n");
	}

	//开启此项服务
	bRet = StartService(hServiceDDK, NULL, NULL);
	if (!bRet)
	{
		DWORD dwRtn = GetLastError();
		if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_ALREADY_RUNNING)
		{
			printf("StartService() Faild %d ! \n", dwRtn);
			bRet = FALSE;
			goto BeforeLeave;
		}
		else
		{
			if (dwRtn == ERROR_IO_PENDING)
			{
				//设备被挂住
				printf("StartService() Faild ERROR_IO_PENDING ! \n");
				bRet = FALSE;
				goto BeforeLeave;
			}
			else
			{
				//服务已经开启
				printf("StartService() Faild ERROR_SERVICE_ALREADY_RUNNING ! \n");
				bRet = TRUE;
				goto BeforeLeave;
			}
		}
	}
	bRet = TRUE;
	//离开前关闭句柄
BeforeLeave:
	if (hServiceDDK)
	{
		CloseServiceHandle(hServiceDDK);
	}
	if (hServiceMgr)
	{
		CloseServiceHandle(hServiceMgr);
	}
	return bRet;
}




//卸载驱动程序 
BOOL UnloadNTDriver(char * szSvrName)
{
	BOOL bRet = FALSE;
	SC_HANDLE hServiceMgr = NULL;//SCM管理器的句柄
	SC_HANDLE hServiceDDK = NULL;//NT驱动程序的服务句柄
	SERVICE_STATUS SvrSta;
	//打开SCM管理器
	hServiceMgr = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (hServiceMgr == NULL)
	{
		//带开SCM管理器失败
		printf("OpenSCManager() Faild %d ! \n", GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	else
	{
		//带开SCM管理器失败成功
		printf("OpenSCManager() ok ! \n");
	}
	//打开驱动所对应的服务
	hServiceDDK = OpenService(hServiceMgr, szSvrName, SERVICE_ALL_ACCESS);

	if (hServiceDDK == NULL)
	{
		//打开驱动所对应的服务失败
		printf("OpenService() Faild %d ! \n", GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	else
	{
		printf("OpenService() ok ! \n");
	}
	//停止驱动程序，如果停止失败，只有重新启动才能，再动态加载。 
	if (!ControlService(hServiceDDK, SERVICE_CONTROL_STOP, &SvrSta))
	{
		printf("ControlService() Faild %d !\n", GetLastError());
	}
	else
	{
		//打开驱动所对应的失败
		printf("ControlService() ok !\n");
	}
	//动态卸载驱动程序。 
	if (!DeleteService(hServiceDDK))
	{
		//卸载失败
		printf("DeleteSrevice() Faild %d !\n", GetLastError());
	}
	else
	{
		//卸载成功
		printf("DelServer:eleteSrevice() ok !\n");
	}
	bRet = TRUE;
BeforeLeave:
	//离开前关闭打开的句柄
	if (hServiceDDK)
	{
		CloseServiceHandle(hServiceDDK);
	}
	if (hServiceMgr)
	{
		CloseServiceHandle(hServiceMgr);
	}
	return bRet;
}

std::vector<byte> CMyMfcDlg::API_读字节集( __int64 地址, int 长度)
{
	byte* tempResult;

	HANDLE hProcess;
	if (Pid == -1)
		hProcess = GetCurrentProcess();
	else
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);

	VirtualProtectEx(hProcess, (LPVOID)地址, 长度, PAGE_EXECUTE_READWRITE, NULL);

	tempResult = new byte[长度];
	memset(tempResult, 0, 长度);//清空申请的缓存区
	ReadProcessMemory(hProcess, (LPCVOID)地址, tempResult, 长度, NULL);
	std::vector<byte> result;
	result.resize(长度);
	for (int i = 0; i < 长度; i++)
	{
		result[i] = tempResult[i];
	}

	CloseHandle(hProcess);
	return result;
}

LPVOID CMyMfcDlg::申请内存( int DwSize)
{
	HANDLE Handle = 0;
	LPVOID Address = 0;
	if (Pid == -1)
		Handle = GetCurrentProcess();
	else
		Handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);
	if (DwSize == 0)
		DwSize = 1;
	Address = VirtualAllocEx(Handle, 0, DwSize, 4096, 64);

	CloseHandle(Handle);
	if (Address > 0)
		return Address;

	return 0;
}

bool CMyMfcDlg::释放内存(LPVOID 释放地址)
{
	HANDLE Handle = 0;

	if (Pid == -1)
		Handle = GetCurrentProcess();
	else
		Handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);

	if (!VirtualFreeEx(Handle, 释放地址, 0, MEM_RELEASE))
		return false;
	else
		return true;
}



std::vector<byte> intToBytes(__int64  i) {
	__int64  adr = (__int64)&i;
	std::vector<byte>c;
	for (size_t i = 0; i < 8; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

/*13FCC04C0 - 0F10 1C 24            - movups xmm3,[rsp]
13FCC04C4 - 0F10 54 24 10         - movups xmm2,[rsp+10]
13FCC04C9 - 0F10 4C 24 20         - movups xmm1,[rsp+20]
13FCC04CE - 0F10 44 24 30         - movups xmm0,[rsp+30]
13FCC04D3 - 48 B8 0000980A00000000 - mov rax,000000000A980000 { (0) }
13FCC04DD - 83 38 01              - cmp dword ptr [rax],01 { 1 }
13FCC04E0 - 75 2A                 - jne 13FCC050C { ->->13FDF00A3 }
13FCC04E2 - 48 81 EC 00030000     - sub rsp,00000300 { 768 }
13FCC04E9 - 48 BB 6400980A00000000 - mov rbx,000000000A980064 { (0) }
13FCC04F3 - FF D3                 - call rbx
13FCC04F5 - 48 B8 0000980A00000000 - mov rax,000000000A980000 { (0) }
13FCC04FF - C7 00 03000000        - mov [rax],00000003 { 3 }
13FCC0505 - 48 81 C4 00030000     - add rsp,00000300 { 768 }
13FCC050C - FF25 00000000 A300DF3F01000000 - jmp 13FDF00A3
*/
/*0x0F,0x10,0x1C,0x24,0x0F,0x10,0x54,0x24,0x10,0x0F,0x10,0x4C,0x24,0x20,0x0F,0x10,0x44,0x24,0x30,0x48,0xB8,0x0,0x0,0x18,0xD,0x0,0x0,0x0,0x0,0x83,0x38,0x1,0x75,0x2A,0x48,0x81,0xEC,0x0,0x3,0x0,0x0,0x48,0xBB,0x64,0x0,0x18,0xD,0x0,0x0,0x0,0x0,0xFF,0xD3,0x48,0xB8,0x0,0x0,0x18,0xD,0x0,0x0,0x0,0x0,0xC7,0x0,0x3,0x0,0x0,0x0,0x48,0x81,0xC4,0x0,0x3,0x0,0x0,0xFF,0x25,0x0,0x0,0x0,0x0,0xA3,0x0,0xDF,0x3F,0x1,0x0,0x0,0x0,*/

std::vector<byte> Ansi转Unicode(CString str)
{
	std::vector<byte>Ret;
	DWORD dwNum = MultiByteToWideChar(936, 0, str, -1, NULL, 0);
	byte* pwText;
	pwText = new  byte[dwNum * 2];
	MultiByteToWideChar(936, 0, str, -1, (LPWSTR)pwText, dwNum * 2);

	for (size_t i = 0; i < dwNum * 2; i++)
	{
		Ret.push_back(pwText[i]);
	}
	Ret.push_back(0);
	Ret.push_back(0);
	return Ret;
}

CString Unicode转Ansi(std::vector<byte> vby)
{
	int length = (int)vby.size();
	byte* str = new byte[vby.size()]();
	for (int i = 0; i < length; ++i)
	{
		str[i] = vby[i];
	}
	length = length / 2;
	length = ::WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)str, length, NULL, 0, NULL, NULL);
	char* resultCha = new char[length + 1]();
	::WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)str, length, resultCha, length, NULL, NULL);
	CString result(resultCha);
	return result;
}


std::vector<byte>内存填充(int 填充大小)
{
	std::vector<byte>填充;

	for (int i = 0; i < 填充大小; i++)
	{
		填充.push_back(0);
	}
	return 填充;
}

int CMyMfcDlg::当前疲劳()
{
	

	return 超级解密(最大疲劳) - 超级解密(最小疲劳);
}

int CMyMfcDlg::解密(__int64 地址)
{
	int v3 = 0;
	v3 = Readint(Readint(Readint(解密机制) + 8 * (Readint(地址) >> 16) + 56) + 4 * (Readshort(地址) & 65535)) + 8476 & 65535;

	return (Readint(地址 + 4) ^ (v3 | (v3 << 16)));
}



void  CMyMfcDlg::神话公告(CString 公告内容, int 类型)
{
	__int64 空白地址 = 0,空白地址1 = 0 , 空白地址2 = 0 ,  文本地址 = 0, 人物机制 = 0x14B714B30, 对象编号 = 0x12C, 公告参数 = 0x14B7166C0, 公告CALL = 0x1446457E0;

	if (空白地址 == 0)
	{
		空白地址 =(__int64) 申请内存(4096) + 600;
		空白地址1 = 空白地址 + 200;
		空白地址2 = 空白地址1 + 350;
	}
	if (类型 == 0)
		类型 = 37;
	else if (类型 == 1)
		类型 = 17;
	else if (类型 == 2)
		类型 = 54;
	else if (类型 == 3)
		类型 = 56;

	Writeint(空白地址 + 8, 空白地址1);
	Writeint(空白地址 + 24,0);
	Writeint(空白地址 + 28, -1);
	Writeint(空白地址 + 32, 65280);
	Writeint(空白地址 + 36, 类型);
	API_写字节集(空白地址1, Ansi转Unicode("凉城 -  " + 公告内容));
	API_写字节集(空白地址2, Ansi转Unicode("character/common/th_music.img"));
	Writeint(空白地址 + 40, 16);
	Writeint(空白地址 + 44, 空白地址2);
	Writeint(空白地址 + 56, 空白地址2);
	Writeint(空白地址 + 108, 16754943);

	data.push_back(0x48);
	data.push_back(0X81);
	data.push_back(0XEC);
	data.push_back(0X00);
	data.push_back(0X01);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X48);
	data.push_back(0XBA);
	data.push_back(intToBytes(空白地址)[0]);
	data.push_back(intToBytes(空白地址)[1]);
	data.push_back(intToBytes(空白地址)[2]);
	data.push_back(intToBytes(空白地址)[3]);
	data.push_back(intToBytes(空白地址)[4]);
	data.push_back(intToBytes(空白地址)[5]);
	data.push_back(intToBytes(空白地址)[6]);
	data.push_back(intToBytes(空白地址)[7]);
	data.push_back(0X48);
	data.push_back(0XBE);
	data.push_back(intToBytes(公告参数)[0]);
	data.push_back(intToBytes(公告参数)[1]);
	data.push_back(intToBytes(公告参数)[2]);
	data.push_back(intToBytes(公告参数)[3]);
	data.push_back(intToBytes(公告参数)[4]);
	data.push_back(intToBytes(公告参数)[5]);
	data.push_back(intToBytes(公告参数)[6]);
	data.push_back(intToBytes(公告参数)[7]);
	data.push_back(0x48);
	data.push_back(0X8B);
	data.push_back(0X36);
	data.push_back(0X48);
	data.push_back(0X89);
	data.push_back(0XF1);
	data.push_back(0XBF);
	data.push_back(0XFF);
	data.push_back(0XFF);
	data.push_back(0XFF);
	data.push_back(0XFF);
	data.push_back(0X48);
	data.push_back(0XB8);
	data.push_back(intToBytes(公告CALL)[0]);
	data.push_back(intToBytes(公告CALL)[1]);
	data.push_back(intToBytes(公告CALL)[2]);
	data.push_back(intToBytes(公告CALL)[3]);
	data.push_back(intToBytes(公告CALL)[4]);
	data.push_back(intToBytes(公告CALL)[5]);
	data.push_back(intToBytes(公告CALL)[6]);
	data.push_back(intToBytes(公告CALL)[7]);
	data.push_back(0xFF);
	data.push_back(0XD0);
	data.push_back(0X48);
	data.push_back(0X81);
	data.push_back(0XC4);
	data.push_back(0X00);
	data.push_back(0X01);
	data.push_back(0X00);
	data.push_back(0X00);

	内存汇编x64(data);

	data.clear();

}


__int64 CMyMfcDlg::超级解密(__int64 address)
{

	__int64 Eax = 0, Esi = 0, Edx = 0;
	Eax = Readint(address);
	Esi = Readint(解密机制);
	Edx = Eax;
	Edx >>= 16;
	Edx = Readint(Esi + Edx * 8 + 56);
	Eax = WORD(Eax);
	Eax = Readint(Edx + Eax * 4 + 8476);
	Eax = WORD(Eax);
	Edx = Eax;
	Esi = Edx;
	Esi <<= 16;
	Esi = Esi + Edx;
	Edx = Readint(address + 4);
	Eax = Esi ^ Edx;
	return Eax;
}


void CMyMfcDlg::内存按键(int key, int Seeps)
{
	int Keys;
	if (Seeps == 0)
		Seeps = 50;
	if (key == VK_F1)
		Keys = 328;
	else if (key == VK_ESCAPE)
		Keys = 270;
	else if (key == 'x')
		Keys = 314;

	API_写字节集(Readint(按键机制) + Keys + 8, { 1 });
	Sleep(Seeps);
	//处理事件();
	API_写字节集(Readint(按键机制) + Keys + 8, { 0 });


}

int CMyMfcDlg::取游戏状态()
{
	return Readint(游戏状态);
}

bool CMyMfcDlg::地面是否有物品()
{
	遍历结构 遍历;

	if (取游戏状态() != 3)
		return false;

	遍历.人物指针 = Readint(人物机制);
	遍历.地图指针 = Readint(遍历.人物指针 + 地图偏移);
	遍历.首 = Readint(遍历.地图指针 + 首地址);
	遍历.尾 = Readint(遍历.地图指针 + 尾地址);
	遍历.遍历数量 = (遍历.尾 - 遍历.首) / 8;

	for (int i = 0; i < 遍历.遍历数量; i++)
	{
		遍历.遍历指针 = Readint(遍历.首 + i  * 8);
		遍历.遍历类型s = Readint(遍历.遍历指针 + 类型偏移);
		遍历.遍历代码 = Readint(遍历.遍历指针 + 代码偏移);
		遍历.遍历名称 = Unicode转Ansi(API_读字节集(Readint( 遍历.遍历指针 + 名称偏移), 100));
		printf("当前名称：%s\t当前代码：%d\n", 遍历.遍历名称, 遍历.遍历代码);
		if (遍历.遍历类型s == 289)
			return true;
	}

	return false;
}


void CMyMfcDlg::HOOK倍功()
{
	UpdateData(true);
	__int64 空白地址 = 0;

	static bool 倍功开关;
	std::vector<byte>Hook数据{ 0x48, 0xB8 };
	std::vector<byte>Hook数据2{ 0xFF, 0x25, 0X00, 0X00, 0X00, 0X00 };
	static std::vector<byte>原数据{ 0x41, 0XFF, 0X93, 0X30, 0X0C, 0X00, 0X00, 0X48, 0X89, 0X44, 0X24, 0X70, 0X49, 0X8B, 0XCC };;
	倍功开关 = !倍功开关;

	if (空白地址 == 0)
		空白地址 = (__int64)申请内存(100);

	printf("倍功空白地址：%p\n", 空白地址);
	if (倍功开关 == true)
	{
	//	原数据 = API_读字节集(HOOK伤害, 15);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[0]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[1]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[2]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[3]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[4]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[5]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[6]);
		Hook数据.push_back(intToBytes((__int64)(_atoi64(倍功伤害) * 1000))[7]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[0]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[1]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[2]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[3]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[4]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[5]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[6]);
		Hook数据.push_back(API_读字节集(HOOK伤害 + 7, 8)[7]);
		Hook数据.push_back(0xFF);
		Hook数据.push_back(0X25);
		Hook数据.push_back(0X00);
		Hook数据.push_back(0X00);
		Hook数据.push_back(0X00);
		Hook数据.push_back(0X00);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[0]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[1]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[2]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[3]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[4]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[5]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[6]);
		Hook数据.push_back(intToBytes(HOOK伤害 + 15)[7]);
		API_写字节集(空白地址, Hook数据);
		Hook数据2.push_back(intToBytes(空白地址)[0]);
		Hook数据2.push_back(intToBytes(空白地址)[1]);
		Hook数据2.push_back(intToBytes(空白地址)[2]);
		Hook数据2.push_back(intToBytes(空白地址)[3]);
		Hook数据2.push_back(intToBytes(空白地址)[4]);
		Hook数据2.push_back(intToBytes(空白地址)[5]);
		Hook数据2.push_back(intToBytes(空白地址)[6]);
		Hook数据2.push_back(intToBytes(空白地址)[7]);
		Hook数据2.push_back(144);

		API_写字节集(HOOK伤害, Hook数据2);

		神话公告("独家倍功 - 开启", 1);

	}
	else
	{
		API_写字节集(HOOK伤害, 原数据);

		if (释放内存((LPVOID)空白地址))
		{
			printf("释放内存成功\n");
		}
		//API_写字节集(空白地址, 内存填充(100));
		神话公告("独家倍功 - 关闭", 1);
	}


}

void CMyMfcDlg::拾取遍历()
{
	遍历结构 遍历;
	坐标 物品坐标 = { 0 };
	if (取游戏状态() != 3)
		return ;

	遍历.人物指针 = Readint(人物机制);
	遍历.地图指针 = Readint(遍历.人物指针 + 地图偏移);
	遍历.首 = Readint(遍历.地图指针 + 首地址);
	遍历.尾 = Readint(遍历.地图指针 + 尾地址);
	遍历.遍历数量 = (遍历.尾 - 遍历.首) / 8;

	for (int i = 0; i < 遍历.遍历数量; i++)
	{
		遍历.遍历指针 = Readint(遍历.首 + i * 8);
		遍历.遍历类型s = Readint(遍历.遍历指针 + 类型偏移);
		遍历.遍历代码 = Readint(遍历.遍历指针 + 代码偏移);
		if (遍历.遍历类型s == 289)
		{
			物品坐标 = 读取坐标(遍历.遍历指针);
			printf("当前物品坐标x= %d \t y= %d \n", 物品坐标.x, 物品坐标.y);
			if (物品坐标.x == 0 || 物品坐标.y == 0)
				continue;
			坐标Call(遍历.人物指针, 物品坐标.x, 物品坐标.y, 物品坐标.z);
			内存按键('x');
			内存按键('x');
		}
	}

	
}

void CMyMfcDlg::吸取遍历()
{
	std::vector<__int64>物品指针;
	遍历结构 遍历;
	坐标 人物坐标 = { 0 };
	if (取游戏状态() != 3)
		return;

	遍历.人物指针 = Readint(人物机制);
	遍历.地图指针 = Readint(遍历.人物指针 + 地图偏移);
	遍历.首 = Readint(遍历.地图指针 + 首地址);
	遍历.尾 = Readint(遍历.地图指针 + 尾地址);
	遍历.遍历数量 = (遍历.尾 - 遍历.首) / 8;

	for (int i = 0; i < 遍历.遍历数量; i++)
	{
		遍历.遍历指针 = Readint(遍历.首 + i * 8);
		遍历.遍历类型s = Readint(遍历.遍历指针 + 类型偏移);
		遍历.遍历代码 = Readint(遍历.遍历指针 + 代码偏移);
		if (遍历.遍历类型s == 289)
		{
			人物坐标 = 读取坐标(遍历.人物指针);

			坐标Call(遍历.遍历指针, 人物坐标.x, 人物坐标.y, 人物坐标.z);


		}
	}


}



void CMyMfcDlg::全屏遍历()
{
	UpdateData(true);

	int 技能数 = 0;
	遍历结构 遍历;
	坐标 怪物坐标 = { 0 };
	if (取游戏状态() != 3)
		return;

	遍历.人物指针 = Readint(人物机制);
	遍历.地图指针 = Readint(遍历.人物指针 + 地图偏移);
	遍历.首 = Readint(遍历.地图指针 + 首地址);
	遍历.尾 = Readint(遍历.地图指针 + 尾地址);
	遍历.遍历数量 = (遍历.尾 - 遍历.首) / 8;

	for (int i = 0; i < 遍历.遍历数量; i++)
	{
		遍历.遍历指针 = Readint(遍历.首 + i * 8);
		遍历.遍历类型s = Readint(遍历.遍历指针 + 类型偏移);
		遍历.遍历代码 = Readint(遍历.遍历指针 + 代码偏移);
		遍历.遍历血量 = Readint(遍历.遍历指针 + 血量偏移);
		遍历.遍历阵营 = Readint(遍历.遍历指针 + 阵营偏移);
		if (遍历.遍历类型s == 529|| 遍历.遍历类型s == 545 || 遍历.遍历类型s == 273)
		{
			if (遍历.遍历阵营 > 0 && 遍历.遍历血量 != 0 && 遍历.人物指针 != 遍历.遍历指针)
			{
				怪物坐标 = 读取坐标(遍历.遍历指针);

				if (怪物坐标.x == 0 && 怪物坐标.y == 0)
					continue;
				if (全屏模式.GetCurSel() == 0)
				{
					释放Call(遍历.人物指针, _atoi64(技能代码), _atoi64(技能伤害), 怪物坐标.x, 怪物坐标.y, 怪物坐标.z);
				}

				if (全屏模式.GetCurSel() == 1)
				{
					技能Call(遍历.人物指针, _atoi64(技能代码), _atoi64(技能伤害), 怪物坐标.x, 怪物坐标.y, 怪物坐标.z, _atoi64(技能大小));
				}
				++技能数;
				if (技能数 >= _atoi64(技能个数))
					break;
			}

		}
	}


}


bool CMyMfcDlg::当前是否通关()
{
	遍历结构 遍历;

	if (取游戏状态() != 3)
		return false;

	遍历.人物指针 = Readint(人物机制);
	遍历.地图指针 = Readint(遍历.人物指针 + 地图偏移);
	遍历.首 = Readint(遍历.地图指针 + 首地址);
	遍历.尾 = Readint(遍历.地图指针 + 尾地址);
	遍历.遍历数量 = (遍历.尾 - 遍历.首) / 8;

	for (int i = 0; i < 遍历.遍历数量; i++)
	{
		遍历.遍历指针 = Readint(遍历.首 + i * 8);
		遍历.遍历类型s = Readint(遍历.遍历指针 + 类型偏移);
		遍历.遍历代码 = Readint(遍历.遍历指针 + 代码偏移);
		if (遍历.遍历代码 == 1045)
			return true;
	}

	return false;
}

int CMyMfcDlg::判断通关()
{
	__int64 房间数据 = Readint(Readint(Readint(房间编号) + 时间机制) + 门型偏移);

	return Readint(房间数据 + 载火判断);
}

bool CMyMfcDlg::当前是否开门()
{
	
	if (超级解密(Readint(Readint(人物机制) + 地图偏移) + 是否开门) == 0)
		return true;
	else
		return false;
}


void CMyMfcDlg::特效Call(int type)
{

	__int64 内存地址 = 0x13FCC04C0 + 100;
	printf("特效CAL 内存地址：%p \n", 内存地址);

	
	__int64 特效指针 = Readint(特效机制);
	data.push_back(0x81);
	data.push_back(0xEC);
	data.push_back(0x00);
	data.push_back(0x01);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(72);
	data.push_back(186);
	data.push_back(1);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(72);
	data.push_back(185);
	data.push_back(intToBytes(内存地址 + 8)[0]);
	data.push_back(intToBytes(内存地址 + 8)[1]);
	data.push_back(intToBytes(内存地址 + 8)[2]);
	data.push_back(intToBytes(内存地址 + 8)[3]);
	data.push_back(intToBytes(内存地址 + 8)[4]);
	data.push_back(intToBytes(内存地址 + 8)[5]);
	data.push_back(intToBytes(内存地址 + 8)[6]);
	data.push_back(intToBytes(内存地址 + 8)[7]);
	data.push_back(72);
	data.push_back(184);
	data.push_back(intToBytes(特效缓冲CALL)[0]);
	data.push_back(intToBytes(特效缓冲CALL)[1]);
	data.push_back(intToBytes(特效缓冲CALL)[2]);
	data.push_back(intToBytes(特效缓冲CALL)[3]);
	data.push_back(intToBytes(特效缓冲CALL)[4]);
	data.push_back(intToBytes(特效缓冲CALL)[5]);
	data.push_back(intToBytes(特效缓冲CALL)[6]);
	data.push_back(intToBytes(特效缓冲CALL)[7]);
	data.push_back(255);
	data.push_back(208);
	data.push_back(72);
	data.push_back(186);
	data.push_back(2);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(72);
	data.push_back(185);
	data.push_back(intToBytes(内存地址 + 8)[0]);
	data.push_back(intToBytes(内存地址 + 8)[1]);
	data.push_back(intToBytes(内存地址 + 8)[2]);
	data.push_back(intToBytes(内存地址 + 8)[3]);
	data.push_back(intToBytes(内存地址 + 8)[4]);
	data.push_back(intToBytes(内存地址 + 8)[5]);
	data.push_back(intToBytes(内存地址 + 8)[6]);
	data.push_back(intToBytes(内存地址 + 8)[7]);
	data.push_back(72);
	data.push_back(184);
	data.push_back(intToBytes(特效缓冲CALL)[0]);
	data.push_back(intToBytes(特效缓冲CALL)[1]);
	data.push_back(intToBytes(特效缓冲CALL)[2]);
	data.push_back(intToBytes(特效缓冲CALL)[3]);
	data.push_back(intToBytes(特效缓冲CALL)[4]);
	data.push_back(intToBytes(特效缓冲CALL)[5]);
	data.push_back(intToBytes(特效缓冲CALL)[6]);
	data.push_back(intToBytes(特效缓冲CALL)[7]);
	data.push_back(255);
	data.push_back(208);
	data.push_back(72);
	data.push_back(185);
	data.push_back(intToBytes(特效指针)[0]); //
	data.push_back(intToBytes(特效指针)[1]);
	data.push_back(intToBytes(特效指针)[2]);
	data.push_back(intToBytes(特效指针)[3]);
	data.push_back(intToBytes(特效指针)[4]);
	data.push_back(intToBytes(特效指针)[5]);
	data.push_back(intToBytes(特效指针)[6]);
	data.push_back(intToBytes(特效指针)[7]);
	data.push_back(73);
	data.push_back(184);
	data.push_back(intToBytes(内存地址)[0]);
	data.push_back(intToBytes(内存地址)[1]);
	data.push_back(intToBytes(内存地址)[2]);
	data.push_back(intToBytes(内存地址)[3]);
	data.push_back(intToBytes(内存地址)[4]);
	data.push_back(intToBytes(内存地址)[5]);
	data.push_back(intToBytes(内存地址)[6]);
	data.push_back(intToBytes(内存地址)[7]);
	data.push_back(72);
	data.push_back(199);
	data.push_back(194);
	data.push_back(type);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0);
	data.push_back(72);
	data.push_back(184);
	data.push_back(intToBytes(BUFF参数1)[0]);
	data.push_back(intToBytes(BUFF参数1)[1]);
	data.push_back(intToBytes(BUFF参数1)[2]);
	data.push_back(intToBytes(BUFF参数1)[3]);
	data.push_back(intToBytes(BUFF参数1)[4]);
	data.push_back(intToBytes(BUFF参数1)[5]);
	data.push_back(intToBytes(BUFF参数1)[6]);
	data.push_back(intToBytes(BUFF参数1)[7]);
	data.push_back(255);
	data.push_back(208);
	data.push_back(72);
	data.push_back(137);
	data.push_back(199);
	data.push_back(72);
	data.push_back(184);
	data.push_back(intToBytes(特效释放CALL)[0]);
	data.push_back(intToBytes(特效释放CALL)[1]);
	data.push_back(intToBytes(特效释放CALL)[2]);
	data.push_back(intToBytes(特效释放CALL)[3]);
	data.push_back(intToBytes(特效释放CALL)[4]);
	data.push_back(intToBytes(特效释放CALL)[5]);
	data.push_back(intToBytes(特效释放CALL)[6]);
	data.push_back(intToBytes(特效释放CALL)[7]);
	data.push_back(255);
	data.push_back(208);
	data.push_back(72);
	data.push_back(137);
	data.push_back(193);
	data.push_back(72);
	data.push_back(137);
	data.push_back(250);
	data.push_back(72);
	data.push_back(184);
	data.push_back(intToBytes(BUFF参数2)[0]);
	data.push_back(intToBytes(BUFF参数2)[1]);
	data.push_back(intToBytes(BUFF参数2)[2]);
	data.push_back(intToBytes(BUFF参数2)[3]);
	data.push_back(intToBytes(BUFF参数2)[4]);
	data.push_back(intToBytes(BUFF参数2)[5]);
	data.push_back(intToBytes(BUFF参数2)[6]);
	data.push_back(intToBytes(BUFF参数2)[7]);
	data.push_back(255);
	data.push_back(208);
	data.push_back(72);
	data.push_back(184);
	data.push_back(intToBytes(特效释放CALL)[0]);
	data.push_back(intToBytes(特效释放CALL)[1]);
	data.push_back(intToBytes(特效释放CALL)[2]);
	data.push_back(intToBytes(特效释放CALL)[3]);
	data.push_back(intToBytes(特效释放CALL)[4]);
	data.push_back(intToBytes(特效释放CALL)[5]);
	data.push_back(intToBytes(特效释放CALL)[6]);
	data.push_back(intToBytes(特效释放CALL)[7]);
	data.push_back(255);
	data.push_back(208);
	data.push_back(72);
	data.push_back(129);
	data.push_back(196);
	data.push_back(0);
	data.push_back(1);
	data.push_back(0);
	data.push_back(0);

	内存汇编x64(data);
	data.clear();

}


void CMyMfcDlg::坐标Call(__int64 触发地址, int x, int y, int z)
{

	printf("触发地址 ：%p\n", 触发地址);



	data.push_back(0X48);
	data.push_back(0X81);
	data.push_back(0xec);
	data.push_back(0X00);
	data.push_back(0x01);
	data.push_back(0X00);
	data.push_back(0x00);
	data.push_back(0X41);
	data.push_back(0xB9);
	data.push_back(intToBytes(z)[0]);
	data.push_back(intToBytes(z)[1]);
	data.push_back(intToBytes(z)[2]);
	data.push_back(intToBytes(z)[3]);
	data.push_back(0X41);
	data.push_back(0xB8);
	data.push_back(intToBytes(y)[0]);
	data.push_back(intToBytes(y)[1]);
	data.push_back(intToBytes(y)[2]);
	data.push_back(intToBytes(y)[3]);
	data.push_back(0xBA);
	data.push_back(intToBytes(x)[0]);
	data.push_back(intToBytes(x)[1]);
	data.push_back(intToBytes(x)[2]);
	data.push_back(intToBytes(x)[3]);
	data.push_back(0x48);
	data.push_back(0xb9);
	data.push_back(intToBytes(触发地址)[0]);
	data.push_back(intToBytes(触发地址)[1]);
	data.push_back(intToBytes(触发地址)[2]);
	data.push_back(intToBytes(触发地址)[3]);
	data.push_back(intToBytes(触发地址)[4]);
	data.push_back(intToBytes(触发地址)[5]);
	data.push_back(intToBytes(触发地址)[6]);
	data.push_back(intToBytes(触发地址)[7]);
	data.push_back(0x48);
	data.push_back(0X8B);
	data.push_back(0X01);
	data.push_back(0XFF);
	data.push_back(0X90);
	data.push_back(intToBytes(坐标CALL偏移)[0]);
	data.push_back(intToBytes(坐标CALL偏移)[1]);
	data.push_back(intToBytes(坐标CALL偏移)[2]);
	data.push_back(intToBytes(坐标CALL偏移)[3]);
	data.push_back(0x48);
	data.push_back(0X81);
	data.push_back(0xc4);
	data.push_back(0X00);
	data.push_back(0X01);
	data.push_back(0x00);
	data.push_back(0X00);

	内存汇编x64(data);

	data.clear();

}


坐标  CMyMfcDlg::读取坐标(__int64 读取指针)
{
	坐标 当前坐标 = { 0 };
	__int64 指针 = Readint(读取指针 + X坐标);
	当前坐标.x = (int)Readflaot(指针 + 0);
	当前坐标.y = (int)Readflaot(指针 + 4);
	当前坐标.z = (int)Readflaot(指针 + 8);
	return 当前坐标;
}

void CMyMfcDlg::公告(CString 公告内容, int 公告颜色, int 公告类型)
{

	__int64  空白地址 = 0;

	if (空白地址 == 0)
		空白地址 = (__int64)申请内存(1024);
	if (公告颜色 == 0)
		公告颜色 = 16776960;
	if (公告类型 == 0)
		公告类型 = 37;
	if (公告类型 == 1)
		公告类型 = 17;
	else if (公告类型 == 2)
		公告类型 = 54;
	else if (公告类型 == 3)
		公告类型 = 56;

	API_写字节集(空白地址, Ansi转Unicode("凉城 - " + 公告内容 ));

	data.push_back(0x48);
	data.push_back(0X81);
	data.push_back(0XEC);
	data.push_back(0x00);
	data.push_back(0x01);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x48);
	data.push_back(0xb9);
	data.push_back(intToBytes(商店机制)[0]);
	data.push_back(intToBytes(商店机制)[1]);
	data.push_back(intToBytes(商店机制)[2]);
	data.push_back(intToBytes(商店机制)[3]);
	data.push_back(intToBytes(商店机制)[4]);
	data.push_back(intToBytes(商店机制)[5]);
	data.push_back(intToBytes(商店机制)[6]);
	data.push_back(intToBytes(商店机制)[7]);
	data.push_back(0x48);
	data.push_back(0x8b);
	data.push_back(0x09);
	data.push_back(0x48);
	data.push_back(0x8b);
	data.push_back(0x89);
	data.push_back(160);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x48);
	data.push_back(0xba);
	data.push_back(intToBytes(空白地址)[0]);
	data.push_back(intToBytes(空白地址)[1]);
	data.push_back(intToBytes(空白地址)[2]);
	data.push_back(intToBytes(空白地址)[3]);
	data.push_back(intToBytes(空白地址)[4]);
	data.push_back(intToBytes(空白地址)[5]);
	data.push_back(intToBytes(空白地址)[6]);
	data.push_back(intToBytes(空白地址)[7]);
	data.push_back(0x41);
	data.push_back(0Xb8);
	data.push_back(intToBytes(公告颜色)[0]);
	data.push_back(intToBytes(公告颜色)[1]);
	data.push_back(intToBytes(公告颜色)[2]);
	data.push_back(intToBytes(公告颜色)[3]);
	data.push_back(intToBytes(公告颜色)[4]);
	data.push_back(intToBytes(公告颜色)[5]);
	data.push_back(intToBytes(公告颜色)[6]);
	data.push_back(intToBytes(公告颜色)[7]);
	data.push_back(0x41);
	data.push_back(0XB9);
	data.push_back(intToBytes(公告类型)[0]);
	data.push_back(intToBytes(公告类型)[1]);
	data.push_back(intToBytes(公告类型)[2]);
	data.push_back(intToBytes(公告类型)[3]);
	data.push_back(intToBytes(公告类型)[4]);
	data.push_back(intToBytes(公告类型)[5]);
	data.push_back(intToBytes(公告类型)[6]);
	data.push_back(intToBytes(公告类型)[7]);
	data.push_back(0x49);
	data.push_back(0xbf);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X4C);
	data.push_back(0X89);
	data.push_back(0X7C);
	data.push_back(0X24);
	data.push_back(0X40);
	data.push_back(0XC6);
	data.push_back(0X44);
	data.push_back(0X24);
	data.push_back(0X38);
	data.push_back(0X00);
	data.push_back(0XC6);
	data.push_back(0X44);
	data.push_back(0X24);
	data.push_back(0X30);
	data.push_back(0X00);
	data.push_back(0X44);
	data.push_back(0X89);
	data.push_back(0X7C);
	data.push_back(0X24);
	data.push_back(0X28);
	data.push_back(0X4C);
	data.push_back(0X89);
	data.push_back(0X7C);
	data.push_back(0X24);
	data.push_back(0X20);
	data.push_back(0x48);
	data.push_back(0XB8);
	data.push_back(intToBytes(喇叭公告)[0]);
	data.push_back(intToBytes(喇叭公告)[1]);
	data.push_back(intToBytes(喇叭公告)[2]);
	data.push_back(intToBytes(喇叭公告)[3]);
	data.push_back(intToBytes(喇叭公告)[4]);
	data.push_back(intToBytes(喇叭公告)[5]);
	data.push_back(intToBytes(喇叭公告)[6]);
	data.push_back(intToBytes(喇叭公告)[7]);
	data.push_back(0XFF);
	data.push_back(0XD0);
	data.push_back(0x48);
	data.push_back(0X81);
	data.push_back(0XC4);
	data.push_back(0X00);
	data.push_back(0X01);
	data.push_back(0X00);
	data.push_back(0X00);
	内存汇编x64(data);
	data.clear();


}


void CMyMfcDlg::物品Call(__int64 物品代码)
{


	data.push_back(0x53);
	data.push_back(0x48);
	data.push_back(0x83);
	data.push_back(0xEC);
	data.push_back(0x28);
	data.push_back(0x48);
	data.push_back(0xB8);
	data.push_back(intToBytes(人物机制)[0]);
	data.push_back(intToBytes(人物机制)[1]);
	data.push_back(intToBytes(人物机制)[2]);
	data.push_back(intToBytes(人物机制)[3]);
	data.push_back(intToBytes(人物机制)[4]);
	data.push_back(intToBytes(人物机制)[5]);
	data.push_back(intToBytes(人物机制)[6]);
	data.push_back(intToBytes(人物机制)[7]);
	data.push_back(0x48);
	data.push_back(0x8B);
	data.push_back(0x00);
	data.push_back(0x4c);
	data.push_back(0X8B);
	data.push_back(0X00);
	data.push_back(0XBA);
	data.push_back(intToBytes(物品代码)[0]);
	data.push_back(intToBytes(物品代码)[1]);
	data.push_back(intToBytes(物品代码)[2]);
	data.push_back(intToBytes(物品代码)[3]);
	data.push_back(intToBytes(物品代码)[4]);
	data.push_back(intToBytes(物品代码)[5]);
	data.push_back(intToBytes(物品代码)[6]);
	data.push_back(intToBytes(物品代码)[7]);
	data.push_back(0x48);
	data.push_back(0X8b);
	data.push_back(0xc8);
	data.push_back(0x41);
	data.push_back(0xff);
	data.push_back(0x90);
	data.push_back(intToBytes(物品CALL)[0]);
	data.push_back(intToBytes(物品CALL)[1]);
	data.push_back(intToBytes(物品CALL)[2]);
	data.push_back(intToBytes(物品CALL)[3]);
	//data.push_back(intToBytes(物品CALL)[4]);
	//data.push_back(intToBytes(物品CALL)[5]);
	//data.push_back(intToBytes(物品CALL)[6]);
	//data.push_back(intToBytes(物品CALL)[7]);
	data.push_back(0x48);
	data.push_back(0x83);
	data.push_back(0xc4);
	data.push_back(0x28);
	data.push_back(0x5b);
	data.push_back(0xc3);
	内存汇编x64(data);


	data.clear();



}

void  CMyMfcDlg::评分Call(int Value)
{

	
	__int64 空白地址 = 0, 评分data = 0;
	if (空白地址 == 0)
		空白地址 = (__int64)申请内存(100);

	Writeint(空白地址, Value);
	评分data = Readint(0x14B474EA8); 评分data += 0x110;
	data.push_back(72);
	data.push_back(129);
	data.push_back(236);
	data.push_back(0);
	data.push_back(1);
	data.push_back(0);
	data.push_back(0);
	data.push_back(0x48);
	data.push_back(0xB9);
	data.push_back(intToBytes(评分data)[0]);
	data.push_back(intToBytes(评分data)[1]);
	data.push_back(intToBytes(评分data)[2]);
	data.push_back(intToBytes(评分data)[3]);
	data.push_back(intToBytes(评分data)[4]);
	data.push_back(intToBytes(评分data)[5]);
	data.push_back(intToBytes(评分data)[6]);
	data.push_back(intToBytes(评分data)[7]);
	data.push_back(0x4C);
	data.push_back(0x8B);
	data.push_back(0xC1);
	data.push_back(0x49);
	data.push_back(0x83);
	data.push_back(0XC0);
	data.push_back(0X04);
	data.push_back(0x48);
	data.push_back(0xBA);
	data.push_back(intToBytes(空白地址)[0]);
	data.push_back(intToBytes(空白地址)[1]);
	data.push_back(intToBytes(空白地址)[2]);
	data.push_back(intToBytes(空白地址)[3]);
	data.push_back(intToBytes(空白地址)[4]);
	data.push_back(intToBytes(空白地址)[5]);
	data.push_back(intToBytes(空白地址)[6]);
	data.push_back(intToBytes(空白地址)[7]);
	data.push_back(0x48);
	data.push_back(0XB8);
	data.push_back(intToBytes(评分CALL)[0]);
	data.push_back(intToBytes(评分CALL)[1]);
	data.push_back(intToBytes(评分CALL)[2]);
	data.push_back(intToBytes(评分CALL)[3]);
	data.push_back(intToBytes(评分CALL)[4]);
	data.push_back(intToBytes(评分CALL)[5]);
	data.push_back(intToBytes(评分CALL)[6]);
	data.push_back(intToBytes(评分CALL)[7]);
	data.push_back(0xFF);
	data.push_back(0xD0);
	data.push_back(72);
	data.push_back(129);
	data.push_back(196);
	data.push_back(0);
	data.push_back(1);
	data.push_back(0);
	data.push_back(0);
	内存汇编x64(data);

	data.clear();
}

void  CMyMfcDlg::处理事件()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


void CMyMfcDlg::技能开关()
{
	static bool 技能开关;
	技能开关 = !技能开关;

	if (技能开关 == true)
	{
		神话公告("技能全屏 - 开启", 1);
		SetTimer(4, _atoi64(技能频率), 0);
	}
	else
	{
		神话公告("技能全屏 - 关闭", 1);
		KillTimer(4);
	}



}

void CMyMfcDlg::释放Call(__int64 触发指针, int 技能代码,int 技能伤害 , int x, int y, int z)
{

	data.push_back(0x53);
	data.push_back(0x48);
	data.push_back(0X83);
	data.push_back(0XEC);
	data.push_back(0X48);
	data.push_back(0XC7);
	data.push_back(0X44);
	data.push_back(0X24);
	data.push_back(0X30);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0X00);
	data.push_back(0XC7);
	data.push_back(0X44);
	data.push_back(0X24);
	data.push_back(0X28);
	data.push_back(intToBytes(z)[0]);
	data.push_back(intToBytes(z)[1]);
	data.push_back(intToBytes(z)[2]);
	data.push_back(intToBytes(z)[3]);
	data.push_back(0Xc7);
	data.push_back(0x44);
	data.push_back(0x24);
	data.push_back(0x20);
	data.push_back(intToBytes(y)[0]);
	data.push_back(intToBytes(y)[1]);
	data.push_back(intToBytes(y)[2]);
	data.push_back(intToBytes(y)[3]);
	data.push_back(0x41);
	data.push_back(0xb9);
	data.push_back(intToBytes(x)[0]);
	data.push_back(intToBytes(x)[1]);
	data.push_back(intToBytes(x)[2]);
	data.push_back(intToBytes(x)[3]);
	data.push_back(0X41);
	data.push_back(0XB8);
	data.push_back(intToBytes(技能伤害)[0]);
	data.push_back(intToBytes(技能伤害)[1]);
	data.push_back(intToBytes(技能伤害)[2]);
	data.push_back(intToBytes(技能伤害)[3]);
	data.push_back(0XBA);
	data.push_back(intToBytes(技能代码)[0]);
	data.push_back(intToBytes(技能代码)[1]);
	data.push_back(intToBytes(技能代码)[2]);
	data.push_back(intToBytes(技能代码)[3]);
	data.push_back(0x48);
	data.push_back(0XB9);
	data.push_back(intToBytes(触发指针)[0]);
	data.push_back(intToBytes(触发指针)[1]);
	data.push_back(intToBytes(触发指针)[2]);
	data.push_back(intToBytes(触发指针)[3]);
	data.push_back(intToBytes(触发指针)[4]);
	data.push_back(intToBytes(触发指针)[5]);
	data.push_back(intToBytes(触发指针)[6]);
	data.push_back(intToBytes(触发指针)[7]);
	data.push_back(0X48);
	data.push_back(0XB8);
	data.push_back(intToBytes(释放CALL)[0]);
	data.push_back(intToBytes(释放CALL)[1]);
	data.push_back(intToBytes(释放CALL)[2]);
	data.push_back(intToBytes(释放CALL)[3]);
	data.push_back(intToBytes(释放CALL)[4]);
	data.push_back(intToBytes(释放CALL)[5]);
	data.push_back(intToBytes(释放CALL)[6]);
	data.push_back(intToBytes(释放CALL)[7]);
	data.push_back(0xff);
	data.push_back(0xD0);
	data.push_back(0X48);
	data.push_back(0X83);
	data.push_back(0XC4);
	data.push_back(0X48);
	data.push_back(0X5B);
	data.push_back(0XC3);

	内存汇编x64(data);

	data.clear();


}


int CMyMfcDlg::取对象坐标(int 读取指针, int 坐标参数)
{
	__int64 指针;
	int 坐标;

	if (Readint(读取指针 + 类型偏移) == 273)
	{
		指针 = Readint(读取指针 + X坐标);
		
		if (坐标参数 == 0)
			坐标 = Readflaot(指针 + 0);
		else if (坐标参数 == 1)
			坐标 = Readflaot(指针 + 4);
		else if (坐标参数 == 2)
			坐标 = Readflaot(指针 + 8);
	}
	else
	{
		指针 = Readint(读取指针 + 方向偏移);
		if (坐标参数 == 0)
			坐标 = Readflaot(指针 + 32);
		else if (坐标参数 == 1)
			坐标 = Readflaot(指针 + 36);
		else if (坐标参数 == 2)
			坐标 = Readflaot(指针 + 40);
	}
	return 坐标;

}

void CMyMfcDlg::内存汇编x64(std::vector<byte>asm_code)
{

	static __int64 Hook空白 = 0;
	bool 异步;
	__int64 空白地址, Hook地址, 判断地址, Hook跳回, 汇编地址 = (__int64)申请内存(1024);
	int 长 = asm_code.size();
	 std::vector<byte> asm_data, asm_as{ 0xFF,0x25,0x00,0x00,0x00,0x00 };

	if (Hook空白 == 0)
	{
		Hook空白 = (__int64)申请内存(4096);
		printf("申请的地址：%p\n", Hook空白);
	}

	空白地址 = 汇编地址 + 100;
	判断地址 = 汇编地址;
	Hook地址 = 0x13FDF0000;//0x1456C9C4D
	Hook地址 = Hook地址 + 144;
	Hook跳回 = Hook地址 + 19;
	异步 = true;
	if (asm_data.empty() == true)
	{
		asm_data = API_读字节集(Hook地址, 19);
		asm_data.push_back(0x48);
		asm_data.push_back(0xB8);
		asm_data.push_back(intToBytes(判断地址)[0]);
		asm_data.push_back(intToBytes(判断地址)[1]);
		asm_data.push_back(intToBytes(判断地址)[2]);
		asm_data.push_back(intToBytes(判断地址)[3]);
		asm_data.push_back(intToBytes(判断地址)[4]);
		asm_data.push_back(intToBytes(判断地址)[5]);
		asm_data.push_back(intToBytes(判断地址)[6]);
		asm_data.push_back(intToBytes(判断地址)[7]);
		asm_data.push_back(0x83);
		asm_data.push_back(0x38);
		asm_data.push_back(0x01);
		asm_data.push_back(0x75);
		asm_data.push_back(0x2A);
		asm_data.push_back(0x48);
		asm_data.push_back(0x81);
		asm_data.push_back(0xEC);
		asm_data.push_back(0x00);
		asm_data.push_back(0x03);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(0x48);
		asm_data.push_back(0xBB);
		asm_data.push_back(intToBytes(空白地址)[0]);
		asm_data.push_back(intToBytes(空白地址)[1]);
		asm_data.push_back(intToBytes(空白地址)[2]);
		asm_data.push_back(intToBytes(空白地址)[3]);
		asm_data.push_back(intToBytes(空白地址)[4]);
		asm_data.push_back(intToBytes(空白地址)[5]);
		asm_data.push_back(intToBytes(空白地址)[6]);
		asm_data.push_back(intToBytes(空白地址)[7]);
		asm_data.push_back(0xFF);
		asm_data.push_back(0xD3);
		asm_data.push_back(0x48);
		asm_data.push_back(0xB8);
		asm_data.push_back(intToBytes(判断地址)[0]);
		asm_data.push_back(intToBytes(判断地址)[1]);
		asm_data.push_back(intToBytes(判断地址)[2]);
		asm_data.push_back(intToBytes(判断地址)[3]);
		asm_data.push_back(intToBytes(判断地址)[4]);
		asm_data.push_back(intToBytes(判断地址)[5]);
		asm_data.push_back(intToBytes(判断地址)[6]);
		asm_data.push_back(intToBytes(判断地址)[7]);
		asm_data.push_back(0xC7);
		asm_data.push_back(0x00);
		asm_data.push_back(0x03);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(0x48);
		asm_data.push_back(0x81);
		asm_data.push_back(0xC4);
		asm_data.push_back(0x00);
		asm_data.push_back(0x03);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(0xFF);
		asm_data.push_back(0x25);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(0x00);
		asm_data.push_back(intToBytes(Hook跳回)[0]);
		asm_data.push_back(intToBytes(Hook跳回)[1]);
		asm_data.push_back(intToBytes(Hook跳回)[2]);
		asm_data.push_back(intToBytes(Hook跳回)[3]);
		asm_data.push_back(intToBytes(Hook跳回)[4]);
		asm_data.push_back(intToBytes(Hook跳回)[5]);
		asm_data.push_back(intToBytes(Hook跳回)[6]);
		asm_data.push_back(intToBytes(Hook跳回)[7]);


		Writeint(判断地址, 1);
		API_写字节集(判断地址, {0x01});
		API_写字节集(Hook空白, asm_data);
		asm_code.push_back(195);
		API_写字节集(空白地址, asm_code);
		asm_as.push_back(intToBytes(Hook空白)[0]);
		asm_as.push_back(intToBytes(Hook空白)[1]);
		asm_as.push_back(intToBytes(Hook空白)[2]);
		asm_as.push_back(intToBytes(Hook空白)[3]);
		asm_as.push_back(intToBytes(Hook空白)[4]);
		asm_as.push_back(intToBytes(Hook空白)[5]);
		asm_as.push_back(intToBytes(Hook空白)[6]);
		asm_as.push_back(intToBytes(Hook空白)[7]);
		API_写字节集(Hook地址, asm_as);
		while (Readint(判断地址) == 1)
		{
			//处理事件();
		}
		API_写字节集(Hook地址, { 15, 16, 28, 36, 15, 16, 84, 36, 16, 15, 16, 76, 36, 32, 15, 16, 68, 36, 48 });
		API_写字节集(Hook空白, asm_data);
		API_写字节集(空白地址, 内存填充(asm_code.size() + 64));



		asm_data .clear();
		//asm_as.clear();
	}



	异步 = false;
}


void CMyMfcDlg::城镇加速()
{
	static bool 加速开关;

	if (加速开关 == false)
	{
		API_写字节集(GM加速, { 52 });

		神话公告("城镇加速 - 开启", 1);

	}
	else
	{
		API_写字节集(GM加速, { 50, 192, 195, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204 });
		神话公告("城镇加速 - 关闭", 1);
	}

	加速开关 = !加速开关;
}


void  CMyMfcDlg::技能Call(__int64 触发指针, int 技能代码, int 技能伤害, int x, int y, int z, int 技能大小)
{
	static __int64 空白 = 空白地址 + 1200;
	if (技能大小 != 0)
		技能大小 = (float)技能大小;
	Writeint(空白, 触发指针);
	Writeint(空白 + 16, 技能代码);
	Writeint(空白 + 20, 技能伤害);
	Writeint(空白 + 32, x);
	Writeint(空白 + 36, y);
	Writeint(空白 + 40, z);
	Writefloat(空白 + 140, 技能大小);
	Writeint(空白 + 144, 65535);
	Writeint(空白 + 148, 65535);

	data.push_back(0X48);
	data.push_back(0x81);
	data.push_back(0xec);
	data.push_back(0x00);
	data.push_back(0x02);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x48);
	data.push_back(0xb9);
	data.push_back(intToBytes(空白)[0]);
	data.push_back(intToBytes(空白)[1]);
	data.push_back(intToBytes(空白)[2]);
	data.push_back(intToBytes(空白)[3]);
	data.push_back(intToBytes(空白)[4]);
	data.push_back(intToBytes(空白)[5]);
	data.push_back(intToBytes(空白)[6]);
	data.push_back(intToBytes(空白)[7]);
	data.push_back(0x48);
	data.push_back(0xb8);
	data.push_back(intToBytes(技能CALL)[0]);
	data.push_back(intToBytes(技能CALL)[1]);
	data.push_back(intToBytes(技能CALL)[2]);
	data.push_back(intToBytes(技能CALL)[3]);
	data.push_back(intToBytes(技能CALL)[4]);
	data.push_back(intToBytes(技能CALL)[5]);
	data.push_back(intToBytes(技能CALL)[6]);
	data.push_back(intToBytes(技能CALL)[7]);
	data.push_back(0xFF);
	data.push_back(0XD0);
	data.push_back(0X48);
	data.push_back(0X81);
	data.push_back(0XC4);
	data.push_back(0X00);
	data.push_back(0X02);
	data.push_back(0X00);
	data.push_back(0X00);

	内存汇编x64(data);

	data.clear();

}
/*.版本 2

.常量 范围左侧, "5457110439", , 14544E5A7 7度_获取
.常量 范围右侧, "5457110398", , 14544E57E 7度_获取
.常量 范围上侧, "5457110538", , 14544E60A 7度_获取
.常量 范围下侧, "5457110492", , 14544E5DC 7度_获取
*/

void CMyMfcDlg::钩子全屏()
{
	static bool 钩子开关;

	钩子开关 = !钩子开关;

	if (钩子开关)
	{

		API_写字节集(钩子上侧, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
		API_写字节集(钩子下侧, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
		API_写字节集(钩子左侧, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
		API_写字节集(钩子右侧, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });

		神话公告("全屏攻击 - 开启", 1);

	}
	else
	{
		API_写字节集(钩子上侧, { 0x0F, 0x82, 0xFF, 0x01, 0x00, 0x00 });
		API_写字节集(钩子下侧, { 0x0F, 0x82, 0x2D, 0x02, 0x00, 0x00 });
		API_写字节集(钩子左侧, { 0x0F, 0x82, 0x62, 0x02, 0x00, 0x00 });
		API_写字节集(钩子右侧, { 0x0F, 0x82, 0x8B, 0x02, 0x00, 0x00 });
		神话公告("全屏攻击 - 关闭", 1);

	}



}

void  CMyMfcDlg::API_写字节集(__int64 地址, std::vector<byte> 值)
{
	HANDLE hProcess;
	int length;
	if (Pid == -1)
		hProcess = GetCurrentProcess();
	else
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);
	length = (int)值.size();
	byte* val = new byte[length];
	for (int i = 0; i < length; i++)
	{
		
		val[i] = 值[i];
	}
	VirtualProtectEx(hProcess, (LPVOID)地址, length, PAGE_EXECUTE_READWRITE, NULL);
	if (WriteProcessMemory(hProcess, (LPVOID)地址,(LPCVOID)val, length, 0) == true)
	{
		//printf("成功\n");
	}
	else
	{
		//printf("失败\n");
	}
	CloseHandle(hProcess);
}


BOOL CMyMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	



	全屏模式.InsertString(0, "释放全屏");
	全屏模式.InsertString(1, "技能全屏");

	全屏模式.SetCurSel(1);

	//窗口置顶
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	//窗口不置顶
	//::SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	RegisterHotKey(this->m_hWnd, 0x70, 0, VK_F1);
	RegisterHotKey(this->m_hWnd, 0x71, 0, VK_F2);
	RegisterHotKey(this->m_hWnd, 0x74, 0, VK_F3);
	RegisterHotKey(this->m_hWnd, 0x75, 0, VK_F4);
	RegisterHotKey(this->m_hWnd, 0x72, 0, 'V');
	RegisterHotKey(this->m_hWnd, 0x73, 0, 192);
	((CButton*)GetDlgItem(IDC_BUTTON2))->EnableWindow(false); 
	//AllocConsole();

	//FILE* Ftp = freopen("CONOUT$", "w", stdout);


	Resourceloading("Mocode.sys", IDR_SYS2, "SYS");

	Sleep(2000); 

	
	
	CWnd* Game_Wnd = FindWindow(NULL, "地下城与勇士");


	if (!Game_Wnd)
	{
		AfxMessageBox("[ 地下城与勇士 ] 未运行，程序初始化失败");


		Sleep(1000);
		this->OnOK();

		return 0;
	}

	int bat;
	BOOL bRet = LoadNTDriver("Mocode.sys", "Mocode.sys");
	if (!bRet)
	{
		bat = MessageBox("驱动加载失败，请检查是否杀软拦截或重启计算机，则还不行，请自行卡图标!\t\n电脑自带图标请点击[ 是 ]，没有请点击 [ 否 ]，请自行卡图标，重新运行程序！", "凉城", MB_YESNO | MB_ICONERROR);
		if (bat == IDNO)
		{
	
			this->OnOK();
		}
	
	}

	if (bRet == true)
	{

		MessageBox("驱动加载成功", "凉城", MB_OK | MB_ICONINFORMATION);

	}
	//加载成功


	
	 ::GetWindowThreadProcessId(Game_Wnd->m_hWnd, &Pid);

	 CString Text;
	 Text.Format("GamePid：%d", Pid);

	 this->SetWindowTextA(Text);
	 Game_Handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);


	 if (!Game_Handle)
	 {
		 AfxMessageBox("打开游戏进程失败,请管理员身份运行我！！！");
		 this->OnOK();
	 }
		 
	
	 if (取游戏状态() == 3 || 取游戏状态() == 0 || 取游戏状态() == 1 || 取游戏状态() == 5)
	 {
		 神话公告("你是我患失患得的梦!");
		 神话公告("我是你可有可无的人!");
		 神话公告("F1 * 技能全屏");
		 神话公告("F2 * 独家倍功");
		 神话公告("F3 * 全屏攻击");
		 神话公告("F4 * 城镇加速");
		 神话公告("V  * 物品聚拢");
		 神话公告("~  * Type秒杀");
		 SetTimer(3, 500,0);
	 }
	 else
	 {
		 AfxMessageBox("辅助激活失败，请重试\n");
		 this->OnOK();
	 }







	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyMfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyMfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{







	
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyMfcDlg::OnBnClickedButton1()
{

  //卡邮件
	((CButton*)GetDlgItem(IDC_BUTTON2))->EnableWindow(true);

	((CButton*)GetDlgItem(IDC_BUTTON1))->EnableWindow(false);

	SetTimer(2, 1000, NULL);
	//MessageBox("符咒初始化成功", "凉城", MB_OK | MB_ICONINFORMATION);
	神话公告("符咒初始化成功", 1);

	// TODO: 在此添加控件通知处理程序代码
}

void CMyMfcDlg::停止符咒()
{
	UINT 部位 = Readint(0X14B714B30);
	部位 += 0x9EB0;
	部位 = Readint(部位);
	部位 += 0x80;
	部位 = Readint(部位);
	部位 += 0x30;
	部位 = Readint(部位);
	部位 += 0xBD8;
	Writeint(部位, 16);
}

void CMyMfcDlg::符咒全屏()
{
	UpdateData(true);



	UINT 部位 = Readint(人物机制);
	部位 += 0x9EB0;
	部位 = Readint(部位);
	部位 += 0x80;
	部位 = Readint(部位);
	部位 += 0x30;
	部位 = Readint(部位);
	部位 += 0xBD8;
	Writeint(部位, 31);


	//符咒伤害
	UINT 伤害2 = Readint(人物机制);
	伤害2 += 0x9EB0;
	伤害2 = Readint(伤害2);
	伤害2 += 0x80;
	伤害2 = Readint(伤害2);
	伤害2 += 0x30;
	伤害2 = Readint(伤害2);
	伤害2 += 0x1248;
	伤害2 = Readint(伤害2);
	伤害2 += 0xB0;
	伤害2 = Readint(伤害2);
	伤害2 += 0x8;
	伤害2 = Readint(伤害2);
	伤害2 += 0x58;
	伤害2 = Readint(伤害2);
	伤害2 += 0x1c;
	printf("伤害：%p\n", 伤害2);
	Writefloat(伤害2, (double)_atoi64(伤害1));


	//符咒频率
	UINT 频率 = Readint(人物机制);
	频率 += 0x9EB0;
	频率 = Readint(频率);
	频率 += 0x80;
	频率 = Readint(频率);
	频率 += 0x30;
	频率 = Readint(频率);
	频率 += 0x1248;
	频率 = Readint(频率);
	频率 += 0x88;
	频率 = Readint(频率);
	频率 += 0x30;
	频率 = Readint(频率);
	频率 += 0x4;
	printf("频率：%p\n", 频率);
	Writeint(频率, _atoi64(伤害));

	UINT 几率 = Readint(人物机制);
	几率 += 0x9EB0;
	几率 = Readint(几率);
	几率 += 0x80;
	几率 = Readint(几率);
	几率 += 0x30;
	几率 = Readint(几率);
	几率 += 0x1248;
	几率 = Readint(几率);
	几率 += 0xB0;
	几率 = Readint(几率);
	几率 += 0x8;
	几率 = Readint(几率);
	几率 += 0x30;
	几率 = Readint(几率);
	几率 += 0x4;
	printf("几率:%p\n", 几率);
	Writefloat(几率, (double)100);


	UINT 触发 = Readint(人物机制);
	触发 += 0x9EB0;
	触发 = Readint(触发);
	触发 += 0x80;
	触发 = Readint(触发);
	触发 += 0x30;
	触发 = Readint(触发);
	触发 += 0x1248;
	触发 = Readint(触发);
	触发 += 0x88;
	触发 = Readint(触发);
	触发 += 0x8;
	触发 = Readint(触发);
	printf("触发：%p\n", 触发);
	Writeint(触发, _atoi64(方式));


	UINT 代码 = Readint(人物机制);
	代码 += 0x9EB0;
	代码 = Readint(代码);
	代码 += 0x80;
	代码 = Readint(代码);
	代码 += 0x30;
	代码 = Readint(代码);
	代码 += 0x1248;
	代码 = Readint(代码);
	代码 += 0xb0;
	代码 = Readint(代码);
	代码 += 0x8;
	代码 = Readint(代码);
	代码 += 0x58;
	代码 = Readint(代码);
	代码 += 0x0c;

	printf("代码：%p\n", 代码);
	Writefloat(代码, (float)_atoi64(code));


	UINT 全屏 = Readint(人物机制);

	全屏 += 0x9EB0;
	全屏 = Readint(全屏);
	全屏 += 0x80;
	全屏 = Readint(全屏);
	全屏 += 0x30;
	全屏 = Readint(全屏);
	全屏 += 0x1248;
	全屏 = Readint(全屏);
	全屏 += 0xb0;
	全屏 = Readint(全屏);
	全屏 += 0x8;
	全屏 = Readint(全屏);
	全屏 += 0x8;
	全屏 = Readint(全屏);
	全屏 += 0x4;
	printf("全屏：%p\n", 全屏);
	Writefloat(全屏, (float)4);

	UINT star = Readint(人物机制);
	star += 0x9EB0;
	star = Readint(star);
	star += 0x80;
	star = Readint(star);
	star += 0x30;
	star = Readint(star);
	star += 0x1248;
	star = Readint(star);
	star += 0xb0;
	star = Readint(star);
	star += 0x8;
	star = Readint(star);
	star += 0x58;
	star = Readint(star);
	star += 0x8;
	printf("star：%p\n", star);
	Writefloat(star, (float)-1);

}

void CMyMfcDlg::OnBnClickedButton2()
{
	CString flg;
	pButton.GetWindowTextA(flg);
	if (flg == "激活符咒")
	{
		pButton.SetWindowTextA("停止符咒");
		SetTimer(1, 1000, NULL);
		//((CButton*)GetDlgItem(IDC_BUTTON1))->EnableWindow(true);
	}

	if (flg == "停止符咒")
	{
		pButton.SetWindowTextA("激活符咒");
		停止符咒();
		KillTimer(1);

	}


	// TODO: 在此添加控件通知处理程序代码
}


void CMyMfcDlg::OnBnClickedButton3()
{

	UINT 被减 = 0;

	UINT 减少 = Readint(人物机制);
	减少 += 0x9EB0;
	减少 = Readint(减少);
	减少 += 0x80;
	减少 = Readint(减少);
	减少 += 0x30;
	减少 = Readint(减少);
	减少 += 0x10;
	被减 = 减少;
	减少 = Readint(被减);

	减少 -= 100000;
	Writeint(被减, 减少);



	// TODO: 在此添加控件通知处理程序代码
}




void CMyMfcDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值




	switch (nIDEvent)
	{

	case 1:
	{
		符咒全屏();

		break;

	}

	case 2:
	{
		UINT 人物指针 = Readint(人物机制);
		人物指针 += 0x9EB0;
		人物指针 = Readint(人物指针);
		人物指针 += 0x80;
		人物指针 = Readint(人物指针);
		人物指针 += 0x30;
		人物指针 = Readint(人物指针);
		人物指针 += 0x30;
		//pass = Readint(人物指针);
		Writeint(人物指针, 100090444);
		break;
	}



	case 3:
	{
		static bool 初始化 = false,通关初始化 = false;
		static int 计次 = 0;

		if (取游戏状态() == 3)
		{

			if (初始化 == false)
			{
				初始化 = true;

				评分Call(9999999);

				物品Call(490001766);
				物品Call(490013664);
				物品Call(490016659);
				物品Call(2600019);
				物品Call(490016659);
				物品Call(490013664);
				物品Call(490017343);

				物品Call(490014049); //三速50 智力 力量14000

				物品Call(490703931);//三速10
				物品Call(490016135); //三速50 智力 力量14000
		
			}
			
			
			if (判断通关() ==  2 && 当前是否开门() == true && 通关初始化 == false)
			{
				计次++;
				CString  通关文本; 
				通关文本.Format("通关副本[ %d ]次 - 剩余疲劳[ %d ]点", 计次, 当前疲劳());
				神话公告(通关文本);
				通关初始化 = true;

			}

		}
		else
		{
			初始化 = false;
			通关初始化 = false;
		}








		break;
	}


	case 4:
	{

		全屏遍历();
		break;
	}


	}
}

void CMyMfcDlg::On32772()
{
	

	MessageBox("1.驱动加载失败请自行卡图标\t\n2.Win10系统请管理员运行\t\n,3在游戏内初始化符咒,材料或消耗品放在物品栏4上,不能少于2个以上,自己进行卡邮件操作,会玩的自然懂!\t\n4.Win7系统如果驱动加载成功了，没效果,请把本程序名字改为；[ csrss ]重新运行即可\t\n5.本软件只用于学习交流纯属免费使用,请在24小时内自行删除,出现任何问题本人概不负责!\t\n\n\t\n\t        [ 稳定优势 ]\t\n\n 不建议使用F1 技能全屏,稳定性自测", "By:凉城" , MB_OK | MB_ICONINFORMATION);

	
}



BOOL CMyMfcDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类



	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case  VK_ESCAPE:
			return TRUE;
		}
	}





	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMyMfcDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值






	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMyMfcDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值






	if (nKey1 == VK_F2 || nKey2 == VK_F2)
	{
		HOOK倍功();

	}
	else if (nKey1 == VK_F1 || nKey2 == VK_F1)
	{
		技能开关();
	}
	else if (nKey1 == VK_F3 || nKey2 == VK_F3)
	{
		钩子全屏();
	}
	else if (nKey1 == VK_F4 || nKey2 == VK_F4)
	{
		城镇加速();
	}
	else if (nKey1 == 'V' || nKey2 == 'V')
	{
		吸取遍历();
	}

	else if (nKey1 == 192 || nKey2 == 192)
	{
		UpdateData(true);

		技能Call(Readint(人物机制), _atoi64(自定义), 999999, 300, 200, 0, 30);

		神话公告("自定义代码秒杀 - 成功",1);

	}




	









	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CMyMfcDlg::OnBnClickedCheck1()
{

	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck() == true)
	{
		Writeint(Readint(人物机制) + 无敌偏移, 100);
		神话公告("无敌霸体 - 开启",1);
	}


	// TODO:  在此添加控件通知处理程序代码
}
