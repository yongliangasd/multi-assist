#pragma once


// CDia2 对话框

class CDia2 : public CDialog
{
	DECLARE_DYNAMIC(CDia2)

public:
	CDia2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDia2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl m_list;
	afx_msg void OnBnClickedBianlirenwu();
};
