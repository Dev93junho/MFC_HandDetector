
// HandDetector.h : HandDetector ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHandDetectorApp:
// �� Ŭ������ ������ ���ؼ��� HandDetector.cpp�� �����Ͻʽÿ�.
//

class CHandDetectorApp : public CWinAppEx
{
public:
	CHandDetectorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	COleTemplateServer m_server;
		// ���� ����⿡ ���� ���� ��ü�Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHandDetectorApp theApp;
