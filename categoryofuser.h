#if !defined(AFX_CATEGORYOFUSER_H__42690CC0_2B26_4BEB_954E_07CD4CCFDEB0__INCLUDED_)
#define AFX_CATEGORYOFUSER_H__42690CC0_2B26_4BEB_954E_07CD4CCFDEB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// categoryofuser.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// categoryofuser dialog

class categoryofuser : public CDialog
{
// Construction
public:
	categoryofuser(CWnd* pParent = NULL);   // standard constructor
BOOL OnCommand(WPARAM wParam, LPARAM lParam);
// Dialog Data
	//{{AFX_DATA(categoryofuser)
	enum { IDD = 0};//_UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(categoryofuser)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(categoryofuser)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATEGORYOFUSER_H__42690CC0_2B26_4BEB_954E_07CD4CCFDEB0__INCLUDED_)
