#pragma once


// detection ��ȭ �����Դϴ�.

class detection : public CDialogEx
{
	DECLARE_DYNAMIC(detection)

public:
	detection(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~detection();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
