// MyTic.cpp: implementation of the CMyTic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TicTac.h"
#include "MyTic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const CRect CMyTic::m_rcSquares[9] = {
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


CMyTic::CMyTic()
{
	m_nNextChar		= EX;
	::ZeroMemory(m_nGameGrid, 9*sizeof(int));

	m_gamemode		= 1;
	m_gamecount		= 0;
	m_pParentView	= NULL;

	m_OWincount		= 0;
	m_XWincount		= 0;
}


CMyTic::~CMyTic()
{

}


void CMyTic::ClickXGamer(CWnd *pView,CPoint point)
{
	if( m_nNextChar != EX)
		return;

	int nPos = GetRectID( point);
	if(( nPos == -1) || (m_nGameGrid[nPos] != 0 ))
		return;

	// 그리드에 X를 추가하고 m_nNextChar를 토글
	m_nGameGrid[nPos] = EX;
	m_nNextChar		  = OH;

	// 화면에 X를 표시하고 승패를 알아 낸다.
	CClientDC dc(pView);
	DrawX(&dc, nPos);
	int idx = CheckForGameOver();	
	if ( idx == 1)
		m_XWincount++;
}

void CMyTic::ClickOGamer(CWnd *pView,CPoint point)
{
	if( m_nNextChar != OH)
		return;

	int nPos = GetRectID( point);
	if(( nPos == -1) || (m_nGameGrid[nPos] != 0 ))
		return;

	// 그리드에 O를 추가하고 m_nNextChar를 토글
	m_nGameGrid[nPos] = OH;
	m_nNextChar		  = EX;

	// 화면에 O를 표시하고 승패를 알아 낸다.
	CClientDC dc(pView);
	DrawO(&dc, nPos);
	int idx = CheckForGameOver();	
	if ( idx == 1)
		m_OWincount++;
}

int CMyTic::GetRectID(CPoint point)
{
	for( int i=0; i<9; i++)
	{
		if( m_rcSquares[i].PtInRect(point))
			return i;
	}
	return -1;
}

void CMyTic::DrawBoard(CDC *pDC)
{
	// tic-tac-toe그리드를 정의하는 선을 그림
	CPen pen(PS_SOLID, 16, RGB(125, 125, 125));
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

void CMyTic::DrawX(CDC *pDC, int nPos)
{
	CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
	CPen *pOldPen = pDC->SelectObject( &pen);

	CRect rect = m_rcSquares[nPos];
 	rect.DeflateRect(16, 16);
 	pDC->MoveTo(rect.left, rect.top);		pDC->LineTo(rect.right, rect.bottom);
 	pDC->MoveTo(rect.left, rect.bottom);	pDC->LineTo(rect.right, rect.top);
	pDC->SelectObject(pOldPen);
}


void CMyTic::DrawO(CDC *pDC, int nPos)
{
	CPen pen(PS_SOLID, 16, RGB(0, 0, 255));
	CPen *pOldPen = pDC->SelectObject( &pen);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16, 16);
	pDC->Ellipse(rect);

	pDC->SelectObject(pOldPen);
}

int CMyTic::CheckForGameOver()
{
	int nWinner;

	//그리드에 세 개의 연속 X나 O가 있으면 승자를 선언하고 새로 게임을 시작
	if( nWinner = IsWinner())
	{
		CString string = (nWinner == EX) ? _T("X wins!") : _T("O Win!");

		MessageBox(NULL, string, _T("Game Over"), MB_ICONEXCLAMATION | MB_OK);

		if(m_gamemode > ++m_gamecount) 
			ReStartGame();
		else
			MessageBox(NULL, _T("게임 종료"), _T("게임 종료"), 	MB_OK);

		return 1;
	}

	// 그리드가 가득차면 새 게임을 시작
	else if( IsDraw() )
	{
		MessageBox(NULL, _T("It's a draw!"), _T("Game Over"), 
			MB_ICONEXCLAMATION | MB_OK);

		if(m_gamemode > ++m_gamecount) 
			ReStartGame();
		else
			MessageBox(NULL, _T("게임 종료"), _T("게임 종료"), 	MB_OK);

		return 2;
	}
	return 0;
}


int CMyTic::IsWinner()
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

BOOL CMyTic::IsDraw()
{
	for( int i=0; i<9; i++)
	{
		if( m_nGameGrid[i] == 0 )
			return FALSE;
	}
	return TRUE;
}


void CMyTic::ResetGame(CWnd *pView, CPoint point)
{
	CClientDC	dc(pView);
	if( dc.GetPixel( point) == RGB(125, 125, 125))
	{
		ReStartGame();
	}
}


void CMyTic::ReStartGame()
{
	m_nNextChar	= EX;
	::ZeroMemory(m_nGameGrid, 9 * sizeof(int));
	m_pParentView->Invalidate();
}


void CMyTic::ParentGetView(CWnd *pView)
{
	m_pParentView = pView;
}
