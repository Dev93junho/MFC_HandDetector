
// HandDetectorDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



// CHandDetectorDlg ��ȭ ����
class CHandDetectorDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHandDetectorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HANDDETECTOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_picture;
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	VideoCapture* capture;
	Mat mat_frame;
	CImage cimage_mfc;

};
