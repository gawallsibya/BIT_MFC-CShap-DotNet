// BamView.cpp : implementation of the CBamView class
//

#include "stdafx.h"
#include "Bam.h"

#include "BamDoc.h"
#include "BamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBamView

IMPLEMENT_DYNCREATE(CBamView, CView)

BEGIN_MESSAGE_MAP(CBamView, CView)
	//{{AFX_MSG_MAP(CBamView)
	ON_COMMAND(ID_PHONE_FIND, OnPhoneFind)
	ON_COMMAND(ID_PHONE_ADD, OnPhoneAdd)
	ON_COMMAND(ID_PHONE_SHOW, OnPhoneShow)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBamView construction/destruction

CBamView::CBamView()
{
	// TODO: add construction code here

}

CBamView::~CBamView()
{
}

BOOL CBamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBamView drawing

void CBamView::OnDraw(CDC* pDC)
{
	CBamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBamView printing

BOOL CBamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBamView diagnostics

#ifdef _DEBUG
void CBamView::AssertValid() const
{
	CView::AssertValid();
}

void CBamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBamDoc* CBamView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBamDoc)));
	return (CBamDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBamView message handlers

CString CBamView::FindVal(CString key)
{
	CString val;
	if(mapBook.Lookup(key, val))
		return val;
	else
		return CString("그런거 없는디유~~");
}

void CBamView::AddData(CString key, CString val)
{
	Invalidate(TRUE);
	mapBook.SetAt(key, val);
}

void CBamView::OnPhoneFind() 
{
	Invalidate(TRUE);
	CClientDC dc(this);

	CDlgFind dlg;
	if(dlg.DoModal() == IDOK)
	{
		CString val = FindVal(dlg.m_Key);
		dc.TextOut(10,10, dlg.m_Key);
		dc.TextOut(100,10, val);
	}
	
}

void CBamView::OnPhoneAdd() 
{
	// TODO: Add your command handler code here
	DlgAdd dlg;
	if(dlg.DoModal()== IDOK)
	{
		AddData(dlg.m_key, dlg.m_val);
	}
	
	
}

void CBamView::OnPhoneShow() 
{
	CClientDC dc(this);
	
	int i=0;
	POSITION ps = mapBook.GetStartPosition();
	while(ps != NULL){
		CString key, val;
		mapBook.GetNextAssoc(ps, key, val);
		dc.TextOut(10, 10+i, key);
		dc.TextOut(100, 10+i, val);
		i = i+20;
	}
}
