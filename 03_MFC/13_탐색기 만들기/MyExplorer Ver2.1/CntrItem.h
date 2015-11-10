// CntrItem.h : interface of the CMyExplorerCntrItem class
//

#if !defined(AFX_CNTRITEM_H__76A78AFB_5173_4616_B589_ADDF2B802274__INCLUDED_)
#define AFX_CNTRITEM_H__76A78AFB_5173_4616_B589_ADDF2B802274__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyExplorerDoc;
class CMyExplorerView;

class CMyExplorerCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CMyExplorerCntrItem)

// Constructors
public:
	CMyExplorerCntrItem(CMyExplorerDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CMyExplorerDoc* GetDocument()
		{ return (CMyExplorerDoc*)COleClientItem::GetDocument(); }
	CMyExplorerView* GetActiveView()
		{ return (CMyExplorerView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyExplorerCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CMyExplorerCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__76A78AFB_5173_4616_B589_ADDF2B802274__INCLUDED_)
