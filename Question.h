#if !defined(AFX_QUESTION_H__9FE2B938_1061_410B_8650_BD3FCAB1D4A8__INCLUDED_)
#define AFX_QUESTION_H__9FE2B938_1061_410B_8650_BD3FCAB1D4A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Question.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuestion dialog

class CQuestion : public CDialog
{
// Construction
public:
	CQuestion(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuestion)
	enum { IDD = IDD_DIALOG2 };
	CString	m_key;
	CString	m_quest;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuestion)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTION_H__9FE2B938_1061_410B_8650_BD3FCAB1D4A8__INCLUDED_)
