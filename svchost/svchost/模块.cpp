#pragma once
#include "pch.h"
#include "模块.h"
#include <process.h>
#include <iostream>
#include "string.h"
#include <Mmsystem.h>



void 处理事件()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		DispatchMessage(&msg);
		TranslateMessage(&msg);
	}
}

DWORD 取进程ID(const char* pName)//通过进程名获取进程ID
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
		if (strcmp(pe.szExeFile, pName) == 0) {
			CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
	}
	CloseHandle(hSnapshot);
	return 0;
}

HANDLE 打开进程(DWORD nID)//通过进程ID获取局部变量1
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}

float 读内存小数型(DWORD 进程ID, INT64 内存地址)
{
	float lpBuffer;
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, PAGE_EXECUTE_READWRITE, &保护属性);

	if (ReadProcessMemory(局部变量1, (LPCVOID)内存地址, &lpBuffer, 4, 0) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
	return lpBuffer;
}

INT16 读内存短整数型(DWORD 进程ID, INT64 内存地址)
{
	INT16 lpBuffer;
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 2, PAGE_EXECUTE_READWRITE, &保护属性);

	if (ReadProcessMemory(局部变量1, (LPCVOID)内存地址, &lpBuffer, 2, 0) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 2, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
	return lpBuffer;
}

INT32 读内存整数型(DWORD 进程ID, INT64 内存地址)
{
	INT32 lpBuffer;
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, PAGE_EXECUTE_READWRITE, &保护属性);

	if (ReadProcessMemory(局部变量1, (LPCVOID)内存地址, &lpBuffer, 4, 0) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
	return lpBuffer;
}

INT64 读内存长整数型(DWORD 进程ID, INT64 内存地址)
{
	INT64 lpBuffer;
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 8, PAGE_EXECUTE_READWRITE, &保护属性);

	if (ReadProcessMemory(局部变量1, (LPCVOID)内存地址, &lpBuffer, 8, 0) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 8, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
	return lpBuffer;
}
vector<byte>  读内存字节集(DWORD 进程ID, INT64 内存地址, INT64 length)
{
	byte* lpBuffer;
	lpBuffer = new byte[length + 1];
	memset(lpBuffer, 0, length);
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), length, PAGE_EXECUTE_READWRITE, &保护属性);

	if (ReadProcessMemory(局部变量1, (LPCVOID)内存地址, lpBuffer, length, 0) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), length, 保护属性, &保护属性);
	
	}	
	vector<byte> result;
	result.resize(length);
	for (int i = 0; i < length; i++)
	{
		result[i] = lpBuffer[i];
	}
	CloseHandle(局部变量1);
	return result;
}

INT64 取偏移地址(INT64 基址, vector<int> 偏移地址)
{
	INT64 地址;
	地址 = 基址;
	for (size_t i = 0; i < 偏移地址.size(); ++i)
	{
		地址 = 读内存长整数型(进程ID, 地址);
		地址 = 地址 + 偏移地址.at(i);
	}
	return 地址;
}


void 写内存小数型(DWORD 进程ID, INT64 内存地址, float 要写入的数据)
{
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, PAGE_EXECUTE_READWRITE, &保护属性);

	if (WriteProcessMemory(局部变量1, (LPVOID)内存地址, &要写入的数据, 4, NULL)==true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
}
void 写内存短整数型(DWORD 进程ID, INT64 内存地址, INT16 要写入的数据)
{
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 2, PAGE_EXECUTE_READWRITE, &保护属性);

	if (WriteProcessMemory(局部变量1, (LPVOID)内存地址, &要写入的数据, 2, NULL) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 2, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
}
void 写内存整数型(DWORD 进程ID, INT64 内存地址, INT32 要写入的数据)
{
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, PAGE_EXECUTE_READWRITE, &保护属性);

	if (WriteProcessMemory(局部变量1, (LPVOID)内存地址, &要写入的数据, 4, NULL) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 4, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
}
void 写内存长整数型(DWORD 进程ID, INT64 内存地址, INT64 要写入的数据)
{
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 8, PAGE_EXECUTE_READWRITE, &保护属性);

	if (WriteProcessMemory(局部变量1, (LPVOID)内存地址, &要写入的数据, 8, NULL) == true)
	{
	
		VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 8, 保护属性, &保护属性);
	
	}
	CloseHandle(局部变量1);
}
void 写内存字节集(DWORD 进程ID, INT64 内存地址, vector<BYTE> 要写入的数据)
{
	DWORD 保护属性;
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 要写入的数据.size(), PAGE_EXECUTE_READWRITE, &保护属性);

	int length;
	length = (int)要写入的数据.size();
	for (int i = 0; i < length; i++)
	{	
		WriteProcessMemory(局部变量1, (LPVOID)内存地址, &要写入的数据[i],1, NULL);
		内存地址++;
	}

	VirtualProtectEx(局部变量1, reinterpret_cast<LPVOID>(内存地址), 要写入的数据.size(), 保护属性, &保护属性);

	CloseHandle(局部变量1);
}





