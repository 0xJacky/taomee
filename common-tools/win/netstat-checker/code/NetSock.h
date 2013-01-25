// NetSock.h: interface for the CNetSock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETSOCK_H__38AA255E_6C4C_4630_86C4_D8A8F6FE510F__INCLUDED_)
#define AFX_NETSOCK_H__38AA255E_6C4C_4630_86C4_D8A8F6FE510F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment (lib,"ws2_32")
#include <WINSOCK2.H>

class CNetSock  
{
public:
	CNetSock();
	virtual ~CNetSock();
public:
	void Init();
	int CreateSock(int nPORT,char* pszIP,int nType);
	int Connect();
	int Bind();
	//����:1.�ɹ�:���͸���. 2.ʧ��:-1
	int Send(char* pszData,int nLen);
	//����:1.�ɹ�:���ո���. 2.ʧ��:-1
	int Recv(char* pszData,int nLen);
private:
	int InitWSA();
	void CleanWSA();
	void CloseSocket();
	void InvalidSocket();
	SOCKET m_s;
	sockaddr_in m_sa;
};

#pragma pack(1)
struct  st_Head
{
	unsigned long PkgLen;//Э����ܳ��ȣ������ֽ��򣬲�����4k
	char Version;//�汾�� 1
	unsigned long CommandID;//��Ϣ������ 104
	unsigned long UserID;//�û�ID�� 55505237
	int Result;//������,��Client->Server������,���ֶβ�������.
};//17

#pragma pack(1)
struct st_LoginPack
{
	st_Head stHead;
	char Password[32];//�û����룬MD5����  142857 -> a420384997c8a1a93d5a84046117c2aa
	unsigned int Channel;//��½����,9
	unsigned int WhichGame;//1��Ħ��ׯ԰��2�������ţ�3�������
	unsigned int IP;//IP(����Ǵ������Php��ҳ�����û�������ַ����������Ϸ��0)
	st_LoginPack(int nWhichGame)
	{
		stHead.PkgLen = htonl(sizeof(*this));
		stHead.Version = '1';
		stHead.CommandID = htonl(104);
		stHead.UserID = htonl(55505237);
		stHead.Result = 0;
		strcpy(Password,"a420384997c8a1a93d5a84046117c2aa");
		Channel = htonl(9);
		WhichGame = htonl(nWhichGame);
		IP = 0;
	}
};//61

#pragma pack(1)
struct st_LoginPackAck 
{
	st_Head stHead;
	unsigned char Session[16];//��½Online�õ�Session
	unsigned int RoleCreated;//����Ϸ�Ľ�ɫ�Ƿ��Ѵ���0-û���� 1-�Ѵ���
};//37
#pragma pack(1)
struct st_OnlinePack
{
	st_Head stHead;
	short unsigned int OnlineID;//3
	unsigned char MD5[16];
	unsigned int SessionLen;
	unsigned char Session[16];//������֤��session
	st_OnlinePack(unsigned char* md5,int md5len,unsigned char* session)
	{
		stHead.PkgLen = htonl(sizeof(*this));
		stHead.Version = '1';
		stHead.CommandID = htonl(201);
		stHead.UserID = htonl(55505237);
		stHead.Result = 0;

		this->OnlineID = htons(3);
		memset(this->MD5,0,sizeof(this->MD5));
		memcpy(this->MD5,md5,md5len);

		this->SessionLen = htonl(sizeof(Session));
		memset(this->Session,0,sizeof(this->Session));
		memcpy(this->Session,session,sizeof(Session));
	}
	
};//39+16=55

#pragma pack(1)
struct st_SeerOnlinePack
{
	st_Head stHead;
	unsigned char Session[16];//������֤��session
	st_SeerOnlinePack(unsigned char* session,int len)
	{
		stHead.PkgLen = htonl(sizeof(*this));
		stHead.Version = '1';
		stHead.CommandID = htonl(1001);
		stHead.UserID = htonl(55505237);
		stHead.Result = 0;//?��½ʱ��дʲô

		memset(this->Session,0,sizeof(this->Session));
		memcpy(this->Session,session,sizeof(Session));
	}
};//17+16=33

#endif // !defined(AFX_NETSOCK_H__38AA255E_6C4C_4630_86C4_D8A8F6FE510F__INCLUDED_)
