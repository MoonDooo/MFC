#pragma once


// Histogram ��ȭ �����Դϴ�.

class Histogram : public CDialogEx
{
	DECLARE_DYNAMIC(Histogram)

public:
	Histogram(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Histogram();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HISTOGRAM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
