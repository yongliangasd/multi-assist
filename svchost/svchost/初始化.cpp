#include "��ʼ��.h"
#include "pch.h"







void �Ƶ����() 
{
	

	�Դ��ھ�� = AfxGetApp()->GetMainWnd()->GetSafeHwnd();
	int ��Ļ�߶� = GetSystemMetrics(SM_CYFULLSCREEN);
	int ���ڸ߶� = rs.Height();
	�ı䴰��λ��(0, (��Ļ�߶� - ���ڸ߶�) / 2);
	������дȨ��();
	//�ü������ı�("��˹������м������500��Ŧ����.");
	//MessageBoxA(�Դ��ھ��, ȡ����Ŀ¼(10), "DNF", 0);
	//ȡ����Ŀ¼(1);
	//ǿ��ɾ���ļ�(ȡִ���ļ���());
	//MessageBoxA(�Դ��ھ��, ���ı�((INT64)(int)(�����ַ)),"DNF",0);
	//PASS��̬((int)�����ַ, 8);
	//���Ժ���("QQPCTray.exe");

}

void ��ͼ����() 
{	
	CFont ft;
	m_Dia1.m_tree.SetFont(&ft);
	m_Dia1.m_tree.SetItemHeight(25);
	hRoot = m_Dia1.m_tree.InsertItem(_T("------1-100����-----"));
	hRoot1 = m_Dia1.m_tree.InsertItem(_T("------��ȥ----------"));
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����֮ɭ------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 1);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------���֮��------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 2);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��᡾���------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 3);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��������------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 4);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------ŵ������------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 5);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------˹��ѩ��------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 6);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------ŵ˹���------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 7);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��ŵ��ɭ��----"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 8);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����֮��------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 9);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�����ٲ�------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 10);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------���ر�³Ͽ�� -"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 11);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�����г�------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 12);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------ʱ��֮��------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 13);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����վ--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 14);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�ž���--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 15);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------ħ��Ӫ��------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 16);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------���빫԰------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 17);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����----------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 18);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------������--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 19);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�ɸ��ػʹ�----"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 20);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�籩��·------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 21);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����˹��ɽ----"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 22);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------ڤ��ʱ��------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 23);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����ɽ--------"), hRoot);
	m_Dia1.m_tree.SetItemData(hArtItem, 24);
	///////////////////////////////////////////////////////////////////////////
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�����Ƿ���----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 100);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����Ͽ��------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 101);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�ն����------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 102);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��ְҵ�Ǳ���--"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 103);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��̫������----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 104);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------ʱ��ʯ����----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 105);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��������------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 106);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�ڹ긱��------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 107);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------¬�˸���------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 108);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��ͨ��ʱ��------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 109);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------̩����˹------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 110);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��ɫĹ��------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 111);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����----------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 112);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����----------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 113);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����ɽ--------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 114);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------���п�ʼ�ط�--"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 115);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------�籩��·------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 116);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����˹��ɽ----"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 117);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------��ѻ֮��------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 118);
	hArtItem = m_Dia1.m_tree.InsertItem(_T("------����ÿ��------"), hRoot1);
	m_Dia1.m_tree.SetItemData(hArtItem, 119);
	չ��(hRoot1);
	
}


