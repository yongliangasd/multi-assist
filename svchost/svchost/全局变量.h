#pragma once

#include "pch.h"
#include "framework.h"
#include "svchost.h"
#include "svchostDlg.h"
#include "afxdialogex.h"
#include "windows.h"

extern	DWORD 进程ID;
extern	HWND 自窗口句柄;

extern	int 全屏代码;
extern	int 全屏伤害;
extern	int 全局_装备部位;
extern	int 选中职业;
extern	int 选中武器;
extern	INT64 武器代码;

extern INT64 空白全局;

extern	int 初始宽度;
extern	CRect rectDlg;
extern	CRect rs;

extern vector <byte> 组包数据;
extern vector<byte> 装备数据;


extern	CDia1 m_Dia1;
extern	CDia2 m_Dia2;
extern	CDia3 m_Dia3;
extern	CDia4 m_Dia4;
extern	CDialog* pDialog[4];
extern	int m_CurSelTab;

extern	HTREEITEM hRoot;      // 树的根节点的句柄
extern	HTREEITEM hRoot1;      // 树的根节点的句柄   
extern	HTREEITEM hTreeIndex; //设置树的索引 
extern	HTREEITEM hArtItem;  // 可表示任一文章节点的句柄   






struct 坐标型 {
	int x;
	int y;
	int z;
};

struct 开关结构{
	bool 自动刷图开关;
	bool 技能全屏开关;
};


