#if !defined(AFX_FEEDBACK_H__390F9889_D43E_4392_A132_D0DE58E6120D__INCLUDED_)
#define AFX_FEEDBACK_H__390F9889_D43E_4392_A132_D0DE58E6120D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// feedback.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cfeedback dialog

class Cfeedback : public CDialog
{
// Construction
public:
	Cfeedback(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cfeedback)
	enum { IDD = IDD_DIALOG4 };
	CString	m_suggest;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cfeedback)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cfeedback)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FEEDBACK_H__390F9889_D43E_4392_A132_D0DE58E6120D__INCLUDED_)
