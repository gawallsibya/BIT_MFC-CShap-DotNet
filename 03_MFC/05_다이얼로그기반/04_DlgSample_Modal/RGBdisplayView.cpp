// RGBdisplayView.cpp : implementation of the CRGBdisplayView class
//

#include "stdafx.h"
#include "RGBdisplay.h"

#include "RGBdisplayDoc.h"
#include "RGBdisplayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayView

IMPLEMENT_DYNCREATE(CRGBdisplayView, CView)

BEGIN_MESSAGE_MAP(CRGBdisplayView, CView)
	//{{AFX_MSG_MAP(CRGBdisplayView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FONTCOLOR, OnFontcolor)
	ON_COMMAND(ID_BACKCOLOR, OnBackcolor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayView construction/destruction

CRGBdisplayView::CRGBdisplayView()
{
	// TODO: add construction code here
	str = "화면의 색깔이 바뀌었습니다.";
	r = g = b = 0;
	fcolor = RGB(0,0,0);
	bcolor = RGB(255,255,255);

}

CRGBdisplayView::~CRGBdisplayView()
{
}

BOOL CRGBdisplayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayView drawing

void CRGBdisplayView::OnDraw(CDC* pDC)
{
	CRGBdisplayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayView diagnostics

#ifdef _DEBUG
void CRGBdisplayView::AssertValid() const
{
	CView::AssertValid();
}

void CRGBdisplayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRGBdisplayDoc* CRGBdisplayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRGBdisplayDoc)));
	return (CRGBdisplayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRGBdisplayView message handlers

void CRGBdisplayView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	dc.SetTextColor(RGB(r,g,b));
	dc.SetBkColor(bcolor);
	dc.TextOut(point.x, point.y, str);	
	CView::OnLButtonDown(nFlags, point);
}
#include "ColorDlg.h"

void CRGBdisplayView::OnFontcolor() 
{
	// TODO: Add your command handler code here
// TODO: Add your command handler code here
	CColorDlg dlg;
	dlg.m_RedVal = r;
	dlg.m_GreenVal = g;
	dlg.m_BlueVal = b;

	
	if(dlg.DoModal() == IDOK)
	{
		r = dlg.m_r;
		g = dlg.m_g;
		b = dlg.m_b;
	}
	
}

void CRGBdisplayView::OnBackcolor() 
{
	CColorDialog dlg;
		if(dlg.DoModal() == IDOK)
		{
			bcolor = dlg.GetColor();
		}
	
}
