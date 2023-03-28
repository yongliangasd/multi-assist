// CDia2.cpp: 实现文件
//

#include "pch.h"
#include "svchost.h"
#include "CDia2.h"
#include "afxdialogex.h"
#include "模块.h"
#include "基址.h"
#include "各种CALL.h"
#include "全局变量.h"
// CDia2 对话框

IMPLEMENT_DYNAMIC(CDia2, CDialog)

CDia2::CDia2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CDia2::~CDia2()
{
}

void CDia2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDia2, CDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDia2::OnNMDblclkList1)
	ON_BN_CLICKED(BIANLIRENWU, &CDia2::OnBnClickedBianlirenwu)
END_MESSAGE_MAP()


// CDia2 消息处理程序


BOOL CDia2::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}


void CDia2::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	

	CString str;
	int i,row,完成次数,任务ID;
	//首先得到点击的位置
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		//MessageBox("请至少选择一项", "提示", MB_ICONEXCLAMATION);
		return;
	}
	//得到行号，通过POSITION转化
	row = (int)m_list.GetNextSelectedItem(pos);
	//获取第row第0列的内容，并保存到str中
	str = m_list.GetItemText(row, 1);
	GetDlgItem(RENWUID)->SetWindowTextA(str);
	任务ID = _ttoi(str);
	完成次数= GetDlgItemInt(WANCHENGCISHU, NULL, TRUE);
	任务接受Call(任务ID);
	for ( i = 0; i < 完成次数; i++)
	{
		任务完成Call(任务ID);
		超级延时(10);
	}
	任务提交Call(任务ID);
	
	*pResult = 0;
}


void CDia2::OnBnClickedBianlirenwu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
	INT64  i, 目标地址, 首地址=0, 尾地址=0, 任务地址, 任务数量;
	int nRow, 总行数,长度, 任务ID;
	CString 任务名称;
	CString str;
	任务地址 = 读内存长整数型(进程ID, 任务基址);

	if (((CButton*)GetDlgItem(BIANLIQUANBU))->GetCheck()) 
	{
		首地址 = 读内存长整数型(进程ID, 任务地址 + 168);
		尾地址 = 读内存长整数型(进程ID, 任务地址 + 176);
		//MessageBoxA("选中全部","DNF" );
	}

	if (((CButton*)GetDlgItem(BIANLIYIJIE))->GetCheck())
	{
		首地址 = 读内存长整数型(进程ID, 任务地址 + 16);
		尾地址 = 读内存长整数型(进程ID, 任务地址 + 24);
		//MessageBoxA("选中已接","DNF" );
	}
	
	任务数量 = (尾地址 - 首地址) / 8;

	//str.Format("%d", 任务数量);
	//MessageBoxA(str, "DNF");

	for ( i = 0; i < 任务数量; i++)
	{
		目标地址 = 读内存长整数型(进程ID, 首地址 + i * 8);
		任务ID = 读内存整数型(进程ID, 目标地址);

		if (任务ID < 0 || 任务ID>1000000 || (任务ID >= 3100 && 任务ID <= 3144) || (任务ID >= 9000 && 任务ID <= 9144) || (任务ID >= 6171 && 任务ID <= 6179) || (任务ID >= 6141 && 任务ID <= 6144) || (任务ID >= 2905 && 任务ID <= 2907)) 
		{
			continue;
		}
		长度 = 读内存整数型(进程ID, 目标地址 + 32);
		if (长度 <= 7) 
		{
			任务名称 = 转换Unicode转Ansi(读内存字节集(进程ID, 目标地址 + 16, 56));			
		}
		else
		{
			任务名称 = 转换Unicode转Ansi(读内存字节集(进程ID, 读内存长整数型(进程ID,目标地址 + 16), 100));
		}

		if (任务名称 != L"") 
		{
			str.Format("%d", 任务ID);
			总行数= m_list.GetItemCount();

			LVITEMA lvItem;

			lvItem.mask = LVIF_TEXT;

			lvItem.iItem = 总行数;  //行数

			lvItem.iSubItem = 0;

			lvItem.pszText = (char*)(LPCTSTR)任务名称;//第一列

			m_list.InsertItem(&lvItem);			

			m_list.SetItemText(总行数, 1, str);// 插入其它列

			//nRow = m_list.InsertItem(0, 任务名称);// 插入行
			//m_list.SetItemText(nRow, 1, (LPCSTR)( str));// 设置其它列数据

			//nRow = m_list.InsertItem(0, "任务名称");// 插入行
			//m_list.SetItemText(nRow, 1, "任务ID");// 设置其它列数据

		}
		处理事件();

	}

}
