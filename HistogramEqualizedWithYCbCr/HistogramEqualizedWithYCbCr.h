
// HistogramEqualizedWithYCbCr.h : HistogramEqualizedWithYCbCr ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHistogramEqualizedWithYCbCrApp:
// �� Ŭ������ ������ ���ؼ��� HistogramEqualizedWithYCbCr.cpp�� �����Ͻʽÿ�.
//

class CHistogramEqualizedWithYCbCrApp : public CWinApp
{
public:
	CHistogramEqualizedWithYCbCrApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHistogramEqualizedWithYCbCrApp theApp;
