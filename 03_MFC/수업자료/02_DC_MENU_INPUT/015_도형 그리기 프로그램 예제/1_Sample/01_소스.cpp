//DC�� �׸��� �Լ�

#include <afxwin.h>

//#########################################################################

// ���鿩���� �׸��� �Լ��� ������ Ŭ������ ����ִٸ� ������尡 ũ��.

// ������ �θ�Ŭ������ CDC�� �Լ��� �ְ� CClientDC�� CWindowDC�� ������ش�.

/*

class CDC

{

public:

        HDC m_hDC;

        HWND m_hWnd;

        

        void Rectangle( int x, int y, int xx, int yy )

        {

               ::Rectangle( m_hDC, x, y, xx, yy );

        }

 

        // �׿��� ���鿩���� �׸��� �Լ���..

};

 

// CClientDC�� �������

class CClinetDC : public CDC

{

        CClientDC( CWnd* pWnd )

        {

               m_hWnd = pWnd->m_hWnd;

 

               m_hDC = GetDC( m_hWnd );

        }

 

        ~CClientDC()

        {

               ReleaseDC( m_hWnd, m_hDC );

        }

 

        

};

 

// CWindowDC�� ���� ���

class CWindowDC : public CDC

{

        CWindowDC( CWnd* pWnd )

        {

               m_hWnd = pWnd->m_hWnd;

 

               m_hDC = GetWindowDC( m_hWnd ); // ĸ�ǹٿ� �׸��� �ַ� ���.

        }

 

        ~CWindowDC()

        {

               ReleaseDC( m_hWnd, m_hDC );

        }

};

*/

 

class Shape

{

public:

        virtual void Draw( CDC* pDC ) = 0; // �� CClient*�� �ƴ�

                                           // CDC*������ �˾ƾ� �Ѵ�.

                                           // ���� ������ �ڽ� DC��ü�� �ü��ִ�.

};

 

class Rect : public Shape

{

        int x1, y1, x2, y2;

public:

        Rect( int _x1=0, int _y1=0, int _x2=0, int _y2=0 ) : 

                              x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

        virtual void Draw( CDC* pDC )
        {
               pDC->Rectangle( x1, y1, x2, y2 );

        }

};

 

//-----------------------------------------------------------------------------

 

#include <afxtempl.h>


class CMainFrame : public CFrameWnd

{

        // ��� ������ �����Ѵ�.

        CList<Shape*, Shape*> shapeList;

 

public:

        void OnRButtonDown( UINT nFlag, CPoint pt )
        {

               // STL�� �ߴٸ�.

               // remove_if( s.begin(), s.end(), inRect ); // STL�̸� ���ߴ�.

 
               // ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 pt�� ���Ե� ������ ã�´�.

               // �ش� node�� list���� �����Ѵ�.
               // �̼��� ȭ���� ��� �������� OnPaint() ȣ��.

               // �� list�� ��� ��ҷ� �׸��� �ٽ� �׸��� �ȴ�.

               InvalidateRect( NULL );

        }

 

        void OnLButtonDown( UINT nFlag, CPoint pt )
        {

               Shape* p = new Rect( pt.x, pt.y, pt.x+50, pt.y+50 );

 

               shapeList.AddTail( p ); // list�� �߰�.

 

               CClientDC dc(this);

               p->Draw( &dc ); // ��ü �ڽſ��� �׸����� �Ѵ�.!!

 

 

        //      CClientDC dc(this); // DC�� ����� �ִ�.

        //      dc.Rectangle( pt.x, pt.y, pt.x + 50, pt.y + 50 );

               

        //      HDC hdc = ::GetDC( this->m_hWnd ); // �׸��� ���� DC ���

        //      ::Rectangle( hdc, pt.x, pt.y, pt.x + 50, pt.y + 50 );

        //      ::ReleaseDC( this->m_hWnd, hdc );

        }

 

        // �Լ� ���.

        void OnPaint()

        {

               // GetDC�� �ƴ϶� BeginPaint�� ���� �Ѵ�.

               // �� CClientDC�� �ƴ϶� CPaintDC�� ���� �Ѵ�.

 

               CPaintDC dc(this);

 

               POSITION pos = shapeList.GetHeadPosition();

 

               while( pos != 0 )

               {

                       Shape* p = shapeList.GetNext( pos );

 

                       p->Draw( &dc ); // ��ü���� ������ �׸��� �����.

               }

        }

 

        DECLARE_MESSAGE_MAP()

};

 

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

 

ON_WM_LBUTTONDOWN()

ON_WM_PAINT()

 

END_MESSAGE_MAP()

 

 

//----------------------------------------------------------

 

class CMyApp : public CWinApp

{

        virtual BOOL InitInstance()

        {

               CMainFrame* pFrame = new CMainFrame;

               pFrame->Create( 0, "");

               pFrame->ShowWindow( SW_SHOW );

 

               m_pMainWnd = pFrame;

 

               return TRUE;

        }

};

 

CMyApp theApp;

 

// ����:

// ������ ��ư�� Ŭ�������� �� ������ ��������

// - ������ ��ư�� Ŭ�������� ��ũ����Ʈ�� ��ȸ�Ͽ�

//   ��ǥ�� �ִ� �ֻ��� ������ �����Ѵ�.
