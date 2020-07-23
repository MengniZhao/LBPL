// chaxunfangshi.cpp : 实现文件
//

#include "stdafx.h"
#include "shuiziyuanyuanchengjiankongzhongxin.h"
#include "chaxunfangshi.h"
#include "afxdialogex.h"
#include "PCfuwuqi.h"
#include "lishishujuchaxun.h"

// chaxunfangshi 对话框

IMPLEMENT_DYNAMIC(chaxunfangshi, CDialogEx)

chaxunfangshi::chaxunfangshi(CWnd* pParent /*=NULL*/)
	: CDialogEx(chaxunfangshi::IDD, pParent)
{

}

chaxunfangshi::~chaxunfangshi()
{
}

void chaxunfangshi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(chaxunfangshi, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &chaxunfangshi::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &chaxunfangshi::OnBnClickedButton2)
END_MESSAGE_MAP()


// chaxunfangshi 消息处理程序


void chaxunfangshi::OnBnClickedButton1()
{
    PCfuwuqi dlg;
	dlg.DoModal();
	
	// TODO:  在此添加控件通知处理程序代码
}


void chaxunfangshi::OnBnClickedButton2()
{
	lishishujuchaxun dlg;
	dlg.DoModal();// TODO:  在此添加控件通知处理程序代码
}

