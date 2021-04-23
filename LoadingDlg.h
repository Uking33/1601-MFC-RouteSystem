#if !defined(AFX_LOADINGDLG_H__22CEC6F7_B360_435B_964C_7F510BBA9FB9__INCLUDED_)
#define AFX_LOADINGDLG_H__22CEC6F7_B360_435B_964C_7F510BBA9FB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoadingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoadingDlg dialog

class CLoadingDlg : public CDialog
{
// Construction
public:
	CLoadingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoadingDlg)
	enum { IDD = IDD_LOADING };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoadingDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADINGDLG_H__22CEC6F7_B360_435B_964C_7F510BBA9FB9__INCLUDED_)
