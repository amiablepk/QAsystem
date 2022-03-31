// QAsystem.h : main header file for the QASYSTEM application
//

#if !defined(AFX_QASYSTEM_H__98584D30_C864_4599_9E36_5662278472BB__INCLUDED_)
#define AFX_QASYSTEM_H__98584D30_C864_4599_9E36_5662278472BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CQAsystemApp:
// See QAsystem.cpp for the implementation of this class
//

class CQAsystemApp : public CWinApp
{
public:
	CQAsystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQAsystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CQAsystemApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QASYSTEM_H__98584D30_C864_4599_9E36_5662278472BB__INCLUDED_)
