#include "初始化.h"
#include "pch.h"







void 移到左侧() 
{
	

	自窗口句柄 = AfxGetApp()->GetMainWnd()->GetSafeHwnd();
	int 屏幕高度 = GetSystemMetrics(SM_CYFULLSCREEN);
	int 窗口高度 = rs.Height();
	改变窗口位置(0, (屏幕高度 - 窗口高度) / 2);
	提升读写权限();
	//置剪辑板文本("纳斯达克上市加入标普500的纽交所.");
	//MessageBoxA(自窗口句柄, 取特殊目录(10), "DNF", 0);
	//取特殊目录(1);
	//强制删除文件(取执行文件名());
	//MessageBoxA(自窗口句柄, 到文本((INT64)(int)(人物基址)),"DNF",0);
	//PASS动态((int)人物基址, 8);
	//测试函数("QQPCTray.exe");

}

void 地图数据() 
{	
	CFont ft;
	m_Dia1.m_tree.SetFont(&ft);
	m_Dia1.m_tree.SetItemHeight(25);
	hRoot = m_Dia1.m_tree.InsertItem(_T("------1-100副本-----"));
	hRoot1 = m_Dia1.m_tree.InsertItem(_T("------常去----------"));
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------格兰之森------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 1);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------天空之城------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 2);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------天帷巨兽------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 3);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------阿法利亚------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 4);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------诺伊佩拉------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 5);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------斯顿雪域------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 6);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------诺斯玛尔------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 7);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------亚诺法森林----"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 8);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------厄运之城------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 9);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------逆流瀑布------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 10);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------安特贝鲁峡谷 -"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 11);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------海上列车------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 12);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------时空之门------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 13);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------发电站--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 14);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------寂静城--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 15);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------魔界营地------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 16);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------中央公园------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 17);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------哈林----------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 18);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------东哈林--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 19);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------旧根特皇宫----"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 20);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------风暴航路------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 21);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------德洛斯矿山----"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 22);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------冥域时空------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 23);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------月轮山--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 24);
	///////////////////////////////////////////////////////////////////////////
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------赛丽亚房间----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 100);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------亡者峡谷------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 101);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------赫顿玛尔------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 102);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------副职业亚贝罗--"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 103);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------老太婆商人----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 104);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------时空石商人----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 105);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------休亚商人------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 106);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------乌龟副本------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 107);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------卢克副本------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 108);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------普通超时空------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 109);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------泰波尔斯------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 110);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------灰色墓地------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 111);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------哈林----------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 112);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------公会----------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 113);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------月轮山--------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 114);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------漩涡开始地方--"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 115);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------风暴航路------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 116);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------德洛斯矿山----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 117);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------黑鸦之境------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 118);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------普雷每日------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 119);
	展开(hRoot1);
	
}


void 注册热键() 
{
	RegisterHotKey(自窗口句柄, 1, 0, VK_F1);//&_遍历任务_被单击
	RegisterHotKey(自窗口句柄, 2, 0, VK_F2);//&满血满蓝
	RegisterHotKey(自窗口句柄, 3, 0, VK_F3);//&改药
	RegisterHotKey(自窗口句柄, 4, 0, VK_F4);//&人物无敌
	RegisterHotKey(自窗口句柄, 5, 0, VK_F5);//&地图遍历1
	RegisterHotKey(自窗口句柄, 6, 0, VK_F6);//&管理权限
	RegisterHotKey(自窗口句柄, 7, 0, VK_F7);//&无视队友
	RegisterHotKey(自窗口句柄, 8, 0, VK_TAB);//&超级评分
	RegisterHotKey(自窗口句柄, 9, MOD_SHIFT, VK_F1);//&召唤怪物
	RegisterHotKey(自窗口句柄, 10, MOD_SHIFT, 0x31);//&使用物品
	RegisterHotKey(自窗口句柄, 11, MOD_SHIFT, VK_F3);//&独家变怪
	RegisterHotKey(自窗口句柄, 12, 0, VK_HOME);//&遍历装备线程
	RegisterHotKey(自窗口句柄, 13, 0, VK_END);//&梦幻装备
	RegisterHotKey(自窗口句柄, 14, 0, 0x56);//&全屏捡物
	RegisterHotKey(自窗口句柄, 15, 0, VK_OEM_3);//&释放技能
	RegisterHotKey(自窗口句柄, 16, MOD_ALT, 0x31);//&吸怪
	RegisterHotKey(自窗口句柄, 17, MOD_ALT, VK_LEFT);//&顺图_左
	RegisterHotKey(自窗口句柄, 18, MOD_ALT, VK_UP);//&顺图_上
	RegisterHotKey(自窗口句柄, 19, MOD_ALT, VK_RIGHT);//&顺图_右
	RegisterHotKey(自窗口句柄, 20, MOD_ALT, VK_DOWN);//&顺图_下
	//RegisterHotKey(自窗口句柄, 22, 0, VK_OEM_3);

}


