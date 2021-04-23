#if !defined(AFX_EDITSTATEDLG_H__8EE9483C_884F_46A7_A885_8DA695C223DD__INCLUDED_)
#define AFX_EDITSTATEDLG_H__8EE9483C_884F_46A7_A885_8DA695C223DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditStateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditStateDlg dialog

class CEditStateDlg : public CDialog
{
// Construction
public:
	CEditStateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditStateDlg)
	enum { IDD = IDD_EDIT_STATE_DIALOG };
	float	m_distance;
	CString	m_name;
	float	m_time;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditStateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditStateDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	bool m_first;
	void Loading(bool first,char name[],float distance, float time);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSTATEDLG_H__8EE9483C_884F_46A7_A885_8DA695C223DD__INCLUDED_)
