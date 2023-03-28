
// moduleDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "module.h"
#include "moduleDlg.h"
#include "afxdialogex.h"
#include "模块.h"
#include "全局变量.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmoduleDlg 对话框




CmoduleDlg::CmoduleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODULE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmoduleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmoduleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CmoduleDlg::OnBnClickedOk)
	ON_WM_HELPINFO()
	ON_WM_HOTKEY()
	ON_BN_CLICKED(IDCANCEL, &CmoduleDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CmoduleDlg 消息处理程序

BOOL CmoduleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	int i=0;
	while (进程ID <= 0 && i<10) 
	{
		i++;
		进程ID = 取进程ID("Dump[2021116].exe");
		超级延迟(500);
	}
	SetWindowText("进程获取成功");
	进程句柄 = 打开进程(进程ID);
	RegisterHotKey(GetSafeHwnd(), 1, NULL, VK_F10);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmoduleDlg::OnPaint()
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
HCURSOR CmoduleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmoduleDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	//pEdit->SetSel(-1);
	//写内存小数型(进程句柄, 5382076572, 53.67);
	//CString str;
	//str = to_string(读内存小数型(进程句柄, 5382076572)).c_str();
	//LPCSTR g=f.c_str();

	//pEdit->ReplaceSel(_T(g));
	//str.Format("%p",进程句柄);
	
	//SetDlgItemText(IDC_EDIT1,str );

	//MessageBox((str));

	进程时钟 = 0;







}







void CmoduleDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nHotKeyId)
	{
	case 1:
		MessageBox(_T("你按下了F10键"));
		break;
	}	
	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CmoduleDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

}
