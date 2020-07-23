
// DlgProxy.cpp : 实现文件
//

#include "stdafx.h"
#include "shuiziyuanyuanchengjiankongzhongxin.h"
#include "DlgProxy.h"
#include "shuiziyuanyuanchengjiankongzhongxinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy

IMPLEMENT_DYNCREATE(CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy, CCmdTarget)

CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy::CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy()
{
	EnableAutomation();
	
	// 为使应用程序在自动化对象处于活动状态时一直保持 
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CshuiziyuanyuanchengjiankongzhongxinDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CshuiziyuanyuanchengjiankongzhongxinDlg)))
		{
			m_pDialog = reinterpret_cast<CshuiziyuanyuanchengjiankongzhongxinDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy::~CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_Ishuiziyuanyuanchengjiankongzhongxin 的支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {967D4C29-34A0-421C-A997-111CDDFB086E}
static const IID IID_Ishuiziyuanyuanchengjiankongzhongxin =
{ 0x967D4C29, 0x34A0, 0x421C, { 0xA9, 0x97, 0x11, 0x1C, 0xDD, 0xFB, 0x8, 0x6E } };

BEGIN_INTERFACE_MAP(CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy, IID_Ishuiziyuanyuanchengjiankongzhongxin, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {83317560-B27B-4498-84FD-F456421DC241}
IMPLEMENT_OLECREATE2(CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy, "shuiziyuanyuanchengjiankongzhongxin.Application", 0x83317560, 0xb27b, 0x4498, 0x84, 0xfd, 0xf4, 0x56, 0x42, 0x1d, 0xc2, 0x41)


// CshuiziyuanyuanchengjiankongzhongxinDlgAutoProxy 消息处理程序
