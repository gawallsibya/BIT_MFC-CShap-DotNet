// SeriView.cpp : implementation of the CSeriView class
//

#include "stdafx.h"
#include "Seri.h"

#include "SeriDoc.h"
#include "SeriView.h"
#include "Data.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeriView

IMPLEMENT_DYNCREATE(CSeriView, CView)

BEGIN_MESSAGE_MAP(CSeriView, CView)
	//{{AFX_MSG_MAP(CSeriView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_USE_PEN, OnUsePen)
	ON_COMMAND(IDM_USE_RECTANGLE, OnUseRectangle)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_UPDATE_COMMAND_UI_RANGE(IDM_USE_RECTANGLE, IDM_USE_ELLIPSE, OnUpdateShape)
    ON_COMMAND_RANGE(IDM_USE_RECTANGLE, IDM_USE_ELLIPSE, OnShape)
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeriView construction/destruction

CSeriView::CSeriView()
{
	// TODO: add construction code here
	m_colorBrush	= RGB(0,0,255);
	m_colorPen		= RGB(255, 0, 0);
	m_nShape		= IDM_USE_RECTANGLE;
}

CSeriView::~CSeriView()
{
}

BOOL CSeriView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSeriView drawing

void CSeriView::OnDraw(CDC* pDC)
{
	CSeriDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CData* pData;
	
	for(POSITION pos = pDoc->m_List.GetHeadPosition(); pos != NULL; )
	{
		pData = (CData*)pDoc->m_List.GetNext(pos);
		
		CPen *pOldPen, pen;
		CBrush *pOldBrush, brush;	
		
		pen.CreatePen(PS_SOLID, 3, pData->m_colorPen);
		pOldPen = (CPen*)pDC->SelectObject(&pen);
		brush.CreateSolidBrush(pData->m_colorBrush);
		pOldBrush = (CBrush*)pDC->SelectObject(&brush);
		
		if(pData->m_nType == IDM_USE_RECTANGLE)	
			pDC->Rectangle(pData->m_ptHead.x, pData->m_ptHead.y, pData->m_ptTail.x, pData->m_ptTail.y);
		else	
			pDC->Ellipse(pData->m_ptHead.x, pData->m_ptHead.y, pData->m_ptTail.x, pData->m_ptTail.y);
		
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSeriView printing

BOOL CSeriView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSeriView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSeriView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSeriView diagnostics

#ifdef _DEBUG
void CSeriView::AssertValid() const
{
	CView::AssertValid();
}

void CSeriView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSeriDoc* CSeriView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeriDoc)));
	return (CSeriDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSeriView message handlers

void CSeriView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
	m_ptOld = m_ptPre = point;

	CClientDC dc(this);
	dc.SetROP2(R2_XORPEN);
	dc.SelectObject(GetStockObject(WHITE_PEN));
	dc.SelectObject(GetStockObject(BLACK_BRUSH));

	if(m_nShape == IDM_USE_RECTANGLE)
	dc.Rectangle(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
	else
	dc.Ellipse(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
	CView::OnLButtonDown(nFlags, point);
}

void CSeriView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();
	CClientDC dc(this);	
	
	dc.SetROP2(R2_XORPEN);
	dc.SelectObject(GetStockObject(WHITE_PEN));
	dc.SelectObject(GetStockObject(BLACK_BRUSH));
	
	if(m_nShape == IDM_USE_RECTANGLE)
		dc.Rectangle(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
	else
		dc.Ellipse(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
	
	dc.SetROP2(R2_COPYPEN);
	
	CPen *pOldPen, pen;
	CBrush *pOldBrush, brush;
	
	pen.CreatePen(PS_SOLID, 3, m_colorPen);
	pOldPen = (CPen*)dc.SelectObject(&pen);
	
	brush.CreateSolidBrush(m_colorBrush);	
	pOldBrush = (CBrush*)dc.SelectObject(&brush);
	
	if(m_nShape == IDM_USE_RECTANGLE)
		dc.Rectangle(m_ptOld.x, m_ptOld.y, point.x, point.y);
	else
		dc.Ellipse(m_ptOld.x, m_ptOld.y, point.x, point.y);
	
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	
	//데이터 저장----------------------------------------------------
	CData *pNode;
	pNode = new CData;
	pNode->m_ptHead			= m_ptOld;
	pNode->m_ptTail			= point;
	pNode->m_nType			= m_nShape;
	pNode->m_colorPen		= m_colorPen;
	pNode->m_colorBrush		= m_colorBrush;
	
	GetDocument()->m_List.AddTail(pNode);		// 분할 윈도우
	GetDocument()->UpdateAllViews(NULL);		// 분할 윈도우
	//====================================================================

	GetDocument()->SetModifiedFlag(TRUE);
	
	CView::OnLButtonUp(nFlags, point);
}

void CSeriView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CString str;
	str.Format("마우스 위치: x = %d, y = %d", point.x, point.y);
	pFrame->m_wndStatusBar.SetPaneText(1, str);
	
	if(nFlags & MK_LBUTTON)
	{
		CClientDC dc(this);
		dc.SetROP2(R2_XORPEN);
		dc.SelectObject(GetStockObject(WHITE_PEN));
		dc.SelectObject(GetStockObject(BLACK_BRUSH));
		if(m_nShape == IDM_USE_RECTANGLE)
			dc.Rectangle(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
		else
			dc.Ellipse(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
		
		m_ptPre = point;
		
		if(m_nShape == IDM_USE_RECTANGLE)
			dc.Rectangle(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
		else
			dc.Ellipse(m_ptOld.x, m_ptOld.y, m_ptPre.x, m_ptPre.y);
		CView::OnMouseMove(nFlags, point);
	}
}

void CSeriView::OnUpdateShape(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nShape == pCmdUI->m_nID);
}

void CSeriView::OnShape(UINT nID)
{
	m_nShape = nID;	
}

void CSeriView::OnUsePen() 
{
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)	
		m_colorPen = dlg.GetColor();	
}

void CSeriView::OnUseRectangle() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;	
	if(dlg.DoModal() == IDOK)	
		m_colorBrush = dlg.GetColor();
}
