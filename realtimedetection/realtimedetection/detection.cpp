// detection.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "realtimedetection.h"
#include "detection.h"
#include "afxdialogex.h"


// detection ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(detection, CDialogEx)

detection::detection(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

detection::~detection()
{
}

void detection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(detection, CDialogEx)
END_MESSAGE_MAP()


// detection �޽��� ó�����Դϴ�.
