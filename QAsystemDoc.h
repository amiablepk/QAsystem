// QAsystemDoc.h : interface of the CQAsystemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QASYSTEMDOC_H__AA5966FE_0F87_4367_B34B_E70707A42AC7__INCLUDED_)
#define AFX_QASYSTEMDOC_H__AA5966FE_0F87_4367_B34B_E70707A42AC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CQAsystemDoc : public CDocument
{
protected: // create from serialization only
	CQAsystemDoc();
	DECLARE_DYNCREATE(CQAsystemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQAsystemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CQAsystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQAsystemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QASYSTEMDOC_H__AA5966FE_0F87_4367_B34B_E70707A42AC7__INCLUDED_)
