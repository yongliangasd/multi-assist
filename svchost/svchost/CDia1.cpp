// CDia1.cpp: 实现文件
//
#pragma once

#include "pch.h"
#include "svchost.h"
#include "CDia1.h"
#include "afxdialogex.h"
#include "模块.h"
#include "基址.h"
#include "全局变量.h"
#include "各种CALL.h"
// CDia1 对话框

IMPLEMENT_DYNAMIC(CDia1, CDialog)

CDia1::CDia1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_check1(FALSE)
{

}

CDia1::~CDia1()
{
}

void CDia1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	//  DDX_Control(pDX, IDC_CHECK4, m_check1);
	//DDX_Control(pDX, IDC_CHECK4, (BOOL)&m_check1);
	DDX_Control(pDX, IDC_COMBO1, m_com1);
	DDX_Control(pDX, IDC_COMBO2, m_com2);
}


BEGIN_MESSAGE_MAP(CDia1, CDialog)
ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CDia1::OnSelchangedTree1)
ON_CBN_SELCHANGE(IDC_COMBO1, &CDia1::OnCbnSelchangeCombo1)
ON_CBN_SELCHANGE(IDC_COMBO1, &CDia1::OnCbnSelchangeCombo1)
ON_CBN_SELCHANGE(IDC_COMBO2, &CDia1::OnCbnSelchangeCombo2)
ON_BN_CLICKED(IDC_BUTTON5, &CDia1::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CDia1::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &CDia1::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CDia1::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &CDia1::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON10, &CDia1::OnBnClickedButton10)

//ON_BN_CLICKED(IDC_BUTTON11, &CDia1::OnBnClickedButton11)
//ON_BN_CLICKED(IDC_BUTTON12, &CDia1::OnBnClickedButton12)
ON_BN_CLICKED(IDC_BUTTON13, &CDia1::OnBnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON14, &CDia1::OnBnClickedButton14)
ON_BN_CLICKED(IDC_BUTTON3, &CDia1::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CDia1::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON11, &CDia1::OnBnClickedButton11)
END_MESSAGE_MAP()


// CDia1 消息处理程序


BOOL CDia1::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}



