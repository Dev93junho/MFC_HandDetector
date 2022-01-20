
// HandDetectorView.cpp : CHandDetectorView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HandDetector.h"
#endif

#include "HandDetectorDoc.h"
#include "HandDetectorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHandDetectorView

IMPLEMENT_DYNCREATE(CHandDetectorView, CView)

BEGIN_MESSAGE_MAP(CHandDetectorView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHandDetectorView 생성/소멸

CHandDetectorView::CHandDetectorView()
{
	EnableActiveAccessibility();
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHandDetectorView::~CHandDetectorView()
{
}

BOOL CHandDetectorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHandDetectorView 그리기

void CHandDetectorView::OnDraw(CDC* /*pDC*/)
{
	CHandDetectorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CHandDetectorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHandDetectorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHandDetectorView 진단

#ifdef _DEBUG
void CHandDetectorView::AssertValid() const
{
	CView::AssertValid();
}

void CHandDetectorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHandDetectorDoc* CHandDetectorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHandDetectorDoc)));
	return (CHandDetectorDoc*)m_pDocument;
}
#endif //_DEBUG


// CHandDetectorView 메시지 처리기
