#pragma once
#include "pch.h"
#include "ģ��.h"
#include <process.h>
#include <iostream>
#include "string.h"
#include <Mmsystem.h>



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

HANDLE �򿪽���(DWORD nID)//ͨ������ID��ȡ�ֲ�����1
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}

float ���ڴ�С����(DWORD ����ID, INT64 �ڴ��ַ)
{
	float lpBuffer;
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, PAGE_EXECUTE_READWRITE, &��������);

	if (ReadProcessMemory(�ֲ�����1, (LPCVOID)�ڴ��ַ, &lpBuffer, 4, 0) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
	return lpBuffer;
}

INT16 ���ڴ��������(DWORD ����ID, INT64 �ڴ��ַ)
{
	INT16 lpBuffer;
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 2, PAGE_EXECUTE_READWRITE, &��������);

	if (ReadProcessMemory(�ֲ�����1, (LPCVOID)�ڴ��ַ, &lpBuffer, 2, 0) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 2, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
	return lpBuffer;
}

INT32 ���ڴ�������(DWORD ����ID, INT64 �ڴ��ַ)
{
	INT32 lpBuffer;
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, PAGE_EXECUTE_READWRITE, &��������);

	if (ReadProcessMemory(�ֲ�����1, (LPCVOID)�ڴ��ַ, &lpBuffer, 4, 0) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
	return lpBuffer;
}

INT64 ���ڴ泤������(DWORD ����ID, INT64 �ڴ��ַ)
{
	INT64 lpBuffer;
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 8, PAGE_EXECUTE_READWRITE, &��������);

	if (ReadProcessMemory(�ֲ�����1, (LPCVOID)�ڴ��ַ, &lpBuffer, 8, 0) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 8, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
	return lpBuffer;
}
vector<byte>  ���ڴ��ֽڼ�(DWORD ����ID, INT64 �ڴ��ַ, INT64 length)
{
	byte* lpBuffer;
	lpBuffer = new byte[length + 1];
	memset(lpBuffer, 0, length);
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), length, PAGE_EXECUTE_READWRITE, &��������);

	if (ReadProcessMemory(�ֲ�����1, (LPCVOID)�ڴ��ַ, lpBuffer, length, 0) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), length, ��������, &��������);
	
	}	
	vector<byte> result;
	result.resize(length);
	for (int i = 0; i < length; i++)
	{
		result[i] = lpBuffer[i];
	}
	CloseHandle(�ֲ�����1);
	return result;
}

INT64 ȡƫ�Ƶ�ַ(INT64 ��ַ, vector<int> ƫ�Ƶ�ַ)
{
	INT64 ��ַ;
	��ַ = ��ַ;
	for (size_t i = 0; i < ƫ�Ƶ�ַ.size(); ++i)
	{
		��ַ = ���ڴ泤������(����ID, ��ַ);
		��ַ = ��ַ + ƫ�Ƶ�ַ.at(i);
	}
	return ��ַ;
}


void д�ڴ�С����(DWORD ����ID, INT64 �ڴ��ַ, float Ҫд�������)
{
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, PAGE_EXECUTE_READWRITE, &��������);

	if (WriteProcessMemory(�ֲ�����1, (LPVOID)�ڴ��ַ, &Ҫд�������, 4, NULL)==true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
}
void д�ڴ��������(DWORD ����ID, INT64 �ڴ��ַ, INT16 Ҫд�������)
{
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 2, PAGE_EXECUTE_READWRITE, &��������);

	if (WriteProcessMemory(�ֲ�����1, (LPVOID)�ڴ��ַ, &Ҫд�������, 2, NULL) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 2, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
}
void д�ڴ�������(DWORD ����ID, INT64 �ڴ��ַ, INT32 Ҫд�������)
{
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, PAGE_EXECUTE_READWRITE, &��������);

	if (WriteProcessMemory(�ֲ�����1, (LPVOID)�ڴ��ַ, &Ҫд�������, 4, NULL) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 4, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
}
void д�ڴ泤������(DWORD ����ID, INT64 �ڴ��ַ, INT64 Ҫд�������)
{
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 8, PAGE_EXECUTE_READWRITE, &��������);

	if (WriteProcessMemory(�ֲ�����1, (LPVOID)�ڴ��ַ, &Ҫд�������, 8, NULL) == true)
	{
	
		VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), 8, ��������, &��������);
	
	}
	CloseHandle(�ֲ�����1);
}
void д�ڴ��ֽڼ�(DWORD ����ID, INT64 �ڴ��ַ, vector<BYTE> Ҫд�������)
{
	DWORD ��������;
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), Ҫд�������.size(), PAGE_EXECUTE_READWRITE, &��������);

	int length;
	length = (int)Ҫд�������.size();
	for (int i = 0; i < length; i++)
	{	
		WriteProcessMemory(�ֲ�����1, (LPVOID)�ڴ��ַ, &Ҫд�������[i],1, NULL);
		�ڴ��ַ++;
	}

	VirtualProtectEx(�ֲ�����1, reinterpret_cast<LPVOID>(�ڴ��ַ), Ҫд�������.size(), ��������, &��������);

	CloseHandle(�ֲ�����1);
}





