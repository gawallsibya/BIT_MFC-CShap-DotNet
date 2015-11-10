// VisualKBView.cpp : implementation of the CVisualKBView class
//

#include "stdafx.h"
#include "VisualKB.h"

#include "VisualKBDoc.h"
#include "VisualKBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisualKBView

IMPLEMENT_DYNCREATE(CVisualKBView, CView)

BEGIN_MESSAGE_MAP(CVisualKBView, CView)
	//{{AFX_MSG_MAP(CVisualKBView)
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
	ON_WM_SYSKEYUP()
	ON_WM_SYSCHAR()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisualKBView construction/destruction


CVisualKBView::~CVisualKBView()
{
}

BOOL CVisualKBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVisualKBView drawing



/////////////////////////////////////////////////////////////////////////////
// CVisualKBView diagnostics

#ifdef _DEBUG
void CVisualKBView::AssertValid() const
{
	CView::AssertValid();
}

void CVisualKBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVisualKBDoc* CVisualKBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVisualKBDoc)));
	return (CVisualKBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVisualKBView message handlers
// ������ ó�� 
CVisualKBView::CVisualKBView()
{
	// TODO: add construction code here
	m_nTextPos		= 0;
	m_nMsgPos		= 0;

	m_hCursorArrow	= AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	m_hCursorIBeam  = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);

}

// WM_CREATE �޽��� �ڵ鷯 
int CVisualKBView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// ȭ�� ������ ���� �޶����� �ɹ� ���� �� �ʱ�ȭ
	CClientDC	dc(this);

	TEXTMETRIC	tm;
	dc.GetTextMetrics(&tm);
	m_cxChar		= tm.tmAveCharWidth;
	m_cyChar		= tm.tmHeight;
	m_cyLine		= tm.tmHeight + tm.tmExternalLeading;

	m_rcTextBoxBorder.SetRect( 16, 16, (m_cxChar * 64 ) + 16, 
		((m_cyChar *3 ) / 2 ) + 16 );

	m_rcTextBox		= m_rcTextBoxBorder;
	m_rcTextBox.InflateRect( -2, -2 );

	m_rcMsgBoxBorder.SetRect( 16,(m_cyChar * 4)+16,
		(m_cxChar*64) + 16, (m_cyLine *MAX_STRINGS) + (m_cyChar *6)+16);
		

	m_rcScroll.SetRect( m_cxChar + 16, (m_cyChar *6) + 16, 
		(m_cxChar * 63) + 16, (m_cyLine * MAX_STRINGS) + 
		(m_cyChar * 5 ) + 16 );

	m_ptTextOrigin.x	= m_cxChar + 16;
	m_ptTextOrigin.y	= (m_cyChar / 4 ) + 16;
	m_ptCaretPos		= m_ptTextOrigin;
	m_nTextLimit		= (m_cxChar * 63);

	m_ptHeaderOrigin.x	= m_cxChar + 16;
	m_ptHeaderOrigin.y  = (m_cyChar * 3 ) + 16;

	m_ptUpperMsgOrigin.x	= m_cxChar + 16;
	m_ptUpperMsgOrigin.y	= (m_cyChar * 5) + 16;

	m_ptLowerMsgOrigin.x	= m_cxChar + 16;
	m_ptLowerMsgOrigin.y	= (m_cyChar * 5) + (m_cyLine *(MAX_STRINGS - 1)) + 16;

	m_nTabStops[0]		= (m_cxChar * 24 ) + 16;
	m_nTabStops[1]		= (m_cxChar * 30 ) + 16;
	m_nTabStops[2]		= (m_cxChar * 36 ) + 16;
	m_nTabStops[3]		= (m_cxChar * 42 ) + 16;
	m_nTabStops[4]		= (m_cxChar * 46 ) + 16;
	m_nTabStops[5]		= (m_cxChar * 50 ) + 16;
	m_nTabStops[6]		= (m_cxChar * 54 ) + 16;

	// â ũ�� ����
	CRect	rect(0, 0, m_rcMsgBoxBorder.right	+ 16,
		m_rcMsgBoxBorder.bottom	+ 16);

	CalcWindowRect(&rect);

	SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
	
	return 0;
}

void CVisualKBView::OnDraw(CDC* pDC)
{
	CVisualKBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	// �ؽ�Ʈ ���ڿ� �޽��� ����� �ѷ��δ� �簢�� �׸���
	pDC->DrawEdge( m_rcTextBoxBorder, EDGE_SUNKEN, BF_RECT);
	pDC->DrawEdge( m_rcMsgBoxBorder, EDGE_SUNKEN, BF_RECT);

	// â�� ��Ÿ���� ��� �ؽ�Ʈ �׸���
	DrawInputText(pDC);
	DrawMessageHeader(pDC);
	DrawMessages(pDC);
}


