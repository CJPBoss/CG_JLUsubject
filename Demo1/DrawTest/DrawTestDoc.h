// DrawTestDoc.h : interface of the CDrawTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWTESTDOC_H__DE8EEB8C_7411_4978_A8FE_6483FD607C22__INCLUDED_)
#define AFX_DRAWTESTDOC_H__DE8EEB8C_7411_4978_A8FE_6483FD607C22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawTestDoc : public CDocument
{
protected: // create from serialization only
	CDrawTestDoc();
	DECLARE_DYNCREATE(CDrawTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTESTDOC_H__DE8EEB8C_7411_4978_A8FE_6483FD607C22__INCLUDED_)
