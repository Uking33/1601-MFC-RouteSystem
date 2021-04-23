// WayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "WayDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <windows.h>

/////////////////////////////////////////////////////////////////////////////
// CWayDlg dialog

CWayDlg::CWayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWayDlg)
	m_choose1 = 0;
	m_choose2 = 0;
	//}}AFX_DATA_INIT
}


void CWayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWayDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Radio(pDX, IDC_RADIO4, m_choose1);
	DDX_Radio(pDX, IDC_RADIO1, m_choose2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWayDlg, CDialog)
	//{{AFX_MSG_MAP(CWayDlg)
	ON_BN_CLICKED(IDC_BTN_LAST, OnBtnLast)
	ON_BN_CLICKED(IDC_BTN_NEXT, OnBtnNext)
	ON_BN_CLICKED(IDC_BTN_FIND, OnBtnFind)
	ON_WM_TIMER()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWayDlg message handlers
void CWayDlg::Loading(Data *data)
{
	m_data=data;
}

BOOL CWayDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int i;
	//页数
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	if(m_data->GetWayNum()>9)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	else		
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);
	m_page=1;
	//网格
	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;
    dwStyle |= LVS_EX_GRIDLINES;                
    m_list.SetExtendedStyle(dwStyle);   
    //表头
	m_list.InsertColumn(1,"换乘次数",LVCFMT_CENTER,80,-1);
	m_list.InsertColumn(2,"费用",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(3,"距离",LVCFMT_CENTER,80,-1);
	m_list.InsertColumn(4,"耗时",LVCFMT_CENTER,80,-1);
	m_list.InsertColumn(5,"路线",LVCFMT_CENTER,340,-1);
	//站点
	for(i=0;i<m_data->GetStateNum();i++){
		CString str(m_data->m_state.GetfromLinkList(i+1)->name);
		((CComboBox*)GetDlgItem(IDC_COMBO_START))->InsertString(i,str);
		((CComboBox*)GetDlgItem(IDC_COMBO_END))->InsertString(i,str);
	}
	//读数据
	UpdateData(true);
	Find();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWayDlg::OnBtnLast() 
{
	// TODO: Add your control notification handler code here
		m_page--;
	if(m_page==1)
		GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	Find();
}

void CWayDlg::OnBtnNext() 
{
	// TODO: Add your control notification handler code here
	m_page++;
	if(m_page==(int)(m_data->GetWayNum()/9)+1)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);	
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(TRUE);
	Find();
}
void CWayDlg::OnBtnFind() 
{
	m_time=0;
	SetTimer(1,100,NULL);
}
void CWayDlg::Find() 
{
	char str[2000];
	int i,n;
	n=m_page*9>m_data->GetWayNum() ? m_data->GetWayNum():m_page*9;
	m_list.DeleteAllItems();

	for(i=0+(m_page-1)*9;i<n;i++){
		m_data->FindWay(i+1,"换乘次数",str);
		m_list.InsertItem(i-(m_page-1)*9,str);
		m_data->FindWay(i+1,"费用",str);
		m_list.SetItemText(i-(m_page-1)*9,1,str);
		m_data->FindWay(i+1,"距离",str);
		m_list.SetItemText(i-(m_page-1)*9,2,str);
		m_data->FindWay(i+1,"耗时",str);
		m_list.SetItemText(i-(m_page-1)*9,3,str);
		m_data->FindWay(i+1,"路线",str);
		m_list.SetItemText(i-(m_page-1)*9,4,str);
	}
}

void CWayDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_time++;
	switch(m_time){
		case 1:
			int start;
			int end;
			start=((CComboBox*)GetDlgItem(IDC_COMBO_START))->GetCurSel();
			end=((CComboBox*)GetDlgItem(IDC_COMBO_END))->GetCurSel();
			if(!(m_data->FindWayBegin(m_data->m_state.GetfromLinkList(start+1)->name,m_data->m_state.GetfromLinkList(end+1)->name)))
				MessageBox("请输入正确的站点","提示");
			break;
		case 2:
			UpdateData();
			m_data->line->LineSort(m_choose1,m_choose2);
			break;
		case 3:
			if(m_data->GetWayNum()>9)
				GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
			else		
				GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);
			//初始化页数
			GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
			if(m_data->GetWayNum()>9)
				GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
			else		
				GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);
			m_page=1;
			Find();
			KillTimer(1);
			break;
		}
	CDialog::OnTimer(nIDEvent);
}


void CWayDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) //双击
{
	// TODO: Add your control notification handler code here
	DWORD dwPos = GetMessagePos();  
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );  
	m_list.ScreenToClient(&point);    
	 //定义结构体   
	LVHITTESTINFO lvinfo;  
	lvinfo.pt = point;    
	 //获取行号信息   
	int index = m_list.HitTest(&lvinfo);  	
	if(index!=-1)
		MessageBox(m_list.GetItemText(index,4),"路线");
	*pResult = 0;
}
