
// HandDetectorView.h : CHandDetectorView Ŭ������ �������̽�
//

#pragma once


class CHandDetectorView : public CView
{
protected: // serialization������ ��������ϴ�.
	CHandDetectorView();
	DECLARE_DYNCREATE(CHandDetectorView)

// Ư���Դϴ�.
public:
	CHandDetectorDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CHandDetectorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HandDetectorView.cpp�� ����� ����
inline CHandDetectorDoc* CHandDetectorView::GetDocument() const
   { return reinterpret_cast<CHandDetectorDoc*>(m_pDocument); }
#endif

