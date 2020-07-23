#include "stdafx.h"
class PCfuwuqi;

class CClientItem
{
public:
	CString m_strIp;
	SOCKET m_ClientSocket;
	HANDLE m_hThread;
	PCfuwuqi *m_pMainWnd;
	CClientItem(){
		m_ClientSocket = INVALID_SOCKET;
		m_hThread = NULL;
		m_pMainWnd = NULL;
	}
};