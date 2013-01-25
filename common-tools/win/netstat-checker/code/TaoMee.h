// TaoMee.h: interface for the CTaoMee class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TAOMEE_H__56B0A89D_D1B2_489B_8D3C_A8A980A03A57__INCLUDED_)
#define AFX_TAOMEE_H__56B0A89D_D1B2_489B_8D3C_A8A980A03A57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Log.h"
#include "NetSock.h"
#include "config.h"
#include "st.h"
#include "NetTestDlg.h"
#include <time.h>
#include <afxinet.h>
#include "md5.h"
class CTaoMee  
{
public:
	CTaoMee();
	virtual ~CTaoMee();
public:
	int Init(CNetTestDlg* p);
	//��ȡhostname
	int GetHostName();
	//��ȡIP������Ϣ ipconfig /all
	int GetIpconfig();
	//��ȡIE�汾��
	int GetIEVersion();
	//��ȡFlash�汾��
	int GetFlashVersion();
	//��ȡWEB_FILE�ļ�
	virtual int GetWebFile() = 0;
	//���Ե�½
	virtual int TryLogin();
	//��������
	virtual int TryOnline(unsigned char* session,int len) = 0;
	//��ȡDNS
	int GetDNS();
	//��ȡtracert����·��
	int GetTracertInfo();
	//��ȡONLINE����·��
	int GetOnlineTracertInfo();
	//��ȡLogin����·��
	int GetLoginTracertInfo();
	//��ȡ��½������Policy File 
	int GetLoginPolicyFile();
	//Telnet��½������
	int TelnetLogin();
	//��ȡ���߷�����Policy File 
	int GetOnlinePolicyFile();
	//Telnet���߷�����
	int TelnetOnline();
protected:
	int ExecDosCmd( char* pszCmd,char* pszOut,int nLen,unsigned long& nOutLen );
	int GetPolicyFile(char* pszIP,int nPort,char* pszOut,int nInLen,unsigned long& nOutLen);
	int Telnet(char* pszIP,int nPort);

	void SendShowOutEdit_S(char* pszMsg,unsigned long nMsgLen,char* pszData = NULL,unsigned long nDataLen = 0);// �ɹ�
	void SendShowOutEdit_F(char* pszMsg,unsigned long nMsgLen);// ʧ��
	void MakeMD5( unsigned char* session,int sessionlen);
	unsigned char m_szMD5[16];
protected:
	CLog m_log;
	CNetSock m_s;
private:
	CNetTestDlg* m_piNetTestDlg;

	
};

#endif // !defined(AFX_TAOMEE_H__56B0A89D_D1B2_489B_8D3C_A8A980A03A57__INCLUDED_)