void CVisualKBView::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	// VisualKB â�� �Է� ��Ŀ���� ������ ĳ�� ǥ�� 
	CreateSolidCaret(max(2, ::GetSystemMetrics(SM_CXBORDER)), m_cyChar);	

	SetCaretPos(m_ptCaretPos);

	ShowCaret();
}

void CVisualKBView::OnKillFocus(CWnd* pNewWnd) 
{
	CView::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
	// VisualKBâ�� �Է� ��Ŀ���� ������ ĳ�� ����
	HideCaret();

	m_ptCaretPos	= GetCaretPos();
	::DestroyCaret();
	
}

BOOL CVisualKBView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	// Ŀ���� �ؽ�Ʈ ���� ���� ������ I-�����, 
	// �� �̿��� ��ҿ� ������ ȭ��ǥ�� ����
	if(nHitTest == HTCLIENT )
	{
		DWORD dwPos = ::GetMessagePos();
		CPoint point(LOWORD(dwPos), HIWORD(dwPos));
		ScreenToClient(&point);
		::SetCursor(m_rcTextBox.PtInRect(point) ? m_hCursorIBeam : m_hCursorArrow);
		return TRUE;
	}
	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void CVisualKBView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// ���� ���콺 ���߷� �ؽ�Ʈ ���ڸ� Ŭ���ϸ� ĳ�� �̵�
	if( m_rcTextBox.PtInRect( point))
	{
		m_nTextPos = GetNearestPos(point);
		PositionCaret();
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CVisualKBView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	ShowMessage(_T("WM_KEYDOWN"), nChar, nRepCnt, nFlags);

	// ����, ������, HOME, END Ű�� ������ ĳ�� �̵�
	switch( nChar)
	{
	case VK_LEFT:
		if( m_nTextPos != 0 )
		{
			m_nTextPos--;
			PositionCaret();
		}
		break;
	case VK_RIGHT:
		if( m_nTextPos != m_strInputText.GetLength())
		{
			m_nTextPos++;
			PositionCaret();
		}
		break;
	case VK_HOME:
		m_nTextPos = 0;
		PositionCaret();
		break;
	case VK_END:
		m_nTextPos = m_strInputText.GetLength();
		PositionCaret();
		break;
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CVisualKBView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	ShowMessage(_T("WM_CHAR"), nChar, nRepCnt, nFlags);

	CClientDC	dc(this);

	// Ű���忡�� �� �Էµ� ���ڸ� ���Ѵ�.
	switch(nChar)
	{
	case VK_ESCAPE:
	case VK_RETURN:
		m_strInputText.Empty();
		m_nTextPos = 0;
		break;
	case VK_BACK:
		if( m_nTextPos != 0 )
		{
			m_strInputText = m_strInputText.Left(m_nTextPos - 1 ) +
				m_strInputText.Right(m_strInputText.GetLength() -
				m_nTextPos);

			m_nTextPos--;
		}
		break;
	default:
		if(( nChar >= 0 ) && (nChar <= 31))
			return;
		if( m_nTextPos == m_strInputText.GetLength())
		{
			m_strInputText += nChar;
			m_nTextPos++;
		}
		else
			m_strInputText.SetAt(m_nTextPos++, nChar);

		CSize size = dc.GetTextExtent(m_strInputText, m_strInputText.GetLength());

		if( ( m_ptTextOrigin.x + size.cx) > m_nTextLimit)
		{
			m_strInputText = nChar;
			m_nTextPos = 1;
		}
		break;
	}

	// �ؽ�Ʈ ���� ���� ����
	HideCaret();
	DrawInputText(&dc);
	PositionCaret(&dc);
	ShowCaret();
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CVisualKBView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	ShowMessage(_T("WM_KEYUP"), nChar, nRepCnt, nFlags);
	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}



void CVisualKBView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	ShowMessage(_T("WM_SYSKEYDOWN"), nChar, nRepCnt, nFlags);
	
	CView::OnSysKeyDown(nChar, nRepCnt, nFlags);
}



void CVisualKBView::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	ShowMessage(_T("WM_SYSCHAR"), nChar, nRepCnt, nFlags);
	
	CView::OnSysChar(nChar, nRepCnt, nFlags);
}


void CVisualKBView::OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	ShowMessage(_T("WM_SYSKEYUP"), nChar, nRepCnt, nFlags);
	
	CView::OnSysKeyUp(nChar, nRepCnt, nFlags);
}


void CVisualKBView::PositionCaret(CDC *pDC)
{
	BOOL	bRelease = FALSE;

	// pDC�� NULL�̸� ��ġ ���ؽ�Ʈ ����
	if( pDC == NULL)
	{
		pDC = GetDC();
		bRelease	= TRUE;
	}

	// ĳ���� ��ġ�� ������ �ٷ� ������ ��, m_nTextPos�� �����
	// ()-��� �ε����� �ű�
	CPoint point	= m_ptTextOrigin;
	CString string	= m_strInputText.Left(m_nTextPos);
	point.x += (pDC->GetTextExtent(string, string.GetLength())).cx;

	SetCaretPos(point);

	// �� �Լ� ������ ��ġ ���ؽ�Ʈ�� ���� �Ǿ����� ����
	if( bRelease)
		ReleaseDC(pDC);
}


