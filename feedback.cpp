// feedback.cpp : implementation file
//

#include "stdafx.h"
#include "QAsystem.h"
#include "feedback.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cfeedback dialog


Cfeedback::Cfeedback(CWnd* pParent /*=NULL*/)
	: CDialog(Cfeedback::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cfeedback)
	m_suggest = _T("");
	//}}AFX_DATA_INIT
}


void Cfeedback::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cfeedback)
	DDX_Text(pDX, IDC_Suggest, m_suggest);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cfeedback, CDialog)
	//{{AFX_MSG_MAP(Cfeedback)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cfeedback message handlers
