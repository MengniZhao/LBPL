// PCfuwuqi.cpp : 实现文件
//

#include "stdafx.h"
#include "shuiziyuanyuanchengjiankongzhongxin.h"
#include "PCfuwuqi.h"
#include "afxdialogex.h"
#include "shuiziyuanyuanchengjiankongzhongxinDlg.h"
#include "mschart1.h"
#include "chaxunfangshi.h"
#include "lishishujuchaxun.h"
#include <windows.h> 
#include<mysql.h>
#include <mysql_error.h> 
#include<string.h>
#include<sys/types.h> 
#include<iostream> 
#include "stdio.h"
#include <winsock2.h>

#pragma comment(lib, "WS2_32.lib") 
#pragma comment(lib, "libmysql.lib") 


double item1[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double item2[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double c , d ;
int A = 0, B = 0;

DWORD   dw1, dw2,dw5;
HANDLE hThread,hThread1,hThread2;



//SOCKET listen_sock;//创建套接字Socket
SOCKET client;
BOOL blnloop = true;


// PCfuwuqi 对话框

IMPLEMENT_DYNAMIC(PCfuwuqi, CDialogEx)
BOOL PCfuwuqi::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();
	
	//SOCKET listen_sock;//创建套接字Socket
	PCfuwuqi::InitMschart1();
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
PCfuwuqi::PCfuwuqi(CWnd* pParent /*=NULL*/)
	: CDialogEx(PCfuwuqi::IDD, pParent)
	
	, EDIT3(_T(""))
	, EDIT4(_T(""))
	
	, EDIT11(_T(""))
{

}

PCfuwuqi::~PCfuwuqi()
{
}

void PCfuwuqi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT3, EDIT3);
	DDX_Text(pDX, IDC_EDIT4, EDIT4);
	DDV_MaxChars(pDX, EDIT4, 40);
	


	DDX_Control(pDX, IDC_EDIT3, EDIT33);
	DDX_Control(pDX, IDC_EDIT4, EDIT44);
	
	DDX_Control(pDX, IDC_MSCHART1, chart1);

	DDX_Control(pDX, IDC_EDIT1, EDIT1);
	DDX_Text(pDX, IDC_EDIT1, EDIT11);
}


BEGIN_MESSAGE_MAP(PCfuwuqi, CDialogEx)
	ON_BN_CLICKED(IDOK, &PCfuwuqi::OnBnClickedOk)
	
	ON_BN_CLICKED(IDC_BUTTON1, &PCfuwuqi::OnBnClickedButton1)
	
	ON_EN_CHANGE(IDC_EDIT3, &PCfuwuqi::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &PCfuwuqi::OnEnChangeEdit4)
	
	
	ON_BN_CLICKED(IDC_BUTTON2, &PCfuwuqi::OnBnClickedButton2)
	
	ON_EN_CHANGE(IDC_EDIT1, &PCfuwuqi::OnEnChangeEdit1)
	ON_BN_CLICKED(IDCANCEL, &PCfuwuqi::OnBnClickedCancel)
END_MESSAGE_MAP()

   


// PCfuwuqi 消息处理程序


