// StateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "StateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStateDlg dialog


CStateDlg::CStateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStateDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStateDlg, CDialog)
	//{{AFX_MSG_MAP(CStateDlg)
	ON_BN_CLICKED(IDC_BTN_LAST, OnBtnLast)
	ON_BN_CLICKED(IDC_BTN_NEXT, OnBtnNext)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStateDlg message handlers

void CStateDlg::Loading(Data *data)
{
	m_data=data;
}


BOOL CStateDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	//ҳ��
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	if(m_data->GetStateNum()>10)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	else		
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);
	m_page=1;
	//����
	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;
    dwStyle |= LVS_EX_GRIDLINES;                
    m_list.SetExtendedStyle(dwStyle);   
    //��ͷ
	m_list.InsertColumn(1,"��վ",LVCFMT_CENTER,120,-1);
	m_list.InsertColumn(2,"������·��",LVCFMT_CENTER,80,-1);
	m_list.InsertColumn(3,"������·",LVCFMT_CENTER,950,-1);
	//������
	Find();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStateDlg::Find() 
{
	char str[2000];
	int i,n;
	n=m_page*10>m_data->GetStateNum() ? m_data->GetStateNum():m_page*10;
	m_list.DeleteAllItems();
	for(i=0+(m_page-1)*10;i<n;i++){
		m_data->FindState(i,"��վ",str);
		m_list.InsertItem(i-(m_page-1)*10,str);
		m_data->FindState(i,"������·��",str);
		m_list.SetItemText(i-(m_page-1)*10,1,str);
		m_data->FindState(i,"������·",str);
		m_list.SetItemText(i-(m_page-1)*10,2,str);
	}
}


void CStateDlg::OnBtnLast() 
{
	// TODO: Add your control notification handler code here
	m_page--;
	if(m_page==1)
		GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	Find();
}

void CStateDlg::OnBtnNext() 
{
	// TODO: Add your control notification handler code here	
	m_page++;
	if(m_page==(int)(m_data->GetStateNum()/10)+1)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);	
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(TRUE);
	Find();
}

void CStateDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here	
	DWORD dwPos = GetMessagePos();  
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );  
	m_list.ScreenToClient(&point);    
	 //����ṹ��   
	LVHITTESTINFO lvinfo;  
	lvinfo.pt = point;    
	 //��ȡ�к���Ϣ   
	int index = m_list.HitTest(&lvinfo);  
	if(index!=-1)
		MessageBox(m_list.GetItemText(index,2),"������·");
	*pResult = 0;
}
