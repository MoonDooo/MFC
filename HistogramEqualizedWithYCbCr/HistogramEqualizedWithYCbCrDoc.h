
// HistogramEqualizedWithYCbCrDoc.h : CHistogramEqualizedWithYCbCrDoc Ŭ������ �������̽�
//


#pragma once
#include "Histogram.h"
class CHistogramEqualizedWithYCbCrDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CHistogramEqualizedWithYCbCrDoc();
	DECLARE_DYNCREATE(CHistogramEqualizedWithYCbCrDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CHistogramEqualizedWithYCbCrDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnViewHistogram();
};
