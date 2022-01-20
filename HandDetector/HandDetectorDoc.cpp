
// HandDetectorDoc.cpp : CHandDetectorDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "HandDetector.h"
#endif

#include "HandDetectorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHandDetectorDoc

IMPLEMENT_DYNCREATE(CHandDetectorDoc, CDocument)

BEGIN_MESSAGE_MAP(CHandDetectorDoc, CDocument)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CHandDetectorDoc, CDocument)
END_DISPATCH_MAP()

// ����: IID_IHandDetector�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {CEF7A77E-C7BC-4BE8-9AC3-1B0A10C13AE4}
static const IID IID_IHandDetector =
{ 0xCEF7A77E, 0xC7BC, 0x4BE8, { 0x9A, 0xC3, 0x1B, 0xA, 0x10, 0xC1, 0x3A, 0xE4 } };

BEGIN_INTERFACE_MAP(CHandDetectorDoc, CDocument)
	INTERFACE_PART(CHandDetectorDoc, IID_IHandDetector, Dispatch)
END_INTERFACE_MAP()


// CHandDetectorDoc ����/�Ҹ�

CHandDetectorDoc::CHandDetectorDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

	EnableAutomation();

	AfxOleLockApp();
}

CHandDetectorDoc::~CHandDetectorDoc()
{
	AfxOleUnlockApp();
}

BOOL CHandDetectorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CHandDetectorDoc serialization

void CHandDetectorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CHandDetectorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CHandDetectorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHandDetectorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHandDetectorDoc ����

#ifdef _DEBUG
void CHandDetectorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHandDetectorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHandDetectorDoc ���
