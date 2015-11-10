// MouseCapView.cpp : implementation of the CMouseCapView class
//

#include "stdafx.h"
#include "MouseCap.h"

#include "MouseCapDoc.h"
#include "MouseCapView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMouseCapView

IMPLEMENT_DYNCREATE(CMouseCapView, CView)

BEGIN_MESSAGE_MAP(CMouseCapView, CView)
	//{{AFX_MSG_MAP(CMouseCapView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseCapView construction/destruction

CMouseCapView::CMouseCapView()
{
	// TODO: add construction code here

	m_bTracking			= FALSE;
}

CMouseCapView::~CMouseCapView()
{
}

BOOL CMouseCapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMouseCapView drawing

void CMouseCapView::OnDraw(CDC* pDC)
{
	CMouseCapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMouseCapView diagnostics

#ifdef _DEBUG
void CMouseCapView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseCapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseCapDoc* CMouseCapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseCapDoc)));
	return (CMouseCapDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMouseCapView message handlers
#include "MainFrm.h"
void CMouseCapView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//앵커 위치를 기록하고 추적 플래그 설정
	m_ptFrom	= point;
	m_ptTo		= point;
	m_bTracking	= TRUE;

	// 캡쳐가 가능하면 마우스 캡쳐
	if( GetParentFrame()->m_bAutoMenuEnable )
		SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CMouseCapView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	// 추적중(선이 늘어나는 상태)인 상태에서 마우스가 이동하면 이전 선을 지우고
	// 새 선을 그림
	if( m_bTracking)
	{
		CClientDC dc(this);
		InvertLine(&dc, m_ptFrom, m_ptTo);
		InvertLine(&dc, m_ptFrom, point);

		m_ptTo	= point;
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMouseCapView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	// 추적중인 동안 왼쪽 마우스 단추를 놓으면 마우스가 현재 캡쳐되는
	// 상태인 경우 마우스를 해제하고 마지막 러버 밴드 선을 지우고
	// 그 자리에 굵은 빨강색의 선을 그림
	if( m_bTracking)
	{
		m_bTracking	= FALSE;
		if( GetCapture() == this)
			::ReleaseCapture();

		CClientDC	dc(this);
		InvertLine(&dc, m_ptFrom, m_ptTo);

		CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
		dc.SelectObject(&pen);

		dc.MoveTo(m_ptFrom);
		dc.LineTo(point);
	}

	CView::OnLButtonUp(nFlags, point);
}



void CMouseCapView::InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo)
{
	// R2_NOT 그리기 모드에서 선을 그려 픽셀 선을 반전
	int nOldMode = pDC->SetROP2(R2_NOT);

	pDC->MoveTo(ptFrom);
	pDC->LineTo(ptTo);

	pDC->SetROP2( nOldMode);
}
