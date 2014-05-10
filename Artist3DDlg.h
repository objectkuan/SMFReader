// Artist3DDlg.h : ͷ�ļ�
//

#pragma once

#ifndef HJQ_UPPER
#define HJQ_UPPER 500
#endif
#include "Elements.h"
#include "CompatibleFile.h"
#include <cmath>
using namespace std;

// CArtist3DDlg �Ի���
class CArtist3DDlg : public CDialog
{
// ����
public:
	CArtist3DDlg(CWnd* pParent = NULL);		// ��׼���캯��
	BOOL SetWindowPixelFormat(HDC hDC);	//�趨���ظ�ʽ
	BOOL CreateViewGLContext(HDC hDC);     //View GL Context
	void RenderScene();                                //���Ƴ���
	void Reshape();
	void InitOpenGL();

	HDC hrenderDC;		//DC
	HGLRC hrenderRC;		//RC

	int PixelFormat;
	int m_yRotate;

	CWnd *Renderer;
	float spin;
	CRect Canvas;
	AET aet;
	double DistanceBetween(CPoint p1, CPoint p2);
	shape* CopyShape(shape s, int index);
	void SingleBuffer(int index);


	typedef enum ShowPattern
	{
		PATTERN1 = 0,
		PATTERN2,
		PATTERN3
	};
	ShowPattern ShowImagePattern;
	void DrawImage(CDC& dc);
	bool CopyBitmap( const CBitmap &bmpSrc, CBitmap &bmpDest );
	CBitmap* GetBitmap(CDC& dc, int x1, int y1, int x2, int y2);
	void ReleaseBitmap(CBitmap* bitmap);

	// ����
	double xScale, yScale, zScale;
	double xRota, yRota, zRota;
	double angle;
	double xTran, yTran, zTran;

	int MaxScale, MaxRota, MaxTran;

// �Ի�������
	enum { IDD = IDD_ARTIST3D_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	// additional data
	shape s;
	int version;
	// additional functions
	void InitGraph();
	void ReadInFile(CString path);
	void ZBuffer();
	COLORREF** CB;


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonBrowse();
	afx_msg void OnNMCustomdrawSliderXscale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderYscale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderZscale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderXrota(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderYrota(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderZrota(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderXtran(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderYtran(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderZtran(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderAngle(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderMaxscale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	afx_msg void OnBnClickedRadioNormallook();
	afx_msg void OnBnClickedRadioLinehidden();
	afx_msg void OnBnClickedRadioReal();
	afx_msg void OnBnClickedButtonShow();
	afx_msg void OnBnClickedRadioOrth();
	afx_msg void OnBnClickedRadioPro();

	afx_msg void OnBnClickedButtonZbuffer();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonXbuffer();
	afx_msg void OnBnClickedButtonYbuffer();
};
