// TextView.cpp : implementation file
//

#include "stdafx.h"
#include "MultiDoc.h"
#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CEditView)

CTextView::CTextView()
{
}

CTextView::~CTextView()
{
}


BEGIN_MESSAGE_MAP(CTextView, CEditView)
	//{{AFX_MSG_MAP(CTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CEditView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers
CTextDoc* CTextView::GetDocument()
{
	return (CTextDoc*)m_pDocument;
}