void 插入任务() 
{
	LONG lStyle;

	lStyle = GetWindowLong(m_Dia2.m_list.m_hWnd, GWL_STYLE);// 获取当前窗口style

	lStyle &= ~LVS_TYPEMASK;// 清除显示方式位

	lStyle |= LVS_REPORT;// 设置style

	SetWindowLong(m_Dia2.m_list.m_hWnd, GWL_STYLE, lStyle);// 设置style

	DWORD dwStyle = m_Dia2.m_list.GetExtendedStyle();

	dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（只适用与report 风格的ListControl ） 

	dwStyle |= LVS_EX_GRIDLINES;// 网格线（只适用与report 风格的ListControl ） 

	//dwStyle |= LVS_EX_CHECKBOXES;//Item前生成checkbox 控件 
	m_Dia2.m_list.SetExtendedStyle(dwStyle); // 设置扩展风格 

	CImageList   m_l;
	m_l.Create(1, 22, TRUE | ILC_COLOR32, 1, 0);
	m_Dia2.m_list.SetImageList(&m_l, LVSIL_SMALL);

	LOGFONT   logfont;//最好弄成类成员,全局变量,静态成员  
	CFont* pfont1 = m_Dia2.m_list.GetFont();
	pfont1->GetLogFont(&logfont);
	 logfont.lfHeight = logfont.lfHeight * 3/2;   //这里可以修改字体的高比例
	logfont.lfWidth = logfont.lfWidth *3/2;   //这里可以修改字体的宽比例
	static   CFont   font1;
	font1.CreateFontIndirect(&logfont);
	m_Dia2.m_list.SetFont(&font1);
	font1.Detach();


	m_Dia2.m_list.InsertColumn(0,"任务名称(双击名称完成)", LVCFMT_LEFT,270);
	m_Dia2.m_list.InsertColumn(1, "任务ID", LVCFMT_LEFT, 120);



	//int nRow;
	//nRow = m_Dia2.m_list.InsertItem(0, "11");// 插入行
	//m_Dia2.m_list.SetItemText(nRow, 1, "jacky");// 设置其它列数据
	//
	//nRow = m_Dia2.m_list.InsertItem(0, "qw424523");// 插入行
	//m_Dia2.m_list.SetItemText(nRow, 1, "wt74456");// 设置其它列数据




}

