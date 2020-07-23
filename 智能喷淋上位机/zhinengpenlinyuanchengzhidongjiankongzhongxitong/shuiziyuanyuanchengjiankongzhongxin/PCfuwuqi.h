#pragma once
#include "afxwin.h"
#include"windows.h"
#include "afxcmn.h"
#include "mschart1.h"
#include "MSChart.h"
#include "CDMSChart.h"
#include "CVcPlot.h"  
#include "CVcAxis.h"  
#include "CVcValueScale.h"  
#include "CVcSeriesCollection.h"  
#include "CVcSeries.h"  
#include "CVcPen.h"  
#include "CVcCategoryScale.h"  
#include "CVcColor.h"  
#include "CVcDataGrid.h"  
#include "CVcBackdrop.h"  
#include "CVcFill.h"  
#include "CVcBrush.h"  
#include "CVcDataPoints.h"  
#include "CVcDataPoint.h"  
#include "CVcDataPointLabel.h"  
#include "CVcAxisTitle.h" 
#include "CVcTitle.h"
#include "CVcFont.h"
#include "CVcLegend.h"
#include "CVcMarker.h"
#include "CVcLabels.h"
#include "CVcLabel.h"
#include "CVcSeriesMarker.h"
#include "CVcTextLayout.h"



// PCfuwuqi 对话框


class PCfuwuqi : public CDialogEx
{
	DECLARE_DYNAMIC(PCfuwuqi)

public:
	PCfuwuqi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PCfuwuqi();

// 对话框数据
	enum { IDD = IDD_PCfuwuqi_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	
	void TCPClient(SOCKET sock);
	
private:

	
public:
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	
	
	CString EDIT3;
	CString EDIT4;
	
	
	afx_msg void OnBnClickedButton2();
	

   CMschart1 chart1;
	
	void InitMschart1();
	void InitSOCKET();

	
	
	CEdit EDIT33;
	CEdit EDIT44;
	
	static DWORD WINAPI ThreadB1(LPVOID lpParam);
	static DWORD WINAPI ThreadB2(LPVOID lpParam);
	
	friend DWORD WINAPI ThreadB5(LPVOID lpParam);
	
	CString str1;
	CString result1;
	CString result2;
	

	CEdit EDIT1;
	CString EDIT11;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCancel();
};
