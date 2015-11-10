// PaneView.cpp : implementation file
//

#include "stdafx.h"
#include "Nam.h"
#include "PaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaneView

IMPLEMENT_DYNCREATE(CPaneView, CFormView)

CPaneView::CPaneView()
	: CFormView(CPaneView::IDD)
{
	//{{AFX_DATA_INIT(CPaneView)
	m_str = _T("");
	m_color = -1;
	//}}AFX_DATA_INIT
}

CPaneView::~CPaneView()
{
}

void CPaneView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPaneView)
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Radio(pDX, IDC_RADIO1, m_color);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPaneView, CFormView)
	//{{AFX_MSG_MAP(CPaneView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaneView diagnostics

#ifdef _DEBUG
void CPaneView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPaneView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaneView message handlers
#include "NamDoc.h"
void CPaneView::OnButton1() 
{
	// control -> 멤버 함수.
	UpdateData( TRUE );

	// 얻어온 값으로 Document를 바꾼다.
	CNamDoc* pDoc = (CNamDoc*)GetDocument();
	pDoc->m_str = m_str;

	switch( m_color )
	{
	case 0: pDoc->m_color = RGB(0,0,0); break;
	case 1: pDoc->m_color = RGB(255,0,0); break;
	case 2: pDoc->m_color = RGB(0,255,0); break;
	case 3: pDoc->m_color = RGB(0,0,255); break;
	}
	// 모든 View를 다시 그리게 한다.
	pDoc->UpdateAllViews(this);
}
