// SampleView.cpp : implementation of the CSampleView class
//

#include "stdafx.h"
#include "Sample.h"

#include "SampleDoc.h"
#include "SampleView.h"

#include "Rectangle.h"
#include "Curve.h"
#include "Line.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CSampleView

IMPLEMENT_DYNCREATE(CSampleView, CView)

BEGIN_MESSAGE_MAP(CSampleView, CView)
	//{{AFX_MSG_MAP(CSampleView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleView construction/destruction

CSampleView::CSampleView()
{
	// TODO: add construction code here
	m_pTempElement		= NULL;
}

CSampleView::~CSampleView()
{
}

BOOL CSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSampleView drawing

void CSampleView::OnDraw(CDC* pDC)
{
	CSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSampleView printing

BOOL CSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSampleView diagnostics

#ifdef _DEBUG
void CSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleDoc* CSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleDoc)));
	return (CSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSampleView message handlers

void CSampleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_firstPoint		= point;
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}

void CSampleView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// Define a Device Context object for the view
	CClientDC aDC(this);
	aDC.SetROP2(R2_NOTXORPEN);    // Set the drawing mode
	if((nFlags & MK_LBUTTON) && (this == GetCapture()))
	{
		m_secondPoint = point;     // Save the current cursor position
		
		if(m_pTempElement)
		{
			// Redraw the old element so it disappears from the view
			m_pTempElement->Draw(&aDC);
			delete m_pTempElement;        // Delete the old element
			m_pTempElement = 0;           // Reset the pointer to 0
		}
		
		// Create a temporary element of the type and color that
		// is recorded in the document object, and draw it
		m_pTempElement = CreateElement();  // Create a new element
		m_pTempElement->Draw(&aDC);        // Draw the element
		
		CView::OnMouseMove(nFlags, point);
	}
}


CElement * CSampleView::CreateElement()
{
// Get a pointer to the document for this view
   CSampleDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);                  // Verify the pointer is good

   // Now select the element using the type stored in the document
   switch(pDoc->GetElementType())
   {
      case RECTANGLE:
         return new CRectangle(m_firstPoint, m_secondPoint, pDoc->GetElementColor());

      case CURVE:
         return new CCurve(pDoc->GetElementColor());

      case LINE: 
         return new CLine(m_firstPoint, m_secondPoint, pDoc->GetElementColor());

	  default:
         // Something's gone wrong
         AfxMessageBox("Bad Element code", MB_OK);
         AfxAbort();
         return NULL;
   }

}

void CSampleView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( this == GetCapture() )
		ReleaseCapture();

	if( m_pTempElement)
	{
		delete m_pTempElement;
		m_pTempElement = 0;
	}
	CView::OnLButtonUp(nFlags, point);
}
