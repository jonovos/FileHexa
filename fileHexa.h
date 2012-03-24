// fileHexa.h : main header file for the fileHexa application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CfileHexaApp:
// See fileHexa.cpp for the implementation of this class
//

class CfileHexaApp : public CWinApp
{
public:
	CfileHexaApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CfileHexaApp theApp;