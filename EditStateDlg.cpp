// EditStateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "EditStateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditStateDlg dialog


CEditStateDlg::CEditStateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditStateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditStateDlg)
	m_distance = 0.0f;
	m_name = _T("");
	m_time = 0.0f;
	//}}AFX_DATA_INIT
	m_first=false;
}


void CEditStateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditStateDlg)
	DDX_Text(pDX, IDC_EDIT_DISTANCE, m_distance);
	DDV_MinMaxFloat(pDX, m_distance, 0.f, 10.f);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 20);
	DDX_Text(pDX, IDC_EDIT_TIME, m_time);
	DDV_MinMaxFloat(pDX, m_time, 0.f, 120.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditStateDlg, CDialog)
	//{{AFX_MSG_MAP(CEditStateDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditStateDlg message handlers

void CEditStateDlg::Loading(bool first,char name[],float distance, float time)
{
	m_first = first;
	if(!first){
		m_distance = distance;
		m_name = name;
		m_time = time;
	}
	else{
		m_distance = 0;
		m_time = 0;
	}
}

BOOL CEditStateDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	//属性
	if(m_first){
		UpdateData();
		(GetDlgItem(IDC_EDIT_DISTANCE))->EnableWindow(FALSE);
		(GetDlgItem(IDC_EDIT_TIME))->EnableWindow(FALSE);
		UpdateData(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditStateDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_name.IsEmpty()){
		MessageBox("请输入站点名!","提示");
		return;
	}
	else if(!m_first && m_distance==0){
		MessageBox("路程要不能为0!","提示");
		return;
	}
	else if(!m_first && m_time==0){
		MessageBox("耗时要不能为0!","提示");
		return;
	}
	CDialog::OnOK();
}
