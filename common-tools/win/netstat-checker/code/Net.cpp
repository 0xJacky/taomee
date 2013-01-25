// Net.cpp: implementation of the CNet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <afxinet.h>
#include <atlbase.h>
#include <process.h>


#include "netTest.h"
#include "Net.h"
#include "config.h"
#include "netTestDlg.h"
#include "st.h"
#include "TaoMee.h"
#include "51Mole.h"
#include "51Seer.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern CTaoMee* g_pTaoMee;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNet::CNet()
{
	m_hThreadTest = NULL;
}

CNet::~CNet()
{
	
}

int CNet::BeginTest()
{
	if (!m_hThreadTest)
	{
		m_hThreadTest = (HANDLE)_beginthreadex(NULL,0,ThreadTest,this,0,NULL);
	}
	return 0;
}

unsigned __stdcall CNet::ThreadTest( void* pData )
{
	CNet* pThis = (CNet*) pData;
	CTaoMee* pTaoMee = NULL;

#ifdef DO_51MOLE
	pTaoMee = new C51Mole;
#else
	pTaoMee = new C51Seer;
#endif // DO_51MOLE
	g_pTaoMee = pTaoMee;

	pTaoMee->Init(pThis->m_piNetTestDlg);
	
	pTaoMee->GetHostName();//��ȡhostname
	pTaoMee->GetIpconfig();//��ȡIP������Ϣ
	pTaoMee->GetIEVersion();//��ȡIE�汾��
	pTaoMee->GetFlashVersion();
	pTaoMee->GetWebFile();//��ȡWEB_FILE�ļ�_51MOLE
	pTaoMee->TryLogin();
	pTaoMee->GetDNS();
	pTaoMee->GetTracertInfo();//��ȡtracert����·��
	pTaoMee->GetLoginTracertInfo();//��ȡlogin������·��
	pTaoMee->GetOnlineTracertInfo();//��ȡonline������·��
	pTaoMee->GetLoginPolicyFile();//��ȡ��½������Policy File 
	pTaoMee->TelnetLogin();//Telnet��½������
	pTaoMee->GetOnlinePolicyFile();//��ȡ���߷�����Policy File 
	pTaoMee->TelnetOnline();//Telnet���߷�����

	if (pTaoMee)
	{
		delete pTaoMee;
		pTaoMee = NULL;
	}
	PostMessage(pThis->m_piNetTestDlg->m_hWnd,WM_MSG_TEST_DONE,0,0);
	return 0;
}

int CNet::Init( CNetTestDlg* piNetTestDlg )
{
	m_piNetTestDlg = piNetTestDlg;
	return 0;
}

int CNet::WaitThread()
{
	if (m_hThreadTest)
	{
		DWORD dw = WaitForSingleObject(m_hThreadTest,INFINITE);
		m_hThreadTest = NULL;
	}
	return 0;
}