// PCfuwuqi.cpp : ʵ���ļ�
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



//SOCKET listen_sock;//�����׽���Socket
SOCKET client;
BOOL blnloop = true;


// PCfuwuqi �Ի���

IMPLEMENT_DYNAMIC(PCfuwuqi, CDialogEx)
BOOL PCfuwuqi::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();
	
	//SOCKET listen_sock;//�����׽���Socket
	PCfuwuqi::InitMschart1();
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

   


// PCfuwuqi ��Ϣ�������


void PCfuwuqi::InitSOCKET()
{
	/*�������������ݳ���

	WSADATA wsaData;  //�ṹ�����

	WORD wVersion;

	wVersion = MAKEWORD(2, 2);

	WSAStartup(wVersion, &wsaData);

	SOCKADDR_IN local_addr; //local address
	SOCKADDR_IN client_addr;

	int iaddrSize = sizeof(client_addr);

	PCfuwuqi* dlg = (PCfuwuqi*)AfxGetApp()->GetMainWnd();
	local_addr.sin_family = AF_INET; //IPv4 address family
	local_addr.sin_port = htons(12345); //ת��Ϊu_short
	local_addr.sin_addr.s_addr = INADDR_ANY;//Any incoming interface  ����ϵͳͨ��ָ��ͨ�����ַ inaddr_any ��Ϊ������Ҫ��Internet��ַ��ѡ����

	listen_sock = socket(AF_INET, SOCK_STREAM, 0);//����IP��ַ-IPV4  ���׽���

	bind(listen_sock, (struct sockaddr*) &local_addr, sizeof(local_addr));//�׽��ְ󶨱��صĵ�ַ�Ͷ˿�

	listen(listen_sock, 5);//���׽�������Ϊ����״̬

	//run forever   ���ս��������
	while (true)
	{
	int sock = accept(listen_sock, (struct sockaddr *)&client_addr, &iaddrSize);

	PCfuwuqi::TCPClient(sock);
	}
	*/
	
	//�ͻ��˽������ݳ���
	
	//EdpPacket* send_pkg;
	WSADATA wsaData;
	SOCKADDR_IN server_addr;

	WORD wVersion;

	wVersion = MAKEWORD(2, 2);

	WSAStartup(wVersion, &wsaData);

	char ip[32];
	sprintf(ip, "183.230.40.34");//ȡ�÷�������IP��ַ  
	server_addr.sin_addr.s_addr = inet_addr(ip);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(80);
	if ((client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		AfxMessageBox(_T("create socket error"));
	}
	if (connect(client, (struct sockaddr *) &server_addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("���ӷ�����ʧ��"));
	}
	else
	{
		AfxMessageBox(_T("�Ƿ����Ӵ˷�����"));

	}

	//send_pkg = PacketConnect1(DEV_ID, API_KEY);
	
	while (true)
	{

		PCfuwuqi::TCPClient(client);
	}
	

}
void PCfuwuqi::InitMschart1()
	{


	// ջģʽ
	chart1.put_Stacking(TRUE);
	

	//Y������


	CVcPlot VcPlot;
	CVcAxis VcAxis;
	VARIANT var;
	CVcValueScale VcValueScale;

	VcPlot = (CVcPlot)chart1.get_Plot();
	VcAxis = (CVcAxis)VcPlot.get_Axis(1, var);
	VcValueScale = VcAxis.get_ValueScale();
	VcValueScale.put_Auto(FALSE); // ���Զ���עY��̶�
	VcValueScale.put_Maximum(30); // Y�����̶�
	VcValueScale.put_Minimum(0); // Y����С�̶�
	VcValueScale.put_MajorDivision(10); // Y��̶�10�ȷ�
	VcValueScale.put_MinorDivision(1); // ÿ�̶�һ���̶���

	chart1.put_ShowLegend(TRUE);
	chart1.put_Column(1);
	chart1.put_ColumnLabel(_T("Temperature"));
	chart1.put_Column(2);
	chart1.put_ColumnLabel(_T("humidity"));
	


	// X������
	
	CVcCategoryScale VcCategoryScale;
	VcPlot = (CVcPlot)chart1.get_Plot();
	VcAxis = (CVcAxis)VcPlot.get_Axis(0, var);
	VcCategoryScale = VcAxis.get_CategoryScale();
	VcCategoryScale.put_Auto(true);  // ���Զ���עX��̶�	
	VcCategoryScale.put_DivisionsPerLabel(1);// ÿ�̶�һ����ע	
	VcCategoryScale.put_DivisionsPerTick(1); // ÿ�̶�һ���̶���	
	


	CVcDataGrid VcDataGrid;
	VcDataGrid = chart1.get_DataGrid();


	CString str;
	for (int row = 1; row <= 8; row++)
	{    
		chart1.put_Row(row);
		str.Format(_T("%d"), row);
		chart1.put_RowLabel(str);

		VcDataGrid.SetData(row, 1, item1[row - 1], 0);//���õ�һ�����ߵĵ�row����
		VcDataGrid.SetData(row, 2, item2[row - 1], 0);//���õڶ������ߵĵ�row����
		
		
	}

	chart1.Refresh();

}



void PCfuwuqi::OnBnClickedOk()
{

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

//�����յ������ݴ��뻺�������ٴ����ı����ٴ����ά���飬������ʾ�ڱ༭��

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
		// �����߳�
		
			hThread = CreateThread(NULL, NULL, ThreadB5, this, NULL, &dw5);
	
		
	}	
	
	
}

