
// 0325Doc.cpp : CMy0325Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "0325.h"
#endif

#include "0325Doc.h"
#include "0325View.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy0325Doc

IMPLEMENT_DYNCREATE(CMy0325Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy0325Doc, CDocument)
END_MESSAGE_MAP()


// CMy0325Doc ����/�Ҹ�

CMy0325Doc::CMy0325Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy0325Doc::~CMy0325Doc()
{
}

BOOL CMy0325Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.
	m_rect.RemoveAll();

//	POSITION po = GetFirstViewPosition();
//	CMy0325View *p =  (CMy0325View*)GetNextView(po);
//	p->Invalidate();

	return TRUE;
}




// CMy0325Doc serialization

void CMy0325Doc::Serialize(CArchive& ar)
{	
	if (ar.IsStoring())
	{
		int size = m_rect.GetSize();
		ar << size;
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		for(int i=0; i<m_rect.GetSize(); i++)
		{
			ar << m_rect[i];
		}
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		int size;
		ar >> size;
		for(int i=0; i<size; i++)
		{
			CPoint pt;
			ar >> pt;
			m_rect.Add(pt);
		}
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy0325Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy0325Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy0325Doc::SetSearchContent(const CString& value)
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

// CMy0325Doc ����

#ifdef _DEBUG
void CMy0325Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy0325Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy0325Doc ���
