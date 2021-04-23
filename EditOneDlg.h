#if !defined(AFX_EDITONEDLG_H__67D0ADA0_9522_492B_86BF_03761C133237__INCLUDED_)
#define AFX_EDITONEDLG_H__67D0ADA0_9522_492B_86BF_03761C133237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditOneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditOneDlg dialog

#include "Data.h"

class CEditOneDlg : public CDialog
{
// Construction
public:
	CEditOneDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditOneDlg)
	enum { IDD = IDD_EDIT_ONE_DIALOG };
	CListCtrl	m_list;
	CString	m_name;
	UINT	m_start;
	UINT	m_end;
	float	m_cost;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditOneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditOneDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnEdit();
	afx_msg void OnBtnDel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	typedef struct  State{
		char name[50];
		float distance;
		float time;
	}State;

	typedef State DataType;
	typedef struct node
	{
		DataType data;
		struct node *next;
	}LNode;
	class SList{
	public:
		SList();
		virtual ~SList  ();
		void CreateLinkList();
		bool InsertLinkList(int i,char name[],float distance,float time);
		void DeleteLinkList(int i);
		int LenLinkList();
		int SearchLinkList(char x[]);
		State* GetfromLinkList(int i);
		LNode *head;
		bool begin;
	};
public:
	Data* m_data;
	SList* m_state;
	int m_index;
	int m_type;
	int m_twoway;

	void Loading(Data *data,int index);
	void Find();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITONEDLG_H__67D0ADA0_9522_492B_86BF_03761C133237__INCLUDED_)