void ע���ȼ�() 
{
	RegisterHotKey(�Դ��ھ��, 1, 0, VK_F1);//&_��������_������
	RegisterHotKey(�Դ��ھ��, 2, 0, VK_F2);//&��Ѫ����
	RegisterHotKey(�Դ��ھ��, 3, 0, VK_F3);//&��ҩ
	RegisterHotKey(�Դ��ھ��, 4, 0, VK_F4);//&�����޵�
	RegisterHotKey(�Դ��ھ��, 5, 0, VK_F5);//&��ͼ����1
	RegisterHotKey(�Դ��ھ��, 6, 0, VK_F6);//&����Ȩ��
	RegisterHotKey(�Դ��ھ��, 7, 0, VK_F7);//&���Ӷ���
	RegisterHotKey(�Դ��ھ��, 8, 0, VK_TAB);//&��������
	RegisterHotKey(�Դ��ھ��, 9, MOD_SHIFT, VK_F1);//&�ٻ�����
	RegisterHotKey(�Դ��ھ��, 10, MOD_SHIFT, 0x31);//&ʹ����Ʒ
	RegisterHotKey(�Դ��ھ��, 11, MOD_SHIFT, VK_F3);//&���ұ��
	RegisterHotKey(�Դ��ھ��, 12, 0, VK_HOME);//&����װ���߳�
	RegisterHotKey(�Դ��ھ��, 13, 0, VK_END);//&�λ�װ��
	RegisterHotKey(�Դ��ھ��, 14, 0, 0x56);//&ȫ������
	RegisterHotKey(�Դ��ھ��, 15, 0, VK_OEM_3);//&�ͷż���
	RegisterHotKey(�Դ��ھ��, 16, MOD_ALT, 0x31);//&����
	RegisterHotKey(�Դ��ھ��, 17, MOD_ALT, VK_LEFT);//&˳ͼ_��
	RegisterHotKey(�Դ��ھ��, 18, MOD_ALT, VK_UP);//&˳ͼ_��
	RegisterHotKey(�Դ��ھ��, 19, MOD_ALT, VK_RIGHT);//&˳ͼ_��
	RegisterHotKey(�Դ��ھ��, 20, MOD_ALT, VK_DOWN);//&˳ͼ_��
	//RegisterHotKey(�Դ��ھ��, 22, 0, VK_OEM_3);

}


void ��������() 
{
	LONG lStyle;

	lStyle = GetWindowLong(m_Dia2.m_list.m_hWnd, GWL_STYLE);// ��ȡ��ǰ����style

	lStyle &= ~LVS_TYPEMASK;// �����ʾ��ʽλ

	lStyle |= LVS_REPORT;// ����style

	SetWindowLong(m_Dia2.m_list.m_hWnd, GWL_STYLE, lStyle);// ����style

	DWORD dwStyle = m_Dia2.m_list.GetExtendedStyle();

	dwStyle |= LVS_EX_FULLROWSELECT;// ѡ��ĳ��ʹ���и�����ֻ������report ����ListControl �� 

	dwStyle |= LVS_EX_GRIDLINES;// �����ߣ�ֻ������report ����ListControl �� 

	//dwStyle |= LVS_EX_CHECKBOXES;//Itemǰ����checkbox �ؼ� 
	m_Dia2.m_list.SetExtendedStyle(dwStyle); // ������չ��� 

	CImageList   m_l;
	m_l.Create(1, 22, TRUE | ILC_COLOR32, 1, 0);
	m_Dia2.m_list.SetImageList(&m_l, LVSIL_SMALL);

	LOGFONT   logfont;//���Ū�����Ա,ȫ�ֱ���,��̬��Ա  
	CFont* pfont1 = m_Dia2.m_list.GetFont();
	pfont1->GetLogFont(&logfont);
	 logfont.lfHeight = logfont.lfHeight * 3/2;   //��������޸�����ĸ߱���
	logfont.lfWidth = logfont.lfWidth *3/2;   //��������޸�����Ŀ����
	static   CFont   font1;
	font1.CreateFontIndirect(&logfont);
	m_Dia2.m_list.SetFont(&font1);
	font1.Detach();


	m_Dia2.m_list.InsertColumn(0,"��������(˫���������)", LVCFMT_LEFT,270);
	m_Dia2.m_list.InsertColumn(1, "����ID", LVCFMT_LEFT, 120);



	//int nRow;
	//nRow = m_Dia2.m_list.InsertItem(0, "11");// ������
	//m_Dia2.m_list.SetItemText(nRow, 1, "jacky");// ��������������
	//
	//nRow = m_Dia2.m_list.InsertItem(0, "qw424523");// ������
	//m_Dia2.m_list.SetItemText(nRow, 1, "wt74456");// ��������������




}

