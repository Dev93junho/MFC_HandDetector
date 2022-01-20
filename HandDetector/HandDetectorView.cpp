
// HandDetectorView.cpp : CHandDetectorView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CHandDetectorView ����/�Ҹ�

CHandDetectorView::CHandDetectorView()
{
	EnableActiveAccessibility();
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CHandDetectorView::~CHandDetectorView()
{
}

BOOL CHandDetectorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CHandDetectorView �׸���

void CHandDetectorView::OnDraw(CDC* /*pDC*/)
{
	CHandDetectorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
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


// CHandDetectorView ����

#ifdef _DEBUG
void CHandDetectorView::AssertValid() const
{
	CView::AssertValid();
}

void CHandDetectorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHandDetectorDoc* CHandDetectorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHandDetectorDoc)));
	return (CHandDetectorDoc*)m_pDocument;
}
#endif //_DEBUG


// CHandDetectorView �޽��� ó����
