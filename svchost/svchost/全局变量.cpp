#include "pch.h"
#include "framework.h"
#include "svchost.h"
#include "svchostDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include "ȫ�ֱ���.h"
#include "��ַ.h"

DWORD ����ID;
HWND �Դ��ھ��;

int ȫ������;
int ȫ���˺�;
int ȫ��_װ����λ;
int ѡ��ְҵ;
int ѡ������;
INT64 ��������;

INT64 �հ�ȫ��;



int ��ʼ���;
CRect rectDlg;
CRect rs;

vector <byte> �������;
vector<byte> װ������;

CDia1 m_Dia1;
CDia2 m_Dia2;
CDia3 m_Dia3;
CDia4 m_Dia4;
CDialog* pDialog[4];
int m_CurSelTab;

HTREEITEM hRoot;      // ���ĸ��ڵ�ľ��
HTREEITEM hRoot1;      // ���ĸ��ڵ�ľ��   
HTREEITEM hTreeIndex; //������������ 
HTREEITEM hArtItem;  // �ɱ�ʾ��һ���½ڵ�ľ��   


