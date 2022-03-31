// Question.cpp : implementation file
//

#include "stdafx.h"
#include "QAsystem.h"
#include "Question.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuestion dialog


CQuestion::CQuestion(CWnd* pParent /*=NULL*/)
	: CDialog(CQuestion::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuestion)
	m_key = _T("");
	m_quest = _T("");
	//}}AFX_DATA_INIT
}


void CQuestion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuestion)
	DDX_Text(pDX, IDC_Keywords, m_key);
	DDX_Text(pDX, IDC_Question, m_quest);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuestion, CDialog)
	//{{AFX_MSG_MAP(CQuestion)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuestion message handlers
