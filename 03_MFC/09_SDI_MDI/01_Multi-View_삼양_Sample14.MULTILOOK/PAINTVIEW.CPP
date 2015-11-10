// PaintView.cpp : implementation file
//

#include "stdafx.h"
#include "MultiLook.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CScrollView)

CPaintView::CPaintView()
{
}

CPaintView::~CPaintView()
{
}


BEGIN_MESSAGE_MAP(CPaintView, CScrollView)
	//{{AFX_MSG_MAP(CPaintView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintView drawing

void CPaintView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 800;
	SetScrollSizes(MM_TEXT, sizeTotal); 
}

void CPaintView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	
	if(m_ptArray.GetSize() != 0)
	{
		CPen newPen(PS_SOLID, 10, RGB(0, 0, 255));
		CPen* pOldPen = pDC->SelectObject(&newPen);

		CPoint pt = *(CPoint*)m_ptArray.GetAt(0);
		m_start = pt;
		for(int i = 1; i < m_ptArray.GetSize(); i++)
		{
			pt = *(CPoint*)m_ptArray.GetAt(i);
			pDC->MoveTo(m_start);
			pDC->LineTo(pt);
			m_start = pt;
		}
		pDC->SelectObject(pOldPen);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView diagnostics

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintView message handlers

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 마우스 커서가 해당 윈도우를 벗어나도 
	// 마우스 메시지를 받을수 있도록 한다.
	SetCapture(); 
	m_start = point; // 드래그가 시작된 위치 설정
	CScrollView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(GetCapture() == this) // 드래그 중이면
	{
		// 굵기10인 파란색 실선으로 자유 곡선을 그린다.
		CClientDC dc(this);
		CPen newPen(PS_SOLID, 10, RGB(0, 0, 255));
		CPen* pOldPen = dc.SelectObject(&newPen);

		dc.MoveTo(m_start);
		dc.LineTo(point);
		// 마우스 움직임에 따른 위치를 m_ptArray에 모두 저장
		CPoint* pt = new CPoint(m_start);
		m_ptArray.Add(pt);
		pt = new CPoint(point);
		m_ptArray.Add(pt);

		m_start = point; // 처음 시작 위치에 현재 위치 설정 
		dc.SelectObject(pOldPen);
	}
	CScrollView::OnMouseMove(nFlags, point);
}

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(GetCapture() == this)
	{
		ReleaseCapture(); // SetCapture() 해제
	}
	CScrollView::OnLButtonUp(nFlags, point);
}

void CPaintView::OnDestroy() 
{
	CScrollView::OnDestroy();
	while(m_ptArray.GetSize())
	{	// m_ptArray에 저장된 요소값과 메모리를 해제한다.
		delete m_ptArray.GetAt(0);
		m_ptArray.RemoveAt(0);
	}
}
