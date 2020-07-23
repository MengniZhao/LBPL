// lishishujuchaxun.cpp : 实现文件
//

#include "stdafx.h"
#include "shuiziyuanyuanchengjiankongzhongxin.h"
#include "lishishujuchaxun.h"
#include "afxdialogex.h"
#include "chaxunfangshi.h"
#include <windows.h> 
#include<mysql.h>
#include <mysql_error.h> 
#include<string.h>
#include<sys/types.h> 
#include<iostream> 
#include "stdio.h"


CString strChoosed;
CString number;
CString time1;
CString temperature;
CString Humidity;

CString Row;
#pragma comment(lib, "libmysql.lib") 

char query[1024];

// lishishujuchaxun 对话框

IMPLEMENT_DYNAMIC(lishishujuchaxun, CDialogEx)

lishishujuchaxun::lishishujuchaxun(CWnd* pParent /*=NULL*/)
	: CDialogEx(lishishujuchaxun::IDD, pParent)
	, combobox11(_T(""))
	, EDIT1(_T(""))
	
{

}

lishishujuchaxun::~lishishujuchaxun()
{
}

void lishishujuchaxun::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combobox1);
	DDX_CBString(pDX, IDC_COMBO1, combobox11);
	DDX_Text(pDX, IDC_EDIT1, EDIT1);
	DDX_Control(pDX, IDC_LIST1, LIST1);
}


BEGIN_MESSAGE_MAP(lishishujuchaxun, CDialogEx)
	ON_BN_CLICKED(IDOK, &lishishujuchaxun::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &lishishujuchaxun::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, &lishishujuchaxun::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &lishishujuchaxun::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &lishishujuchaxun::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// lishishujuchaxun 消息处理程序

BOOL lishishujuchaxun::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	combobox1.ResetContent();
	combobox1.InsertString(0, _T("id"));
	combobox1.InsertString(1, _T("time1"));
	combobox1.InsertString(2, _T("temperature"));
	combobox1.InsertString(3, _T("humidity"));
	

	LIST1.InsertString(0,_T("请输入查询关键字以及对应查询内容，点击查询按钮，即可显示历史数据信息"));

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}



void lishishujuchaxun::OnBnClickedOk()
{
    chaxunfangshi dlg;
	dlg.DoModal();// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void lishishujuchaxun::OnCbnSelchangeCombo1()
{

	int iCount = combobox1.GetCount();

	combobox1.GetLBText(combobox1.GetCurSel(), strChoosed);//获取选择的关键字存入  strChoosed 中


	//((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(strChoosed);第一次为空 ，后面每次会获取第一次的数据
	//combobox1.GetWindowTextW(strChoosed);


	// TODO:  在此添加控件通知处理程序代码
}




void lishishujuchaxun::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void lishishujuchaxun::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	GetDlgItemText(IDC_EDIT1, EDIT1); //获取编辑框输入的数据，存入 EDIT1 中
	if (strChoosed == ""){

		AfxMessageBox(_T("查询关键字不可为空"));
	}

	if (EDIT1 == ""){

		AfxMessageBox(_T("查询内容不可为空"));
	}


	//连接数据库，查询数据库数据

	MYSQL my_connection;
	MYSQL *conn_ptr;  //定义链接句柄

	conn_ptr = mysql_init(&my_connection);

	conn_ptr = mysql_real_connect(&my_connection, "localhost", "root", "aA165147", "szysj", 8081, NULL, 0);

	

	MYSQL_RES *res;//声明数据查询结果  
	MYSQL_ROW row;//取每行结果的对象  

	sprintf(query, "select*from sssss where %S like '%S' \n", strChoosed, EDIT1);

	int SELECT = mysql_query(&my_connection, query); //查询函数，语句用字符串表示  

	if (SELECT == 0)
	{
		res = mysql_store_result(&my_connection);

		if (NULL != res);//得到查询结果 
		{   LIST1.ResetContent();
		LIST1.InsertString(0, _T("以上为数据库历史数据查询结果"));
		while (row = mysql_fetch_row(res))//逐行取出查询结果并操作 
		{

			//将从数据库获取的数据保存在字符串中
			number = row[0];
			time1 = row[1];
			temperature = row[2];
			Humidity = row[3];
			

			//将数据整合在一起，方便LIST控件显示
			Row = _T("序号:")+ number + _T("  时间:") + time1 + _T("  温度:") + temperature + _T("  湿度:") + Humidity + _T("\r\n");//数据之间用空格隔开

			LIST1.AddString(Row);
		}

		}
		mysql_free_result(res);//释放结果集

	}
	for (int k = 0; k < 1500; k++)//清空query数组
	{
		memset(query, 0, 1024);
	}

	mysql_close(&my_connection);
}


void lishishujuchaxun::OnLbnSelchangeList1()
{
	// TODO:  在此添加控件通知处理程序代码
}
