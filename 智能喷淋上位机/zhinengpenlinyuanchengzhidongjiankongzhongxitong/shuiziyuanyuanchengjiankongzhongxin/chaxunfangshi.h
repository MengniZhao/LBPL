#pragma once


// chaxunfangshi 对话框

class chaxunfangshi : public CDialogEx
{
	DECLARE_DYNAMIC(chaxunfangshi)

public:
	chaxunfangshi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~chaxunfangshi();

// 对话框数据
	enum { IDD = IDD_chaxunfangshi_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	
};
