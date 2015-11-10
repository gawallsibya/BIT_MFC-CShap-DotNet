// HelloDoc.h : interface of the CHelloDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CHelloDoc : public CDocument
{
protected: // create from serialization only
	CPoint m_ptLoc;
	CHelloDoc();
	DECLARE_DYNCREATE(CHelloDoc)

// Attributes
public:
	void SetLocation(CPoint pt);
	CPoint GetLocation();
	void SetColor(COLORREF color);
	COLORREF GetColor();
protected:
	COLORREF m_curColor;
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
