// HelloDoc.h : interface of the CHelloDoc class
//
/////////////////////////////////////////////////////////////////////////////
#define BLACK	RGB(0x00, 0x00, 0x00)
#define RED		RGB(0xff, 0x00, 0x00)
#define GREEN	RGB(0x00, 0xff, 0x00)
#define BLUE	RGB(0x00, 0x00, 0xff)

class CHelloDoc : public CDocument
{
protected: // create from serialization only
	CHelloDoc();
	DECLARE_DYNCREATE(CHelloDoc)

// Attributes
public:
	void SetData(CString str, CPoint point, COLORREF color);
	CPoint GetMax();
	CString GetText();
	void SetMax(CPoint point);
	void SetColor(COLORREF color);
	COLORREF GetColor();
	void SetLocation(CPoint point);
	CPoint GetLocation();
protected:
	CString m_strText;
	CPoint m_nMax;
	COLORREF m_clrCur;
	CPoint m_ptLoc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHelloDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHelloDoc)
	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
