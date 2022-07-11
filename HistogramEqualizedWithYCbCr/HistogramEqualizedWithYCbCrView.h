
// HistogramEqualizedWithYCbCrView.h : CHistogramEqualizedWithYCbCrView Ŭ������ �������̽�
//

#pragma once
#include "YCbCr.h"
const short MAX_INTENSITY_LEVEL = 256; //�ִ� ��� ���� ����

class CHistogramEqualizedWithYCbCrView : public CView
{
protected: // serialization������ ��������ϴ�.
	CHistogramEqualizedWithYCbCrView();
	DECLARE_DYNCREATE(CHistogramEqualizedWithYCbCrView)

// Ư���Դϴ�.
public:
	CHistogramEqualizedWithYCbCrDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CHistogramEqualizedWithYCbCrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
private:
	CImage Input_image;
	CImage Output_image;
	int InputImageHeight;
	int InputImageWidth;
	bool isAlreadyEqualized;
	int histogramOfYInYCbCr[MAX_INTENSITY_LEVEL];
	int cumulativeNumberOfIntensity[MAX_INTENSITY_LEVEL];
	int resultHistogramOfYInYCbCr[MAX_INTENSITY_LEVEL];
	YCbCr** YCbCrImage;
public:
	bool getIsAlreadyEqualized();
	int *getHistogramOfYInYCbCr();
	int *getResultHistogramOfYInYCbCr();
	void LoadInputImage();
	void InitializeArray();
	void InitializeYCbCr();
	void CalculationHistogramFromImage();
	void ConvertRGBIntoYCbCr(int x, int y);
	void Histogram_Equalized();
	void CalculateCumulativeNumberOfIntensity();
	void SetOutputImage();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
#ifndef _DEBUG  // HistogramEqualizedWithYCbCrView.cpp�� ����� ����
inline CHistogramEqualizedWithYCbCrDoc* CHistogramEqualizedWithYCbCrView::GetDocument() const
   { return reinterpret_cast<CHistogramEqualizedWithYCbCrDoc*>(m_pDocument); }
#endif


