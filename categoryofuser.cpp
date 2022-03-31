// categoryofuser.cpp : implementation file
//

#include "stdafx.h"
#include "QAsystem.h"
#include "categoryofuser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// categoryofuser dialog


categoryofuser::categoryofuser(CWnd* pParent /*=NULL*/)
	: CDialog(categoryofuser::IDD, pParent)
{
	//{{AFX_DATA_INIT(categoryofuser)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void categoryofuser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(categoryofuser)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(categoryofuser, CDialog)
	//{{AFX_MSG_MAP(categoryofuser)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// categoryofuser message handlers

BOOL categoryofuser::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::OnCommand(wParam, lParam);
}
