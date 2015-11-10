// MapView.cpp : implementation of the CMapView class
//

#include "stdafx.h"
#include "Map.h"

#include "MapDoc.h"
#include "MapView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapView

IMPLEMENT_DYNCREATE(CMapView, CView)

BEGIN_MESSAGE_MAP(CMapView, CView)
	//{{AFX_MSG_MAP(CMapView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapView construction/destruction

CMapView::CMapView()
{
	// TODO: add construction code here

}

CMapView::~CMapView()
{
}

BOOL CMapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMapView drawing

void CMapView::OnDraw(CDC* pDC)
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMapView diagnostics

#ifdef _DEBUG
void CMapView::AssertValid() const
{
	CView::AssertValid();
}

void CMapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapDoc* CMapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapDoc)));
	return (CMapDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapView message handlers
void CMapView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	m_Map = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, 
		PAGE_READWRITE, 0, sizeof(CData), "kitri");
	if(!m_Map)
	{
		AfxMessageBox("메모리 맵 생성 실패");
		return;
	}
	m_ViewData = (CData*)MapViewOfFile(m_Map, FILE_MAP_WRITE,
		0,0,0);
	if(!m_ViewData)
	{
		AfxMessageBox("메모리 맵에 쓰기 실패");
		return;
	}
	m_ViewData->flag = DRAW_READY;
}

void CMapView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 마우스 커서가 해당 윈도우를 벗어나도 
	// 마우스 메시지를 받을수 있도록 한다.
	SetCapture(); 
	m_start = point; // 드래그가 시작된 위치 설정
	CView::OnLButtonDown(nFlags, point);
}

void CMapView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(GetCapture() == this) // 드래그 중이면
	{
		// 굵기10인 파란색 실선으로 자유 곡선을 그린다.
		CClientDC dc(this);
		CPen newPen(PS_SOLID, 10, m_color);
		CPen* pOldPen = dc.SelectObject(&newPen);

		dc.MoveTo(m_start);
		dc.LineTo(point);
		
		// 메모리 맵 파일에 데이터를 입력한다.
		m_ViewData->flag = DRAW_START;
		m_ViewData->color = m_color;
		m_ViewData->start = m_start;
		m_ViewData->pt = point;

		m_start = point; // 처음 시작 위치에 현재 위치 설정 
		dc.SelectObject(pOldPen);
	}	
	CView::OnMouseMove(nFlags, point);
}


void CMapView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(GetCapture() == this)
	{
		m_ViewData->flag = DRAW_READY;
		ReleaseCapture(); // SetCapture() 해제
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMapView::OnDestroy() 
{
	CView::OnDestroy();
	m_ViewData->flag = DRAW_STOP; 
	CloseHandle(m_Map); // 메모리 맵 파일을 닫는다.
}


void CMapView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_color = dlg.GetColor(); // 색상 설정
	}
	CView::OnRButtonDown(nFlags, point);
}

