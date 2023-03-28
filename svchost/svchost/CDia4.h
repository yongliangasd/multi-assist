#pragma once


// CDia4 对话框

class CDia4 : public CDialog
{
	DECLARE_DYNAMIC(CDia4)

public:
	CDia4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDia4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_com;
	afx_msg void OnBnClickedButton1();
};