void CDia1::展开C(HTREEITEM hTreeItem)
{
	
	if (!m_tree.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hNextItem = m_tree.GetChildItem(hTreeItem);
	while (hNextItem != NULL)
	{
		展开C(hNextItem);
		hNextItem = m_tree.GetNextItem(hNextItem, TVGN_NEXT);
	}
	m_tree.Expand(hTreeItem, TVE_EXPAND);
}

void CDia1::ExpandTree(HTREEITEM hTreeItem)
{
	if (!m_tree.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hNextItem = m_tree.GetChildItem(hTreeItem);
	while (hNextItem != NULL)
	{
		ExpandTree(hNextItem);
		hNextItem = m_tree.GetNextItem(hNextItem, TVGN_NEXT);
	}
	HTREEITEM hchild = m_tree.GetChildItem(hTreeItem);
	CString NodeData, NodeName;
	NodeName = m_tree.GetItemText(hchild);
	if (NodeData.Compare(_T("2")) == 0)
	{
		return;
	}
	m_tree.Expand(hTreeItem, TVE_EXPAND);
}

void CDia1::折叠C(HTREEITEM hTreeItem)
{
	if (!m_tree.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hNextItem = m_tree.GetChildItem(hTreeItem);
	while (hNextItem != NULL)
	{
		ExpandTree(hNextItem);
		hNextItem = m_tree.GetNextItem(hNextItem, TVGN_NEXT);
	}
	m_tree.Expand(hTreeItem, TVE_COLLAPSE);
}


void CDia1::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	const char* roott1 = "------1-100副本-----";
	const char* roott2 = "------常去----------";
	CString	root1c(roott1);
	CString	root2c(roott2);
	CString	root3c;
	CString strText; // 树节点的标签文本字符串 
	HTREEITEM hItems = m_tree.GetSelectedItem();
	DWORD sen = (DWORD)m_tree.GetItemData(hItems);
	
	//DWORD n = m_tree.GetItemData(hItems);
	//CString strh;
	//strh.Format("%p", n);
	//MessageBox(strh);
	
	strText = m_tree.GetItemText(hItems);
	HTREEITEM hItem1 = m_tree.GetRootItem();
	HTREEITEM hItem2 = m_tree.GetNextItem(hItem1,TVGN_NEXT);
	int i = 0;
	while (NULL != m_tree.GetNextItem(hItem2, TVGN_NEXT))
	{
		hItem2 = m_tree.GetNextItem(hItem2, TVGN_NEXT);
		root3c = m_tree.GetItemText(hItem2);
		if (root3c==root2c)
		{
			break;
		}
		i++;
	}
	if (TVIS_EXPANDED & m_tree.GetItemState(hItems, TVIS_EXPANDED)) 
	{
		//树已经展开;
		return;
	}
	else 
	{
		//没有展开
		if (strText == root1c)
		{
			展开C(hItem1);
			折叠C(hItem2);
		}
		else if (strText == root2c)
		{
			展开C(hItem2);
			折叠C(hItem1);
		}
	}

	switch (sen)
	{
//////////////////////////1-100副本/////////////////////////////////////////////////
	case 1:
		组包_城镇移动(38, 2, 100, 250);		//格兰之森副本
		break;
	case 2:
		组包_城镇移动(40, 7, 850, 250);		//天空之城
		break;
	case 3:
		组包_城镇移动(40, 4, 1050, 300);	//天帷巨兽
		break;
	case 4:
		组包_城镇移动(41, 2, 850, 225);		//阿法利亚
		break;								
	case 5:									
		组包_城镇移动(42, 3, 1050, 225);	//诺伊佩拉
		break;								
	case 6:									
		组包_城镇移动(43, 1, 100, 400);		//斯顿雪域副本
		break;								
	case 7:									
		组包_城镇移动(39, 5, 80, 300);		//诺斯玛尔
		break;								
	case 8:									
		组包_城镇移动(46, 6, 250, 275);		//亚诺法森林
		break;								
	case 9:									
		组包_城镇移动(46, 5, 325, 235);		//厄运之城
		break;								
	case 10:								
		组包_城镇移动(46, 4, 850, 250);		//逆流瀑布
		break;								
	case 11:								
		组包_城镇移动(6, 1, 175, 225);		//安特贝鲁峡谷
		break;								
	case 12:								
		组包_城镇移动(9, 1, 850, 225);		//海上列车
		break;								
	case 13:								
		组包_城镇移动(12, 0, 80, 250);		//时空之门
		break;								
	case 14:								
		组包_城镇移动(14, 2, 850, 225);		//发电站
		break;								
	case 15:								
		组包_城镇移动(22, 2, 1050, 300);	//寂静城
		break;								
	case 16:								
		组包_城镇移动(30, 2, 800, 300);		//魔界营地
		break;								
	case 17:								
		组包_城镇移动(31, 2, 100, 300);		//中央公园
		break;								
	case 18:								
		组包_城镇移动(54, 2, 1050, 200);	//哈林
		break;								
	case 19:								
		组包_城镇移动(68, 2, 1050, 250);	//东哈林
		break;								
	case 20:								
		组包_城镇移动(6, 5, 80, 250);		//旧根特皇宫
		break;								
	case 21:								
		组包_城镇移动(78, 0, 1250, 350);	//风暴航路
		break;								
	case 22:								
		组包_城镇移动(80, 1, 525, 225);		//德洛斯矿山
		break;								
	case 23:								
		组包_城镇移动(77, 0, 1250, 350);	//冥域时空
		break;								
	case 24:								
		组包_城镇移动(18, 0, 350, 300);		//月轮山
		break;								
//////////////////////////常去/////////////////////////////////////////////////
	case 100:								
		组包_城镇移动(38, 1, 450, 225);		//赛丽亚房间
		break;								
	case 101:								
		组包_城镇移动(38, 5, 125, 300);		//亡者峡谷
		break;								
	case 102:								
		组包_城镇移动(39, 0, 1800, 250);	//赫顿玛尔
		break;								
	case 103:								
		组包_城镇移动(40, 0, 1600, 250);	//副职业亚贝罗
		break;								
	case 104:								
		组包_城镇移动(54, 1, 600, 550);		//老太婆商人
		break;								
	case 105:								
		组包_城镇移动(31, 3, 700, 300);		//时空石商人
		break;								
	case 106:								
		组包_城镇移动(35, 0, 850, 250);		//休亚商人
		break;								
	case 107:								
		组包_城镇移动(20, 2, 1000, 400);	//乌龟
		break;								
	case 108:								
		组包_城镇移动(22, 4, 1050, 300);	//卢克
		break;								
	case 109:								
		组包_城镇移动(115, 0, 1200, 425);	//普通超时空
		break;							
	case 110:								
		组包_城镇移动(35, 2, 1050, 300);	//泰波尔斯
		break;								
	case 111:								
		组包_城镇移动(60, 1, 1250, 250);	//灰色墓地
		break;								
	case 112:								
		组包_城镇移动(54, 2, 1050, 200);	//哈林
		break;								
	case 113:								
		组包_城镇移动(8, 1, 980, 225);		//公会
		break;								
	case 114:								
		组包_城镇移动(18, 0, 300, 300);		//月轮山
		break;								
	case 115:								
		组包_城镇移动(57, 2, 1000, 1000);	//旋涡开始地方
		break;								
	case 116:								
		组包_城镇移动(78, 0, 1250, 350);	//风暴航路
		break;
	case 117:								
		组包_城镇移动(80, 1, 525, 225);		//德洛斯矿山
		break;
	case 118:								
		组包_城镇移动(80, 3, 800, 220);	//黑鸦之境
		break;
	case 119:
		组包_城镇移动(118, 0, 800, 250);	//灰色墓地
		break;
	}







	*pResult = 0;
}


//void CDia1::OnNMClickTree1(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//	HTREEITEM 本次选中 = m_tree.GetSelectedItem();
//	上次选中 = 本次选中;
//	DWORD sen = (DWORD)m_tree.GetItemData(上次选中);
//
//	
//
//
//
//
//
//	*pResult = 0;
//}


void CDia1::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	选中职业 = m_com1.GetCurSel();
	switch (选中职业)
	{
	case 0:
		m_com2.ResetContent();
		m_com2.AddString("星之海 : 巴德纳尔光剑");//101040587
		m_com2.AddString("赤光剑路易纳斯光剑");//101040588
		m_com2.AddString("信念徽章 : 自由短剑");//101000860
		m_com2.AddString("战场的热血 : 安格巴迪短剑");//101000861
		m_com2.AddString("太极天帝剑太刀");//101011025
		m_com2.AddString("前瞻守卫者太刀");//101011026
		m_com2.AddString("卡西姆的大剑巨剑");//101030890
		m_com2.AddString("神之意象巨剑");//101030891
		m_com2.AddString("哈蒂 - 赎月者钝器");//101020806
		m_com2.AddString("骚动的冥焰钝器");//101020807
		break;
	case 1:
		m_com2.ResetContent();
		m_com2.AddString("世界树的根须法杖");//106030707
		m_com2.AddString("银月的祝福法杖");//106030708
		m_com2.AddString("火焰地狱魔杖");//106020675
		m_com2.AddString("魔力之泉 : 加斯达利亚魔杖");//106020676
		m_com2.AddString("精灵浮风棍棍棒");//106010631
		m_com2.AddString("混沌之种棍棒");//106010632
		m_com2.AddString("歼灵灭魂矛矛");//106000606
		m_com2.AddString("吟唱 : 不灭之魂矛");//106000607
		m_com2.AddString("世界树之精灵扫把");//106040579
		m_com2.AddString("纯白的祈祷扫把");//106040580

		break;
	case 2:
		m_com2.ResetContent();
		m_com2.AddString("乾坤极电炮手炮");//104030639
		m_com2.AddString("绝杀 : 无人生还手炮");//104030640
		m_com2.AddString("午夜生死轮盘左轮");//104000656
		m_com2.AddString("血枪之脉左轮");//104000657
		m_com2.AddString("湍流步枪");//104020626
		m_com2.AddString("强力打击-X步枪");//104020627
		m_com2.AddString("激光流星弓手弩");//104040650
		m_com2.AddString("吟游诗人的轻吟手弩");//104040651
		m_com2.AddString("寻觅海石竹自动手枪");//104010639
		m_com2.AddString("雷霆怒啸手枪自动手枪");//104010640

		break;
	case 3:
		m_com2.ResetContent();
		m_com2.AddString("万夫之勇战戟");//114010285
		m_com2.AddString("沙岩幻戟战戟");//114010286
		m_com2.AddString("幻影狂欢长枪长枪");//114000304
		m_com2.AddString("彪悍冲锋者长枪");//114000305
		m_com2.AddString("千芒闪爆枪光枪");//114020187
		m_com2.AddString("天将军 : 传承之光光枪");//114020188
		m_com2.AddString("寂灭剧毒矛暗矛");//114030187
		m_com2.AddString("魅影飞龙暗矛");//114030188

		break;
	case 4:
		m_com2.ResetContent();
		m_com2.AddString("白虎啸魂手套手套");//102000626
		m_com2.AddString("无瑕之意志手套手套");//102000627
		m_com2.AddString("猎焰追魂拳套拳套");//102030575
		m_com2.AddString("幻光绽放拳套拳套");//102030576
		m_com2.AddString("太阴神 : 灵龟臂铠");//102010681
		m_com2.AddString("毁灭之碾压臂铠");//102010682
		m_com2.AddString("青沙棍东方棍");//102040638
		m_com2.AddString("鸣鸿破影棍东方棍");//102040639
		m_com2.AddString("疯狂飓风爪");//102020583
		m_com2.AddString("痛苦之源爪");//102020584

		break;
	case 5:
		m_com2.ResetContent();
		m_com2.AddString("金刚密藏刀长刀");//116000206
		m_com2.AddString("夜天刀长刀");//116000207
		m_com2.AddString("聚能擎天剑重剑");//116020182
		m_com2.AddString("爆烈红焰重剑");//116020183
		m_com2.AddString("冰洁的红焰小太刀");//116010180
		m_com2.AddString("冥焰黑暗之触小太刀");//116010181
		m_com2.AddString("远古御神战剑源力剑");//116030220
		m_com2.AddString("谍影 : 超级核心源力剑");//116030221

		break;
	case 6:
		m_com2.ResetContent();
		m_com2.AddString("弗卡奴斯的第二个痕迹战斧");//108040562
		m_com2.AddString("信念之重量战斧");//108040563
		m_com2.AddString("圣者的慈悲十字架");//108000599
		m_com2.AddString("闪耀的神威十字架");//108000600
		m_com2.AddString("轮回之环 : 桓龙念珠");//108010588
		m_com2.AddString("古代神兽的记忆念珠");//108010589
		m_com2.AddString("暗战终结者图腾");//108020498
		m_com2.AddString("拓荒者之路图腾");//108020499
		m_com2.AddString("泯灭之灵镰刀");//108030612
		m_com2.AddString("异教主的审判镰刀");//108030613

		break;
	case 7:
		m_com2.ResetContent();
		m_com2.AddString("匿影匕首");//109000565
		m_com2.AddString("暗杀团长的玉妆刀匕首");//109000566
		m_com2.AddString("一叶障目双剑");//109010517
		m_com2.AddString("血色舞会双剑");//109010518
		m_com2.AddString("绿色生命的面容手杖");//109030492
		m_com2.AddString("圣洁的精灵遗物手杖");//109030493
		m_com2.AddString("血腥红宝石之眼苦无");//109040373
		m_com2.AddString("天幕道火扇苦无");//109040374

		break;
	}
}


void CDia1::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	选中武器 = m_com2.GetCurSel();
	switch (选中职业)
	{
	case 0:									//鬼剑士
		switch (选中武器)
		{
		case 0:
			武器代码 = 101040587;
			break;
		case 1:
			武器代码 = 101040588;
			break;
		case 2:
			武器代码 = 101000860;
			break;
		case 3:
			武器代码 = 101000861;
			break;
		case 4:
			武器代码 = 101011025;
			break;
		case 5:
			武器代码 = 101011026;
			break;
		case 6:
			武器代码 = 101030890;
			break;
		case 7:
			武器代码 = 101030891;
			break;
		case 8:
			武器代码 = 101020806;
			break;
		case 9:
			武器代码 = 101020807;
			break;
		}

		break;
	case 1:									//魔法师
		switch (选中武器)
		{
		case 0:
			武器代码 = 106030707;
			break;
		case 1:
			武器代码 = 106030708;
			break;
		case 2:
			武器代码 = 106020675;
			break;
		case 3:
			武器代码 = 106020676;
			break;
		case 4:
			武器代码 = 106010631;
			break;
		case 5:
			武器代码 = 106010632;
			break;
		case 6:
			武器代码 = 106000606;
			break;
		case 7:
			武器代码 = 106000607;
			break;
		case 8:
			武器代码 = 106040579;
			break;
		case 9:
			武器代码 = 106040580;
			break;
		}
		break;
	case 2:									//神枪手
		switch (选中武器)
		{
		case 0:
			武器代码 = 104030639;
			break;
		case 1:
			武器代码 = 104030640;
			break;
		case 2:
			武器代码 = 104000656;
			break;
		case 3:
			武器代码 = 104000657;
			break;
		case 4:
			武器代码 = 104020626;
			break;
		case 5:
			武器代码 = 104020627;
			break;
		case 6:
			武器代码 = 104040650;
			break;
		case 7:
			武器代码 = 104040651;
			break;
		case 8:
			武器代码 = 104010639;
			break;
		case 9:
			武器代码 = 104010640;
			break;
		}
		break;
	case 3:										//魔枪士
		switch (选中武器)
		{
		case 0:
			武器代码 = 114010285;
			break;
		case 1:
			武器代码 = 114010286;
			break;
		case 2:
			武器代码 = 114000304;
			break;
		case 3:
			武器代码 = 114000305;
			break;
		case 4:
			武器代码 = 114020187;
			break;
		case 5:
			武器代码 = 114020188;
			break;
		case 6:
			武器代码 = 114030187;
			break;
		case 7:
			武器代码 = 114030188;
			break;
		}
		break;
	case 4:										//格斗家
		switch (选中武器)
		{
		case 0:
			武器代码 = 102000626;
			break;
		case 1:
			武器代码 = 102000627;
			break;
		case 2:
			武器代码 = 102030575;
			break;
		case 3:
			武器代码 = 102030576;
			break;
		case 4:
			武器代码 = 102010681;
			break;
		case 5:
			武器代码 = 102010682;
			break;
		case 6:
			武器代码 = 102040638;
			break;
		case 7:
			武器代码 = 102040639;
			break;
		case 8:
			武器代码 = 102020583;
			break;
		case 9:
			武器代码 = 102020584;
			break;
		}
		break;
	case 5:										//枪剑士
		switch (选中武器)
		{
		case 0:
			武器代码 = 116000206;
			break;
		case 1:
			武器代码 = 116000207;
			break;
		case 2:
			武器代码 = 116020182;
			break;
		case 3:
			武器代码 = 116020183;
			break;
		case 4:
			武器代码 = 116010180;
			break;
		case 5:
			武器代码 = 116010181;
			break;
		case 6:
			武器代码 = 116030220;
			break;
		case 7:
			武器代码 = 116030221;
			break;
		}
		break;
	case 6:										//圣职者
		switch (选中武器)
		{
		case 0:
			武器代码 = 108040562;
			break;
		case 1:
			武器代码 = 108040563;
			break;
		case 2:
			武器代码 = 108000599;
			break;
		case 3:
			武器代码 = 108000600;
			break;
		case 4:
			武器代码 = 108010588;
			break;
		case 5:
			武器代码 = 108010589;
			break;
		case 6:
			武器代码 = 108020498;
			break;
		case 7:
			武器代码 = 108020499;
			break;
		case 8:
			武器代码 = 108030612;
			break;
		case 9:
			武器代码 = 108030613;
			break;
		}
		break;
	case 7:											//暗夜使者
		switch (选中武器)
		{
		case 0:
			武器代码 = 109000565;
			break;
		case 1:
			武器代码 = 109000566;
			break;
		case 2:
			武器代码 = 109010517;
			break;
		case 3:
			武器代码 = 109010518;
			break;
		case 4:
			武器代码 = 109030492;
			break;
		case 5:
			武器代码 = 109030493;
			break;
		case 6:
			武器代码 = 109040373;
			break;
		case 7:
			武器代码 = 109040374;
			break;
		}
		break;
	}
}


