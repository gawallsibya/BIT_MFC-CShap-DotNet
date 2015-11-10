//DC와 그리기 함수

#include <afxwin.h>

//#########################################################################

// 수백여개의 그리는 함수가 각각의 클래스에 들어있다면 오버헤드가 크다.

// 때문에 부모클래스인 CDC에 함수가 있고 CClientDC와 CWindowDC에 상속해준다.

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

 

        // 그외의 수백여개의 그리는 함수들..

};

 

// CClientDC의 실제모양

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

 

// CWindowDC의 실제 모양

class CWindowDC : public CDC

{

        CWindowDC( CWnd* pWnd )

        {

               m_hWnd = pWnd->m_hWnd;

 

               m_hDC = GetWindowDC( m_hWnd ); // 캡션바에 그릴때 주로 사용.

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

        virtual void Draw( CDC* pDC ) = 0; // 왜 CClient*가 아닌

                                           // CDC*인지를 알아야 한다.

                                           // 여러 종류의 자식 DC객체가 올수있다.

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

        // 모든 도형을 보관한다.

        CList<Shape*, Shape*> shapeList;

 

public:

        void OnRButtonDown( UINT nFlag, CPoint pt )
        {

               // STL로 했다면.

               // remove_if( s.begin(), s.end(), inRect ); // STL이면 편했다.

 
               // 연결리스트를 순회하면서 pt가 포함된 도형을 찾는다.

               // 해당 node를 list에서 제거한다.
               // 이순간 화면이 모두 지워지고 OnPaint() 호출.

               // 즉 list의 모든 요소로 그림을 다시 그리게 된다.

               InvalidateRect( NULL );

        }

 

        void OnLButtonDown( UINT nFlag, CPoint pt )
        {

               Shape* p = new Rect( pt.x, pt.y, pt.x+50, pt.y+50 );

 

               shapeList.AddTail( p ); // list에 추가.

 

               CClientDC dc(this);

               p->Draw( &dc ); // 객체 자신에게 그리도록 한다.!!

 

 

        //      CClientDC dc(this); // DC는 멤버로 있다.

        //      dc.Rectangle( pt.x, pt.y, pt.x + 50, pt.y + 50 );

               

        //      HDC hdc = ::GetDC( this->m_hWnd ); // 그리는 도구 DC 얻기

        //      ::Rectangle( hdc, pt.x, pt.y, pt.x + 50, pt.y + 50 );

        //      ::ReleaseDC( this->m_hWnd, hdc );

        }

 

        // 함수 모양.

        void OnPaint()

        {

               // GetDC가 아니라 BeginPaint로 얻어야 한다.

               // 즉 CClientDC가 아니라 CPaintDC로 얻어야 한다.

 

               CPaintDC dc(this);

 

               POSITION pos = shapeList.GetHeadPosition();

 

               while( pos != 0 )

               {

                       Shape* p = shapeList.GetNext( pos );

 

                       p->Draw( &dc ); // 객체에게 스스로 그리게 만든다.

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

 

// 숙제:

// 오른쪽 버튼을 클릭했을때 그 도형이 지워지게

// - 오른쪽 버튼을 클릭했을때 링크리스트를 순회하여

//   좌표상에 있는 최상위 도형을 삭제한다.
