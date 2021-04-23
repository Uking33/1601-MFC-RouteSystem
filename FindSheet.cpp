// FindSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Map.h"
#include "FindSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// FindSheet

IMPLEMENT_DYNAMIC(FindSheet, CPropertySheet)

FindSheet::FindSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

FindSheet::FindSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

FindSheet::~FindSheet()
{
}


BEGIN_MESSAGE_MAP(FindSheet, CPropertySheet)
	//{{AFX_MSG_MAP(FindSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// FindSheet message handlers
