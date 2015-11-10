// TextFormView.cpp : implementation file
//

#include "stdafx.h"
#include "MDIHello.h"
#include "MDIHelloDoc.h"
#include "TextFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextFormView

IMPLEMENT_DYNCREATE(CTextFormView, CFormView)

CTextFormView::CTextFormView()
	: CFormView(CTextFormView::IDD)
{
	//{{AFX_DATA_INIT(CTextFormView)
	m_strText = _T("");
	m_nColor = -1;
	m_nX = 0;
	m_nY = 0;
	//}}AFX_DATA_INIT
}

CTextFormView::~CTextFormView()
{
	GetDocument()->SetNullDataForm();
}

void CTextFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextFormView)
	DDX_Control(pDX, IDC_SPINY, m_ctlSpinY);
	DDX_Control(pDX, IDC_SPINX, m_ctlSpinX);
	DDX_Text(pDX, IDC_TEXT, m_strText);
	DDX_Radio(pDX, IDC_COLOR, m_nColor);
	DDX_Text(pDX, IDC_X, m_nX);
	DDX_Text(pDX, IDC_Y, m_nY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTextFormView, CFormView)
	//{{AFX_MSG_MAP(CTextFormView)
	ON_BN_CLICKED(ID_DATA_UPDATE, OnDataUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextFormView diagnostics

#ifdef _DEBUG
void CTextFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTextFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMDIHelloDoc* CTextFormView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIHelloDoc)));
	return (CMDIHelloDoc*)m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextFormView message handlers
const static COLORREF colors[] = { BLACK, RED, GREEN, BLUE };

void CTextFormView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CMDIHelloDoc* pDoc = GetDocument();

	CPoint pt = pDoc->GetLocation();
	m_nX = pt.x;
	m_nY = pt.y;
	m_strText = pDoc->GetText();
	COLORREF color = pDoc->GetColor();
	m_nColor = 0;
	for(int i = 0; i < 4; ++i) {
		if(color == colors[i]) {
			m_nColor = i;
			break;
		}
	}
	UpdateData(FALSE);
	pt = pDoc->GetMax();
	m_ctlSpinX.SetRange(0, pt.x);
	m_ctlSpinY.SetRange(0, pt.y);
}

void CTextFormView::OnDataUpdate() 
{
	// TODO: Add your control notification handler code here
	CMDIHelloDoc* pDoc = GetDocument();

	UpdateData(TRUE);
	pDoc->SetData(m_strText, CPoint(m_nX, m_nY), colors[m_nColor]);
}

void CTextFormView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_ctlSpinX.SetBase(10);
	m_ctlSpinY.SetBase(10);
	OnUpdate(NULL, 0, NULL);
}
