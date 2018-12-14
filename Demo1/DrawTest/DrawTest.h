// DrawTest.h : main header file for the DRAWTEST application
//

#if !defined(AFX_DRAWTEST_H__07C6C1E6_B612_4057_9520_95760E8B8259__INCLUDED_)
#define AFX_DRAWTEST_H__07C6C1E6_B612_4057_9520_95760E8B8259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawTestApp:
// See DrawTest.cpp for the implementation of this class
//

class CDrawTestApp : public CWinApp
{
public:
	CDrawTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTEST_H__07C6C1E6_B612_4057_9520_95760E8B8259__INCLUDED_)