void CDia1::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int state1, state2;
	//神话公告("开始换装", 0);
	装备数据 = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	换装call(人物基址, 100070719, 14);  //' 上衣
	//神话公告("换装上衣", 0);
	换装call(人物基址, 100170667, 15); // ' 头肩
	换装call(人物基址, 100120696, 16);  //' 下装
	换装call(人物基址, 100270668, 17);  //' 鞋子
	换装call(人物基址, 100220667, 18); // ' 腰带
	CButton* ptn1 = (CButton*)GetDlgItem(IDC_CHECK1);
	CButton* ptn2 = (CButton*)GetDlgItem(IDC_CHECK2);
	state1 = ptn1->GetCheck();
	state2 = ptn2->GetCheck();
	if (state1 == 1) 
	{
		换装call(人物基址, 100301126, 19);  //' 项链
		神话公告("换装项链", 0);
		换装call(人物基址, 100322715, 21);  //' 戒指
		换装call(人物基址, 100312844, 20); // ' 手镯
		换装call(人物基址, 400330106, 13); // ' 称号
	}
	if (state2 == 1) 
	{
		换装call(人物基址, 100345240, 22);  //' 辅助装备
		神话公告("换装辅助装备", 0);
		换装call(人物基址, 100353401, 23);  //' 魔法石
		换装call(人物基址, 100390336, 26); // ' 耳环
	}
	换装call(人物基址, 武器代码, 12);  //武器
	神话公告("换装武器", 0);
	装备数据.push_back(0x48);
	装备数据.push_back(0x81);
	装备数据.push_back(0xC4);
	装备数据.push_back(0x50);
	装备数据.push_back(0x01);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xC3);
	神话公告("开始汇编", 0);
	内存汇编x64(装备数据);
	//装备数据.clear();
	超级延时(3000);
	vector<byte>().swap(装备数据);
	神话公告("清空汇编数据", 0);
	无视等级();

	神话公告("换装成功!",0);
}


