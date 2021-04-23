#if !defined(AFX_CARDLG_H__8D461C3A_47CC_4445_BED3_1C1B77F0C3B9__INCLUDED_)
#define AFX_CARDLG_H__8D461C3A_47CC_4445_BED3_1C1B77F0C3B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarDlg dialog

#include "Data.h"

class CCarDlg : public CDialog
{
// Construction
public:
	CCarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCarDlg)
	enum { IDD = IDD_FIND_CAR_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCarDlg)
	afx_msg void OnBtnLast();
	afx_msg void OnBtnNext();
	virtual BOOL OnInitDialog();
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

#endif // !defined(AFX_CARDLG_H__8D461C3A_47CC_4445_BED3_1C1B77F0C3B9__INCLUDED_)
