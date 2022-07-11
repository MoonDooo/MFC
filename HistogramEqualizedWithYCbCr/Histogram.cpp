// Histogram.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HistogramEqualizedWithYCbCr.h"
#include "Histogram.h"
#include "afxdialogex.h"
#include "HistogramEqualizedWithYCbCrDoc.h"
#include "ChildFrm.h"
#include "MainFrm.h"
#include "Resource.h"
#include "HistogramEqualizedWithYCbCrView.h"
// Histogram ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Histogram, CDialogEx)

Histogram::Histogram(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HISTOGRAM, pParent)
{

}

Histogram::~Histogram()
{
}

void Histogram::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Histogram, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Histogram �޽��� ó�����Դϴ�.


void Histogram::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�
	CMainFrame *pMainFrame = (CMainFrame *)AfxGetMainWnd();
	CChildFrame *pChild = (CChildFrame *)pMainFrame->GetActiveFrame();
	CHistogramEqualizedWithYCbCrView *pView = (CHistogramEqualizedWithYCbCrView*)pChild->GetActiveView();
	dc.SetDCPenColor(RGB(0, 0, 0));
	for (int i = 0; i < 256; i++) {
		dc.MoveTo(50 + (2 * i), 270);
		dc.LineTo(50 + (2 * i), 270 - (pView->getHistogramOfYInYCbCr()[i] / 16));
	}
	if (pView->getIsAlreadyEqualized()) {
		for (int i = 0; i < 256; i++) {
			dc.MoveTo(50 + (2 * i), 500);
			dc.LineTo(50 + (2 * i), 500 - (pView->getResultHistogramOfYInYCbCr()[i] / 16));
		}
	}
}

