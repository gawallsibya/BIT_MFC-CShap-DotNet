///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Hotbtn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
CHotButton::CHotButton()
{
    m_onsurface = FALSE;
    m_down = FALSE;
	m_txtColor = RGB(255, 0,0);
	m_hIcon = NULL;
	m_szIcon = CSize(0, 0);
}

CHotButton::~CHotButton()
{
    
}


BEGIN_MESSAGE_MAP(CHotButton, CButton)
//{{AFX_MSG_MAP(CHotButton)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_WM_KEYUP()
ON_WM_KILLFOCUS()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

////////////////////////////////////////////////////////////////////////////////
void CHotButton::DrawItem(DRAWITEMSTRUCT* pDraw)
{
    CDC*        pdc = CDC::FromHandle(pDraw->hDC);
    CRect       rtx;
    POINT       pt={0};
    CString     text;
    int         nStateFlag = DSS_NORMAL;
    int         image = 0;
    COLORREF    lt = GetSysColor(COLOR_BTNHIGHLIGHT);
    COLORREF    dk = GetSysColor(COLOR_BTNSHADOW);
    int         offset = 0;
    
    rtx.CopyRect(&pDraw->rcItem);
      
    if ( pDraw->itemState & ODS_SELECTED )
    {   // 버튼이 선택되었을 경우 
        COLORREF temp = lt;
        lt = dk;
        dk = temp;
        offset = 2;
    }

    if ( pDraw->itemState & ODS_DISABLED )
    {   
		nStateFlag = DSS_DISABLED;
    }

    if ((pDraw->itemAction & ODA_DRAWENTIRE)||
       (pDraw->itemAction & ODA_SELECT))
    {
        
        if(m_onsurface && offset == 0)
          offset = -2;
		/*
		//******************************************
        // 여기서 다이얼로그 템플릿 수정할 것!!!....

        RECT rt; GetWindowRect(&rt);GetParent()->ScreenToClient(&rt);
        CDC memdc;
        memdc.CreateCompatibleDC(pdc);

        CBitmap* old = memdc.SelectObject(((CFlatBtnDlg*)GetParent())->GetBrush());
        pdc->BitBlt(0,0,rt.right,rt.bottom,&memdc,rt.left+offset,rt.top+offset,SRCCOPY );
        memdc.SelectObject(old);
        memdc.DeleteDC();
		*/

        CString strCaption;
		GetWindowText(strCaption);

		int x = (rtx.Width() - m_szIcon.cx)/2;
		int y;
		if(strCaption.IsEmpty())
			y = (rtx.Height() - m_szIcon.cy)/2;
		else
		{
			y = rtx.top+3;
			rtx.bottom -= 3;
		}

        if(m_onsurface)
        {   // 마우스가 버튼 위에 있을 경우
			if(m_border)
              pdc->Draw3dRect(&pDraw->rcItem,lt,dk);
            
            pdc->SetBkMode(TRANSPARENT);
            pdc->SetTextColor(m_txtColor);

			if(m_hIcon)
			{
				pdc->DrawState(CPoint(x-1, y-1), m_szIcon,
					(HICON)m_hIcon, DST_ICON | nStateFlag,
					(CBrush*)NULL);
				pdc->DrawText(strCaption, rtx,
					DT_CENTER|DT_SINGLELINE|DT_BOTTOM);
			}
			else
			{
				pdc->DrawText(strCaption, rtx,
					DT_CENTER|DT_SINGLELINE|DT_VCENTER );
			}
        }
        else
        {   // 마우스가 버튼 위에 없을 경우
            pdc->SetTextColor(RGB(128,128,128));
            pdc->SetBkMode(TRANSPARENT);
			
			if(m_hIcon)
			{
				pdc->DrawState(CPoint(x, y), m_szIcon,
					(HICON)m_hIcon, DST_ICON | nStateFlag,
					(CBrush*)NULL);
			
				pdc->DrawText(strCaption, rtx,
					DT_CENTER|DT_SINGLELINE|DT_BOTTOM);
			}
			else
			{
				pdc->DrawText(strCaption, rtx,
					DT_CENTER|DT_SINGLELINE|DT_VCENTER );
			}
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void CHotButton::OnLButtonDown(UINT nFlags, CPoint point)
{
    m_down=TRUE;
    if(GetCapture()==this)
    {
        ReleaseCapture();
        // the down will capture forward the mouse
    }
    CButton::OnLButtonDown(nFlags, point);
}

////////////////////////////////////////////////////////////////////////////////
void CHotButton::OnLButtonUp(UINT nFlags, CPoint point)
{
    
    CRect rc; 
	GetClientRect(rc);
    
    m_down=FALSE;
    if(!rc.PtInRect(point))
    {
        m_onsurface = FALSE;
        Invalidate();
    }

    CButton::OnLButtonUp(nFlags, point);
	// 마우스를 누른 상태에서 버튼 사각형을 
	// 벗어났을 경우
    ReleaseCapture();
    m_onsurface =FALSE;
}

////////////////////////////////////////////////////////////////////////////////
void CHotButton::OnMouseMove(UINT nFlags, CPoint point)
{
    CRect rc; 
	GetClientRect(rc);
    
    if(rc.PtInRect(point))
    {
        if(m_onsurface == FALSE)
        {
            m_onsurface = TRUE;
            Invalidate();
            if( ! m_down )
            {
				// 마우스의 메시지를 제어 하기 위함
				//(버튼을 누른 상태에서 마우스를 Move하여
				// 버튼 사각형을 벗어나도 메시지를 얻음) 
                SetCapture();
            }
        }
    }
    else
    {   // 버튼을 누른 상태에서 마우스를 Move
        if(m_onsurface == TRUE)
        {
            m_onsurface = FALSE;
            Invalidate();
            if(GetCapture()==this)
            {
                ReleaseCapture();
                // the down will capture forward the mouse
            }
        }
    }
    CButton::OnMouseMove(nFlags, point);
}

////////////////////////////////////////////////////////////////////////////////
void CHotButton::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    CButton::OnKeyUp(nChar, nRepCnt, nFlags);
    if(GetCapture()==this)
    {
        ReleaseCapture();
    }

    m_onsurface = FALSE;
    m_down =FALSE;
}

////////////////////////////////////////////////////////////////////////////////
void CHotButton::OnKillFocus(CWnd* pNewWnd)
{
    if(GetCapture()==this)
    {
        ReleaseCapture();
    }
    CButton::OnKillFocus(pNewWnd);
    
    m_onsurface = FALSE;
    m_down =FALSE;
    Invalidate();
}

//******************************************************
// 새로 추가한 멤버 함수
void CHotButton::SetButtonBorder(BOOL border)
{
	m_border = border;
}

void CHotButton::BtnTextColor(COLORREF color)
{
	m_txtColor = color;
}

void CHotButton::SetIcon(UINT nID, int nWidth, int nHeight)
{
	m_hIcon = (HICON)(AfxGetApp()->LoadIcon(nID));
	m_szIcon = CSize(nWidth, nHeight);
}
