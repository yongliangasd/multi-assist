#pragma once


// CDia3 对话框

class CDia3 : public CDialog
{
	DECLARE_DYNAMIC(CDia3)

public:
	CDia3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDia3();

	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_list;
	afx_msg void OnNMRClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void On32771();
	afx_msg void OnBnClickedDanci();
};
