// Map.h : main header file for the MAP application
//

#if !defined(AFX_MAP_H__11A723FE_A51D_48DC_A8F3_50E01D8D6777__INCLUDED_)
#define AFX_MAP_H__11A723FE_A51D_48DC_A8F3_50E01D8D6777__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMapApp:
// See Map.cpp for the implementation of this class
//

class CMapApp : public CWinApp
{
public:
	CMapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMapApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAP_H__11A723FE_A51D_48DC_A8F3_50E01D8D6777__INCLUDED_)
