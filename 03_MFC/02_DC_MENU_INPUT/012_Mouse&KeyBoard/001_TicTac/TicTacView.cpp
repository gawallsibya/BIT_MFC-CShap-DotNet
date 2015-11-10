// TicTacView.cpp : implementation of the CTicTacView class
//

#include "stdafx.h"
#include "TicTac.h"

#include "TicTacDoc.h"
#include "TicTacView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTicTacView

IMPLEMENT_DYNCREATE(CTicTacView, CView)

BEGIN_MESSAGE_MAP(CTicTacView, CView)
	//{{AFX_MSG_MAP(CTicTacView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTicTacView construction/destruction

const CRect CTicTacView::m_rcSquares[9] = {
	CRect( 16,  16, 112, 112),
	CRect(128,  16, 224, 112),
	CRect(240,  16, 336, 112),
	CRect( 16, 128, 112, 224),
	CRect(128, 128, 224, 224),
	CRect(240, 128, 336, 224),
	CRect( 16, 240, 112, 336),
	CRect(128, 240, 224, 336),
	CRect(240, 240, 336, 336)
};

CTicTacView::CTicTacView()
{
	// TODO: add construction code here
	m_nNextChar		= EX;
	::ZeroMemory(m_nGameGrid, 9*sizeof(int));
}


CTicTacView::~CTicTacView()
{
}

BOOL CTicTacView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTicTacView drawing

void CTicTacView::OnDraw(CDC* pDC)
{
	CTicTacDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawBoard(pDC);
}

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

void CTicTacView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 0의 차례이거나 그리드 외부에서 클릭하였거나 비어있지 않은
	// 영역을 클락하면 아무것도 하지 않음
	if( m_nNextChar != EX)
		return;

	int nPos = GetRectID( point);
	if(( nPos == -1) || (m_nGameGrid[nPos] != 0 ))
		return;

	// 그리드에 X를 추가하고 m_nNextChar를 토글
	m_nGameGrid[nPos] = EX;
	m_nNextChar		  = OH;

	// 화면에 X를 표시하고 승패를 알아 낸다.
	CClientDC dc(this);
	DrawX(&dc, nPos);
	CheckForGameOver();
	
	CView::OnLButtonDown(nFlags, point);
}


void CTicTacView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// X의 차례이거나 그리드 외부에서 클릭하였거나 비어있지 않은
	// 영역을 클락하면 아무것도 하지 않음
	if( m_nNextChar != OH)
		return;

	int nPos = GetRectID( point);
	if(( nPos == -1) || (m_nGameGrid[nPos] != 0 ))
		return;

	// 그리드에 O를 추가하고 m_nNextChar를 토글
	m_nGameGrid[nPos] = OH;
	m_nNextChar		  = EX;

	// 화면에 O를 표시하고 승패를 알아 낸다.
	CClientDC dc(this);
	DrawO(&dc, nPos);
	CheckForGameOver();	
	CView::OnRButtonDown(nFlags, point);
}


void CTicTacView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{

	// 게임 그리드를 정의하는 굵은 검정선을 왼쪽마우스 DB 클릭하면
	// 게임을 재설정

	CClientDC	dc(this);
	if( dc.GetPixel( point) == RGB(0, 0, 0))
		ResetGame();

	CView::OnLButtonDblClk(nFlags, point);
}


int CTicTacView::GetRectID( CPoint point)
{
	// 각 그리드의 9개 사각형이 눌렸는지 검사하고
	// (point.x, point.y)가 사각형 안에 있으면 ID(0~8)을 반환
	for( int i=0; i<9; i++)
	{
		if( m_rcSquares[i].PtInRect(point))
			return i;
	}
	return -1;
}


void CTicTacView::DrawBoard(CDC *pDC)
{
	// tic-tac-toe그리드를 정의하는 선을 그림
	CPen pen(PS_SOLID, 16, RGB(0, 0, 0));
	CPen *pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(120, 16);	pDC->LineTo(120, 336);
	pDC->MoveTo(232, 16);	pDC->LineTo(232, 336);
	pDC->MoveTo(16, 120);	pDC->LineTo(336, 120);
	pDC->MoveTo(16, 232);	pDC->LineTo(336, 232);


	// X와 O를 그림
	for( int i=0; i<9; i++)
	{
		if( m_nGameGrid[i] == EX)
			DrawX(pDC, i);
		else if( m_nGameGrid[i] == OH)
			DrawO(pDC, i);
	}
	pDC->SelectObject(pOldPen);
}

void CTicTacView::DrawX( CDC *pDC, int nPos)
{
	CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
	CPen *pOldPen = pDC->SelectObject( &pen);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16, 16);
	pDC->MoveTo(rect.left, rect.top);		pDC->LineTo(rect.right, rect.bottom);
	pDC->MoveTo(rect.left, rect.bottom);	pDC->LineTo(rect.right, rect.top);

	pDC->SelectObject(pOldPen);
}

void CTicTacView::DrawO( CDC *pDC, int nPos)
{
	CPen pen(PS_SOLID, 16, RGB(0, 0, 255));
	CPen *pOldPen = pDC->SelectObject( &pen);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16, 16);
	pDC->Ellipse(rect);

	pDC->SelectObject(pOldPen);
}

void CTicTacView::CheckForGameOver()
{
	int nWinner;

	//그리드에 세 개의 연속 X나 O가 있으면 승자를 선언하고 새로 게임을 시작
	if( nWinner = IsWinner ())
	{
		CString string = (nWinner == EX) ? _T("X wins!") : _T("O Win!");

		MessageBox(string, _T("Game Over"), MB_ICONEXCLAMATION | MB_OK);

		ResetGame();
	}

	// 그리드가 가득차면 새 게임을 시작
	else if( IsDraw() )
	{
		MessageBox(_T("It's a draw!"), _T("Game Over"), 
			MB_ICONEXCLAMATION | MB_OK);

		ResetGame();
	}
}


int CTicTacView::IsWinner()
{
	static int nPattern[8][3] = {
		0, 1, 2, 
		3, 4, 5, 
		6, 7, 8, 
		0, 3, 6, 
		1, 4, 7, 
		2, 5, 8, 
		0, 4, 8, 
		2, 4, 6
	};

	for( int i=0; i<8; i++)
	{
		if( (m_nGameGrid[nPattern[i][0]] == EX) &&
			(m_nGameGrid[nPattern[i][1]] == EX) &&
			(m_nGameGrid[nPattern[i][2]] == EX) )
			return EX;

		if( (m_nGameGrid[nPattern[i][0]] == OH) &&
			(m_nGameGrid[nPattern[i][1]] == OH) &&
			(m_nGameGrid[nPattern[i][2]] == OH) )
			return OH;
	}
	return 0;
}

BOOL CTicTacView::IsDraw()
{
	for( int i=0; i<9; i++)
	{
		if( m_nGameGrid[i] == 0 )
			return FALSE;
	}
	return TRUE;
}

void CTicTacView::ResetGame()
{
	m_nNextChar	= EX;

	::ZeroMemory(m_nGameGrid, 9 * sizeof(int));

	Invalidate();
}