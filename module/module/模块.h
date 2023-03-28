#include "windows.h"



#pragma once

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

HANDLE 打开进程(DWORD nID)//通过进程ID获取进程句柄
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}

float 读内存小数型(HANDLE 进程句柄, ULONG64 内存地址)
{
	float lpBuffer;
	ReadProcessMemory(进程句柄, (LPCVOID)内存地址, &lpBuffer, 4, 0);
	return lpBuffer;
}

UINT 读内存整数型(HANDLE 进程句柄, ULONG64 内存地址)
{
	UINT lpBuffer;
	ReadProcessMemory(进程句柄, (LPCVOID)内存地址, &lpBuffer, 4, 0);
	return lpBuffer;
}

ULONG64 读内存长整数型(HANDLE 进程句柄, ULONG64 内存地址)
{
	ULONG64 lpBuffer;
	ReadProcessMemory(进程句柄, (LPCVOID)内存地址, &lpBuffer, 8, 0);
	return lpBuffer;
}
vector<byte>  读内存字节集(HANDLE 进程句柄, ULONG64 内存地址, ULONG64 length)
{
	byte* lpBuffer;
	lpBuffer = new byte[length+1];
	memset(lpBuffer, 0, length);
	ReadProcessMemory(进程句柄, (LPCVOID)内存地址, lpBuffer, length, 0);
	vector<byte> result;
	result.resize(length);
	for (int i = 0; i < length; i++)
	{
		result[i] = lpBuffer[i];
	}
	return result;
}

void 写内存小数型(HANDLE 进程句柄,UINT64 内存地址, float 要写入的数据)
{
	WriteProcessMemory(进程句柄, (LPVOID)内存地址, &要写入的数据, 4, NULL);
}
void 写内存整数型(HANDLE 进程句柄, UINT64 内存地址, UINT 要写入的数据)
{
	WriteProcessMemory(进程句柄, (LPVOID)内存地址, &要写入的数据, 4, NULL);
}
void 写内存长整数型(HANDLE 进程句柄, UINT64 内存地址, ULONG64 要写入的数据)
{
	WriteProcessMemory(进程句柄, (LPVOID)内存地址, &要写入的数据, 8, NULL);
}
void 写内存字节集(HANDLE 进程句柄, UINT64 内存地址, vector<BYTE> 要写入的数据)
{
	WriteProcessMemory(进程句柄, (LPVOID)内存地址, 要写入的数据.data(),要写入的数据.size(), NULL);
}


/*
*延时间隔	1000微秒 = 1毫秒 ； 1000毫秒 = 1秒
延时单位	可空:毫秒  0 毫秒  1 微秒  2 秒  3 分  4 小时  5 天
*/
void 超级延时(ULONG64 延时间隔,ULONG64 延时单位) 
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
void 超级延迟(ULONG64 延时间隔)
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


