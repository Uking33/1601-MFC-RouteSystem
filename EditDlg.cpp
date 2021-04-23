// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "EditOneDlg.h"
#include "PasswordDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog


CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	ON_BN_CLICKED(IDC_BTN_LAST, OnBtnLast)
	ON_BN_CLICKED(IDC_BTN_NEXT, OnBtnNext)
	ON_BN_CLICKED(IDC_BTN_PASSWORD, OnBtnPassword)
	ON_BN_CLICKED(IDC_BTN_EDIT, OnBtnEdit)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers

void CEditDlg::Loading(Data *data)
{
	m_data=data;
}

BOOL CEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	//页数
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	if(m_data->GetCarNum()>10)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	else		
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);
	m_carPage=1;
	//网格
	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;
    dwStyle |= LVS_EX_GRIDLINES;                
    m_list.SetExtendedStyle(dwStyle);   
    //表头
	m_list.InsertColumn(1,"车种",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(2,"车名",LVCFMT_CENTER,100,-1);
	m_list.InsertColumn(3,"发车时段",LVCFMT_CENTER,100,-1);
	m_list.InsertColumn(4,"双程",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(5,"收费",LVCFMT_CENTER,50,-1);
	m_list.InsertColumn(6,"车站",LVCFMT_CENTER,800,-1);
	//读数据
	Find();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CEditDlg::OnBtnLast() 
{
	// TODO: Add your control notification handler code here
	m_carPage--;
	if(m_carPage==1)
		GetDlgItem(IDC_BTN_LAST)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_NEXT)->EnableWindow(TRUE);
	Find();
}

void CEditDlg::OnBtnNext() 
{
	// TODO: Add your control notification handler code here
	m_carPage++;
	if(m_carPage==(int)(m_data->GetCarNum()/10)+1)
		GetDlgItem(IDC_BTN_NEXT)->EnableWindow(FALSE);	
	GetDlgItem(IDC_BTN_LAST)->EnableWindow(TRUE);
	Find();
}

void CEditDlg::Find() 
{
	char str[2000];
	int i,n;
	n=m_carPage*10>m_data->GetCarNum() ? m_data->GetCarNum():m_carPage*10;
	m_list.DeleteAllItems();
	for(i=0+(m_carPage-1)*10;i<n;i++){		
		m_data->FindCar(i,"车种",str);
		m_list.InsertItem(i-(m_carPage-1)*10,str);
		m_data->FindCar(i,"车名",str);
		m_list.SetItemText(i-(m_carPage-1)*10,1,str);
		m_data->FindCar(i,"发车时段",str);
		m_list.SetItemText(i-(m_carPage-1)*10,2,str);
		m_data->FindCar(i,"双程",str);
		m_list.SetItemText(i-(m_carPage-1)*10,3,str);
		m_data->FindCar(i,"收费",str);
		m_list.SetItemText(i-(m_carPage-1)*10,4,str);
		m_data->FindCar(i,"车站",str);
		m_list.SetItemText(i-(m_carPage-1)*10,5,str);
	}
}


void CEditDlg::OnBtnPassword() 
{
	// TODO: Add your control notification handler code here	
	CPasswordDlg dlg;
	dlg.m_type=1;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
		return;
	}
}

void CEditDlg::OnBtnEdit() 
{
	// TODO: Add your control notification handler code here
	CEditOneDlg dlg;
	int index=m_list.GetSelectionMark ();
	if(index==-1)
		MessageBox("请选择某一车次!","提示");
	else{
		dlg.Loading(m_data,index);
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
			//修改
			char m_type[50];
			char str[50];
			char stateLine[1000];
			int twoway;
			if(dlg.m_type==0)
				strcpy(m_type,"bus");
			else if(dlg.m_type==1)
				strcpy(m_type,"sub");
			if(dlg.m_twoway==0)
				twoway=1;
			else if(dlg.m_twoway==1)
				twoway=0;
			strcpy(stateLine,dlg.m_state->GetfromLinkList(1)->name);
			strcat(stateLine,"-");
			for(int i=2;i<=dlg.m_state->LenLinkList();i++){
				strcat(stateLine,dlg.m_state->GetfromLinkList(i)->name);
				strcat(stateLine,"#");
				sprintf(str,"%.0f",dlg.m_state->GetfromLinkList(i)->distance);
				strcat(stateLine,str);
				strcat(stateLine,"#");
				sprintf(str,"%.0f",dlg.m_state->GetfromLinkList(i)->time);
				strcat(stateLine,str);
				strcat(stateLine,"-");
			}
		
			m_data->CarNum++;
			m_data->Init(m_data->GetCarNum()-1,m_type,(char *) dlg.m_name.GetBuffer(0),stateLine,dlg.m_cost,(float)dlg.m_start,(float)dlg.m_end,dlg.m_state->LenLinkList(),twoway);	
			//储存
			m_data->Save();
			Find();
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}
}

void CEditDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	CEditOneDlg dlg;
	dlg.Loading(m_data,-1);
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
		//添加
		char m_type[50];
		char str[50];
		char stateLine[1000];
		int twoway;
		if(dlg.m_type==0)
			strcpy(m_type,"bus");
		else if(dlg.m_type==1)
			strcpy(m_type,"sub");
		if(dlg.m_twoway==0)
			twoway=1;
		else if(dlg.m_twoway==1)
			twoway=0;
		strcpy(stateLine,dlg.m_state->GetfromLinkList(1)->name);
		strcat(stateLine,"-");
		for(int i=2;i<=dlg.m_state->LenLinkList();i++){
			strcat(stateLine,dlg.m_state->GetfromLinkList(i)->name);
			strcat(stateLine,"#");
			sprintf(str,"%.0f",dlg.m_state->GetfromLinkList(i)->distance);
			strcat(stateLine,str);
			strcat(stateLine,"#");
			sprintf(str,"%.0f",dlg.m_state->GetfromLinkList(i)->time);
			strcat(stateLine,str);
			strcat(stateLine,"-");
		}
	
		m_data->CarNum++;
		m_data->Init(m_data->GetCarNum()-1,m_type,(char *) dlg.m_name.GetBuffer(0),stateLine,dlg.m_cost,(float)dlg.m_start,(float)dlg.m_end,dlg.m_state->LenLinkList(),twoway);	
		//储存
		m_data->Save();
		Find();
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
}

void CEditDlg::OnBtnDel() 
{
	// TODO: Add your control notification handler code here
	int index=m_list.GetSelectionMark ();
	if(index==-1)
		MessageBox("请选择某一车次!","提示");
	else{
		if(m_data->DeleteCar(index+1))
		{
			MessageBox("删除成功!","提示");
			Find();
		}
		else
			MessageBox("删除失败!","提示");
	}
}

void CEditDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here	
	int index=m_list.GetSelectionMark ();
	if(index!=-1)
		MessageBox(m_list.GetItemText(index,5),"车站");
	*pResult = 0;
}
