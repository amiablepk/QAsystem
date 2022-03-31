// Suggest.cpp : implementation file
//

#include "stdafx.h"
#include "QAsystem.h"
#include "Suggest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Suggest dialog


Suggest::Suggest(CWnd* pParent /*=NULL*/)
	: CDialog(Suggest::IDD, pParent)
{
	//{{AFX_DATA_INIT(Suggest)
	m_s1 = _T("");
	//}}AFX_DATA_INIT
}


void Suggest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Suggest)
	DDX_Text(pDX, IDC_EDIT2, m_s1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Suggest, CDialog)
	//{{AFX_MSG_MAP(Suggest)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Suggest message handlers
