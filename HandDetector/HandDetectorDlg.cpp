
// HandDetectorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HandDetector.h"
#include "HandDetectorDlg.h"
#include "afxdialogex.h"
#include <iostream>


using namespace cv;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHandDetectorDlg 대화 상자

CHandDetectorDlg::CHandDetectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HANDDETECTOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHandDetectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_picture);
}

BEGIN_MESSAGE_MAP(CHandDetectorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()


int detect(Mat img, CascadeClassifier face_cascade, Rect &face)
{
	vector<Rect>faces;

	face_cascade.detectMultiScale(img, faces, 1.1, 5, CASCADE_SCALE_IMAGE, Size(30, 30));

	if (faces.size() == 0)
		return -1;
	else
	{
		face = faces[0];

		return 0;
	}
}

int findFaceArea(Mat img, CascadeClassifier face_cascade, Rect &face)
{
	Mat img_gray;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	equalizeHist(img_gray, img_gray);
	int ret = detect(img, face_cascade, face);

	return ret;
}

int findMaxArea(vector<vector<cv::Point>> contours)
{
	int max_area = -1;
	int max_index = -1;

	for (int i; i < contours.size(); i++)
	{

		int area = contourArea(contours[i]);
		Rect rect = boundingRect(contours[i]);

		if ((rect.width*rect.height)*0.4 > area)
			continue;

		if (rect.width > rect.height)
			continue;

		if (area > max_area) {
			max_area = area;
			max_index = i;
		}
	}

	if (max_area < 10000)
		max_index = -1;
	return max_index;
}

double calculateAngle(Point A, Point B)
{
	double dot = A.x*B.x + A.y*B.y;
	double det = A.x*B.y + A.y*B.x;
	double angle = atan2(det, dot) * 180 / CV_PI;

	return angle;
}

double distanceBetweenTwoPoints(Point start, Point end)
{
	int x1 = start.x;
	int y1 = start.y;
	int x2 = end.x;
	int y2 = end.y;

	return (int)(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

bool sort_custum(const cv::Point p1, const cv::Point p2)
{
	return((p1.x + p1.y) < (p2.x + p2.y));
}

int getFingerPosition(vector<Point>max_contour, Mat img_result,
	vector<cv::Point> &new_points, bool debug)
{
	// find max_contour centor of gravity 
	vector<cv::Point> points1;

	Moments M;
	M = moments(max_contour);

	int cx = (int)(M.m10 / M.m00);
	int cy = (int)(M.m01 / M.m00);

	// approximate contour
	vector<cv::Point> approx;
	approxPolyDP(Mat(max_contour), approx,
		arcLength(Mat(max_contour), true)*0.02, true);

	// convex hull
	vector<cv::Point> hull;
	convexHull(Mat(approx), hull, true);

	// save the finger tip to convexHull points
	// Use to recognize one finger
	for (int i; i < hull.size(); i++)
		if (cy > hull[i].y)
			points1.push_back(hull[i]);

	if (debug)
	{
		vector<vector<cv::Point>>result;
		result.push_back(hull);
		drawContours(img_result, result, -1, Scalar(0, 255, 0), 2);

		for (int i; i < points1.size(); i++)
			circle(img_result, points1[i], 15, Scalar(0, 0, 0), -1);
	}

	// Convexity Defects
	vector<int>hull2;
	convexHull(Mat(approx), hull2, false);

	vector<Vec4i> defects;
	convexityDefects(approx, hull2, defects);

	if (defects.size() == 0)
		return -1;

	// detect finger tip using Convexity Defects
	vector<cv::Point> point2;
	for (int j = 0; j < defects.size(); j++)
	{
		cv::Point start = approx[defects[j][0]];
		cv::Point end = approx[defects[j][1]];
		cv::Point far = approx[defects[j][2]];
		int d = defects[j][3];

		double angle = calculateAngle(
			cv::Point(start.x - far.x, start.y - far.y),
			cv::Point(end.x - far.x, end.y - far.y));

		if (angle > 0 && angle < 45 && d > 10000)
		{
			if (start.y < cy)
				points2.push_back(start);

			if (end.y < cy)
				points2.push_back(end);
		}
	}
}


// CHandDetectorDlg 메시지 처리기

BOOL CHandDetectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	capture = new VideoCapture(0);
	if (!capture->isOpened())
	{
		MessageBox(_T("웹캠을 열수 없습니다.\n"));
	}

	// Fixed Image Size
	capture->set(CAP_PROP_FRAME_WIDTH, 320);
	capture->set(CAP_PROP_FRAME_HEIGHT, 240);

	SetTimer(1000, 30, NULL);

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHandDetectorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHandDetectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHandDetectorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CHandDetectorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	// input image
	capture->read(mat_frame);

	// Convert to Gray scale image
	//cvtColor(mat_frame, mat_frame, COLOR_BGR2GRAY);

	// On the Display
	int bpp = 8 * mat_frame.elemSize();
	assert((bpp == 8 || bpp == 24 || bpp == 32));

	int padding = 0;
	//32bit image
	if (bpp < 32)
		padding = 4 - (mat_frame.cols % 4);
	
	if (bpp == 4)
		padding = 0;

	int border = 0;
	//32 bit image is always DWORD aligned because each pixel requires 4 bytes
	if (bpp < 32)
	{
		border = 4 - (mat_frame.cols % 4);
	}



	Mat mat_temp;
	if (border > 0 || mat_frame.isContinuous() == false)
	{
		// Adding needed columns on the right (max 3 px)
		cv::copyMakeBorder(mat_frame, mat_temp, 0, 0, 0, border, cv::BORDER_CONSTANT, 0);
	}
	else
	{
		mat_temp = mat_frame;
	}


	RECT r;
	m_picture.GetClientRect(&r);
	cv::Size winSize(r.right, r.bottom);

	cimage_mfc.Create(winSize.width, winSize.height, 24);


	BITMAPINFO* bitInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
	bitInfo -> bmiHeader.biBitCount = bpp;
	bitInfo -> bmiHeader.biWidth = mat_temp.cols;
	bitInfo -> bmiHeader.biHeight = -mat_temp.rows;
	bitInfo -> bmiHeader.biPlanes = 1;
	bitInfo -> bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitInfo -> bmiHeader.biCompression = BI_RGB;
	bitInfo -> bmiHeader.biClrImportant = 0;
	bitInfo -> bmiHeader.biClrUsed = 0;
	bitInfo -> bmiHeader.biSizeImage = 0;
	bitInfo -> bmiHeader.biXPelsPerMeter = 0;
	bitInfo -> bmiHeader.biYPelsPerMeter = 0;
	
	if (bpp == 8)
	{
		RGBQUAD* palette = bitInfo -> bmiColors;
		for (int i = 0; i < 256; i++)
		{
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}


	// Image is bigger or smaller than into destination rectangle
	// we use stretch in full rect

	if (mat_temp.cols == winSize.width && mat_temp.rows == winSize.height)
	{
		// source and destination have same size
		// transfer memory block
		// NOTE: the padding border will be shown here. Anyway it will be max 3px width

		SetDIBitsToDevice(cimage_mfc.GetDC(),
			//destination rectangle
			0, 0, winSize.width, winSize.height,
			0, 0, 0, mat_temp.rows,
			mat_temp.data, bitInfo, DIB_RGB_COLORS);
	}
	else
	{
		// destination rectangle
		int destx = 0, desty = 0;
		int destw = winSize.width;
		int desth = winSize.height;

		// rectangle defined on source bitmap
		// using imgWidth instead of mat_temp.cols will ignore the padding border
		int imgx = 0, imgy = 0;
		int imgWidth = mat_temp.cols - border;
		int imgHeight = mat_temp.rows;

		StretchDIBits(cimage_mfc.GetDC(),
			destx, desty, destw, desth,
			imgx, imgy, imgWidth, imgHeight,
			mat_temp.data, bitInfo, DIB_RGB_COLORS, SRCCOPY);
	}


	HDC dc = ::GetDC(m_picture.m_hWnd);
	cimage_mfc.BitBlt(dc, 0, 0);


	::ReleaseDC(m_picture.m_hWnd, dc);

	cimage_mfc.ReleaseDC();
	cimage_mfc.Destroy();


	CDialogEx::OnTimer(nIDEvent);
}