void �����ͼ() 
{
	DWORD dwStyle = m_Dia3.m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;// ѡ��ĳ��ʹ���и�����ֻ������report ����ListControl �� 
	dwStyle |= LVS_EX_GRIDLINES;// �����ߣ�ֻ������report ����ListControl �� 
	m_Dia3.m_list.SetExtendedStyle(dwStyle); // ������չ��� 

	CImageList   m_l;
	m_l.Create(1, 18, TRUE | ILC_COLOR32, 1, 0);
	m_Dia3.m_list.SetImageList(&m_l, LVSIL_SMALL);

	m_Dia3.m_list.InsertColumn(0, "��ַ", LVCFMT_LEFT, 80);
	m_Dia3.m_list.InsertColumn(1, "����", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(2, "��Ӫ", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(3, "X��", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(4, "Y��", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(5, "Z��", LVCFMT_LEFT, 60);
	m_Dia3.m_list.InsertColumn(6, "����(�Ҽ�����)", LVCFMT_LEFT, 110);
	m_Dia3.m_list.InsertColumn(7, "����", LVCFMT_LEFT, 170);

	//int nRow;
	//nRow = m_Dia3.m_list.InsertItem(0, "FFFFFFFFF");// ������
	//m_Dia3.m_list.SetItemText(nRow, 1, "60000");// ��������������
	//m_Dia3.m_list.SetItemText(nRow, 2, "60000");// ��������������
	//m_Dia3.m_list.SetItemText(nRow, 3, "60000");// ��������������
	//m_Dia3.m_list.SetItemText(nRow, 4, "60000");// ��������������
	//m_Dia3.m_list.SetItemText(nRow, 5, "60000");// ��������������
	//m_Dia3.m_list.SetItemText(nRow, 6, "1070009035");// ��������������
	//m_Dia3.m_list.SetItemText(nRow, 7, "��������������");// ��������������

}


void ��ӱ༭������() 
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


	//��ʼ����ť״̬
	((CButton*)m_Dia1.GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);
	((CButton*)m_Dia1.GetDlgItem(IDC_CHECK4))->SetCheck(BST_CHECKED);
	((CButton*)m_Dia2.GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);	
}


void ʹ����Ʒ()
{
	CButton* ptn;
	CString str;
	int ��Ʒ����,state;
	��Ʒ���� = m_Dia1.GetDlgItemInt(WUPIN, NULL, TRUE);
	��ƷCall(��Ʒ����);
	 ptn = (CButton*)m_Dia1.GetDlgItem(ZIZENG);
	state = ptn->GetCheck();
	if (state == 1) 
	{
		//��Ʒ���� = _ttoi(str);
		��Ʒ���� += 1;
		str.Format("%d", ��Ʒ����);
		m_Dia1.GetDlgItem(WUPIN)->SetWindowTextA(str);	
	}	
}

void ����װ��()
{
	INT64 װ��ָ��,װ������;
	CString װ������;
	TCHAR װ��·��[1024];
	TCHAR *װ���ļ� = _T("\\װ������.txt");
	CString str;
	str.Format("%d", װ���ļ�);
	//��ȡ��ǰ�û�������·��
	SHGetSpecialFolderPath(0, װ��·��, CSIDL_DESKTOPDIRECTORY, 0);
	INT64 len1 = lstrlen(str);
	INT64 lpath = lstrlen(װ��·��);
	TCHAR* strn = new TCHAR[lpath + len1 + 1];
	strn[0] = _T('\0');
	lstrcat(strn, װ��·��);
	lstrcat(strn, str);
	fstream fp(strn, ios::app | ios::out);

	װ��ָ�� = ���ڴ泤������(����ID, ����ַ);
	װ������ = ���ڴ泤������(����ID, װ��ָ�� + 48);
	str.Format("%d", װ������);
	m_Dia4.GetDlgItem(ZHUANGBEIDAIMA)->SetWindowTextA(str);
	װ������ = ת��UnicodeתAnsi(���ڴ��ֽڼ�(����ID, ���ڴ泤������(����ID, װ��ָ�� + 56), 52));

	str.AppendFormat("%d", "        ");
	str.AppendFormat("%d", װ������);
	str.AppendFormat("%d", "\n");
	fp << str;
	fp.close();
}

void ����װ���߳�() 
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)����װ��, NULL, 0,NULL);
}

