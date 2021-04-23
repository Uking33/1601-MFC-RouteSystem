// EditOneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "EditOneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "EditStateDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CEditOneDlg dialog


CEditOneDlg::CEditOneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditOneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditOneDlg)
	m_name = _T("");
	m_start = 0;
	m_end = 0;
	m_cost = 0.0f;
	//}}AFX_DATA_INIT
}


void CEditOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditOneDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 12);
	DDX_Text(pDX, IDC_EDIT_START, m_start);
	DDV_MinMaxUInt(pDX, m_start, 0, 24);
	DDX_Text(pDX, IDC_EDIT_END, m_end);
	DDV_MinMaxUInt(pDX, m_end, 0, 24);
	DDX_Text(pDX, IDC_EDIT_COST, m_cost);
	DDV_MinMaxFloat(pDX, m_cost, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditOneDlg, CDialog)
	//{{AFX_MSG_MAP(CEditOneDlg)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_EDIT, OnBtnEdit)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditOneDlg message handlers

void CEditOneDlg::Loading(Data *data,int index=-1)
{
	m_data=data;
	m_index=index;
}

BOOL CEditOneDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	//����
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->InsertString(0,"����");
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->InsertString(1,"����");
	((CComboBox*)GetDlgItem(IDC_COMBO_TWOWAY))->InsertString(0,"��");
	((CComboBox*)GetDlgItem(IDC_COMBO_TWOWAY))->InsertString(1,"��");
	//����
	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;
    dwStyle |= LVS_EX_GRIDLINES;      
    m_list.SetExtendedStyle(dwStyle);   
    //��ͷ
	m_list.InsertColumn(1,"վ��",LVCFMT_CENTER,205,-1);
	m_list.InsertColumn(2,"ʱ��(min)",LVCFMT_CENTER,100,-1);
	m_list.InsertColumn(3,"·��(km)",LVCFMT_CENTER,100,-1);
	//������
	m_state=new SList();
	if(m_index!=-1){
		UpdateData();
		m_name=m_data->car[m_index].name;
		m_cost=m_data->car[m_index].costCount;
		if(m_data->car[m_index].type==bus)
			((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->SetCurSel(0);
		else if(m_data->car[m_index].type==sub)
			((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->SetCurSel(1);

		if(m_data->car[m_index].twoway==1)
			((CComboBox*)GetDlgItem(IDC_COMBO_TWOWAY))->SetCurSel(0);
		else if(m_data->car[m_index].twoway==0)
			((CComboBox*)GetDlgItem(IDC_COMBO_TWOWAY))->SetCurSel(1);
		m_start=(unsigned int)m_data->car[m_index].start;
		m_end=(unsigned int)m_data->car[m_index].end;
		UpdateData(false);


		int j,z;
		int state;//��ȡ״̬
		char *ch;//��ʱ���ַ�
		char str[50]="";//��ʱ���ַ���
		char stateName[50];//��ʱ��վ����
		float tempf1;//��ʱ��float
		float tempf2;//��ʱ��float

		state=1;
		j=0;
		z=0;
		for(ch=(char*)&(m_data->car[m_index].state);*ch!='\0';ch++){
			if(*ch=='#' || *ch=='-'){
				switch(state){
					case 1://����
						//���ݴ���
						str[z]='\0';
						strcpy(stateName,str);
						//���ݳ�ʼ��
						if(j!=0){
							state=2;
						}
						if(j==0){
							m_state->InsertLinkList(1,stateName,0,0);
							j++;
						}
						z=0;
						break;
					case 2://·��ǧ��
						//���ݴ���
						str[z]='\0';
						tempf1=(float)(atof(str));
						//���ݳ�ʼ��
						state=3;
						z=0;
						break;
					case 3://ʱ�����
						//���ݴ���
						str[z]='\0';
						tempf2=(float)(atof(str));
						//��������
						m_state->InsertLinkList(m_state->LenLinkList()+1,stateName,tempf1,tempf2);
						//���ݳ�ʼ��
						state=1;
						z=0;
						j++;
						break;
				}
			}
			else{
				str[z]=*ch;
				z++;
			}
		}
	}
	Find();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditOneDlg::Find()
{
	char str[2000];
	int i,n;
	n=m_state->LenLinkList();
	m_list.DeleteAllItems();

	for(i=0;i<n;i++){
		m_list.InsertItem(i,m_state->GetfromLinkList(i+1)->name);
		sprintf(str,"%.1fǧ��",m_state->GetfromLinkList(i+1)->distance);
		m_list.SetItemText(i,1,str);
		sprintf(str,"%.1f����",m_state->GetfromLinkList(i+1)->time);
		m_list.SetItemText(i,2,str);
	}
}

void CEditOneDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	CEditStateDlg dlg;
	if(m_state->LenLinkList()==0){
		dlg.Loading(true,"",0,0);
	}
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
		m_state->InsertLinkList(m_state->LenLinkList()+1,(char *) dlg.m_name.GetBuffer(0),dlg.m_distance,dlg.m_time);
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	Find();
}

void CEditOneDlg::OnBtnEdit() 
{
	// TODO: Add your control notification handler code here
	CEditStateDlg dlg;
	int index=m_list.GetSelectionMark ();
	if(index==-1)
		MessageBox("��ѡ��ĳһվ��!","��ʾ");
	else{			
		dlg.Loading(false,m_state->GetfromLinkList(index+1)->name,m_state->GetfromLinkList(index+1)->distance,m_state->GetfromLinkList(index+1)->time);
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
			strcpy(m_state->GetfromLinkList(index+1)->name,(char *) dlg.m_name.GetBuffer(0));
			m_state->GetfromLinkList(index+1)->distance=dlg.m_distance;
			m_state->GetfromLinkList(index+1)->time=dlg.m_time;
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}	
	Find();
}

void CEditOneDlg::OnBtnDel() 
{
	// TODO: Add your control notification handler code here
	
	int index=m_list.GetSelectionMark ();
	if(index==-1)
		MessageBox("��ѡ��ĳһվ��!","��ʾ");
	else{
		m_state->DeleteLinkList(index+1);
	}
	Find();
}

//List
CEditOneDlg::SList::SList(){
	begin=false;
	CreateLinkList();
}

CEditOneDlg::SList::~SList(){
}

void CEditOneDlg::SList::CreateLinkList(){
	//ɾ��֮ǰ�ڵ㣨��ֹ�ڴ�й©��
	if(begin)
		while(head->next!=NULL)
		{
			DeleteLinkList(1);
		}
	begin=true;
	head=(LNode *)malloc(sizeof(LNode));  
	head->next=NULL;
}

int CEditOneDlg::SList::LenLinkList(){
	int n=0;
	LNode *p=head;
	int z=1;
	while(1)
	{
		if(p->next!=NULL)
		{
			p=p->next;
			n++;
		}
		else
			break;
	}
	return n;
}
bool CEditOneDlg::SList::InsertLinkList(int i,char name[],float distance,float time){
    LNode *p=head,*s;
    int index=1;
    int length=LenLinkList();
    if( i<1 || i>(length+1))
    {
	    return false;
    }
	while(1)
	{
        if(i==index)
        {
            s=(LNode *)malloc(sizeof(LNode));
			strcpy(s->data.name,name);
			s->data.distance=distance;
			s->data.time=time;
            s->next=p->next;
            p->next=s;
            p=s;
	        return true;
        }
        p=p->next;
        index++;
	}
	return false;
}
void CEditOneDlg::SList::DeleteLinkList(int i){
	LNode *p=head,*s;
	int index=1; 
	int length=LenLinkList();
	if( i<1 || i>(length))
	{
		return;
	}
	while(1)
	{
		if(i==index)
		{
			s=p->next;
			p->next=s->next;
			free(s);
			return;
		}
		p=p->next;
		index++;
	}
}

int CEditOneDlg::SList::SearchLinkList(char x[])
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
	if (length==0) return -1;
	while(1)
	{
        p=p->next;
        index++;
        if(index>length)
        {
            return -1;
        }
        if(!strcmp(p->data.name,x))
        {
            return index;
        }
	}
	return -1;
}
CEditOneDlg::State* CEditOneDlg::SList::GetfromLinkList(int i)
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
    if( i<1 || i>length)
    {
		return &p->data;
    }
	while(1)
	{
        if(index==i)
        {
            return &p->data;
        }
        p=p->next;
        index++;
	}
	return NULL;
}

void CEditOneDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_name.IsEmpty()){
		MessageBox("�����복��!","��ʾ");
		return;
	}
	else if(m_cost==0){
		MessageBox("����Ҫ����Ϊ0!","��ʾ");
		return;
	}
	if((m_type=((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->GetCurSel())==CB_ERR){
		MessageBox("��ѡ����!","��ʾ");
		return;
	}
	if((m_twoway=((CComboBox*)GetDlgItem(IDC_COMBO_TWOWAY))->GetCurSel())==CB_ERR){
		MessageBox("��ѡ���Ƿ�˫��!","��ʾ");
		return;
	}
	else if(m_start>=m_end){
		MessageBox("��������ȷ�ķ���ʱ��!","��ʾ");
		return;
	}
	else if(m_state->LenLinkList()<=1){
		MessageBox("���������2��վ��!","��ʾ");
		return;
	}
	CDialog::OnOK();
}
