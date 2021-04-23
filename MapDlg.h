// MapDlg.h : header file
//

#if !defined(AFX_MAPDLG_H__81A6020B_C265_43C3_B1AC_7D20CC8F7268__INCLUDED_)
#define AFX_MAPDLG_H__81A6020B_C265_43C3_B1AC_7D20CC8F7268__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Data.h"

/////////////////////////////////////////////////////////////////////////////
// CMapDlg dialog

class CMapDlg : public CDialog
{
// Construction
public:
	CMapDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMapDlg)
	enum { IDD = IDD_MAP_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMapDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnFindcar();
	afx_msg void OnBtnFindcarstate();
	afx_msg void OnBtnFindWay();
	virtual void OnCancel();
	afx_msg void OnBtnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	Data data;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPDLG_H__81A6020B_C265_43C3_B1AC_7D20CC8F7268__INCLUDED_)
