
// realtimedetectionView.cpp : implementation of the CrealtimedetectionView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "realtimedetection.h"
#endif

#include "realtimedetectionDoc.h"
#include "realtimedetectionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrealtimedetectionView

IMPLEMENT_DYNCREATE(CrealtimedetectionView, CView)

BEGIN_MESSAGE_MAP(CrealtimedetectionView, CView)
END_MESSAGE_MAP()

// CrealtimedetectionView construction/destruction

CrealtimedetectionView::CrealtimedetectionView()
{
	// TODO: add construction code here

}

CrealtimedetectionView::~CrealtimedetectionView()
{
}

BOOL CrealtimedetectionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CrealtimedetectionView drawing

void CrealtimedetectionView::OnDraw(CDC* /*pDC*/)
{
	CrealtimedetectionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CrealtimedetectionView diagnostics

#ifdef _DEBUG
void CrealtimedetectionView::AssertValid() const
{
	CView::AssertValid();
}

void CrealtimedetectionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CrealtimedetectionDoc* CrealtimedetectionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CrealtimedetectionDoc)));
	return (CrealtimedetectionDoc*)m_pDocument;
}
#endif //_DEBUG


// CrealtimedetectionView message handlers
