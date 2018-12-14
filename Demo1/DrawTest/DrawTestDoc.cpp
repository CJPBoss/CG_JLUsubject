// DrawTestDoc.cpp : implementation of the CDrawTestDoc class
//

#include "stdafx.h"
#include "DrawTest.h"

#include "DrawTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawTestDoc

IMPLEMENT_DYNCREATE(CDrawTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawTestDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawTestDoc construction/destruction

CDrawTestDoc::CDrawTestDoc()
{
	// TODO: add one-time construction code here

}

CDrawTestDoc::~CDrawTestDoc()
{
}

BOOL CDrawTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawTestDoc serialization

void CDrawTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTestDoc diagnostics

#ifdef _DEBUG
void CDrawTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawTestDoc commands
