
// 0325Doc.cpp : CMy0325Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CMy0325Doc 생성/소멸

CMy0325Doc::CMy0325Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMy0325Doc::~CMy0325Doc()
{
}

BOOL CMy0325Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
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
		// TODO: 여기에 저장 코드를 추가합니다.
		for(int i=0; i<m_rect.GetSize(); i++)
		{
			ar << m_rect[i];
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
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

// 축소판 그림을 지원합니다.
void CMy0325Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void CMy0325Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CMy0325Doc 진단

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


// CMy0325Doc 명령
