#pragma once


// CDia1 对话框

class CDia1 : public CDialog
{
	DECLARE_DYNAMIC(CDia1)

public:
	CDia1(CWnd* pParent = nullptr);   // 标准构造函数
	void 展开C(HTREEITEM hTreeItem);
	void ExpandTree(HTREEITEM hTreeItem);
	void 折叠C(HTREEITEM hTreeItem);
	virtual ~CDia1();
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CTreeCtrl m_tree;

//	afx_msg void OnTvnSingleExpandTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
//	CButton m_check1;
	BOOL m_check1;
//	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_com1;
	CComboBox m_com2;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
//	afx_msg void OnNMClickTree1(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnNMClickTree1(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnBnClickedButton11();
//	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton11();
};