void PCfuwuqi::TCPClient(SOCKET sock)
{
	
	int res;
	char msg[1500] = { 0 };
	
	while (blnloop)

	{  
		
		//����ƽ̨��ȡ����
	const char* buff = "GET //devices/35369142/datastreams?datastream_ids=tempr,humi HTTP/1.1\r\nAccept: text/html, application/xhtml+xml, */*\r\nAccept-Language: zh-CN\r\nUser-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)\r\nHost: api.heclouds.com:80\r\nConnection: Keep-Alive\r\napi-key:=MVhcCVM2zySP5dWQvfjuwanLIY=\r\n\r\n";
	send(sock, buff, strlen(buff), 0);

	res = recv(sock, msg, 1500, 0);//��������  
    msg[res] = '\0';

		if (msg[0] > 0)
		{
			//�����ݴ���TXT�ı��ļ�,�����е�����,��Ϊ�浵
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

			result1 = str1.Mid(index + 1, index1 - index - 1);//ȡ�¶�ֵ

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
			result2 = str1.Mid(index2 + 1, index3 - index2 - 1);//ȡʪ��

			

			
			EDIT33.SetSel(0, -1);
			EDIT33.ReplaceSel(result1);


			EDIT44.SetSel(0, -1);
			EDIT44.ReplaceSel(result2);


			

			
			CTime tm; tm = CTime::GetCurrentTime();
			EDIT11= tm.Format(_T("%X"));
			EDIT1.SetSel(0, -1);
			EDIT1.ReplaceSel(EDIT11);

			double c = _ttof(result1); double d = _ttof(result2); 

			//�����ݴ浽��������,ʵ��������£�����ʵ�ֶ��е�Ч��

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

			
			//�滻����



			CVcDataGrid VcDataGrid;
			VcDataGrid = chart1.get_DataGrid();

			for (int row = 1; row <= 8; row++)
			{
				VcDataGrid.SetData(row, 1, item1[row - 1], 0);//���õ�һ�����ߵĵ�row����
				VcDataGrid.SetData(row, 2, item2[row - 1] - item1[row - 1], 0);//���õڶ������ߵĵ�row����
				

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
			

			//�������ݿ⣬�����ݴ������ݿ�
			char sql[1024];
			MYSQL my_connection;
			MYSQL *conn_ptr;  //�������Ӿ��

			conn_ptr = mysql_init(&my_connection);

			conn_ptr = mysql_real_connect(&my_connection, "localhost", "root", "aA165147", "szysj", 8081, NULL, 0);

			sprintf(sql, "insert into sssss(temperature,humidity) values('%S','%S')\n", result1, result2);


			if ((mysql_query(&my_connection, sql) == 0))        //ִ��SQL�������  
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void PCfuwuqi::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}











void PCfuwuqi::OnBnClickedButton2()
{
	
	
	//closesocket(listen_sock);
	lishishujuchaxun dlg;
	dlg.DoModal();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


DWORD WINAPI PCfuwuqi::ThreadB1(LPVOID lpParam)
{
	// ����ṹ����  
	PROCESS_INFORMATION pi;
	STARTUPINFO         si;
	

	// ����ռ�  
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));

	// ���ý�����������  
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
	// ����ṹ����  
	PROCESS_INFORMATION pi;
	STARTUPINFO         si;


	// ����ռ�  
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));

	// ���ý�����������  
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void PCfuwuqi::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	TerminateThread(hThread, dw5);
	CloseHandle(hThread);

	blnloop = false;
	closesocket(client);
	CDialogEx::OnCancel();
}
