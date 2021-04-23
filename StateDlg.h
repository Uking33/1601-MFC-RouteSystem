#if !defined(AFX_STATEDLG_H__19541662_4FF9_4BD9_94FE_FA63C6D699AF__INCLUDED_)
#define AFX_STATEDLG_H__19541662_4FF9_4BD9_94FE_FA63C6D699AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStateDlg dialog

#include "Data.h"

class CStateDlg : public CDialog
{
// Construction
public:
	CStateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStateDlg)
	enum { IDD = IDD_FIND_STATE_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnLast();
	afx_msg void OnBtnNext();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	Data* m_data;
	int m_page;

	void Loading(Data *data);
	void Find();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATEDLG_H__19541662_4FF9_4BD9_94FE_FA63C6D699AF__INCLUDED_)
