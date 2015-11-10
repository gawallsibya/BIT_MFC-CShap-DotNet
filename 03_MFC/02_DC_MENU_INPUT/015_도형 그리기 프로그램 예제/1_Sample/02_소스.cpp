#include <afxwin.h>

#include <afxtempl.h>

 

class Shape

{

public:

         virtual void Draw( CDC* pDC )    = 0; 

         virtual BOOL IsLie( CPoint& pt ) = 0;

};

 

class Rect : public Shape

{

         int x1, y1, x2, y2;

 

public:

         Rect( int _x1=0, int _y1=0, int _x2=0, int _y2=0 ) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

 

         virtual void Draw( CDC* pDC )

         {

                  pDC->Rectangle( x1, y1, x2, y2 );

         }

 

         // 인자로 받은 좌표에 현재 도형이 위치하고 있는지를 알려준다.

         BOOL IsLie( CPoint& pt )

         {

                  if( pt.x >= x1 && pt.x <= x2 && pt.y >= y1 && pt.y <= y2 )

                           return TRUE;

                  else

                           return FALSE;

         }

};

 

class CMainFrame : public CFrameWnd

{

         // 모든 도형을 보관한다.

         CList<Shape*, Shape*> shapeList;

 

public:

         void OnRButtonDown( UINT nFlag, CPoint pt )
         {
                  POSITION pos = shapeList.GetTailPosition();

                  while( pos )
                  {
                           if( shapeList.GetAt( pos )->IsLie( pt ) )
                           {
                                   shapeList.RemoveAt( pos );

                                   break;

                           }

                           shapeList.GetPrev( pos );                   

                  }

 

                  InvalidateRect( NULL );

         }

 

         void OnLButtonDown( UINT nFlag, CPoint pt )

         {

                  Shape* p = new Rect( pt.x, pt.y, pt.x+50, pt.y+50 );

 

                  shapeList.AddTail( p ); // list에 추가.

 

                  CClientDC dc(this);

                  p->Draw( &dc ); // 객체 자신에게 그리도록 한다.!!

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

    ON_WM_PAINT()
 END_MESSAGE_MAP()

  

//----------------------------------------------------------

 

class CMyApp : public CWinApp

{

         virtual BOOL InitInstance()

         {

                  CMainFrame* pFrame = new CMainFrame;

                  pFrame->Create( 0, "" );

                  pFrame->ShowWindow( SW_SHOW );

 

                  m_pMainWnd = pFrame;

 

                  return TRUE;

         }

};

 

CMyApp theApp;

