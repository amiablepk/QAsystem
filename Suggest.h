#if !defined(AFX_SUGGEST_H__D4820C7A_CCAF_4F8D_9D73_D5DB427F0C91__INCLUDED_)
#define AFX_SUGGEST_H__D4820C7A_CCAF_4F8D_9D73_D5DB427F0C91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Suggest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Suggest dialog

class Suggest : public CDialog
{
// Construction
public:
	Suggest(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Suggest)
	enum { IDD = IDD_DIALOG3 };
	CString	m_s1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Suggest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Suggest)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUGGEST_H__D4820C7A_CCAF_4F8D_9D73_D5DB427F0C91__INCLUDED_)
