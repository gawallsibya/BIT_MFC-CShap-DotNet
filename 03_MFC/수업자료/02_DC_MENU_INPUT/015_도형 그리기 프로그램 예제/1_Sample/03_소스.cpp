/*
������ ���콺 ������ ��ư���� Ŭ���� ���¿��� �����̸� ������ ������ �̵���ų�� �ֽ��ϴ�.

 

��ũ�����̽� ��ü���ϰ� �ҽ� ���ϵ� ���� ÷���Ͽ����ϴ�!

 

[���� ����]

���� ���콺�� ������ ������ Ŀ�� ���������� ��ǥ�� ����Ͽ� ������ �׸��� ���ֽ��ϴ�.

������ ���� �ڵ带 �״�� ����� ��� ������ ���콺 Ŭ�����¿��� �̵��Ҷ� ������ ����������

Ŀ�� ������ �κ����� �̵��ϰ� �˴ϴ�.

�̷� ������ �����ϱ����� ��� ����(cx, xy)�� ����� �ε巴�� �̵� �ǵ��� ��������ϴ�.

 

������ ���� ������۸��� �ƴϰ� �ڷᱸ���� ��ǥ�� �����Ͽ� �ٽ� �ѷ��ִ� ���·� ������� �ֱ⶧����

�ణ�� �������� �����ֽ��ϴ�. ������ �̵���Ű�� �ܻ� ������^^

 */

#include <afxwin.h>

#include <afxtempl.h>

 

class Shape

{

public:

         virtual void Draw( CDC* pDC ) = 0; 

         virtual BOOL IsLie( const CPoint& pt ) const = 0;

};

 

class Rect : public Shape

{

         int x1, y1, x2, y2, cx, cy;

 

public:

         Rect( int _x1=0, int _y1=0, int _x2=0, int _y2=0 ) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), cx(0), cy(0) {}

 

         virtual void Draw( CDC* pDC )

         {

                  pDC->Rectangle( x1-cx, y1-cy, x2-cx, y2-cy );

         }

 

         // ���ڷ� ���� ��ǥ�� ���� ������ ��ġ�ϰ� �ִ����� �˷��ش�.

         BOOL IsLie( const CPoint& pt ) const

         {

                  if( pt.x >= x1 && pt.x <= x2 && pt.y >= y1 && pt.y <= y2 )

                           return TRUE;

                  else

                           return FALSE;

         }

 

         const RECT GetRect()

         {

                  RECT rect;

                  rect.left   = x1;

                  rect.right  = x2;

                  rect.top    = y1;

                  rect.bottom = y2;

 

                  return rect;

         }

 

         // ������ ��ǥ���� �����Ѵ�.

         void SetRectPos( const RECT& r )

         {

                  x1 = r.left;

                  y1 = r.top;

                  x2 = r.right;

                  y2 = r.bottom;

         }

 

         // Ŀ���� ������ ��ġ�� �����ϰ� ������ǥ���� ����

         void SetCurPos( const int& x, const int& y )

         {

                  cx = x;

                  cy = y;

         }

 

         const int GetCx() const

         {

                  return cx;

         }

 

         const int GetCy() const

         {

                  return cy;

         }

};

 

class CMainFrame : public CFrameWnd

{

         // ��� ������ �����Ѵ�.

         CList<Shape*, Shape*> shapeList;

 

         BOOL bRBtnClick;

 

public:

         CMainFrame() : bRBtnClick(FALSE) {}

 

 

         void OnLButtonDown( UINT nFlag, CPoint pt )

         {

                  Shape* p = new Rect( pt.x, pt.y, pt.x+50, pt.y+50 );

 

                  shapeList.AddTail( p ); // list�� �߰�.

 

                  CClientDC dc(this);

                  p->Draw( &dc ); // ��ü �ڽſ��� �׸����� �Ѵ�.!!

         }

 

         void OnRButtonDown( UINT nFlag, CPoint pt )

         {                 

                  POSITION pos = shapeList.GetTailPosition();

 

                  while( pos )

                  {

                           if( shapeList.GetAt( pos )->IsLie( pt ) )

                           {

                                   RECT rect;

 

                                   bRBtnClick = TRUE;

 

                                   rect = ((Rect*)(shapeList.GetAt( pos )))->GetRect();

                                   shapeList.RemoveAt( pos );

 

                                   Rect* p = new Rect( rect.left, rect.top, rect.right, rect.bottom );

                                   p->SetCurPos( pt.x-rect.left, pt.y-rect.top );                                  

 

                                   shapeList.AddTail( p );

 

                                   break;

                           }

                           shapeList.GetPrev( pos );                   

                  }                 

         }

 

         void OnRButtonUp( UINT nFlag, CPoint pt )

         {

                  // ������ ������ ���� ������ ��Ȯ�� ��ġ�� �׸��� ���ߴ�.

                  // ������ ������ ��ġ���� �ٽ� ������ ���ƾ� �Ѵ�.            

                  bRBtnClick = FALSE;

 

                  Rect* p = (Rect*)shapeList.GetTail();

                  RECT  r = p->GetRect();

                  int  cx = p->GetCx();

                  int  cy = p->GetCy();

 

                  r.left   = r.left - cx;

                  r.right  = r.right - cx;

                  r.top    = r.top - cy;

                  r.bottom = r.bottom - cy;

 

                  p->SetRectPos( r );        

                  p->SetCurPos( 0, 0 );

         }        

 

         void OnMouseMove( UINT nFlag, CPoint pt )

         {

                  static CClientDC dc(this);

 

                  if( bRBtnClick )

                  {

                           Rect* p;

                           int cx, cy;

 

                           p = (Rect*)shapeList.RemoveTail();

                           cx = p->GetCx();

                           cy = p->GetCy();

                           delete p;

 

                           p = new Rect( pt.x, pt.y, pt.x+50, pt.y+50 );

                           p->SetCurPos( cx, cy );

                           shapeList.AddTail( p );

 

                           RECT rect;

                           rect.left   = pt.x-(cx+50);

                           rect.right  = pt.x+100-cx;

                           rect.top    = pt.y-(cy+50);

                           rect.bottom = pt.y+100-cy;

 

                           InvalidateRect( &rect );

                  }

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

         ON_WM_RBUTTONDOWN()

         ON_WM_RBUTTONUP()

         ON_WM_MOUSEMOVE()

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
