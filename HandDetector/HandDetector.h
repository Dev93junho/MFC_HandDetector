
// HandDetector.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHandDetectorApp:
// �� Ŭ������ ������ ���ؼ��� HandDetector.cpp�� �����Ͻʽÿ�.
//

class CHandDetectorApp : public CWinApp
{
public:
	CHandDetectorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHandDetectorApp theApp;