/*
*��ʱ���	1000΢�� = 1���� �� 1000���� = 1��
��ʱ��λ	�ɿ�:����  0 ����  1 ΢��  2 ��  3 ��  4 Сʱ  5 ��
*/
void �����ӳ�(INT64 ��ʱ���, INT64 ��ʱ��λ)
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
void ������ʱ(INT64 ��ʱ���)
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


WCHAR* ת��AnsiתUnicode(CHAR* str)
{
	DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	 wchar_t* pwText;	 
	pwText = new wchar_t[dwNum];
	if (!pwText) delete[]pwText;
	MultiByteToWideChar(CP_ACP, 0, str, -1, pwText, dwNum);
	return pwText;
}

vector<byte> AnsiתUnicode(CString str)
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

CString ת��UnicodeתAnsi(vector<BYTE> ��_�ֽڼ�)
{
	size_t ��_�ֽڳ��� = ��_�ֽڼ�.size();
	 CHAR* ��_Unicode;
	��_Unicode = new CHAR[��_�ֽڳ���]; 
	for (size_t i = 0; i < ��_�ֽڳ���; i++)
	{
		��_Unicode[i] = ��_�ֽڼ�[i];
	}
	//UniCode��Ansi
	DWORD ��_���� = WideCharToMultiByte(936, 512, (LPCWCH)��_Unicode, -1, 0, 0, 0, FALSE);
	 CHAR* ������;
	������ = new CHAR[��_����];	
	WideCharToMultiByte(936, 512, (LPCWCH)��_Unicode, -1, ������, ��_����, NULL, NULL);
	// stringתwstring
	DWORD nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ������, -1, NULL, 0);
	 WCHAR* pResult;
	pResult = new WCHAR[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ������, -1, pResult, nLen);
	wstring wresult = pResult;
	CString cs(wresult.c_str());
	return cs;
}


