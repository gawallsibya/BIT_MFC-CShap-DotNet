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

 

         // ���ڷ� ���� ��ǥ�� ���� ������ ��ġ�ϰ� �ִ����� �˷��ش�.

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

         // ��� ������ �����Ѵ�.

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

 

                  shapeList.AddTail( p ); // list�� �߰�.

 

                  CClientDC dc(this);

                  p->Draw( &dc ); // ��ü �ڽſ��� �׸����� �Ѵ�.!!

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

