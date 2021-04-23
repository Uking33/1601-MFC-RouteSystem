#if !defined(AFX_WAYDLG_H__5EEBE0D0_A4CB_4A8E_A005_13C926D57268__INCLUDED_)
#define AFX_WAYDLG_H__5EEBE0D0_A4CB_4A8E_A005_13C926D57268__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WayDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWayDlg dialog
#include <windows.h>
#include "Data.h"

class CWayDlg : public CDialog
{
// Construction
public:
	CWayDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWayDlg)
	enum { IDD = IDD_FIND_WAY_DIALOG };
	CListCtrl	m_list;
	int		m_choose1;
	int		m_choose2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnLast();
	afx_msg void OnBtnNext();
	afx_msg void OnBtnFind();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	Data* m_data;
	int m_page;
	int m_time;
	void Loading(Data *data);
	void Find();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAYDLG_H__5EEBE0D0_A4CB_4A8E_A005_13C926D57268__INCLUDED_)
