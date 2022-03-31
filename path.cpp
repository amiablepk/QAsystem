// path.cpp : implementation file
//

#include "stdafx.h"
#include "QAsystem.h"
#include "path.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cpath dialog


Cpath::Cpath(CWnd* pParent /*=NULL*/)
	: CDialog(Cpath::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cpath)
	m_pa = _T("");
	//}}AFX_DATA_INIT
}


void Cpath::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cpath)
	DDX_Text(pDX, IDC_Path, m_pa);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cpath, CDialog)
	//{{AFX_MSG_MAP(Cpath)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cpath message handlers
