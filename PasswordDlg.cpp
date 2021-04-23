// PasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "PasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg dialog


CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswordDlg)
	m_password = _T("");
	m_text = _T("");
	//}}AFX_DATA_INIT
	m_type=0;
}


void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswordDlg)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 16);
	DDX_Text(pDX, IDC_TEXT, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CPasswordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg message handlers

int CPasswordDlg::Enter(char str[]){	//登陆验证
	FILE *fp;
	char password[16];
	fp=fopen(PASSWORD_PATH,"r+");
	if(fp==NULL)
	{
		fp=fopen(PASSWORD_PATH,"w+");
		if(fp==NULL)
		{
			printf("can not open '%s'",PASSWORD_PATH);
			exit(1);
		}
		fprintf(fp,"%s","123456");
		strcpy(password,"123456");
	}
	else
		fscanf(fp,"%s",password);
	fclose(fp);
	if(strcmp(password,str))
		return 0;
	else
		return 1;
}

int CPasswordDlg::EditPassword(char password[]){	//修改密码
	FILE *fp;
	fp=fopen(PASSWORD_PATH,"w+");
	if(fp==NULL)
	{
		printf("can not open '%s'",PASSWORD_PATH);
		return 0;
	}
	fprintf(fp,"%s",password);
	fclose(fp);
	return 1;
}

void CPasswordDlg::Model(int type=0){
	m_type=type;
	switch(m_type){
		case 0:	
			break;
		case 1:		
			break;
		case 2:	
			UpdateData();
			m_text="请输入修改密码：";
			m_password="";
			UpdateData(false);
			break;
		case 3:		
			UpdateData();
			m_text="请再次输入修改密码：";
			m_password="";
			UpdateData(false);
			break;
	}
}
void CPasswordDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	switch(m_type){
		case 0:
			if(Enter((char *) m_password.GetBuffer(0))){
				MessageBox("登陆成功","登陆提示");
			}
			else{
				MessageBox("密码错误","登陆提示");
				UpdateData();
				m_password="";
				UpdateData(false);
				return;
			}
		break;
		case 1:
			if(Enter((char *) m_password.GetBuffer(0))){
				Model(2);
				return;
			}
			else{
				MessageBox("密码错误","修改提示");
				return;
			}
		break;
		case 2:
			if(Enter((char *) m_password.GetBuffer(0))){
				MessageBox("密码重复","修改提示");
				return;
			}
			else{
				password=(char *) m_password.GetBuffer(0);
				Model(3);
				return;
			}
		break;
		case 3:
			if(!m_password.Compare(password)){
				EditPassword((char *) m_password.GetBuffer(0));
				MessageBox("密码修改成功","修改提示");
			}
			else{
				MessageBox("两次的密码不同","修改提示");
				return;
			}
		break;
	}
	CDialog::OnOK();
}

BOOL CPasswordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	UpdateData();
	switch(m_type){
		case 0:	
			m_text="请输入密码：";
			//GetDlgItem(IDC_TEXT)->SetWindowText("请输入密码：");
			break;
		case 1:	
			m_text="请输入原始密码：";
			break;
	}
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