void 插入地图() 
{
	DWORD dwStyle = m_Dia3.m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（只适用与report 风格的ListControl ） 
	dwStyle |= LVS_EX_GRIDLINES;// 网格线（只适用与report 风格的ListControl ） 
	m_Dia3.m_list.SetExtendedStyle(dwStyle); // 设置扩展风格 

	CImageList   m_l;
	m_l.Create(1, 18, TRUE | ILC_COLOR32, 1, 0);
	m_Dia3.m_list.SetImageList(&m_l, LVSIL_SMALL);

	m_Dia3.m_list.InsertColumn(0, "地址", LVCFMT_LEFT, 80);
	m_Dia3.m_list.InsertColumn(1, "类型", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(2, "阵营", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(3, "X轴", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(4, "Y轴", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(5, "Z轴", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(6, "代码(右键复制)", LVCFMT_LEFT, 110);
	m_Dia3.m_list.InsertColumn(7, "名称", LVCFMT_LEFT, 170);

	//int nRow;
	//nRow = m_Dia3.m_list.InsertItem(0, "FFFFFFFFF");// 插入行
	//m_Dia3.m_list.SetItemText(nRow, 1, "60000");// 设置其它列数据
	//m_Dia3.m_list.SetItemText(nRow, 2, "60000");// 设置其它列数据
	//m_Dia3.m_list.SetItemText(nRow, 3, "60000");// 设置其它列数据
	//m_Dia3.m_list.SetItemText(nRow, 4, "60000");// 设置其它列数据
	//m_Dia3.m_list.SetItemText(nRow, 5, "60000");// 设置其它列数据
	//m_Dia3.m_list.SetItemText(nRow, 6, "1070009035");// 设置其它列数据
	//m_Dia3.m_list.SetItemText(nRow, 7, "设置其它列数据");// 设置其它列数据

}


void 添加编辑框内容() 
{
	CString   str = "6000";
	m_Dia1.GetDlgItem(CHUSHIZHI)->SetWindowText(str);
	   str = "3000";
	m_Dia1.GetDlgItem(CISHU)->SetWindowText(str);
//	   str = "20";
//	m_Dia1.GetDlgItem(BEISHANG)->SetWindowText(str);
	   str = "62129";
	m_Dia1.GetDlgItem(JINENGDAIMA)->SetWindowText(str);
	   str = "999999999";
	m_Dia1.GetDlgItem(JINENGSHANGHAI)->SetWindowText(str);
	   str = "1";
	m_Dia1.GetDlgItem(JINENGDAXIAO)->SetWindowText(str);
	   str = "109008635";
	m_Dia1.GetDlgItem(RENOU)->SetWindowText(str);
	   str = "51";
	m_Dia1.GetDlgItem(WUPIN)->SetWindowText(str);
	   str = "61500";
	m_Dia1.GetDlgItem(BIANGUAI)->SetWindowText(str);
	str = "1";
	m_Dia2.GetDlgItem(WANCHENGCISHU)->SetWindowText(str);	
	str = "1000";
	m_Dia3.GetDlgItem(PINLV)->SetWindowText(str);


	//初始化按钮状态
	((CButton*)m_Dia1.GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);
	((CButton*)m_Dia1.GetDlgItem(IDC_CHECK4))->SetCheck(BST_CHECKED);
	((CButton*)m_Dia2.GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);	
}


void 使用物品()
{
	CButton* ptn;
	CString str;
	int 物品代码,state;
	物品代码 = m_Dia1.GetDlgItemInt(WUPIN, NULL, TRUE);
	物品Call(物品代码);
	 ptn = (CButton*)m_Dia1.GetDlgItem(ZIZENG);
	state = ptn->GetCheck();
	if (state == 1) 
	{
		//物品代码 = _ttoi(str);
		物品代码 += 1;
		str.Format("%d", 物品代码);
		m_Dia1.GetDlgItem(WUPIN)->SetWindowTextA(str);	
	}	
}

void 遍历装备()
{
	INT64 装备指针,装备代码;
	CString 装备名称;
	TCHAR 装备路径[1024];
	TCHAR *装备文件 = _T("\\装备代码.txt");
	CString str;
	str.Format("%d", 装备文件);
	//获取当前用户的桌面路径
	SHGetSpecialFolderPath(0, 装备路径, CSIDL_DESKTOPDIRECTORY, 0);
	INT64 len1 = lstrlen(str);
	INT64 lpath = lstrlen(装备路径);
	TCHAR* strn = new TCHAR[lpath + len1 + 1];
	strn[0] = _T('\0');
	lstrcat(strn, 装备路径);
	lstrcat(strn, str);
	fstream fp(strn, ios::app | ios::out);

	装备指针 = 读内存长整数型(进程ID, 鼠标基址);
	装备代码 = 读内存长整数型(进程ID, 装备指针 + 48);
	str.Format("%d", 装备代码);
	m_Dia4.GetDlgItem(ZHUANGBEIDAIMA)->SetWindowTextA(str);
	装备名称 = 转换Unicode转Ansi(读内存字节集(进程ID, 读内存长整数型(进程ID, 装备指针 + 56), 52));

	str.AppendFormat("%d", "        ");
	str.AppendFormat("%d", 装备名称);
	str.AppendFormat("%d", "\n");
	fp << str;
	fp.close();
}

void 遍历装备线程() 
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)遍历装备, NULL, 0,NULL);
}

void 释放技能()
{
	int state,技能大小;
	CString str;
	INT64 一级偏移;
	坐标型 对象坐标;
	一级偏移 = 读内存长整数型(进程ID, 人物基址);
	m_Dia1.GetDlgItem(JINENGDAIMA)->GetWindowTextA(str);
	全屏代码 = _atoi64(str);
	m_Dia1.GetDlgItem(JINENGSHANGHAI)->GetWindowTextA(str);
	全屏伤害 = _atoi64(str);
	m_Dia1.GetDlgItem(JINENGDAXIAO)->GetWindowTextA(str);
	技能大小 = atoi(str);
	对象坐标 = 读坐标(一级偏移);
	CButton* ptn = (CButton*)m_Dia1.GetDlgItem(IDC_CHECK4);
	state = ptn->GetCheck();
	if (state ==1)
	{
		释放call(一级偏移, 全屏代码, 全屏伤害, 对象坐标.x, 对象坐标.y, 对象坐标.z);
	}
	else
	{
		技能Call(一级偏移, 全屏代码, 全屏伤害, 对象坐标.x, 对象坐标.y, 对象坐标.z, 技能大小);
	}
}

void 梦幻装备()
{
	INT64 换装指针,换装代码;
	CString str;
	m_Dia4.GetDlgItem(ZHUANGBEIDAIMA)->GetWindowTextA(str);
	换装代码 = _atoi64(str);
	换装指针 = 人物基址;	
	装备数据 = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	换装call(换装指针, 换装代码, 全局_装备部位);
	装备数据.push_back(0x48);
	装备数据.push_back(0x81);
	装备数据.push_back(0xC4);
	装备数据.push_back(0x50);
	装备数据.push_back(0x01);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xC3);
	内存汇编x64(装备数据);
	vector<byte>().swap(装备数据);
	无视等级();
	神话公告("换装成功!", 1);
}

void 周期获取进程()
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)取DNF进程, NULL, 0, NULL);
}

