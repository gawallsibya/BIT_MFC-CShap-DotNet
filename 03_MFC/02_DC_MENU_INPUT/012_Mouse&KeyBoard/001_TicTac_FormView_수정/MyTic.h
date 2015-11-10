// MyTic.h: interface for the CMyTic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTIC_H__ABB0EB93_8C58_4D1D_B28C_92F83B970527__INCLUDED_)
#define AFX_MYTIC_H__ABB0EB93_8C58_4D1D_B28C_92F83B970527__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define EX	1
#define OH	2

class CMyTic  
{
private:
	static const	CRect m_rcSquares[9];	// Grid coordinates
	int		m_nGameGrid[9];					// Grid contents
	int		m_nNextChar;					// Next Caracter( EX or OH)
	CWnd*	m_pParentView;

public:
	int		m_gamemode;			// ���� �� 
	int		m_gamecount;
	int		m_OWincount;
	int		m_XWincount;
public:
	// ������ �׸���
	void DrawBoard(CDC *pDC);

	// ���� �ٽ� �����ϱ�
	void ResetGame(CWnd *pView=NULL, CPoint point=NULL);

	// ���� ����(���̸� ��ǥ ����) 
	void ClickOGamer(CWnd *pView, CPoint point);
	void ClickXGamer(CWnd *pView, CPoint point);

private:
	void DrawO(CDC* pDC, int nPos);
	void DrawX( CDC *pDC, int nPos);
	int IsWinner();
	BOOL IsDraw();

	int CheckForGameOver();
	int GetRectID( CPoint point);
	void ReStartGame();

public:
	void ParentGetView(CWnd *pView);
	CMyTic();
	virtual ~CMyTic();

};

#endif // !defined(AFX_MYTIC_H__ABB0EB93_8C58_4D1D_B28C_92F83B970527__INCLUDED_)
