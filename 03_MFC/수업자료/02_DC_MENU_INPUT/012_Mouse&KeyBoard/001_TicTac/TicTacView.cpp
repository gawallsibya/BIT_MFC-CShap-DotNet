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
	// 0�� �����̰ų� �׸��� �ܺο��� Ŭ���Ͽ��ų� ������� ����
	// ������ Ŭ���ϸ� �ƹ��͵� ���� ����
	if( m_nNextChar != EX)
		return;

	int nPos = GetRectID( point);
	if(( nPos == -1) || (m_nGameGrid[nPos] != 0 ))
		return;

	// �׸��忡 X�� �߰��ϰ� m_nNextChar�� ���
	m_nGameGrid[nPos] = EX;
	m_nNextChar		  = OH;

	// ȭ�鿡 X�� ǥ���ϰ� ���и� �˾� ����.
	CClientDC dc(this);
	DrawX(&dc, nPos);
	CheckForGameOver();
	
	CView::OnLButtonDown(nFlags, point);
}


void CTicTacView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// X�� �����̰ų� �׸��� �ܺο��� Ŭ���Ͽ��ų� ������� ����
	// ������ Ŭ���ϸ� �ƹ��͵� ���� ����
	if( m_nNextChar != OH)
		return;

	int nPos = GetRectID( point);
	if(( nPos == -1) || (m_nGameGrid[nPos] != 0 ))
		return;

	// �׸��忡 O�� �߰��ϰ� m_nNextChar�� ���
	m_nGameGrid[nPos] = OH;
	m_nNextChar		  = EX;

	// ȭ�鿡 O�� ǥ���ϰ� ���и� �˾� ����.
	CClientDC dc(this);
	DrawO(&dc, nPos);
	CheckForGameOver();	
	CView::OnRButtonDown(nFlags, point);
}


void CTicTacView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{

	// ���� �׸��带 �����ϴ� ���� �������� ���ʸ��콺 DB Ŭ���ϸ�
	// ������ �缳��

	CClientDC	dc(this);
	if( dc.GetPixel( point) == RGB(0, 0, 0))
		ResetGame();

	CView::OnLButtonDblClk(nFlags, point);
}


int CTicTacView::GetRectID( CPoint point)
{
	// �� �׸����� 9�� �簢���� ���ȴ��� �˻��ϰ�
	// (point.x, point.y)�� �簢�� �ȿ� ������ ID(0~8)�� ��ȯ
	for( int i=0; i<9; i++)
	{
		if( m_rcSquares[i].PtInRect(point))
			return i;
	}
	return -1;
}


void CTicTacView::DrawBoard(CDC *pDC)
{
	// tic-tac-toe�׸��带 �����ϴ� ���� �׸�
	CPen pen(PS_SOLID, 16, RGB(0, 0, 0));
	CPen *pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(120, 16);	pDC->LineTo(120, 336);
	pDC->MoveTo(232, 16);	pDC->LineTo(232, 336);
	pDC->MoveTo(16, 120);	pDC->LineTo(336, 120);
	pDC->MoveTo(16, 232);	pDC->LineTo(336, 232);


	// X�� O�� �׸�
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

	//�׸��忡 �� ���� ���� X�� O�� ������ ���ڸ� �����ϰ� ���� ������ ����
	if( nWinner = IsWinner ())
	{
		CString string = (nWinner == EX) ? _T("X wins!") : _T("O Win!");

		MessageBox(string, _T("Game Over"), MB_ICONEXCLAMATION | MB_OK);

		ResetGame();
	}

	// �׸��尡 �������� �� ������ ����
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