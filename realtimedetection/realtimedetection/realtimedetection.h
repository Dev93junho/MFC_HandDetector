
// realtimedetection.h : main header file for the realtimedetection application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CrealtimedetectionApp:
// See realtimedetection.cpp for the implementation of this class
//

class CrealtimedetectionApp : public CWinApp
{
public:
	CrealtimedetectionApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CrealtimedetectionApp theApp;
