
// realtimedetecthand.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CrealtimedetecthandApp:
// �� Ŭ������ ������ ���ؼ��� realtimedetecthand.cpp�� �����Ͻʽÿ�.
//

class CrealtimedetecthandApp : public CWinApp
{
public:
	CrealtimedetecthandApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CrealtimedetecthandApp theApp;