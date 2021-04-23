#if !defined(AFX_FINDSHEET_H__A8010B7B_BFF5_471C_8B05_1CD703ECCEA8__INCLUDED_)
#define AFX_FINDSHEET_H__A8010B7B_BFF5_471C_8B05_1CD703ECCEA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FindSheet

class FindSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(FindSheet)

// Construction
public:
	FindSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	FindSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(FindSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~FindSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(FindSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDSHEET_H__A8010B7B_BFF5_471C_8B05_1CD703ECCEA8__INCLUDED_)