void CDia1::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int state1, state2;
	装备数据 = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	换装call(人物基址, 100050898, 14);  //' 上衣
	换装call(人物基址, 100150762, 15); // ' 头肩
	换装call(人物基址, 100100792, 16);  //' 下装
	换装call(人物基址, 100250754, 17);  //' 鞋子
	换装call(人物基址, 100200736, 18); // ' 腰带
	CButton* ptn1 = (CButton*)GetDlgItem(IDC_CHECK1);
	CButton* ptn2 = (CButton*)GetDlgItem(IDC_CHECK2);
	state1 = ptn1->GetCheck();
	state2 = ptn2->GetCheck();
	if (state1 == 1)
	{
		换装call(人物基址, 100301126, 19);  //' 项链
		换装call(人物基址, 100322715, 21);  //' 戒指
		换装call(人物基址, 100312844, 20); // ' 手镯
		换装call(人物基址, 400330106, 13); // ' 称号
	}
	if (state2 == 1)
	{
		换装call(人物基址, 100345240, 22);  //' 辅助装备
		换装call(人物基址, 100353401, 23);  //' 魔法石
		换装call(人物基址, 100390336, 26); // ' 耳环
	}
	换装call(人物基址, 武器代码, 12);  //武器
	装备数据.push_back(0x48);
	装备数据.push_back(0x81);
	装备数据.push_back(0xC4);
	装备数据.push_back(0x50);
	装备数据.push_back(0x01);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xC3);
	内存汇编x64(装备数据);
	超级延时(3000);
	vector<byte>().swap(装备数据);
	//装备数据.clear();
	//vector<byte>().swap(装备数据); 
	无视等级();
	神话公告("换装成功!", 0);
}


