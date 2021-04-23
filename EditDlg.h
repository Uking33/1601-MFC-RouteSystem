#if !defined(AFX_EDITDLG_H__6BFF3516_0A33_4E51_BC24_2EEFE8FA388D__INCLUDED_)
#define AFX_EDITDLG_H__6BFF3516_0A33_4E51_BC24_2EEFE8FA388D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog

#include "Data.h"

class CEditDlg : public CDialog
{
// Construction
public:
	CEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditDlg)
	enum { IDD = IDD_EDIT_CAR_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDlg)
	afx_msg void OnBtnLast();
	afx_msg void OnBtnNext();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnPassword();
	afx_msg void OnBtnEdit();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnDel();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	Data* m_data;
	int m_carPage;

	void Loading(Data *data);
	void Find();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDLG_H__6BFF3516_0A33_4E51_BC24_2EEFE8FA388D__INCLUDED_)
