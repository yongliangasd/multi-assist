#include "windows.h"



#pragma once

void �����¼�()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		DispatchMessage(&msg);
		TranslateMessage(&msg);	
	}
}

DWORD ȡ����ID(const char* pName)//ͨ����������ȡ����ID
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

HANDLE �򿪽���(DWORD nID)//ͨ������ID��ȡ���̾��
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}

float ���ڴ�С����(HANDLE ���̾��, ULONG64 �ڴ��ַ)
{
	float lpBuffer;
	ReadProcessMemory(���̾��, (LPCVOID)�ڴ��ַ, &lpBuffer, 4, 0);
	return lpBuffer;
}

UINT ���ڴ�������(HANDLE ���̾��, ULONG64 �ڴ��ַ)
{
	UINT lpBuffer;
	ReadProcessMemory(���̾��, (LPCVOID)�ڴ��ַ, &lpBuffer, 4, 0);
	return lpBuffer;
}

ULONG64 ���ڴ泤������(HANDLE ���̾��, ULONG64 �ڴ��ַ)
{
	ULONG64 lpBuffer;
	ReadProcessMemory(���̾��, (LPCVOID)�ڴ��ַ, &lpBuffer, 8, 0);
	return lpBuffer;
}
vector<byte>  ���ڴ��ֽڼ�(HANDLE ���̾��, ULONG64 �ڴ��ַ, ULONG64 length)
{
	byte* lpBuffer;
	lpBuffer = new byte[length+1];
	memset(lpBuffer, 0, length);
	ReadProcessMemory(���̾��, (LPCVOID)�ڴ��ַ, lpBuffer, length, 0);
	vector<byte> result;
	result.resize(length);
	for (int i = 0; i < length; i++)
	{
		result[i] = lpBuffer[i];
	}
	return result;
}

void д�ڴ�С����(HANDLE ���̾��,UINT64 �ڴ��ַ, float Ҫд�������)
{
	WriteProcessMemory(���̾��, (LPVOID)�ڴ��ַ, &Ҫд�������, 4, NULL);
}
void д�ڴ�������(HANDLE ���̾��, UINT64 �ڴ��ַ, UINT Ҫд�������)
{
	WriteProcessMemory(���̾��, (LPVOID)�ڴ��ַ, &Ҫд�������, 4, NULL);
}
void д�ڴ泤������(HANDLE ���̾��, UINT64 �ڴ��ַ, ULONG64 Ҫд�������)
{
	WriteProcessMemory(���̾��, (LPVOID)�ڴ��ַ, &Ҫд�������, 8, NULL);
}
void д�ڴ��ֽڼ�(HANDLE ���̾��, UINT64 �ڴ��ַ, vector<BYTE> Ҫд�������)
{
	WriteProcessMemory(���̾��, (LPVOID)�ڴ��ַ, Ҫд�������.data(),Ҫд�������.size(), NULL);
}


/*
*��ʱ���	1000΢�� = 1���� �� 1000���� = 1��
��ʱ��λ	�ɿ�:����  0 ����  1 ΢��  2 ��  3 ��  4 Сʱ  5 ��
*/
void ������ʱ(ULONG64 ��ʱ���,ULONG64 ��ʱ��λ) 
{
	HANDLE �ֲ�����1;
	_LARGE_INTEGER �ֲ�����2;

	//if (��ʱ��� < 1) 
	//{
	//	return;
	//}

	switch (��ʱ��λ)
	{
	case 1:
		�ֲ�����2.QuadPart = -10 * ��ʱ���;
		�ֲ�����1 = CreateWaitableTimerA(NULL, FALSE, NULL);
		if (�ֲ�����1 != 0) 
		{
			SetWaitableTimer(�ֲ�����1, &�ֲ�����2, 0, NULL, NULL, FALSE);
			while (MsgWaitForMultipleObjects(1, &�ֲ�����1, FALSE, INFINITE, QS_ALLINPUT) != 0)
			{
				�����¼�();
			}
			CloseHandle(�ֲ�����1);
		}
		return;
		break;
	case 0:
		��ʱ��λ = 1;
		break;
	case 2:
		��ʱ��λ = 1000;
		break;
	case 3:
		��ʱ��λ = 1000 * 60;
		break;
	case 4:
		��ʱ��λ = 1000 * 60 * 60;
		break;
	case 5:
		��ʱ��λ = 1000 * 60 * 60 * 24;
		break;
	}
	�ֲ�����2.QuadPart = -10 * ��ʱ��� * 1000 * ��ʱ��λ;
	�ֲ�����1 = CreateWaitableTimerA(NULL, FALSE, NULL);
	if (�ֲ�����1 != 0) 
	{
		SetWaitableTimer(�ֲ�����1, &�ֲ�����2, 0, NULL, NULL, FALSE);
		while (MsgWaitForMultipleObjects(1, &�ֲ�����1, FALSE, INFINITE, QS_ALLINPUT) != 0)
		{
			�����¼�();
		}
		CloseHandle(�ֲ�����1);
	}
	return;
}
/*
*��ʱ���	1000΢�� = 1���� �� 1000���� = 1��
��ʱ��λ	�ɿ�:����  0 ����  1 ΢��  2 ��  3 ��  4 Сʱ  5 ��
*/
void �����ӳ�(ULONG64 ��ʱ���)
{
	HANDLE �ֲ�����1;
	_LARGE_INTEGER �ֲ�����2;
	�ֲ�����2.QuadPart = -10 * ��ʱ��� * 1000;
	�ֲ�����1 = CreateWaitableTimerA(NULL, FALSE, NULL);
	if (�ֲ�����1 != 0)
	{
		SetWaitableTimer(�ֲ�����1, &�ֲ�����2, 0, NULL, NULL, FALSE);
		while (MsgWaitForMultipleObjects(1, &�ֲ�����1, FALSE, INFINITE, QS_ALLINPUT) != 0)
		{
			�����¼�();
		}
		CloseHandle(�ֲ�����1);
	}
	return;
}