vector<byte> �������ֽڼ�(INT64   i) {
	INT64   adr = (INT64)&i;
	vector<byte>c;
	for (size_t i = 0; i < 8; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

CString ���ı�(LONG64 a)
{
	
	wstring result;
	WCHAR str[20];
	_i64tow_s(a, str, 20, 10);
	result = str;
	CString cstr(result.c_str());
	return cstr;
}


CString ʮ��ʮ��(LONG64 a)
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



BOOL �ü������ı�(CString �ı�)
{
	HGLOBAL �ֲ�����1=0;
	HANDLE �ֲ�����2=0;
	OpenClipboard(0);
	EmptyClipboard();

	�ֲ�����1=GlobalAlloc(66, (�ı�.GetLength() + (long long)(long)1));
	if (�ֲ�����1 != 0)
	{
		memmove(GlobalLock(�ֲ�����1), �ı�, �ı�.GetLength());
		GlobalUnlock(�ֲ�����1);
		�ֲ�����2 = SetClipboardData(1, �ֲ�����1);
		GlobalFree(�ֲ�����1);
	}
	CloseClipboard();
	return (�ֲ�����2 != 0);
}
//
//string �ֽڼ���ʮ������(const BYTE* bytes, const int length)
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
///*��ԭʮ�������ַ�����ʽ�ֽڼ����ı����ֽڼ�*/
//void ��ԭ�ֽڼ�2(const string& hex, BYTE* bytes)
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
//void ɾȫ����(string& s)
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
//void ɾ��β��(string& s)
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
//int Ѱ���ֽڼ�(byte* ����Ѱ���ֽڼ�, int ����Ѱ����, byte* ���������ֽڼ�, int Ҫ�����ĳ���, int ��ʼ��Ѱλ��)
//{//int SearchByteShuZu(byte * bForSearch,int ifLen, byte* bWaitSearch, int iwLen,int iFirstSearchPos);//Ѱ���ֽڼ�����(��Ѱ�ҵ�,��Ѱ�ҵ���󳤶�,ҪѰ�ҵ�,ҪѰ�ҵĳ���,��ʼѰ��λ��)  ����-1 Ϊδ�ҵ� λ�ô�0��ʼ
//	int iCurrentPos = 0;//������λ��
//	if (��ʼ��Ѱλ�� > ����Ѱ����)//�����������ĳ���
//	{
//		return -1;
//	}
//	if (Ҫ�����ĳ��� > ����Ѱ����)//Ҫ�����ĳ��ȱ� �������ĳ��ȴ� ����
//	{
//		return -1;
//	}
//	if (Ҫ�����ĳ��� == 0 || ����Ѱ���� == 0)
//	{
//		return -1;//0 ����
//	}
//	//    bForSearch+=iFirstSearchPos;//������ʼ����λ��
//	iCurrentPos += ��ʼ��Ѱλ��;//������ʼ����λ��
//	����Ѱ���ֽڼ� += iCurrentPos;//����ָ�� ��Ӧ
//	while (1)
//	{
//		while (*����Ѱ���ֽڼ� != *���������ֽڼ�)//�ҵ���һ����ͬ��
//		{
//			iCurrentPos += 1;//��ǰ����λ��ǰ��1
//			����Ѱ���ֽڼ� += 1;//��ǰָ��ǰ��1
//			if (iCurrentPos > ����Ѱ����)    //���ȳ��������������峤�ȷ���
//			{
//				return -1;
//			}
//		}
//		for (int i = 0; i < Ҫ�����ĳ���; ++i)//��ʼ�Ա�
//		{
//			if (*(����Ѱ���ֽڼ� + i) != *(���������ֽڼ� + i))
//			{
//				iCurrentPos += 1;//��ǰ����λ��ǰ��1
//				����Ѱ���ֽڼ� += 1;//��ǰָ��ǰ��1
//				//������ָ��ǰ��1
//				break;//�ҵ�һ����ͬ�� ����
//			}
//			if (i + 1 == Ҫ�����ĳ���)
//			{
//				return iCurrentPos;//�ҵ���
//			}
//		}
//	}
//}
//
//template<class T>
//int ȡ�ֽڼ�����(T& array)
//{
//	return sizeof(array) / sizeof(array[0]);
//}


wstring stringתwstring(string str)
{
	wstring result;
	//��ȡ��������С��������ռ䣬��������С���ַ�����  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	wchar_t* buffer = new wchar_t[len + 1];
	//���ֽڱ���ת���ɿ��ֽڱ���  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //����ַ�����β  
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}

string wstringתstring(wstring wstr)
{
	string result;
	//��ȡ��������С��������ռ䣬��������С�°��ֽڼ����  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//���ֽڱ���ת���ɶ��ֽڱ���  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}

//
//void HOOK����() 
//{
//	GetProcAddress(, "timeGetTime")
//	GetModuleHandleA
//
//
//
//
//}


void ���̽���(DWORD ����PID) 
{
	HANDLE �ֲ�����1;
	
	if (����PID==0)
	{
		�ֲ�����1 = GetCurrentProcess();
	}
	else
	{
		�ֲ�����1 = OpenProcess(1, 0, ����ID);
	}

	TerminateProcess(�ֲ�����1, 0);
	CloseHandle(�ֲ�����1);
	//char s[10];
	//_countof( s);
}


void ��������Ȩ��() 
{

	HANDLE �ֲ�����1;
	HANDLE �ֲ�����2;
	TOKEN_PRIVILEGES tp;
	
	�ֲ�����1 = GetCurrentProcess();
	OpenProcessToken(�ֲ�����1, TOKEN_ALL_ACCESS, &�ֲ�����2);
	LookupPrivilegeValueA(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(�ֲ�����2, FALSE, &tp, sizeof(tp), NULL, NULL);
	CloseHandle(�ֲ�����2);
}


LPVOID �����ڴ�x64(int DwSize)
{
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	LPVOID Address = 0;
	if (DwSize == 0)
		DwSize = 1;
	Address = VirtualAllocEx(�ֲ�����1, 0, DwSize, 4096, 64);
	CloseHandle(�ֲ�����1);
	if (Address > 0)
		return Address;
	return 0;
}

bool �ͷ��ڴ�(LPVOID �ͷŵ�ַ)
{
	HANDLE �ֲ�����1;
	�ֲ�����1 = OpenProcess(2035711, 0, ����ID);
	if (!VirtualFreeEx(�ֲ�����1, �ͷŵ�ַ, 0, MEM_RELEASE)) 
	{
		return false;
		CloseHandle(�ֲ�����1);
	}
	else 
	{
		return true;
	}		
}

vector<byte>�ڴ����(INT64 ����С)
{
	vector<byte>���;

	for (INT64 i = 0; i < ����С; i++)
	{
		���.push_back(0);
	}
	return ���;
}

vector<byte>HOOK_JMP(INT64 Hook��ַ,INT64 ��ת��ַ,vector<byte>	�����ֽڼ�)
{
	vector<byte> �ֲ�1, �ֲ�2;
	�ֲ�1 = { 233 };
	�ֲ�2 = �������ֽڼ�(��ת��ַ - Hook��ַ - 5);
	�ֲ�1.insert(�ֲ�1.end(), �ֲ�2.begin(), �ֲ�2.end());
	if (sizeof(�����ֽڼ�) != 0)
	{
		�ֲ�1.insert(�ֲ�1.end(), �����ֽڼ�.begin(), �����ֽڼ�.end());
	}
	return �ֲ�1;
}

void д���ļ�(LPCTSTR �ļ�·��, int ��ԴID,const char* ��Դ���� )
{
	HRSRC   hResource = FindResource(GetModuleHandle(NULL), MAKEINTRESOURCE(��ԴID), TEXT(��Դ����));
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
				if (calcFile.Open(�ļ�·��, CFile::modeCreate | CFile::modeReadWrite))
				{
					calcFile.Write(pData, dwSize);
					calcFile.Close();
				}
			}
		}
	}
}

 bool �ļ��Ƿ����(const char* name)
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
 

DWORD �����Ƿ����(LPCTSTR name)
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

void ������дȨ��() 
{
	WCHAR ������Ϣ[_MAX_PATH];
	GetModuleFileNameW(NULL, ������Ϣ, _MAX_PATH);
	CString st1 = "C:\\Windows\\SysWOW64\\PsExec64.exe -i -d -s ";
	string st2 = wstringתstring(������Ϣ);
	st1 += st2.c_str();
	if (!�ļ��Ƿ����("C:\\Windows\\SysWOW64\\PsExec64.exe"))
	{
		д���ļ�("C:\\Windows\\SysWOW64\\PsExec64.exe", IDR_PSEXEC1,"Psexec");
		����("C:\\Windows\\SysWOW64\\PsExec64.exe /accepteula");
	}
	if (�����Ƿ����("cmd.exe")==0)
	{
		WinExec("cmd.exe",0);
		//MessageBoxA(�Դ��ھ��, st1, "��ʾ", 0);
		//MessageBoxA(�Դ��ھ��, "���̲�����", "��ʾ", 0);
		//WinExec(st1,1);
		//������ʱ(2000);
		if (WinExec(st1,0) <31)
		{
			ָ�������̻��systemȨ��(ȡ����ID("winlogon.exe"), st2.c_str());			
		}
		exit(0);
	}
	����("taskkill /f /T /im cmd.exe");
}

void ָ�������̻��systemȨ��(DWORD ����1,CString ����2)
{
	HMODULE hDll = ::LoadLibraryA("ntdll.dll");
	typedef int (*type_RtlAdjustPrivilege)(int, bool, bool, int*);
	type_RtlAdjustPrivilege RtlAdjustPrivilege = (type_RtlAdjustPrivilege)GetProcAddress(hDll, "RtlAdjustPrivilege");
	RtlAdjustPrivilege(20, 1, 0, 0);
	LPSTARTUPINFOA �ֲ�1 ;
	LPCSTR �ֲ�2="", �ֲ�3="";
	LPPROCESS_INFORMATION �ֲ�4;
	ZeroMemory(&�ֲ�1, sizeof(�ֲ�1));
	ZeroMemory(&�ֲ�4, sizeof(�ֲ�4));
	HANDLE �ֲ�8 = OpenProcess(2035711, 0, ����1);
	SIZE_T �ֲ�5=0;	
	InitializeProcThreadAttributeList(NULL, 1, 0, &�ֲ�5);
	char* temp;
	temp = new char[�ֲ�5];
	LPPROC_THREAD_ATTRIBUTE_LIST �ֲ�6 = (LPPROC_THREAD_ATTRIBUTE_LIST)temp;
	LPPROC_THREAD_ATTRIBUTE_LIST �ֲ�7 = (LPPROC_THREAD_ATTRIBUTE_LIST)temp;
	InitializeProcThreadAttributeList(�ֲ�6,1,0,&�ֲ�5);
	HeapAlloc(GetProcessHeap(), 0, �ֲ�5);
	memmove(�ֲ�7,�ֲ�6,�ֲ�5);
	UpdateProcThreadAttribute(�ֲ�7, 0, 131072, �ֲ�8, 4, 0, 0);	
	�ֲ�1->cb = 68;
	�ֲ�1->dwFlags = 0;
	�ֲ�1->wShowWindow = 1;
	CreateProcessAsUserA(0,�ֲ�2, (LPSTR)(LPCSTR)����2, 0, 0, 0, 524288, 0, �ֲ�3, �ֲ�1, �ֲ�4);	
	DeleteProcThreadAttributeList(�ֲ�7);
	HeapFree(GetProcessHeap(), 0, �ֲ�7);
}

void ��ֹ����(CString ������) 
{
	CString ����, ����1, stid;
	int PID=ȡ����ID(������);
	stid.Format("%d", PID);
	 ����= "taskkill /F /T /PID ";
	 ����1 = ���� + stid;
	//system(����1);
	����(����1);
}

CString Ѱ��һ���ļ�(CString �ļ���)
{
	WIN32_FIND_DATA fileinfo;
	DWORD errorcode = 0;
	HANDLE hFile;
	hFile = FindFirstFileA(�ļ���, &fileinfo);
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

void ����(CString strCmd)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	//���ص����ܳ��ֵ�cmd�����
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













/*0�ҵ����� 1��ʱĿ¼ 2�ҵĳ��� 5�ҵ��ĵ� 6�ҵ��ղؼ� 7�ҵ����� 8��������ĵ� 9�ҵķ��͵� 11�ҵĿ�ʼ�˵� 13�ҵ����� 14�ҵ���Ƶ 16�ҵ����� 20ϵͳ���� 22��ʼ�˵��� 23������ 24������ 25���� 31�ղؼ� 32�ҵ��������ʱĿ¼ 33�ҵ�Cookies 34�ҵ���ʷ��¼ 36Windows��װĿ¼ 37ϵͳĿ¼ 38�ļ���װĿ¼ 39�ҵ�ͼƬ 40�û�Ŀ¼ 41ϵͳĿ¼ 46�ĵ� 47������ 48�ҵĹ����� 53���� 54ͼƬ 55��Ƶ
*/
CString ȡ����Ŀ¼(int Ŀ¼ID)
{
	CString ·��1;	
	if (Ŀ¼ID == 1) 
	{
		GetTempPathA(260, (LPSTR)(LPCTSTR)·��1);
		//MessageBoxA(�Դ��ھ��, ·��1, "DNF", 0);
	}
	else
	{
		SHGetSpecialFolderPathA(NULL, (LPSTR)(LPCTSTR)·��1, Ŀ¼ID, FALSE);
	}
	return ·��1;
}



INT64 ȡ����ʱ��() 
{
	INT64 t = GetTickCount64();
	//str1.Format("ϵͳ������ %dʱ", t / 3600000);
	//str = str1;
	//t %= 3600000;
	//str1.Format("%d��", t / 60000);
	//str += str1;
	//t %= 60000;
	//str1.Format("%d��", t / 1000);
	//str += str1;
	//AfxMessageBox(str);
	return t;
}

void ǿ��ɾ���ļ�(CString �ļ���) 
{
	CString ��ȫĿ¼;
	SECURITY_ATTRIBUTES ��ȫ�Խṹ;
	ZeroMemory(&��ȫ�Խṹ, sizeof(��ȫ�Խṹ));
	��ȫĿ¼ = ȡ����Ŀ¼(1) + ���ı�(ȡ����ʱ��());
	CreateDirectoryA(��ȫĿ¼, &��ȫ�Խṹ);
	CreateDirectoryA(��ȫĿ¼+"\\....\\", &��ȫ�Խṹ);
	//MessageBoxA(�Դ��ھ��, ��ȫĿ¼, "DNF", 0);
	MoveFileA(�ļ���, ��ȫĿ¼ + "\\....\\TemporaryFile");
	MoveFileA(��ȫĿ¼ + "\\....\\", ��ȫĿ¼ + "\\TemporaryFile");
	remove(��ȫĿ¼);	
}


CString ȡִ���ļ���() 
{	
	WCHAR ������Ϣ[_MAX_PATH];
	GetModuleFileNameW(NULL, ������Ϣ, _MAX_PATH);
	string st1 = wstringתstring(������Ϣ);
	return st1.c_str();
}

int �����ȼ�(LPTHREAD_START_ROUTINE ��Ӧ�¼�,int ������=0,int ���ܼ�����=0,int ������=0,int ����=10,bool ֱ�Ӵ���=FALSE )
{



	//setTimer()		
}