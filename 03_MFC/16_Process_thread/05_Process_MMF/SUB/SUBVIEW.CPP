// SubView.cpp : implementation of the CSubView class
//

#include "stdafx.h"
#include "Sub.h"

#include "SubDoc.h"
#include "SubView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubView

IMPLEMENT_DYNCREATE(CSubView, CView)

BEGIN_MESSAGE_MAP(CSubView, CView)
	//{{AFX_MSG_MAP(CSubView)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubView construction/destruction

CSubView::CSubView()
{
	// TODO: add construction code here

}

CSubView::~CSubView()
{
}

BOOL CSubView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSubView drawing

void CSubView::OnDraw(CDC* pDC)
{
	CSubDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSubView diagnostics

#ifdef _DEBUG
void CSubView::AssertValid() const
{
	CView::AssertValid();
}

void CSubView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSubDoc* CSubView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSubDoc)));
	return (CSubDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSubView message handlers

void CSubView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// 메모리 맵 파일 열고 데이터를 읽는다.
	m_Map = OpenFileMapping(FILE_MAP_READ, FALSE, "kitri");
	if(!m_Map)
	{
		AfxMessageBox("메모리 맵 열기 실패");
		return;
	}
	m_ViewData = (CData*)MapViewOfFile(m_Map, FILE_MAP_READ,
		0,0,0);
	if(!m_ViewData)
	{
		AfxMessageBox("메모리 맵 데이터 읽기 실패");
		return ;
	}
	AfxBeginThread(SpyInfo, this);
}

void CSubView::OnDestroy() 
{
	CView::OnDestroy();
	CloseHandle(m_Map); // 메모리 맵 파일을 닫는다.	
}

UINT CSubView::SpyInfo(LPVOID lParam)
{
	CSubView* pWnd = (CSubView*)lParam;
	while(1)
	{
		switch(pWnd->m_ViewData->flag)
		{
		case DRAW_READY:
			continue;
		case DRAW_START:
			{
				CClientDC dc(pWnd);
				CPen newPen(PS_SOLID, 10, pWnd->m_ViewData->color);
				CPen* pOldPen = dc.SelectObject(&newPen);
				dc.MoveTo(pWnd->m_ViewData->start);
				dc.LineTo(pWnd->m_ViewData->pt);
				dc.SelectObject(pOldPen);
				break;
			}
		case DRAW_STOP:
			AfxMessageBox("보내는 프로그램이 종료 되었음");
			AfxGetMainWnd()->PostMessage(WM_CLOSE);
			return 0;
		}
	}
}
