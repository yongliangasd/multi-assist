#pragma once

#include "pch.h"
#include "framework.h"
#include "svchost.h"
#include "svchostDlg.h"
#include "afxdialogex.h"
#include "windows.h"

extern	DWORD ����ID;
extern	HWND �Դ��ھ��;

extern	int ȫ������;
extern	int ȫ���˺�;
extern	int ȫ��_װ����λ;
extern	int ѡ��ְҵ;
extern	int ѡ������;
extern	INT64 ��������;

extern INT64 �հ�ȫ��;

extern	int ��ʼ���;
extern	CRect rectDlg;
extern	CRect rs;

extern vector <byte> �������;
extern vector<byte> װ������;


extern	CDia1 m_Dia1;
extern	CDia2 m_Dia2;
extern	CDia3 m_Dia3;
extern	CDia4 m_Dia4;
extern	CDialog* pDialog[4];
extern	int m_CurSelTab;

extern	HTREEITEM hRoot;      // ���ĸ��ڵ�ľ��
extern	HTREEITEM hRoot1;      // ���ĸ��ڵ�ľ��   
extern	HTREEITEM hTreeIndex; //������������ 
extern	HTREEITEM hArtItem;  // �ɱ�ʾ��һ���½ڵ�ľ��   






struct ������ {
	int x;
	int y;
	int z;
};

struct ���ؽṹ{
	bool �Զ�ˢͼ����;
	bool ����ȫ������;
};