void 取DNF进程()
{
	int i=0;
	SetWindowTextA(自窗口句柄, "龙井: 正在获取进程...");
	while ((进程ID = 取进程ID("DNF.exe")) == 0)
	{
		i += 1;
		超级延时(500);
		if (i > 15)
		{
			SetWindowTextA(自窗口句柄, "龙井: 进程获取失败!");
			return ;
		}		
	}
	进程ID = 取进程ID("DNF.exe");
	DWORD s1 = 进程ID;
	CString str1("龙井: 进程获取成功,进程ID:");
	CString str2;
	str2.Format("%u", s1);
	str1 += str2;	
	SetWindowTextA(自窗口句柄, + (LPCSTR)(LPCTSTR)str1);
	//MessageBoxA(自窗口句柄,(LPCSTR)(LPCTSTR)str1  ,"DNF:",0);
	//写内存长整数型(进程ID, 0x140001000, 0);
	//写内存整数型(进程ID, 0x140001002, 1);
	//写内存短整数型(进程ID, 0x140001004, 2);
	//写内存小数型(进程ID, 0x140001006, 3.0);
	//写内存字节集(进程ID, 0x140001008, {4});
	空白全局 =全局空白;

	/*神话公告("测试公告0", 0);
	神话公告("测试公告1", 1);
	神话公告("测试公告2", 2);
	神话公告("测试公告3", 3);*/

}
