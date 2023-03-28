// CDia3.cpp: 实现文件
//

#include "pch.h"
#include "svchost.h"
#include "CDia3.h"
#include "afxdialogex.h"
#include "基址.h"
#include "模块.h"
#include "各种CALL.h"
#include "全局变量.h"

// CDia3 对话框

IMPLEMENT_DYNAMIC(CDia3, CDialog)

CDia3::CDia3(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
{

}

CDia3::~CDia3()
{
}

void CDia3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDia3, CDialog)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CDia3::OnNMRClickList1)
	ON_COMMAND(ID_32771, &CDia3::On32771)
	ON_BN_CLICKED(DANCI, &CDia3::OnBnClickedDanci)
END_MESSAGE_MAP()


// CDia3 消息处理程序


BOOL CDia3::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}


void CDia3::OnNMRClickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//m_menu.LoadMenuA(IDR_MENU1)
	CMenu menuMain, menu1;
	menuMain.CreatePopupMenu();
	menu1.CreatePopupMenu();
	menu1.AppendMenu(MF_STRING, IDR_MENU1, _T("复制代码"));
	//menu1.InsertMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING, (INT32)menuMain.m_hMenu, _T("子菜单")); //添加子菜单
	
	CPoint pt;
	GetCursorPos(&pt);
	menu1.TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
	menu1.DestroyMenu();


	*pResult = 0;
}


void CDia3::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CString str;
	int nIdx;
	POSITION pos = m_list.GetFirstSelectedItemPosition(); //pos选中的首行位置
	nIdx = m_list.GetNextSelectedItem(pos);
	if (nIdx >= 0 && nIdx < m_list.GetItemCount())
	{
		str = m_list.GetItemText(nIdx, 6);//获取指定列，为字符串形式
	}
	置剪辑板文本(str);
}

void CDia3::OnBnClickedDanci()
{
	// TODO: 在此添加控件通知处理程序代码
	INT64 一级偏移, 二级偏移, 局_首地址, 局_尾地址, 对象指针, 代码, 对象数量;
	INT32  i, 类型, 阵营, X, Y, Z, 索引;
	坐标型 人物坐标;
	CString 名称;
	m_list.DeleteAllItems();
	一级偏移 = 读内存长整数型(进程ID, 人物基址);
	二级偏移 = 读内存长整数型(进程ID, 一级偏移 + 地图偏移);
	局_首地址 = 读内存长整数型(进程ID, 二级偏移 + 首地址);
	局_尾地址 = 读内存长整数型(进程ID, 二级偏移 + 尾地址);
	对象数量 = (尾地址 - 首地址) / 8;
	SetDlgItemTextA(SHULIANG, 到文本(对象数量));
	for ( i = 0; i < 对象数量; i++)
	{
		对象指针 = 读内存长整数型(进程ID, 首地址 + i * (INT64)8);
		类型 = 读内存整数型(进程ID, 对象指针 + 类型偏移);
		阵营 = 读内存整数型(进程ID, 对象指针 + 阵营偏移);
		if (类型==273)
		{
			人物坐标 = 读坐标(对象指针);
			X = 人物坐标.x;
			Y = 人物坐标.y;
			Z = 人物坐标.z;
			代码 = 0;
			//代码 = 解密(人偶目录);
		}
		else
		{
			X = (INT32)读内存小数型(进程ID, 读内存长整数型(进程ID, 对象指针 + 312) + 32);
			Y = (INT32)读内存小数型(进程ID, 读内存长整数型(进程ID, 对象指针 + 312) + 36);
			Z = (INT32)读内存小数型(进程ID, 读内存长整数型(进程ID, 对象指针 + 312) + 40);
			代码 = 读内存长整数型(进程ID, 对象指针 + 代码偏移);
		}
		索引 = m_list.InsertItem(0, 十到十六(对象指针));
		//m_list.SetItemText(索引, 1, 到文本(类型));

		/*else if ((类型 = 273) && (阵营 != 0))
	{
		m_list.SetItemText(索引, 1, "人偶");
	}*/
		if (类型 != 273 && 类型 != 289 && 类型 != 529 && 类型 != 1057)
		{
			m_list.SetItemText(索引, 1, 到文本(类型));
		}	
		else
		{
			switch (类型)
			{
			case 273:
				if (阵营!=0)
				{
					m_list.SetItemText(索引, 1, "人偶");
				}
				else
				{
					m_list.SetItemText(索引, 1, 到文本(类型));
				}
				break;
			case 289:
				m_list.SetItemText(索引, 1, "物品");
				break;
			case 529:
				m_list.SetItemText(索引, 1, "怪物");
				break;
			case 1057:
				m_list.SetItemText(索引, 1, "建筑");
				break;
			}
		}
		名称 = 转换Unicode转Ansi(读内存字节集(进程ID, 读内存长整数型(进程ID, 对象指针 + 名称偏移), 52));
		m_list.SetItemText(索引, 2, 到文本(阵营));
		m_list.SetItemText(索引, 3, 到文本(X));
		m_list.SetItemText(索引, 4, 到文本(Y));
		m_list.SetItemText(索引, 5, 到文本(Z));
		m_list.SetItemText(索引, 6, 到文本(代码));
		m_list.SetItemText(索引, 7, 名称);
	}
}
