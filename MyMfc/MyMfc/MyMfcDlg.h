﻿
// MyMfcDlg.h: 头文件
//

#pragma once
#include "afxwin.h"
#include<vector>


typedef struct 遍历类型
{
	__int64 人物指针, 地图指针, 首, 尾, 遍历指针, 遍历血量;

	int 遍历对象;
	int 遍历类型s;
	int 遍历阵营;
	int 遍历数量;
	int 遍历代码;
	CString 遍历名称;

}遍历结构, * 遍历结构类型;


typedef struct 坐标系列
{
	int x;
	int y;
	int z;

}坐标, * 坐标结构;


// CMyMfcDlg 对话框
class CMyMfcDlg : public CDialogEx
{
// 构造
public:
	CMyMfcDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()




public:

	afx_msg void On32772();
	HANDLE Game_Handle;
	DWORD Pid ;

	

	void  CMyMfcDlg::API_写字节集(__int64  地址, std::vector<byte> 值);

	std::vector<byte> CMyMfcDlg::API_读字节集(__int64 地址, int 长度);

	DWORD Readint(__int64 Address);

	bool Writeint(__int64 Address, int data);

	void HOOK倍功();

	LPVOID CMyMfcDlg::申请内存(int DwSize);

	bool CMyMfcDlg::释放内存(LPVOID 释放地址);

	void CMyMfcDlg::吸取遍历();
	void CMyMfcDlg::释放Call(__int64 触发指针, int 技能代码, int 技能伤害, int x, int y, int z);

	__int64 超级解密(__int64 address);

	void 神话公告(CString 公告内容, int 类型 = 0);

	void 内存按键(int key, int Seeps = 0);



private:
	void 特效Call(int type);

public:
	void 处理事件();


	void 内存汇编x64(std::vector<byte>asm_code);

	int ReadLONG(__int64 内存地址);

	int ReadINT(__int64 内存地址);


	void 评分Call(int Value);

	__int64 GetProcessModule(DWORD Pid, char Name[]);

	bool WriteINT(int 内存地址, __int64 Ret);

	afx_msg void OnBnClickedButton1();


	bool Writefloat(__int64 Address, float data);

	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

	UINT pass = 0;
	void 符咒全屏();
	int 当前疲劳();


	void 停止符咒();
	int 解密(__int64 地址);
	short CMyMfcDlg::Readshort(__int64 Address);


	void  Resourceloading(LPCSTR FileName, DWORD ID, LPCSTR type);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButton pButton;
	CString code;
	CString 伤害;
	CString 伤害1;
	CString 方式;


	void 物品Call(__int64 物品代码);

	void 公告(CString  公告内容, int 公告颜色 = 0, int 公告类型  = 0);



	std::vector<byte> data;
	BOOL CMyMfcDlg::installDvr(CONST CHAR drvPath[50], CONST CHAR serviceName[20]);
	BOOL CMyMfcDlg::startDvr(CONST CHAR serviceName[20]);
	BOOL CMyMfcDlg::stopDvr(CONST CHAR serviceName[20]);
	BOOL CMyMfcDlg::unloadDvr(CONST CHAR serviceName[20]);

	BOOL bRet = FALSE;
	char * szFileName;






	CImage img;




	void 坐标Call(__int64 触发地址, int x, int y, int z);

	int 取游戏状态();

	bool 地面是否有物品();

	int 取对象坐标(int 读取指针, int 坐标参数);

	bool 当前是否开门();

	float CMyMfcDlg::Readflaot(__int64 Address);

	bool CMyMfcDlg::当前是否通关();

	坐标 读取坐标(__int64 读取指针);

	void 城镇加速();

	void CMyMfcDlg::拾取遍历();

	void CMyMfcDlg::全屏遍历();

	void 技能开关();

	int 判断通关();

	void 钩子全屏();


	void 技能Call(__int64 触发指针, int 技能代码, int 技能伤害, int x, int y, int z , int 技能大小);

	public:
		__int64 商店机制, 喇叭公告, 最大疲劳, 最小疲劳, 解密机制, 评分CALL, 按键机制, 人物机制, 物品CALL, 钩子上侧, 钩子下侧, 钩子左侧, 钩子右侧;
		__int64 特效缓冲CALL, 特效释放CALL, BUFF参数1, BUFF参数2, 特效机制, 坐标CALL偏移, X坐标, 方向偏移, 游戏状态, 释放CALL, 技能CALL, HOOK伤害, 无敌偏移;
		__int64 地图偏移, 首地址, 尾地址, 类型偏移, 血量偏移, 阵营偏移, 是否开门, 代码偏移, 名称偏移, 房间编号, 时间机制, 载火判断, 门型偏移, GM加速, 空白地址;

		virtual BOOL PreTranslateMessage(MSG* pMsg);
		afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
		afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
		CComboBox 全屏模式;
		CString 技能代码;
		CString 技能伤害;
		CString 技能频率;
		CString 技能大小;
		CString 自定义;
		CString 技能个数;
		CString 倍功伤害;
		afx_msg void OnBnClickedCheck1();
};
