// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"
#include "Data.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	 m_nState = 0;

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	CData *pData;
	for(POSITION pos = pDoc->m_List.GetHeadPosition(); pos != NULL;)
	{
		pData = (CData*)pDoc->m_List.GetNext(pos);
		CPen *pOldPen, pen;
		pen.CreatePen(PS_SOLID, 5, pData->m_colorPen);
		pOldPen = (CPen*)pDC->SelectObject(&pen);
		pDC->MoveTo(pData->m_ptHead.x, pData->m_ptHead.y);
		pDC->LineTo(pData->m_ptTail.x, pData->m_ptTail.y);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::OnLButtonDown(UINT nFlags, CPoint point) 
{
// TODO: Add your message handler code here and/or call default
	// 마우스 왼쪽 버튼이 눌려지는 순간 마우스를 캡쳐한다.
	SetCapture();
	m_ptFrom = point;
	m_ptTo = point;	
	CView::OnLButtonDown(nFlags, point);
}

void CTestView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(GetCapture() == this)
		::ReleaseCapture();
	CClientDC dc(this);
	// 눌려진 위치부터 놓인 위치까지 붉은색 선을 그린다. 
	InvertLine(&dc, m_ptFrom, m_ptTo);
	CPen pen(PS_SOLID, 16, RGB(255, 0,0));
	dc.SelectObject(&pen);
	dc.MoveTo(m_ptFrom);
	dc.LineTo(point);

	CData *pNode;
	pNode = new CData;
	pNode->m_ptHead	= m_ptFrom;
	pNode->m_ptTail = point;
	pNode->m_colorPen = RGB(255,0,0);
	GetDocument()->m_List.AddTail(pNode);
	CView::OnLButtonUp(nFlags, point);
}

void CTestView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	// 이전에 그려진 임시선을 지우는 효과
	InvertLine(&dc, m_ptFrom, m_ptTo);
	// 새로운 임시선을 그린다.
	InvertLine(&dc, m_ptFrom, point);
	m_ptTo = point;	




	CView::OnMouseMove(nFlags, point);
}

void CTestView::InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo)
{
// 기존 픽셀을 반전시킨다. 따라서 배경이 어떤 색이든 선을 볼 수 있다. 
	// 특히, 같은 위치에 다시 선을 그리면 원래의 화면 색으로 복원되므로.
	// 지워지는 효과를 얻을 수 있다. 
	int nOldMode = pDC->SetROP2(R2_NOT);
	pDC->MoveTo(ptFrom);
	pDC->LineTo(ptTo);
	pDC->SetROP2(nOldMode);
}

BOOL CTestView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
::SetCursor(LoadCursorFromFile("c:\\winnt\\cursors\\Globe.ani"));
	return TRUE;  // 윈도우에게 커서가 정해졌음을 알림....
//	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CTestView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
SetTimer(0,500,NULL);		
}

int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CTestView::OnDestroy() 
{
	CView::OnDestroy();
	
KillTimer(0);		
}

void CTestView::OnTimer(UINT nIDEvent) 
{
CClientDC dc(this);
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap *pOldBitmap, bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);

	if(m_nState == 0)
	{
		dc.BitBlt(50,50, 90,100, &MemDC, 0,0, SRCCOPY);
		m_nState = 1;
	}
	else if(m_nState ==1)
	{
		dc.BitBlt(50,50, 90,100, &MemDC, 80,0, SRCCOPY);
		m_nState = 2;
	}
	if(m_nState == 2)
	{
			dc.BitBlt(50,50, 90,100, &MemDC,160 ,0, SRCCOPY);
			m_nState = 0;
	}	
	CView::OnTimer(nIDEvent);
}
