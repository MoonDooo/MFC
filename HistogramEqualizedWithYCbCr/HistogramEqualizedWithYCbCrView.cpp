
// HistogramEqualizedWithYCbCrView.cpp : CHistogramEqualizedWithYCbCrView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "HistogramEqualizedWithYCbCr.h"
#endif

#include "HistogramEqualizedWithYCbCrDoc.h"
#include "HistogramEqualizedWithYCbCrView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHistogramEqualizedWithYCbCrView

IMPLEMENT_DYNCREATE(CHistogramEqualizedWithYCbCrView, CView)

BEGIN_MESSAGE_MAP(CHistogramEqualizedWithYCbCrView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CHistogramEqualizedWithYCbCrView ����/�Ҹ�

CHistogramEqualizedWithYCbCrView::CHistogramEqualizedWithYCbCrView()
	:isAlreadyEqualized(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	Input_image.Load(L"lena.bmp"); //Ǯ�� �� "���ϸ�" �̹��� �ҷ�����
	Output_image.Load(L"lena.bmp");
	InputImageHeight = Input_image.GetHeight();
	InputImageWidth = Input_image.GetWidth();
	InitializeArray();
	//LoadInputImage();
	CalculationHistogramFromImage();
}

void CHistogramEqualizedWithYCbCrView::InitializeArray()
{
	for (int i = 0; i < MAX_INTENSITY_LEVEL; i++) {
		resultHistogramOfYInYCbCr[i] = 0;
		histogramOfYInYCbCr[i] = 0;
		cumulativeNumberOfIntensity[i] = 0;
	}
}


void CHistogramEqualizedWithYCbCrView::LoadInputImage()
{
	Input_image.Load(L"lena.bmp"); //Ǯ�� �� "���ϸ�" �̹��� �ҷ�����
	Output_image.Load(L"lena.bmp");
	InputImageHeight = Input_image.GetHeight();
	InputImageWidth = Input_image.GetWidth();
	Invalidate();
}


void CHistogramEqualizedWithYCbCrView::CalculationHistogramFromImage()
{
	InitializeYCbCr();
	for (int x = 0; x < InputImageWidth; x++) {
		for (int y = 0; y < InputImageHeight; y++) {
			ConvertRGBIntoYCbCr(x, y);
			histogramOfYInYCbCr[YCbCrImage[x][y].GetY()]++;
		}
	}

}

void CHistogramEqualizedWithYCbCrView::InitializeYCbCr()
{
	YCbCrImage = new YCbCr*[InputImageWidth];
	for (int y = 0; y < InputImageWidth; y++) {
		YCbCrImage[y] = new YCbCr[InputImageHeight];
	}
}

void CHistogramEqualizedWithYCbCrView::ConvertRGBIntoYCbCr(int x, int y)
{
	BYTE R = GetRValue(Input_image.GetPixel(x, y));
	BYTE G = GetGValue(Input_image.GetPixel(x, y));
	BYTE B = GetBValue(Input_image.GetPixel(x, y));
	YCbCrImage[x][y].ConvertRGBIntoYCbCr(R, G, B);
}


CHistogramEqualizedWithYCbCrView::~CHistogramEqualizedWithYCbCrView()
{
	for (int y = 0; y < InputImageHeight; y++) {
		delete[] YCbCrImage[y];
	}
	delete[] YCbCrImage;
}

BOOL CHistogramEqualizedWithYCbCrView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CHistogramEqualizedWithYCbCrView �׸���

void CHistogramEqualizedWithYCbCrView::OnDraw(CDC* pDC)
{
	CHistogramEqualizedWithYCbCrDoc* pDoc = GetDocument();
	CClientDC dc(this);
	Input_image.Draw(dc, 0, 0);
	if (isAlreadyEqualized) {
		Output_image.Draw(dc, InputImageWidth, 0);
	}
	else {
		pDC->TextOut(InputImageWidth + 100, 300, _T("Ŭ���� ��� ���� ���"));
		pDC->TextOut(InputImageWidth + 100, 350, _T("���� -> ������׷� ,  ��Ȱȭ ���� Ȯ�� �� ��� ���� ������׷��� ���� ���ɴϴ�"));
	}
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CHistogramEqualizedWithYCbCrView �μ�

BOOL CHistogramEqualizedWithYCbCrView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CHistogramEqualizedWithYCbCrView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CHistogramEqualizedWithYCbCrView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CHistogramEqualizedWithYCbCrView ����

#ifdef _DEBUG
void CHistogramEqualizedWithYCbCrView::AssertValid() const
{
	CView::AssertValid();
}

void CHistogramEqualizedWithYCbCrView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHistogramEqualizedWithYCbCrDoc* CHistogramEqualizedWithYCbCrView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHistogramEqualizedWithYCbCrDoc)));
	return (CHistogramEqualizedWithYCbCrDoc*)m_pDocument;
}
#endif //_DEBUG


// CHistogramEqualizedWithYCbCrView �޽��� ó����
void CHistogramEqualizedWithYCbCrView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Histogram_Equalized();
	SetOutputImage();
	Invalidate();
	isAlreadyEqualized = true;
	CView::OnLButtonDown(nFlags, point);
}
void CHistogramEqualizedWithYCbCrView::Histogram_Equalized()
{
	if (!isAlreadyEqualized) {
		int ImageSize = InputImageWidth*InputImageHeight;
		CalculateCumulativeNumberOfIntensity();
		for (int x = 0; x < InputImageWidth; x++) {
			for (int y = 0; y < InputImageHeight; y++) {
				BYTE tmp_Y = YCbCrImage[x][y].GetY();
				tmp_Y = (cumulativeNumberOfIntensity[tmp_Y] * (MAX_INTENSITY_LEVEL - 1) / ImageSize);
				YCbCrImage[x][y].SetY(tmp_Y);
				resultHistogramOfYInYCbCr[tmp_Y]++;
			}
		}
	}
	else return;
}
void CHistogramEqualizedWithYCbCrView::CalculateCumulativeNumberOfIntensity() {
	int sumIntensity = 0;
	for (int i = 0; i < MAX_INTENSITY_LEVEL; i++) {
		sumIntensity += histogramOfYInYCbCr[i];
		cumulativeNumberOfIntensity[i] = sumIntensity;
	}
}

void CHistogramEqualizedWithYCbCrView::SetOutputImage()
{
	for (int x = 0; x < InputImageWidth; x++) {
		for (int y = 0; y < InputImageHeight; y++) {
			Output_image.SetPixel(x, y, YCbCrImage[x][y].ConvertYCbCrIntoRGB());
		}
	}
}

int * CHistogramEqualizedWithYCbCrView::getHistogramOfYInYCbCr()
{
	return histogramOfYInYCbCr;
}

int * CHistogramEqualizedWithYCbCrView::getResultHistogramOfYInYCbCr()
{
	return resultHistogramOfYInYCbCr;
}

bool CHistogramEqualizedWithYCbCrView::getIsAlreadyEqualized()
{
	return isAlreadyEqualized;
}