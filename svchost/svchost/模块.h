#pragma once
#include "pch.h"
#include "ȫ�ֱ���.h"


using namespace std;

void �����¼�();

DWORD ȡ����ID(const char* pName);//ͨ����������ȡ����ID

HANDLE �򿪽���(DWORD nID);//ͨ������ID��ȡ����ID

float ���ڴ�С����(DWORD ����ID, INT64 �ڴ��ַ);

INT16 ���ڴ��������(DWORD ����ID, INT64 �ڴ��ַ);

INT32 ���ڴ�������(DWORD ����ID, INT64 �ڴ��ַ);

INT64 ���ڴ泤������(DWORD ����ID, INT64 �ڴ��ַ);

INT64 ȡƫ�Ƶ�ַ( INT64 ��ַ, vector<int> ƫ�Ƶ�ַ);

vector<byte>  ���ڴ��ֽڼ�(DWORD ����ID, INT64 �ڴ��ַ, INT64 length);

void д�ڴ�С����(DWORD ����ID, INT64 �ڴ��ַ, float Ҫд�������);

void д�ڴ��������(DWORD ����ID, INT64 �ڴ��ַ, INT16 Ҫд�������);

void д�ڴ�������(DWORD ����ID, INT64 �ڴ��ַ, INT32 Ҫд�������);

void д�ڴ泤������(DWORD ����ID, INT64 �ڴ��ַ, INT64 Ҫд�������);

void д�ڴ��ֽڼ�(DWORD ����ID, INT64 �ڴ��ַ, vector<BYTE> Ҫд�������);


/*
*��ʱ���	1000΢�� = 1���� �� 1000���� = 1��
��ʱ��λ	�ɿ�:����  0 ����  1 ΢��  2 ��  3 ��  4 Сʱ  5 ��
*/
void �����ӳ�(INT64 ��ʱ���, INT64 ��ʱ��λ );

/*
*��ʱ���	1���� �� 1000���� = 1��
*/
void ������ʱ(INT64 ��ʱ���);

CString ת��UnicodeתAnsi(vector<BYTE> ��_�ֽڼ�);

WCHAR* ת��AnsiתUnicode(CHAR* str);

vector<byte> AnsiתUnicode(CString str);

vector<byte> �������ֽڼ�(INT64   i);

CString ���ı�(LONG64 a);

CString ʮ��ʮ��(LONG64 a);

BOOL �ü������ı�(CString �ı�);

wstring stringתwstring(string str);

string wstringתstring(wstring wstr);

void ���̽���(DWORD ����PID);

void ��������Ȩ��();

LPVOID �����ڴ�x64(int DwSize);

bool �ͷ��ڴ�(LPVOID �ͷŵ�ַ);

vector<byte>�ڴ����(INT64 ����С);

vector<byte>HOOK_JMP(INT64 Hook��ַ, INT64 ��ת��ַ, vector<byte>	�����ֽڼ�);

void д���ļ�(LPCTSTR �ļ�·��, int ��ԴID,const char* ��Դ����);

void ������дȨ��();

void ָ�������̻��systemȨ��(DWORD ����1, CString ����2);

bool �ļ��Ƿ����(const char* name);

//byte intToByte(int i);

DWORD �����Ƿ����(LPCTSTR name);

void ��ֹ����(CString ������);

CString Ѱ��һ���ļ�(CString �ļ���);

CString ȡ����Ŀ¼(int Ŀ¼ID);

INT64 ȡ����ʱ��();

void ǿ��ɾ���ļ�(CString �ļ���);

CString ȡִ���ļ���();

void ����(CString strCmd);