/*
*延时间隔	1000微秒 = 1毫秒 ； 1000毫秒 = 1秒
延时单位	可空:毫秒  0 毫秒  1 微秒  2 秒  3 分  4 小时  5 天
*/
void 超级延迟(INT64 延时间隔, INT64 延时单位)
{
	HANDLE 局部变量1;
	_LARGE_INTEGER 局部变量2;

	//if (延时间隔 < 1) 
	//{
	//	return;
	//}

	switch (延时单位)
	{
	case 1:
		局部变量2.QuadPart = -10 * 延时间隔;
		局部变量1 = CreateWaitableTimerA(NULL, FALSE, NULL);
		if (局部变量1 != 0)
		{
			SetWaitableTimer(局部变量1, &局部变量2, 0, NULL, NULL, FALSE);
			while (MsgWaitForMultipleObjects(1, &局部变量1, FALSE, INFINITE, QS_ALLINPUT) != 0)
			{
				处理事件();
			}
			CloseHandle(局部变量1);
		}
		return;
		break;
	case 0:
		延时单位 = 1;
		break;
	case 2:
		延时单位 = 1000;
		break;
	case 3:
		延时单位 = 1000 * 60;
		break;
	case 4:
		延时单位 = 1000 * 60 * 60;
		break;
	case 5:
		延时单位 = 1000 * 60 * 60 * 24;
		break;
	}
	局部变量2.QuadPart = -10 * 延时间隔 * 1000 * 延时单位;
	局部变量1 = CreateWaitableTimerA(NULL, FALSE, NULL);
	if (局部变量1 != 0)
	{
		SetWaitableTimer(局部变量1, &局部变量2, 0, NULL, NULL, FALSE);
		while (MsgWaitForMultipleObjects(1, &局部变量1, FALSE, INFINITE, QS_ALLINPUT) != 0)
		{
			处理事件();
		}
		CloseHandle(局部变量1);
	}
	return;
}
/*
*延时间隔	1000微秒 = 1毫秒 ； 1000毫秒 = 1秒
延时单位	可空:毫秒  0 毫秒  1 微秒  2 秒  3 分  4 小时  5 天
*/
void 超级延时(INT64 延时间隔)
{
	HANDLE 局部变量1;
	_LARGE_INTEGER 局部变量2;
	局部变量2.QuadPart = -10 * 延时间隔 * 1000;
	局部变量1 = CreateWaitableTimerA(NULL, FALSE, NULL);
	if (局部变量1 != 0)
	{
		SetWaitableTimer(局部变量1, &局部变量2, 0, NULL, NULL, FALSE);
		while (MsgWaitForMultipleObjects(1, &局部变量1, FALSE, INFINITE, QS_ALLINPUT) != 0)
		{
			处理事件();
		}
		CloseHandle(局部变量1);
	}
	return;
}


WCHAR* 转换Ansi转Unicode(CHAR* str)
{
	DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	 wchar_t* pwText;	 
	pwText = new wchar_t[dwNum];
	if (!pwText) delete[]pwText;
	MultiByteToWideChar(CP_ACP, 0, str, -1, pwText, dwNum);
	return pwText;
}

vector<byte> Ansi转Unicode(CString str)
{
	vector<byte>Ret;
	DWORD dwNum = MultiByteToWideChar(936, 0, str, -1, NULL, 0);
	byte* pwText;
	pwText = new  byte[dwNum * (long)2];
	MultiByteToWideChar(936, 0, str, -1, (LPWSTR)pwText, dwNum * 2);

	for (size_t i = 0; i < dwNum * (long)2; i++)
	{
		Ret.push_back(pwText[i]);
	}
	Ret.push_back(0);
	Ret.push_back(0);
	return Ret;
}

