#include "pch.h"
#include "framework.h"
#include "svchost.h"
#include "svchostDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include "全局变量.h"
#include "基址.h"

DWORD 进程ID;
HWND 自窗口句柄;

int 全屏代码;
int 全屏伤害;
int 全局_装备部位;
int 选中职业;
int 选中武器;
INT64 武器代码;

INT64 空白全局;



int 初始宽度;
CRect rectDlg;
CRect rs;

vector <byte> 组包数据;
vector<byte> 装备数据;

CDia1 m_Dia1;
CDia2 m_Dia2;
CDia3 m_Dia3;
CDia4 m_Dia4;
CDialog* pDialog[4];
int m_CurSelTab;

HTREEITEM hRoot;      // 树的根节点的句柄
HTREEITEM hRoot1;      // 树的根节点的句柄   
HTREEITEM hTreeIndex; //设置树的索引 
HTREEITEM hArtItem;  // 可表示任一文章节点的句柄   


