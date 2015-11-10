/*
도형을 마우스 오른쪽 버튼으로 클릭한 상태에서 움직이면 선택한 도형을 이동시킬수 있습니다.

 

워크스페이스 전체파일과 소스 파일도 따로 첨부하였습니다!

 

[중점 사항]

왼쪽 마우스로 도형을 생성시 커서 꼭지점부터 좌표를 계산하여 도형을 그리게 되있습니다.

때문에 기존 코드를 그대로 사용할 경우 오른쪽 마우스 클릭상태에서 이동할때 도형이 순간적으로

커서 꼭지점 부분으로 이동하게 됩니다.

이런 현상을 방지하기위해 쇼바 변수(cx, xy)를 만들어 부드럽게 이동 되도록 만들었습니다.

 

하지막 역시 더블버퍼링이 아니고 자료구조에 좌표를 저장하여 다시 뿌려주는 형태로 만들어져 있기때문에

약간의 깜빡임을 볼수있습니다. 빠르게 이동시키면 잔상도 남구요^^

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

 

         // 인자로 받은 좌표에 현재 도형이 위치하고 있는지를 알려준다.

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

 

         // 도형의 좌표값을 수정한다.

         void SetRectPos( const RECT& r )

         {

                  x1 = r.left;

                  y1 = r.top;

                  x2 = r.right;

                  y2 = r.bottom;

         }

 

         // 커서와 도형의 위치를 유연하게 내부좌표값을 설정

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

         // 모든 도형을 보관한다.

         CList<Shape*, Shape*> shapeList;

 

         BOOL bRBtnClick;

 

public:

         CMainFrame() : bRBtnClick(FALSE) {}

 

 

         void OnLButtonDown( UINT nFlag, CPoint pt )

         {

                  Shape* p = new Rect( pt.x, pt.y, pt.x+50, pt.y+50 );

 

                  shapeList.AddTail( p ); // list에 추가.

 

                  CClientDC dc(this);

                  p->Draw( &dc ); // 객체 자신에게 그리도록 한다.!!

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

                  // 유연성 유지를 위해 도형을 정확한 위치에 그리지 못했다.

                  // 때문에 도형의 위치값을 다시 수정해 놓아야 한다.            

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