CString 转换Unicode转Ansi(vector<BYTE> 参_字节集)
{
	size_t 局_字节长度 = 参_字节集.size();
	 CHAR* 局_Unicode;
	局_Unicode = new CHAR[局_字节长度]; 
	for (size_t i = 0; i < 局_字节长度; i++)
	{
		局_Unicode[i] = 参_字节集[i];
	}
	//UniCode到Ansi
	DWORD 局_计数 = WideCharToMultiByte(936, 512, (LPCWCH)局_Unicode, -1, 0, 0, 0, FALSE);
	 CHAR* 缓冲区;
	缓冲区 = new CHAR[局_计数];	
	WideCharToMultiByte(936, 512, (LPCWCH)局_Unicode, -1, 缓冲区, 局_计数, NULL, NULL);
	// string转wstring
	DWORD nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, 缓冲区, -1, NULL, 0);
	 WCHAR* pResult;
	pResult = new WCHAR[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, 缓冲区, -1, pResult, nLen);
	wstring wresult = pResult;
	CString cs(wresult.c_str());
	return cs;
}


vector<byte> 整数到字节集(INT64   i) {
	INT64   adr = (INT64)&i;
	vector<byte>c;
	for (size_t i = 0; i < 8; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

CString 到文本(LONG64 a)
{
	
	wstring result;
	WCHAR str[20];
	_i64tow_s(a, str, 20, 10);
	result = str;
	CString cstr(result.c_str());
	return cstr;
}


CString 十到十六(LONG64 a)
{
	char s[255];
	//char* s1;
	sprintf_s(s, "%I64x", a);
	for (size_t i = 0; i < 255; i++)
	{
		s[i] = toupper(s[i]);
	}
	string t(s);
	CString cs(t.c_str());
	return cs;
}



BOOL 置剪辑板文本(CString 文本)
{
	HGLOBAL 局部变量1=0;
	HANDLE 局部变量2=0;
	OpenClipboard(0);
	EmptyClipboard();

	局部变量1=GlobalAlloc(66, (文本.GetLength() + (long long)(long)1));
	if (局部变量1 != 0)
	{
		memmove(GlobalLock(局部变量1), 文本, 文本.GetLength());
		GlobalUnlock(局部变量1);
		局部变量2 = SetClipboardData(1, 局部变量1);
		GlobalFree(局部变量1);
	}
	CloseClipboard();
	return (局部变量2 != 0);
}
//
//string 字节集到十六进制(const BYTE* bytes, const int length)
//{
//	if (bytes == NULL) {
//		return "";
//	}
//	string buff;
//	const int len = length;
//	for (int j = 0; j < len; j++) {
//		/*if ((bytes[j] & 0xff) < 16) {
//			buff.append("0");
//		}*/
//		int high = bytes[j] / 16, low = bytes[j] % 16;
//		buff += (high < 10) ? ('0' + high) : ('a' + high - 10);
//		buff += (low < 10) ? ('0' + low) : ('a' + low - 10);
//	}
//	return buff;
//}
///*还原十六进制字符串形式字节集的文本到字节集*/
//void 还原字节集2(const string& hex, BYTE* bytes)
//{
//	int bytelen = hex.length() / 2;
//	string strByte;
//	unsigned int n;
//	for (int i = 0; i < bytelen; i++)
//	{
//		strByte = hex.substr(i * 2, 2);
//		sscanf(strByte.c_str(), "%x", &n);
//		bytes[i] = n;
//	}
//}
//
//void 删全部空(string& s)
//{
//	int index = 0;
//	if (!s.empty())
//	{
//		while ((index = s.find(' ', index)) != string::npos)
//		{
//			s.erase(index, 1);
//		}
//	}
//}
//
//void 删首尾空(string& s)
//{
//	int index = 0;
//	if (!s.empty())
//	{
//		while ((index = s.find(' ', index)) != string::npos)
//		{
//			s.erase(index, 1);
//		}
//	}
//}
//
//int 寻找字节集(byte* 被搜寻的字节集, int 被搜寻长度, byte* 待搜索的字节集, int 要搜索的长度, int 起始搜寻位置)
//{//int SearchByteShuZu(byte * bForSearch,int ifLen, byte* bWaitSearch, int iwLen,int iFirstSearchPos);//寻找字节集数组(待寻找的,待寻找的最大长度,要寻找的,要寻找的长度,起始寻找位置)  返回-1 为未找到 位置从0开始
//	int iCurrentPos = 0;//待搜索位置
//	if (起始搜寻位置 > 被搜寻长度)//超过待搜索的长度
//	{
//		return -1;
//	}
//	if (要搜索的长度 > 被搜寻长度)//要搜索的长度比 待搜索的长度大 返回
//	{
//		return -1;
//	}
//	if (要搜索的长度 == 0 || 被搜寻长度 == 0)
//	{
//		return -1;//0 返回
//	}
//	//    bForSearch+=iFirstSearchPos;//设置起始搜索位置
//	iCurrentPos += 起始搜寻位置;//设置起始搜索位置
//	被搜寻的字节集 += iCurrentPos;//设置指针 对应
//	while (1)
//	{
//		while (*被搜寻的字节集 != *待搜索的字节集)//找到第一个相同的
//		{
//			iCurrentPos += 1;//当前搜索位置前进1
//			被搜寻的字节集 += 1;//当前指针前进1
//			if (iCurrentPos > 被搜寻长度)    //长度超过待搜索的整体长度返回
//			{
//				return -1;
//			}
//		}
//		for (int i = 0; i < 要搜索的长度; ++i)//开始对比
//		{
//			if (*(被搜寻的字节集 + i) != *(待搜索的字节集 + i))
//			{
//				iCurrentPos += 1;//当前搜索位置前进1
//				被搜寻的字节集 += 1;//当前指针前进1
//				//设置下指针前进1
//				break;//找到一个不同的 跳出
//			}
//			if (i + 1 == 要搜索的长度)
//			{
//				return iCurrentPos;//找到列
//			}
//		}
//	}
//}
//
//template<class T>
//int 取字节集长度(T& array)
//{
//	return sizeof(array) / sizeof(array[0]);
//}


wstring string转wstring(string str)
{
	wstring result;
	//获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	wchar_t* buffer = new wchar_t[len + 1];
	//多字节编码转换成宽字节编码  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //添加字符串结尾  
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}

string wstring转string(wstring wstr)
{
	string result;
	//获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//宽字节编码转换成多字节编码  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}

//
//void HOOK加速() 
//{
//	GetProcAddress(, "timeGetTime")
//	GetModuleHandleA
//
//
//
//
//}


void 进程结束(DWORD 进程PID) 
{
	HANDLE 局部变量1;
	
	if (进程PID==0)
	{
		局部变量1 = GetCurrentProcess();
	}
	else
	{
		局部变量1 = OpenProcess(1, 0, 进程ID);
	}

	TerminateProcess(局部变量1, 0);
	CloseHandle(局部变量1);
	//char s[10];
	//_countof( s);
}


void 提升进程权限() 
{

	HANDLE 局部变量1;
	HANDLE 局部变量2;
	TOKEN_PRIVILEGES tp;
	
	局部变量1 = GetCurrentProcess();
	OpenProcessToken(局部变量1, TOKEN_ALL_ACCESS, &局部变量2);
	LookupPrivilegeValueA(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(局部变量2, FALSE, &tp, sizeof(tp), NULL, NULL);
	CloseHandle(局部变量2);
}


LPVOID 申请内存x64(int DwSize)
{
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	LPVOID Address = 0;
	if (DwSize == 0)
		DwSize = 1;
	Address = VirtualAllocEx(局部变量1, 0, DwSize, 4096, 64);
	CloseHandle(局部变量1);
	if (Address > 0)
		return Address;
	return 0;
}

bool 释放内存(LPVOID 释放地址)
{
	HANDLE 局部变量1;
	局部变量1 = OpenProcess(2035711, 0, 进程ID);
	if (!VirtualFreeEx(局部变量1, 释放地址, 0, MEM_RELEASE)) 
	{
		return false;
		CloseHandle(局部变量1);
	}
	else 
	{
		return true;
	}		
}

vector<byte>内存填充(INT64 填充大小)
{
	vector<byte>填充;

	for (INT64 i = 0; i < 填充大小; i++)
	{
		填充.push_back(0);
	}
	return 填充;
}

vector<byte>HOOK_JMP(INT64 Hook地址,INT64 跳转地址,vector<byte>	附加字节集)
{
	vector<byte> 局部1, 局部2;
	局部1 = { 233 };
	局部2 = 整数到字节集(跳转地址 - Hook地址 - 5);
	局部1.insert(局部1.end(), 局部2.begin(), 局部2.end());
	if (sizeof(附加字节集) != 0)
	{
		局部1.insert(局部1.end(), 附加字节集.begin(), 附加字节集.end());
	}
	return 局部1;
}

void 写到文件(LPCTSTR 文件路径, int 资源ID,const char* 资源类型 )
{
	HRSRC   hResource = FindResource(GetModuleHandle(NULL), MAKEINTRESOURCE(资源ID), TEXT(资源类型));
	if (hResource)
	{
		HGLOBAL   hg = LoadResource(GetModuleHandle(NULL), hResource);
		if (hg)
		{
			LPVOID   pData = LockResource(hg);
			if (pData)
			{
				DWORD   dwSize = SizeofResource(GetModuleHandle(NULL), hResource);
				CFile   calcFile;
				if (calcFile.Open(文件路径, CFile::modeCreate | CFile::modeReadWrite))
				{
					calcFile.Write(pData, dwSize);
					calcFile.Close();
				}
			}
		}
	}
}

 bool 文件是否存在(const char* name)
 {
	int iRtn = _access(name, 0);
	if (iRtn==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 

DWORD 进程是否存在(LPCTSTR name)
 {
	 PROCESSENTRY32 pe;
	 DWORD id = 0;
	 HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	 pe.dwSize = sizeof(PROCESSENTRY32);
	 if (!Process32First(hSnapshot, &pe))
		 return 0;
	 while (1)
	 {
		 pe.dwSize = sizeof(PROCESSENTRY32);
		 if (Process32Next(hSnapshot, &pe) == FALSE)
			 break;
		 if (strcmp(pe.szExeFile, name) == 0)
		 {
			 id = pe.th32ProcessID;
			 break;
		 }
	 }
	 CloseHandle(hSnapshot);
	 return id;
 }

void 提升读写权限() 
{
	WCHAR 自身信息[_MAX_PATH];
	GetModuleFileNameW(NULL, 自身信息, _MAX_PATH);
	CString st1 = "C:\\Windows\\SysWOW64\\PsExec64.exe -i -d -s ";
	string st2 = wstring转string(自身信息);
	st1 += st2.c_str();
	if (!文件是否存在("C:\\Windows\\SysWOW64\\PsExec64.exe"))
	{
		写到文件("C:\\Windows\\SysWOW64\\PsExec64.exe", IDR_PSEXEC1,"Psexec");
		运行("C:\\Windows\\SysWOW64\\PsExec64.exe /accepteula");
	}
	if (进程是否存在("cmd.exe")==0)
	{
		WinExec("cmd.exe",0);
		//MessageBoxA(自窗口句柄, st1, "提示", 0);
		//MessageBoxA(自窗口句柄, "进程不存在", "提示", 0);
		//WinExec(st1,1);
		//超级延时(2000);
		if (WinExec(st1,0) <31)
		{
			指定父进程获得system权限(取进程ID("winlogon.exe"), st2.c_str());			
		}
		exit(0);
	}
	运行("taskkill /f /T /im cmd.exe");
}

void 指定父进程获得system权限(DWORD 参数1,CString 参数2)
{
	HMODULE hDll = ::LoadLibraryA("ntdll.dll");
	typedef int (*type_RtlAdjustPrivilege)(int, bool, bool, int*);
	type_RtlAdjustPrivilege RtlAdjustPrivilege = (type_RtlAdjustPrivilege)GetProcAddress(hDll, "RtlAdjustPrivilege");
	RtlAdjustPrivilege(20, 1, 0, 0);
	LPSTARTUPINFOA 局部1 ;
	LPCSTR 局部2="", 局部3="";
	LPPROCESS_INFORMATION 局部4;
	ZeroMemory(&局部1, sizeof(局部1));
	ZeroMemory(&局部4, sizeof(局部4));
	HANDLE 局部8 = OpenProcess(2035711, 0, 参数1);
	SIZE_T 局部5=0;	
	InitializeProcThreadAttributeList(NULL, 1, 0, &局部5);
	char* temp;
	temp = new char[局部5];
	LPPROC_THREAD_ATTRIBUTE_LIST 局部6 = (LPPROC_THREAD_ATTRIBUTE_LIST)temp;
	LPPROC_THREAD_ATTRIBUTE_LIST 局部7 = (LPPROC_THREAD_ATTRIBUTE_LIST)temp;
	InitializeProcThreadAttributeList(局部6,1,0,&局部5);
	HeapAlloc(GetProcessHeap(), 0, 局部5);
	memmove(局部7,局部6,局部5);
	UpdateProcThreadAttribute(局部7, 0, 131072, 局部8, 4, 0, 0);	
	局部1->cb = 68;
	局部1->dwFlags = 0;
	局部1->wShowWindow = 1;
	CreateProcessAsUserA(0,局部2, (LPSTR)(LPCSTR)参数2, 0, 0, 0, 524288, 0, 局部3, 局部1, 局部4);	
	DeleteProcThreadAttributeList(局部7);
	HeapFree(GetProcessHeap(), 0, 局部7);
}

void 终止进程(CString 进程名) 
{
	CString 命令, 命令1, stid;
	int PID=取进程ID(进程名);
	stid.Format("%d", PID);
	 命令= "taskkill /F /T /PID ";
	 命令1 = 命令 + stid;
	//system(命令1);
	运行(命令1);
}

CString 寻找一个文件(CString 文件名)
{
	WIN32_FIND_DATA fileinfo;
	DWORD errorcode = 0;
	HANDLE hFile;
	hFile = FindFirstFileA(文件名, &fileinfo);
	if (hFile != INVALID_HANDLE_VALUE && errorcode != ERROR_NO_MORE_FILES)
	{
		return fileinfo.cFileName;
		//FindNextFile(hFile, &fileinfo);
		//errorcode = GetLastError();
	}
	else
	{

		return "";
	}
}

void 运行(CString strCmd)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	//隐藏掉可能出现的cmd命令窗口
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	ZeroMemory(&pi, sizeof(pi));

	// Start the child process. 
	if (!CreateProcessA(NULL,   // No module name (use command line)
		(LPSTR)(LPCTSTR)strCmd,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		//printf("CreateProcess failed (%d).\n", GetLastError());
		return;
	}
	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}













/*0我的桌面 1临时目录 2我的程序 5我的文档 6我的收藏夹 7我的启动 8我最近的文档 9我的发送到 11我的开始菜单 13我的音乐 14我的视频 16我的桌面 20系统字体 22开始菜单组 23程序组 24启动组 25桌面 31收藏夹 32我的浏览器临时目录 33我的Cookies 34我的历史记录 36Windows安装目录 37系统目录 38文件安装目录 39我的图片 40用户目录 41系统目录 46文档 47管理工具 48我的管理工具 53音乐 54图片 55视频
*/
CString 取特殊目录(int 目录ID)
{
	CString 路径1;	
	if (目录ID == 1) 
	{
		GetTempPathA(260, (LPSTR)(LPCTSTR)路径1);
		//MessageBoxA(自窗口句柄, 路径1, "DNF", 0);
	}
	else
	{
		SHGetSpecialFolderPathA(NULL, (LPSTR)(LPCTSTR)路径1, 目录ID, FALSE);
	}
	return 路径1;
}



INT64 取启动时间() 
{
	INT64 t = GetTickCount64();
	//str1.Format("系统已运行 %d时", t / 3600000);
	//str = str1;
	//t %= 3600000;
	//str1.Format("%d分", t / 60000);
	//str += str1;
	//t %= 60000;
	//str1.Format("%d秒", t / 1000);
	//str += str1;
	//AfxMessageBox(str);
	return t;
}

void 强制删除文件(CString 文件名) 
{
	CString 安全目录;
	SECURITY_ATTRIBUTES 安全性结构;
	ZeroMemory(&安全性结构, sizeof(安全性结构));
	安全目录 = 取特殊目录(1) + 到文本(取启动时间());
	CreateDirectoryA(安全目录, &安全性结构);
	CreateDirectoryA(安全目录+"\\....\\", &安全性结构);
	//MessageBoxA(自窗口句柄, 安全目录, "DNF", 0);
	MoveFileA(文件名, 安全目录 + "\\....\\TemporaryFile");
	MoveFileA(安全目录 + "\\....\\", 安全目录 + "\\TemporaryFile");
	remove(安全目录);	
}


CString 取执行文件名() 
{	
	WCHAR 自身信息[_MAX_PATH];
	GetModuleFileNameW(NULL, 自身信息, _MAX_PATH);
	string st1 = wstring转string(自身信息);
	return st1.c_str();
}

int 监视热键(LPTHREAD_START_ROUTINE 响应事件,int 键代码=0,int 功能键代码=0,int 其他键=0,int 周期=10,bool 直接触发=FALSE )
{



	//setTimer()		
}