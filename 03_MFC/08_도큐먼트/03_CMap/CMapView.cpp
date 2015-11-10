// CMapView.cpp : implementation of the CCMapView class
//

#include "stdafx.h"
#include "CMap.h"

#include "CMapDoc.h"
#include "CMapView.h"
#include "MapDialog.h"
#include <iostream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMapView

IMPLEMENT_DYNCREATE(CCMapView, CView)

BEGIN_MESSAGE_MAP(CCMapView, CView)
	//{{AFX_MSG_MAP(CCMapView)
	ON_COMMAND(ID_MCMAP, OnMcmap)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMapView construction/destruction

CCMapView::CCMapView()
{
	// TODO: add construction code here

}

CCMapView::~CCMapView()
{
}

BOOL CCMapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCMapView drawing

void CCMapView::OnDraw(CDC* pDC)
{
	CCMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCMapView printing

BOOL CCMapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCMapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCMapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCMapView diagnostics

#ifdef _DEBUG
void CCMapView::AssertValid() const
{
	CView::AssertValid();
}

void CCMapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCMapDoc* CCMapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCMapDoc)));
	return (CCMapDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCMapView message handlers

void CCMapView::OnMcmap() 
{
	CCMapDoc* pDoc = GetDocument();

	CMapDialog dlg;
	CString str;
	CClientDC dc(this);
	
	if(dlg.DoModal() == IDOK)
	{
		int num = 0;

		while(dlg.m_strSelected[num].GetLength() > 0)
			num++;


		for(int i=0; i < num; i++)
			pDoc->map.SetAt(i, dlg.m_strSelected[i]);

		for(i=0; i < num; i++)
		{
			str.Format("키값 : %d, 이름 : %s", i, pDoc->map[i]);
			dc.TextOut(10, 10 + i*25, str, strlen(str));
		}
	}
}