void CDia1::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	int state1, state2;
	装备数据 = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	换装call(人物基址, 100080743, 14);  //' 上衣
	换装call(人物基址, 100180673, 15); // ' 头肩
	换装call(人物基址, 100130709, 16);  //' 下装
	换装call(人物基址, 100280672, 17);  //' 鞋子
	换装call(人物基址, 100230676, 18); // ' 腰带
	CButton* ptn1 = (CButton*)GetDlgItem(IDC_CHECK1);
	CButton* ptn2 = (CButton*)GetDlgItem(IDC_CHECK2);
	state1 = ptn1->GetCheck();
	state2 = ptn2->GetCheck();
	if (state1 == 1)
	{
		换装call(人物基址, 100301126, 19);  //' 项链
		换装call(人物基址, 100322715, 21);  //' 戒指
		换装call(人物基址, 100312844, 20); // ' 手镯
		换装call(人物基址, 400330106, 13); // ' 称号
	}
	if (state2 == 1)
	{
		换装call(人物基址, 100345240, 22);  //' 辅助装备
		换装call(人物基址, 100353401, 23);  //' 魔法石
		换装call(人物基址, 100390336, 26); // ' 耳环
	}
	换装call(人物基址, 武器代码, 12);  //武器
	装备数据.push_back(0x48);
	装备数据.push_back(0x81);
	装备数据.push_back(0xC4);
	装备数据.push_back(0x50);
	装备数据.push_back(0x01);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xC3);
	内存汇编x64(装备数据);	
	//装备数据.clear();
	超级延时(3000);
	vector<byte>().swap(装备数据);
	无视等级();
	神话公告("换装成功!", 0);
}


