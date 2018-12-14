// DrawTestView.h : interface of the CDrawTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWTESTVIEW_H__C4AB7FB9_20FC_4B96_B7D7_97D68BEC2806__INCLUDED_)
#define AFX_DRAWTESTVIEW_H__C4AB7FB9_20FC_4B96_B7D7_97D68BEC2806__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawTestView : public CView
{
public:
	int m_DrawType;
	BOOL m_isDraw;
	CPoint m_StartPoint,m_EndPoint;
	bool m_LButtonDown;//判断鼠标左键是否按下

protected: // create from serialization only
	CDrawTestView();
	DECLARE_DYNCREATE(CDrawTestView)
	
// Attributes
public:
	CDrawTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DDATuo(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void DDACircle(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void Draw(CDC *pDC);
	virtual ~CDrawTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawTestView)
	afx_msg void OnDrawcircle();
	afx_msg void OnDrawellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawTestView.cpp
inline CDrawTestDoc* CDrawTestView::GetDocument()
   { return (CDrawTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTESTVIEW_H__C4AB7FB9_20FC_4B96_B7D7_97D68BEC2806__INCLUDED_)
