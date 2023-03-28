// CDia4.cpp: 实现文件
//

#include "pch.h"
#include "svchost.h"
#include "CDia4.h"
#include "afxdialogex.h"
#include "全局变量.h"
#include "基址.h"
#include "模块.h"
// CDia4 对话框

IMPLEMENT_DYNAMIC(CDia4, CDialog)

CDia4::CDia4(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
{

}

CDia4::~CDia4()
{
}

void CDia4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_com);
}


BEGIN_MESSAGE_MAP(CDia4, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDia4::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDia4::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDia4 消息处理程序


BOOL CDia4::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}


void CDia4::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_com.GetCurSel();
	switch (index)
	{
	case 0:
		全局_装备部位 = 12;
		break;
	case 1:
		全局_装备部位 = 14;
		break;
	case 2:
		全局_装备部位 = 16;
		break;
	case 3:
		全局_装备部位 = 15;
		break;
	case 4:
		全局_装备部位 = 18;
		break;
	case 5:
		全局_装备部位 = 17;
		break;
	case 6:
		全局_装备部位 = 19;
		break;
	case 7:
		全局_装备部位 = 20;
		break;
	case 8:
		全局_装备部位 = 21;
		break;
	case 9:
		全局_装备部位 = 22;
		break;
	case 10:
		全局_装备部位 = 23;
		break;
	case 11:
		全局_装备部位 = 26;
		break;
	case 12:
		全局_装备部位 = 13;
		break;
	}
}

void CDia4::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Dia4.GetDlgItem(DAQUYU)->SetWindowTextA(到文本(读内存整数型(进程ID, 城镇大区域)));
	m_Dia4.GetDlgItem(XIAOQUYU)->SetWindowTextA(到文本(读内存整数型(进程ID, 城镇小区域)));
}
