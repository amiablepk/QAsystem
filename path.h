#if !defined(AFX_PATH_H__C76F7A2E_D6EA_4551_A53E_04FC1BF17BA0__INCLUDED_)
#define AFX_PATH_H__C76F7A2E_D6EA_4551_A53E_04FC1BF17BA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// path.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cpath dialog

class Cpath : public CDialog
{
// Construction
public:
	Cpath(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cpath)
	enum { IDD = IDD_DIALOG1 };
	CString	m_pa;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cpath)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cpath)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATH_H__C76F7A2E_D6EA_4551_A53E_04FC1BF17BA0__INCLUDED_)
