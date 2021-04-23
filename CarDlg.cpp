// CarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "CarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarDlg dialog


CCarDlg::CCarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCarDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCarDlg, CDialog)
	//{{AFX_MSG_MAP(CCarDlg)
	ON_BN_CLICKED(IDC_BTN_LAST, OnBtnLast)
	ON_BN_CLICKED(IDC_BTN_NEXT, OnBtnNext)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarDlg message handlers

void CCarDlg::Loading(Data *data)
{
	m_data=data;
}

BOOL CCarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	//ҳ��
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	if(m_data->GetCarNum()>10)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	else		
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);
	m_carPage=1;
	//����
	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;
    dwStyle |= LVS_EX_GRIDLINES;                
    m_list.SetExtendedStyle(dwStyle);   
    //��ͷ
	m_list.InsertColumn(1,"����",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(2,"����",LVCFMT_CENTER,100,-1);
	m_list.InsertColumn(3,"����ʱ��",LVCFMT_CENTER,100,-1);
	m_list.InsertColumn(4,"˫��",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(5,"�շ�",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(6,"��վ",LVCFMT_CENTER,800,-1);
	//������
	Find();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CCarDlg::OnBtnLast() 
{
	// TODO: Add your control notification handler code here
	m_carPage--;
	if(m_carPage==1)
		GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	Find();
}

void CCarDlg::OnBtnNext() 
{
	// TODO: Add your control notification handler code here
	
	// TODO: Add your control notification handler code here
	m_carPage++;
	if(m_carPage==(int)(m_data->GetCarNum()/10)+1)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);	
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(TRUE);
	Find();
}

void CCarDlg::Find() 
{
	char str[2000];
	int i,n;
	n=m_carPage*10>m_data->GetCarNum() ? m_data->GetCarNum():m_carPage*10;
	m_list.DeleteAllItems();
	for(i=0+(m_carPage-1)*10;i<n;i++){
		m_data->FindCar(i,"����",str);
		m_list.InsertItem(i-(m_carPage-1)*10,str);
		m_data->FindCar(i,"����",str);
		m_list.SetItemText(i-(m_carPage-1)*10,1,str);
		m_data->FindCar(i,"����ʱ��",str);
		m_list.SetItemText(i-(m_carPage-1)*10,2,str);
		m_data->FindCar(i,"˫��",str);
		m_list.SetItemText(i-(m_carPage-1)*10,3,str);
		m_data->FindCar(i,"�շ�",str);
		m_list.SetItemText(i-(m_carPage-1)*10,4,str);
		m_data->FindCar(i,"��վ",str);
		m_list.SetItemText(i-(m_carPage-1)*10,5,str);
	}
}

void CCarDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
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
		MessageBox(m_list.GetItemText(index,5),"��վ");
	*pResult = 0;
}
