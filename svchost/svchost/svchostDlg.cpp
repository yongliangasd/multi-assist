
// svchostDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "svchost.h"
#include "svchostDlg.h"
#include "afxdialogex.h"
#include "初始化.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CsvchostDlg 对话框

CsvchostDlg::CsvchostDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SVCHOST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CsvchostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CsvchostDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CsvchostDlg::OnTcnSelchangeTab1)
	ON_WM_HOTKEY()
END_MESSAGE_MAP()


// CsvchostDlg 消息处理程序

BOOL CsvchostDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	m_tab.InsertItem(0, "基础功能");
	m_tab.InsertItem(1, "一键任务");
	m_tab.InsertItem(2, "地图遍历");
	m_tab.InsertItem(3, "装备操作");

	m_Dia1.Create(IDD_DIALOG1, &m_tab);
	m_Dia2.Create(IDD_DIALOG2, &m_tab);
	m_Dia3.Create(IDD_DIALOG3, &m_tab);
	m_Dia4.Create(IDD_DIALOG4, &m_tab);

	CWnd* pWnd;
	pWnd = GetDlgItem(IDC_TAB1);
	pWnd->SetWindowPos(NULL, 0, 0, 1050, 704, SWP_NOZORDER | SWP_NOMOVE);    //把编辑控件的大小设为(1050,704)，位置不变

	m_tab.GetClientRect(rs);
	rs.top += 20;
	rs.bottom -= 0;
	rs.left += 0;
	rs.right -= 0;

	m_Dia1.MoveWindow(&rs);
	m_Dia2.MoveWindow(&rs);
	m_Dia3.MoveWindow(&rs);
	m_Dia4.MoveWindow(&rs);

	pDialog[0] = &m_Dia1;
	pDialog[1] = &m_Dia2;
	pDialog[2] = &m_Dia3;
	pDialog[3] = &m_Dia4;

	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);

	m_CurSelTab = 0;
	
	移到左侧();

	地图数据();

	注册热键();
	
	插入任务();

	插入地图();

	添加编辑框内容();
	
	周期获取进程();
	
	//提升进程权限();


	//超级延迟(2, 5);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsvchostDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CsvchostDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsvchostDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{	
	// TODO: 在此添加控件通知处理程序代码
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	m_CurSelTab = m_tab.GetCurSel();
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	
	if (m_CurSelTab == 2) 
	{			
		改变窗口大小( 796, 704);
	}
	else
	{
		改变窗口大小(436, 704);
	}
	*pResult = 0;
}

BOOL CsvchostDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CsvchostDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nHotKeyId)
	{
	case 1:
		//MessageBox("你按下了F1!");
		m_Dia2.OnBnClickedBianlirenwu();
		break;
	case 2:
		满血满蓝();
		break;
	case 3:
		物品buff();
		break;
	case 4:
		透明无敌();
		break;
	case 5:
		m_Dia3.OnBnClickedDanci();
		break;
	case 6:
		管理权限();
		break;
	case 7:
		队友消失();
		break;
	case 8:
		超级评分();
		break;
	case 9:
		
		break;
	case 10:
		使用物品();
		break;
	case 11:

		break;
	case 12:
		遍历装备线程();
		break;
	case 13:
		梦幻装备();
		break;
	case 14:
		全屏捡物();
		break;
	case 15:
		释放技能();
		break;
	case 16:
		吸怪();
		break;
	case 17:
		顺图_左();
		break;
	case 18:
		顺图_上();
		break;
	case 19:
		顺图_右();
		break;
	case 20:
		顺图_下();
		break;
	case 21:

		break;

	}
}