void CDia1::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	int state1, state2;
	装备数据 = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	换装call(人物基址, 100090549, 14);  //' 上衣
	换装call(人物基址, 100190496, 15); // ' 头肩
	换装call(人物基址, 100140529, 16);  //' 下装
	换装call(人物基址, 100290520, 17);  //' 鞋子
	换装call(人物基址, 100240503, 18); // ' 腰带
	CButton* ptn1 = (CButton*)GetDlgItem(IDC_CHECK1);
	CButton* ptn2 = (CButton*)GetDlgItem(IDC_CHECK2);
	state1 = ptn1->GetCheck();
	state2 = ptn2->GetCheck();
	if (state1 == 1)
	{
		换装call(人物基址, 100301126, 19);  //' 项链
		换装call(人物基址, 100322715, 21);  //' 戒指
		换装call(人物基址, 100312844, 20); // ' 手镯
		换装call(人物基址, 400330106, 13); // ' 称号
	}
	if (state2 == 1)
	{
		换装call(人物基址, 100345240, 22);  //' 辅助装备
		换装call(人物基址, 100353401, 23);  //' 魔法石
		换装call(人物基址, 100390336, 26); // ' 耳环
	}
	换装call(人物基址, 武器代码, 12);  //武器
	装备数据.push_back(0x48);
	装备数据.push_back(0x81);
	装备数据.push_back(0xC4);
	装备数据.push_back(0x50);
	装备数据.push_back(0x01);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xC3);
	内存汇编x64(装备数据);
	//装备数据.clear();
	超级延时(3000);
	vector<byte>().swap(装备数据);
	无视等级();
	神话公告("换装成功!", 0);
}


