
// shuiziyuanyuanchengjiankongzhongxinDlg.h : 头文件
//

#pragma once

class CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy;


// CshuiziyuanyuanchengjiankongzhongxinDlg 对话框
class CshuiziyuanyuanchengjiankongzhongxinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CshuiziyuanyuanchengjiankongzhongxinDlg);
	friend class CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy;

// 构造
public:
	CshuiziyuanyuanchengjiankongzhongxinDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CshuiziyuanyuanchengjiankongzhongxinDlg();

// 对话框数据
	enum { IDD = IDD_SHUIZIYUANYUANCHENGJIANKONGZHONGXIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

private:
	

public:
	
	
	afx_msg void OnEnChangeEdit1();
};
