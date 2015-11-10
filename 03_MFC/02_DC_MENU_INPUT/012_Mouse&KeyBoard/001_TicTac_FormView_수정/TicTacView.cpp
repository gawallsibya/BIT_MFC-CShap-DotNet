// TicTacView.cpp : implementation of the CTicTacView class
//

#include "stdafx.h"
#include "TicTac.h"

#include "TicTacDoc.h"
#include "TicTacView.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTicTacView

IMPLEMENT_DYNCREATE(CTicTacView, CFormView)

BEGIN_MESSAGE_MAP(CTicTacView, CFormView)
	//{{AFX_MSG_MAP(CTicTacView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDC_GAME_START, OnGameStart)
	ON_COMMAND(IDC_GAME_END, OnGameEnd)
	ON_UPDATE_COMMAND_UI(IDC_GAME_START, OnUpdateGameStart)
	ON_UPDATE_COMMAND_UI(IDC_GAME_END, OnUpdateGameEnd)
	ON_COMMAND(IDC_GAME_ONE, OnGameOne)
	ON_COMMAND(IDC_GAME_THREE, OnGameThree)
	ON_COMMAND(IDC_GAME_FIVE, OnGameFive)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTicTacView construction/destruction


CTicTacView::CTicTacView()
	: CFormView(CTicTacView::IDD)
{
	// TODO: add construction code here
	m_bGameStart	= false;
	m_pTic			= NULL;
	m_count			= 0;
}


CTicTacView::~CTicTacView()
{
	delete m_pTic;
}


BOOL CTicTacView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTicTacView drawing


/////////////////////////////////////////////////////////////////////////////
// CTicTacView diagnostics

#ifdef _DEBUG
void CTicTacView::AssertValid() const
{
	CView::AssertValid();
}

void CTicTacView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTicTacDoc* CTicTacView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTicTacDoc)));
	return (CTicTacDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTicTacView message handlers

void CTicTacView::OnDraw(CDC* pDC)
{
	CTicTacDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	if(m_bGameStart)
	{
		m_pTic->DrawBoard(pDC);

		CStatic *pEdit = (CStatic*)this->GetDlgItem(IDC_STATIC_MODE);	
		switch(m_pTic->m_gamemode)
		{
		case 1:	pEdit->SetWindowText("´ÜÆÇ½Â");	break;
		case 3: pEdit->SetWindowText("3ÆÇ 2¼±½ÂÁ¦");	break;
		case 5: pEdit->SetWindowText("5ÆÇ 3¼±½ÂÁ¦");  break;
		}
	}
}

void CTicTacView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(m_bGameStart)
		m_pTic->ClickXGamer(this, point);

	CView::OnLButtonDown(nFlags, point);
}

void CTicTacView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if(m_bGameStart)
		m_pTic->ClickOGamer(this, point);

//	IDC_STATIC_WINCOUNT

	CView::OnRButtonDown(nFlags, point);
}

void CTicTacView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	if(m_bGameStart)
		m_pTic->ResetGame(this, point);

	CView::OnLButtonDblClk(nFlags, point);
}


void CTicTacView::OnGameStart() 
{
	if( m_pTic == NULL)
	{
		m_pTic			= new CMyTic;

		SetTimer(1, 1000, NULL);
	}
	m_pTic->ParentGetView(this);
	m_bGameStart	= true;
	Invalidate();
}


void CTicTacView::OnGameEnd() 
{
	delete m_pTic;
	m_pTic = NULL;
	m_bGameStart	= false;
	Invalidate();
	KillTimer(1);
	m_count = 0;
	CStatic *pEdit = (CStatic*)this->GetDlgItem(IDC_STATIC_TIMER);	
	pEdit->SetWindowText("");
}


void CTicTacView::OnUpdateGameStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( !m_bGameStart);
}

void CTicTacView::OnUpdateGameEnd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_bGameStart);
}


void CTicTacView::OnGameOne() 
{
	if( m_pTic == NULL)
		m_pTic = new CMyTic;
	m_pTic->m_gamemode	= 1;
}
void CTicTacView::OnGameThree() 
{
	if( m_pTic == NULL)
		m_pTic = new CMyTic;
	m_pTic->m_gamemode	= 3;
}
void CTicTacView::OnGameFive() 
{
	if( m_pTic == NULL)
		m_pTic = new CMyTic;
	m_pTic->m_gamemode	= 5;
}

void CTicTacView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
}

void CTicTacView::OnTimer(UINT nIDEvent) 
{
	CStatic *pEdit = (CStatic*)this->GetDlgItem(IDC_STATIC_TIMER);	
	int min, sec;
	min	= ++m_count/60;
	sec = m_count%60;
	if( pEdit != NULL)
	{
	
		CString str;
		str.Format("%dºÐ %dÃÊ", min, sec);
		pEdit->SetWindowText(str);
	}

	CStatic *pEdit1 = (CStatic*)this->GetDlgItem(IDC_STATIC_WINCOUNT);	
	CString str1;
	str1.Format("O [%d½Â] : X [%d½Â]", 
		m_pTic->m_OWincount, m_pTic->m_XWincount);

	pEdit1->SetWindowText(str1);


		
	CFormView::OnTimer(nIDEvent);
}