int CVisualKBView::GetNearestPos(CPoint point)
{
	//(point.x, point.y)�� �ؽ�Ʈ ������ �ؽ�Ʈ ���ʿ� ������
	// 0�� ��ȯ

	if( point.x <= m_ptTextOrigin.x)
		return 0;

	//(point.x, point.y)�� �ؽ�Ʈ ������ �ؽ�Ʈ  �����ʿ� ������
	// ���ڿ��� ���̸� ��ȯ
	CClientDC	dc(this);
	int nLen = m_strInputText.GetLength();
	if( point.x >= ( m_ptTextOrigin.x + 
		(dc.GetTextExtent(m_strInputText, nLen)).cx))
		return nLen;

	//(point.x, point.y)�� �ؽ�Ʈ ������ �ؽ�Ʈ ������ ������
	// ���� �ε����� ��ȯ
	int i = 0;
	int nPrevChar	= m_ptTextOrigin.x;
	int nNextChar	= m_ptTextOrigin.x;

	while( nNextChar < point.x)
	{
		i++;
		nPrevChar	= nNextChar;
		nNextChar	=m_ptTextOrigin.x + 
			(dc.GetTextExtent(m_strInputText.Left(i), i)).cx;
	}
	return ((point.x - nPrevChar) < ( nNextChar - point.x)) ? i -1 : i;

}


void CVisualKBView::DrawInputText(CDC *pDC)
{
	pDC->ExtTextOut(m_ptTextOrigin.x, m_ptTextOrigin.y, 
		ETO_OPAQUE, m_rcTextBox, m_strInputText, NULL);
}

void CVisualKBView::ShowMessage(LPCTSTR pszMessage, UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// �޽��� ���ڿ� ���� ����
	CString string;
	string.Format(_T("%s\t %u\t %u\t %u\t %u\t %u\t %u\t %u"),
		pszMessage, nChar, nRepCnt, nFlags & 0xff,
		(nFlags >> 8 ) & 0x01, (nFlags >> 13 ) & 0x01,
		(nFlags >> 14 ) & 0x01, ( nFlags >> 15) & 0x01);

	// �ٸ� �޽��� ���ڿ��� ���� �ø��� ��ũ�� �簢���� ��ȿȭ�ƿ� OnPaint�� ȣ����� 
	// �ʵ��� �Ѵ�.
	ScrollWindow(0, -m_cyLine, &m_rcScroll);
	ValidateRect(m_rcScroll);

	// �� �޽��� ���ڿ��� ����ϰ� â�� ǥ��
	CClientDC	dc(this);
	dc.SetBkColor((COLORREF)::GetSysColor(COLOR_3DFACE));

	m_strMessages[m_nMsgPos] = string;
	dc.TabbedTextOut(m_ptLowerMsgOrigin.x, m_ptLowerMsgOrigin.y,
		m_strMessages[m_nMsgPos], m_strMessages[m_nMsgPos].GetLength(),
		sizeof(m_nTabStops), m_nTabStops, m_ptLowerMsgOrigin.x);

	// ���� �޽��� ���ڿ��� ����� �迭 �ε��� ����
	if( ++m_nMsgPos == MAX_STRINGS)
		m_nMsgPos = 0;
}

void CVisualKBView::DrawMessageHeader(CDC *pDC)
{
	static CString string = 
		_T("Message\tChar\tRep\tScan\tExt\tCon\tPrv\tTran");

	pDC->SetBkColor((COLORREF)::GetSysColor(COLOR_3DFACE));
	pDC->TabbedTextOut( m_ptHeaderOrigin.x, m_ptHeaderOrigin.y,
		string, string.GetLength(), sizeof(m_nTabStops), m_nTabStops, 
		m_ptHeaderOrigin.x);
}

void CVisualKBView::DrawMessages(CDC *pDC)
{
	int nPos = m_nMsgPos;
	pDC->SetBkColor((COLORREF)::GetSysColor(COLOR_3DFACE));

	for( int i=0; i<MAX_STRINGS; i++)
	{
		pDC->TabbedTextOut(m_ptUpperMsgOrigin.x, 
			m_ptUpperMsgOrigin.y + ( m_cyLine * i),
			m_strMessages[nPos], m_strMessages[nPos].GetLength(),
			sizeof(m_nTabStops), m_nTabStops, m_ptUpperMsgOrigin.x);
	}
	if( ++nPos == MAX_STRINGS)
		nPos = 0;
}