void PCfuwuqi::InitSOCKET()
{
	/*服务器接收数据程序

	WSADATA wsaData;  //结构体对象

	WORD wVersion;

	wVersion = MAKEWORD(2, 2);

	WSAStartup(wVersion, &wsaData);

	SOCKADDR_IN local_addr; //local address
	SOCKADDR_IN client_addr;

	int iaddrSize = sizeof(client_addr);

	PCfuwuqi* dlg = (PCfuwuqi*)AfxGetApp()->GetMainWnd();
	local_addr.sin_family = AF_INET; //IPv4 address family
	local_addr.sin_port = htons(12345); //转化为u_short
	local_addr.sin_addr.s_addr = INADDR_ANY;//Any incoming interface  允许系统通过指定通配符地址 inaddr_any 作为我们想要的Internet地址来选择他

	listen_sock = socket(AF_INET, SOCK_STREAM, 0);//家族IP地址-IPV4  流套接字

	bind(listen_sock, (struct sockaddr*) &local_addr, sizeof(local_addr));//套接字绑定本地的地址和端口

	listen(listen_sock, 5);//把套接字设置为监听状态

	//run forever   接收进入的连接
	while (true)
	{
	int sock = accept(listen_sock, (struct sockaddr *)&client_addr, &iaddrSize);

	PCfuwuqi::TCPClient(sock);
	}
	*/
	
	//客户端接收数据程序
	
	//EdpPacket* send_pkg;
	WSADATA wsaData;
	SOCKADDR_IN server_addr;

	WORD wVersion;

	wVersion = MAKEWORD(2, 2);

	WSAStartup(wVersion, &wsaData);

	char ip[32];
	sprintf(ip, "183.230.40.34");//取得服务器的IP地址  
	server_addr.sin_addr.s_addr = inet_addr(ip);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(80);
	if ((client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		AfxMessageBox(_T("create socket error"));
	}
	if (connect(client, (struct sockaddr *) &server_addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("连接服务器失败"));
	}
	else
	{
		AfxMessageBox(_T("是否连接此服务器"));

	}

	//send_pkg = PacketConnect1(DEV_ID, API_KEY);
	
	while (true)
	{

		PCfuwuqi::TCPClient(client);
	}
	

}
void PCfuwuqi::InitMschart1()
	{


	// 栈模式
	chart1.put_Stacking(TRUE);
	

	//Y轴设置


	CVcPlot VcPlot;
	CVcAxis VcAxis;
	VARIANT var;
	CVcValueScale VcValueScale;

	VcPlot = (CVcPlot)chart1.get_Plot();
	VcAxis = (CVcAxis)VcPlot.get_Axis(1, var);
	VcValueScale = VcAxis.get_ValueScale();
	VcValueScale.put_Auto(FALSE); // 不自动标注Y轴刻度
	VcValueScale.put_Maximum(30); // Y轴最大刻度
	VcValueScale.put_Minimum(0); // Y轴最小刻度
	VcValueScale.put_MajorDivision(10); // Y轴刻度10等分
	VcValueScale.put_MinorDivision(1); // 每刻度一个刻度线

	chart1.put_ShowLegend(TRUE);
	chart1.put_Column(1);
	chart1.put_ColumnLabel(_T("Temperature"));
	chart1.put_Column(2);
	chart1.put_ColumnLabel(_T("humidity"));
	


	// X轴设置
	
	CVcCategoryScale VcCategoryScale;
	VcPlot = (CVcPlot)chart1.get_Plot();
	VcAxis = (CVcAxis)VcPlot.get_Axis(0, var);
	VcCategoryScale = VcAxis.get_CategoryScale();
	VcCategoryScale.put_Auto(true);  // 不自动标注X轴刻度	
	VcCategoryScale.put_DivisionsPerLabel(1);// 每刻度一个标注	
	VcCategoryScale.put_DivisionsPerTick(1); // 每刻度一个刻度线	
	


	CVcDataGrid VcDataGrid;
	VcDataGrid = chart1.get_DataGrid();


	CString str;
	for (int row = 1; row <= 8; row++)
	{    
		chart1.put_Row(row);
		str.Format(_T("%d"), row);
		chart1.put_RowLabel(str);

		VcDataGrid.SetData(row, 1, item1[row - 1], 0);//设置第一条曲线的第row个点
		VcDataGrid.SetData(row, 2, item2[row - 1], 0);//设置第二条曲线的第row个点
		
		
	}

	chart1.Refresh();

}



void PCfuwuqi::OnBnClickedOk()
{

	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

//将接收到的数据存入缓存区，再存入文本，再存入二维数组，进而显示在编辑框

DWORD WINAPI ThreadB5(LPVOID lpParam)
{
	PCfuwuqi *pDlg = (PCfuwuqi*)lpParam;
	pDlg->InitSOCKET();
	return 0;
}




void PCfuwuqi::OnBnClickedButton1()
{
	
	
		if (hThread == NULL)
	{
		// 创建线程
		
			hThread = CreateThread(NULL, NULL, ThreadB5, this, NULL, &dw5);
	
		
	}	
	
	
}

void PCfuwuqi::TCPClient(SOCKET sock)
{
	
	int res;
	char msg[1500] = { 0 };
	
	while (blnloop)

	{  
		
		//从云平台获取数据
	const char* buff = "GET //devices/35369142/datastreams?datastream_ids=tempr,humi HTTP/1.1\r\nAccept: text/html, application/xhtml+xml, */*\r\nAccept-Language: zh-CN\r\nUser-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)\r\nHost: api.heclouds.com:80\r\nConnection: Keep-Alive\r\napi-key:=MVhcCVM2zySP5dWQvfjuwanLIY=\r\n\r\n";
	send(sock, buff, strlen(buff), 0);

	res = recv(sock, msg, 1500, 0);//接收数据  
    msg[res] = '\0';

		if (msg[0] > 0)
		{
			//将数据存入TXT文本文件,有所有的数据,作为存档
			FILE *fp;
			fp = fopen("G:\\SQL\\JSSJ.txt", "a+");
			fwrite(msg, res, 1, fp);
			fclose(fp);

			str1=msg;

			char F = ':';
			int index = 0;
			for (int i = 0; i <= 16; i++)
			{
				index = str1.Find(F, index + 1);
			}

			char G = '}';
			int index1 = 0;
			index1 = str1.Find(G, index1 + 1);

			result1 = str1.Mid(index + 1, index1 - index - 1);//取温度值

			int index2 = 0;
			for (int i = 0; i <= 23; i++)
			{
				index2 = str1.Find(F, index2 + 1);
			}


			int index3 = 0;
			for (int i = 0; i <= 1; i++)
			{
				index3 = str1.Find(G, index3 + 1);
			}
			result2 = str1.Mid(index2 + 1, index3 - index2 - 1);//取湿度

			

			
			EDIT33.SetSel(0, -1);
			EDIT33.ReplaceSel(result1);


			EDIT44.SetSel(0, -1);
			EDIT44.ReplaceSel(result2);


			

			
			CTime tm; tm = CTime::GetCurrentTime();
			EDIT11= tm.Format(_T("%X"));
			EDIT1.SetSel(0, -1);
			EDIT1.ReplaceSel(EDIT11);

			double c = _ttof(result1); double d = _ttof(result2); 

			//将数据存到缓冲区中,实现数组更新，数组实现队列的效果

			const int nRowCount = 8;
			chart1.put_RowCount(nRowCount);

			if (A == nRowCount)
			{
				for (int t = 1; t < nRowCount; t++)
				{
					item1[t - 1] = item1[t];
				}
				item1[nRowCount - 1] = c;
				A--;
			}
			item1[A] = c;

			if (B == nRowCount)
			{
				for (int t = 1; t < nRowCount; t++)
				{
					item2[t - 1] = item2[t];

				}
				item2[nRowCount - 1] = d;
				B--;
			}
			item2[B] = d;

			
			//替换数据



			CVcDataGrid VcDataGrid;
			VcDataGrid = chart1.get_DataGrid();

			for (int row = 1; row <= 8; row++)
			{
				VcDataGrid.SetData(row, 1, item1[row - 1], 0);//设置第一条曲线的第row个点
				VcDataGrid.SetData(row, 2, item2[row - 1] - item1[row - 1], 0);//设置第二条曲线的第row个点
				

				Sleep(1);
				MSG   msg1;
				while (PeekMessage(&msg1, 0, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg1);
					DispatchMessage(&msg1);
				}
			}

			chart1.Refresh();
			A++; B++; 

			if (c >23){
				if (hThread1 == NULL){
					hThread1 = CreateThread(NULL, 0, ThreadB1, NULL, 0, &dw1);
                }
			}

			if (d<0.9){
				if (hThread2 == NULL){
					hThread2 = CreateThread(NULL, 0, ThreadB2, NULL, 0, &dw2);
				}
			}
			

			//连接数据库，将数据存入数据库
			char sql[1024];
			MYSQL my_connection;
			MYSQL *conn_ptr;  //定义链接句柄

			conn_ptr = mysql_init(&my_connection);

			conn_ptr = mysql_real_connect(&my_connection, "localhost", "root", "aA165147", "szysj", 8081, NULL, 0);

			sprintf(sql, "insert into sssss(temperature,humidity) values('%S','%S')\n", result1, result2);


			if ((mysql_query(&my_connection, sql) == 0))        //执行SQL插入语句  
			{
				for (int k = 0; k < 1500; k++)
				{
					memset(sql, 0, 1024);
				}

			}

			
			mysql_close(&my_connection);
		}
		for (int k = 0; k < 1500; k++)
		{
			memset(msg, 0, 1500);
		}


		Sleep(1000);
		MSG   msg2;
		while (PeekMessage(&msg2, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg2);
			DispatchMessage(&msg2);
		}
	}

}




void PCfuwuqi::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void PCfuwuqi::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}











void PCfuwuqi::OnBnClickedButton2()
{
	
	
	//closesocket(listen_sock);
	lishishujuchaxun dlg;
	dlg.DoModal();
	// TODO:  在此添加控件通知处理程序代码
}


DWORD WINAPI PCfuwuqi::ThreadB1(LPVOID lpParam)
{
	// 定义结构对象  
	PROCESS_INFORMATION pi;
	STARTUPINFO         si;
	

	// 申请空间  
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));

	// 设置进程启动属性  
	si.cb = sizeof(STARTUPINFO);
	si.lpReserved = NULL;
	si.lpDesktop = NULL;
	si.lpTitle = NULL;
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	si.cbReserved2 = NULL;
	si.lpReserved2 = NULL;

	AfxMessageBox(_T("Temperature anomaly,please check"));
	
	return TRUE;

}

DWORD WINAPI PCfuwuqi::ThreadB2(LPVOID lpParam)
{
	// 定义结构对象  
	PROCESS_INFORMATION pi;
	STARTUPINFO         si;


	// 申请空间  
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));

	// 设置进程启动属性  
	si.cb = sizeof(STARTUPINFO);
	si.lpReserved = NULL;
	si.lpDesktop = NULL;
	si.lpTitle = NULL;
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	si.cbReserved2 = NULL;
	si.lpReserved2 = NULL;

	AfxMessageBox(_T("humidity anomaly,please check"));

	return TRUE;

}






void PCfuwuqi::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void PCfuwuqi::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	
	TerminateThread(hThread, dw5);
	CloseHandle(hThread);

	blnloop = false;
	closesocket(client);
	CDialogEx::OnCancel();
}
