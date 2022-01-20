// detection.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "realtimedetection.h"
#include "detection.h"
#include "afxdialogex.h"


// detection 대화 상자입니다.

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


// detection 메시지 처리기입니다.
