// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Serialize.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}



// serialize �� �Ǵ� class �����--------------------------
struct People : public CObject				// 1
{
	int a;	int b;

	People() {}  // default ������ �ʿ�.	// 2

	void Serialize( CArchive& ar )			// 3
	{
		CObject::Serialize(ar);
		if( ar.IsStoring() )
			ar << a << b; // ����� �ִ´�.
		else
		{
			ar >> a >> b;
		}
	}

	DECLARE_SERIAL( People )				//4
};


IMPLEMENT_SERIAL( People, CObject ,1 )		//5

//-----------------------------------------------------------

////////////////////////////////////////////////////////



void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	
	//1) ���� ����
	CFile file("a.txt", CFile::modeCreate | CFile::modeWrite);

	//2) file�� ����� Archive �����.
	CArchive ar( &file, CArchive::store);

	int a = 10; RECT r = {10,10,20,20}; CString s = "hello";

	People p;
	p.a		= 10;
	p.b		= 20;
	ar << &p;		// ���� ����...!!!!!!

//	ar << a << r << s; // serialize

	ar.Close();
	file.Close();
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CFile file("a.txt", CFile::modeRead);
	
	// file�� ����� Archive �����.
	CArchive ar( &file, CArchive::load);

	int a ; RECT r; CString s;

	People *p = new People;
//	ar >> a >> r >> s; // serialize
	ar >> p;

	ar.Close();
	file.Close();
	int n	= p->a;
	int n1	= p->b;
	char temp[20];
	wsprintf(temp, "%d : %d", n, n1);
	MessageBox( temp );


	/*
	try
	{
		CFile file("b.txt", CFile::modeRead);

	}
	catch( CFileException* e )
	{
		if ( e->m_cause == CFileException::fileNotFound)
			MessageBox("ȭ���� �����ϴ�.");

		e->Delete(); // MFC���� ���ܴ� new�� ����� ������.
	}
	*/
}



