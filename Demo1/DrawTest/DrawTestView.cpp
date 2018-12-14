// DrawTestView.cpp : implementation of the CDrawTestView class
//

#include "stdafx.h"
#include "DrawTest.h"
#include "cmath"
#include "DrawTestDoc.h"
#include "DrawTestView.h"
#include "cmath"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawTestView

IMPLEMENT_DYNCREATE(CDrawTestView, CView)

BEGIN_MESSAGE_MAP(CDrawTestView, CView)
	//{{AFX_MSG_MAP(CDrawTestView)
	ON_COMMAND(ID_DRAWCIRCLE, OnDrawcircle)
	ON_COMMAND(ID_DRAWELLIPSE, OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawTestView construction/destruction

CDrawTestView::CDrawTestView()
{
	// TODO: add construction code here
	
	m_DrawType = 1;//默认画圆
	m_isDraw = true;//当前处于绘图状态
	m_LButtonDown = false;
}

CDrawTestView::~CDrawTestView()
{
}

BOOL CDrawTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTestView drawing

void CDrawTestView::OnDraw(CDC* pDC)
{
	CDrawTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDC);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTestView printing

BOOL CDrawTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTestView diagnostics

#ifdef _DEBUG
void CDrawTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawTestDoc* CDrawTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawTestDoc)));
	return (CDrawTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawTestView message handlers

void CDrawTestView::Draw(CDC *pDC)
{
	pDC->LineTo(200,100);//使用传入的CDC对象指针绘图
	CClientDC dc(this);//构造CClientDC设备环境对象
	dc.LineTo(200,200);//利用构造的CClientDC设备环境对象绘图
	CDC* p=this->GetDC();//通过GetDC函数获得设备环境对象指针
	p->LineTo(100,200);//利用GetDC函数获得设备环境对象指针绘图
	this->ReleaseDC(p);//由GetDC函数获得的设备环境对象必须用ReleaseDC函数释放
}  

void CDrawTestView::OnDrawcircle() 
{
	// TODO: Add your command handler code here
	m_DrawType = 1;//画圆
	m_isDraw = true;//当前处于绘图状态
}

void CDrawTestView::OnDrawellipse() 
{
	// TODO: Add your command handler code here
	m_DrawType = 2;//画椭圆
	m_isDraw = true;//当前处于绘图状态
}

void CDrawTestView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_DrawType ==1 || m_DrawType == 2){
		this->SetCapture();//捕捉鼠标
		//设置开始点和终止点，此时为同一点
		m_StartPoint = point;
		m_EndPoint = point;
		m_LButtonDown = true;//设置鼠标左键按下
	}

	CView::OnLButtonDown(nFlags, point);
}

void CDrawTestView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	ReleaseCapture();//释放鼠标
	m_LButtonDown = false;

	CView::OnLButtonUp(nFlags, point);
}

void CDrawTestView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if ((m_LButtonDown && m_DrawType == 1)){
		CDC* pDC = this->GetDC();//构造设备环境对象
		pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		DDACircle(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(0,0,0));
		DDACircle(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y,RGB(0,0,0));
		//保存新的直线段终点
		m_EndPoint = point;
	}
	if ((m_LButtonDown && m_DrawType == 2)){
		CDC* pDC = this->GetDC();//构造设备环境对象
		pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		DDATuo(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(0,0,0));
		DDATuo(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y,RGB(0,0,0));
		//保存新的直线段终点
		m_EndPoint = point;

	}

	CView::OnMouseMove(nFlags, point);
}

void CDrawTestView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	double dx,dy,e,x,y;
	dx = x2 -x1;
	dy = y2- y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx):fabs(dy);
	dx/=e;
	dy/=e;
	x = x1;
	y = y1;
	for (int i=1;i<=e;i++)
	{
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),color);
		x+=dx;
		y+=dy;
	}
}

void CDrawTestView::DDACircle(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int R = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	int x,y,p;
	x=0;
	y=R;
	p=3-2*R;
	for(;x<=y;x++)
	{
		pDC->SetPixel(x1+x,y1+y,color);
		pDC->SetPixel(x1-x,y1+y,color);
		pDC->SetPixel(x1+x,y1-y,color);
		pDC->SetPixel(x1-x,y1-y,color);
		pDC->SetPixel(x1+y,y1+x,color);
		pDC->SetPixel(x1-y,y1+x,color);
		pDC->SetPixel(x1+y,y1-x,color);
		pDC->SetPixel(x1-y,y1-x,color);
		if(p>=0)
		{
			p+=4*(x-y)+10;
			y--;
		}
		else
		{
			p+=4*x+6;
		}
	}
}

void CDrawTestView::DDATuo(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	double a = abs(x2-x1)/2;
	double b = abs(y2-y1)/2;
	int xx = (x1+x2)/2;
	int yy = (y1+y2)/2;

	int x,y;
	int d1,d2;
	x=0;y=b;
	d1=b*b+a*a*(-b+0.25);
	pDC->SetPixel(xx+x,yy+y,color);
	pDC->SetPixel(xx-x,yy+y,color);
	pDC->SetPixel(xx+x,yy-y,color);
	pDC->SetPixel(xx-x,yy-y,color);
	while(b*b*(x+1)<a*a*(y-0.5))
	{
		if(d1<0)
		{
			d1+=b*b*(2*x+3);
			x++;
		}
		else
		{
			d1+=(b*b*(2*x+3)+a*a*(-2*y+2));
			x++;
			y--;
		}
		pDC->SetPixel(xx+x,yy+y,color);
		pDC->SetPixel(xx-x,yy+y,color);
		pDC->SetPixel(xx+x,yy-y,color);
		pDC->SetPixel(xx-x,yy-y,color);
	}
	d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
	while(y>0)
	{
		if(d2<0)
		{
			d2+=b*b*(2*x+2)+a*a*(-2*y+3);
			x++;
			y--;
		}
		else
		{
			d2+=a*a*(-2*y+3);
			y--;
		}
		pDC->SetPixel(xx+x,yy+y,color);
		pDC->SetPixel(xx-x,yy+y,color);
		pDC->SetPixel(xx+x,yy-y,color);
		pDC->SetPixel(xx-x,yy-y,color);
	}
}