void �ͷż���()
{
	int state,���ܴ�С;
	CString str;
	INT64 һ��ƫ��;
	������ ��������;
	һ��ƫ�� = ���ڴ泤������(����ID, �����ַ);
	m_Dia1.GetDlgItem(JINENGDAIMA)->GetWindowTextA(str);
	ȫ������ = _atoi64(str);
	m_Dia1.GetDlgItem(JINENGSHANGHAI)->GetWindowTextA(str);
	ȫ���˺� = _atoi64(str);
	m_Dia1.GetDlgItem(JINENGDAXIAO)->GetWindowTextA(str);
	���ܴ�С = atoi(str);
	�������� = ������(һ��ƫ��);
	CButton* ptn = (CButton*)m_Dia1.GetDlgItem(IDC_CHECK4);
	state = ptn->GetCheck();
	if (state ==1)
	{
		�ͷ�call(һ��ƫ��, ȫ������, ȫ���˺�, ��������.x, ��������.y, ��������.z);
	}
	else
	{
		����Call(һ��ƫ��, ȫ������, ȫ���˺�, ��������.x, ��������.y, ��������.z, ���ܴ�С);
	}
}

void �λ�װ��()
{
	INT64 ��װָ��,��װ����;
	CString str;
	m_Dia4.GetDlgItem(ZHUANGBEIDAIMA)->GetWindowTextA(str);
	��װ���� = _atoi64(str);
	��װָ�� = �����ַ;	
	װ������ = { 0x48,0x81,0xEC,0x50,0x01,0x00,0x00 };
	��װcall(��װָ��, ��װ����, ȫ��_װ����λ);
	װ������.push_back(0x48);
	װ������.push_back(0x81);
	װ������.push_back(0xC4);
	װ������.push_back(0x50);
	װ������.push_back(0x01);
	װ������.push_back(0x00);
	װ������.push_back(0x00);
	װ������.push_back(0xC3);
	�ڴ���x64(װ������);
	vector<byte>().swap(װ������);
	���ӵȼ�();
	�񻰹���("��װ�ɹ�!", 1);
}

void ���ڻ�ȡ����()
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ȡDNF����, NULL, 0, NULL);
}

void ȡDNF����()
{
	int i=0;
	SetWindowTextA(�Դ��ھ��, "����: ���ڻ�ȡ����...");
	while ((����ID = ȡ����ID("DNF.exe")) == 0)
	{
		i += 1;
		������ʱ(500);
		if (i > 15)
		{
			SetWindowTextA(�Դ��ھ��, "����: ���̻�ȡʧ��!");
			return ;
		}		
	}
	����ID = ȡ����ID("DNF.exe");
	DWORD s1 = ����ID;
	CString str1("����: ���̻�ȡ�ɹ�,����ID:");
	CString str2;
	str2.Format("%u", s1);
	str1 += str2;	
	SetWindowTextA(�Դ��ھ��, + (LPCSTR)(LPCTSTR)str1);
	//MessageBoxA(�Դ��ھ��,(LPCSTR)(LPCTSTR)str1  ,"DNF:",0);
	//д�ڴ泤������(����ID, 0x140001000, 0);
	//д�ڴ�������(����ID, 0x140001002, 1);
	//д�ڴ��������(����ID, 0x140001004, 2);
	//д�ڴ�С����(����ID, 0x140001006, 3.0);
	//д�ڴ��ֽڼ�(����ID, 0x140001008, {4});
	�հ�ȫ�� =ȫ�ֿհ�;

	/*�񻰹���("���Թ���0", 0);
	�񻰹���("���Թ���1", 1);
	�񻰹���("���Թ���2", 2);
	�񻰹���("���Թ���3", 3);*/

}