void CDia1::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码

	int state1, state2;
	装备数据 = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	换装call(人物基址, 100060773, 14);  //' 上衣
	换装call(人物基址, 100160681, 15); // ' 头肩
	换装call(人物基址, 100110745, 16);  //' 下装
	换装call(人物基址, 100260725, 17);  //' 鞋子
	换装call(人物基址, 100210705, 18); // ' 腰带
	CButton* ptn1 = (CButton*)GetDlgItem(IDC_CHECK1);
	CButton* ptn2 = (CButton*)GetDlgItem(IDC_CHECK2);
	state1 = ptn1->GetCheck();
	state2 = ptn2->GetCheck();
	if (state1 == 1)
	{
		换装call(人物基址, 100301126, 19);  //' 项链
		换装call(人物基址, 100322715, 21);  //' 戒指
		换装call(人物基址, 100312844, 20); // ' 手镯
		换装call(人物基址, 400330106, 13); // ' 称号
	}
	if (state2 == 1)
	{
		换装call(人物基址, 100345240, 22);  //' 辅助装备
		换装call(人物基址, 100353401, 23);  //' 魔法石
		换装call(人物基址, 100390336, 26); // ' 耳环
	}
	换装call(人物基址, 武器代码, 12);  //武器
	装备数据.push_back(0x48);
	装备数据.push_back(0x81);
	装备数据.push_back(0xC4);
	装备数据.push_back(0x50);
	装备数据.push_back(0x01);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xC3);
	内存汇编x64(装备数据);
	//装备数据.clear();
	超级延时(3000);
	vector<byte>().swap(装备数据);
	无视等级();
	神话公告("换装成功!", 0);
}


void CDia1::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	改药();
}




//void CDia1::OnBnClickedButton11()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)砍全屏, NULL, 0, NULL);
//}

//
//void CDia1::OnBnClickedButton12()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)一刀秒, NULL, 0, NULL);
//}


void CDia1::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	缓冲Call(160);
	加密Call(2, 4);
	发包Call();

}


void CDia1::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)清理DNF, NULL, 0, NULL);
}


void CDia1::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	三速负重耐久();
}


void CDia1::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	static bool 开关;
	if (开关==false)
	{
		写内存字节集(进程ID, 换装校验, { 15,133 });
	}
	else
	{
		写内存字节集(进程ID, 换装校验, { 15,132 });
	}

}


void CDia1::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	INT64 冒险团指针 = 读内存长整数型(进程ID, 冒险团基址);
	写内存整数型(进程ID, 冒险团指针 + 冒险团属性体力, 0);
	写内存整数型(进程ID, 冒险团指针 + 冒险团属性回避率, 100*10);
	写内存整数型(进程ID, 冒险团指针 + 冒险团属性暴击率, 100*10);
	写内存整数型(进程ID, 冒险团指针 + 冒险团属性攻击速度, 0);
}
