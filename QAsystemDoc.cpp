// QAsystemDoc.cpp : implementation of the CQAsystemDoc class
//

#include "stdafx.h"
#include "QAsystem.h"

#include "QAsystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQAsystemDoc

IMPLEMENT_DYNCREATE(CQAsystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CQAsystemDoc, CDocument)
	//{{AFX_MSG_MAP(CQAsystemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQAsystemDoc construction/destruction

CQAsystemDoc::CQAsystemDoc()
{
	// TODO: add one-time construction code here

}

CQAsystemDoc::~CQAsystemDoc()
{
}

BOOL CQAsystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CQAsystemDoc serialization

void CQAsystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CQAsystemDoc diagnostics

#ifdef _DEBUG
void CQAsystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CQAsystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQAsystemDoc commands
