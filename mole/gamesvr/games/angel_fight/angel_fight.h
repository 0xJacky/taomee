/*
 * =====================================================================================
 *
 *       Filename:  angel_fight.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/08/2011 05:56:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ericlee, Ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef ANGEL_FIGHT_H
#define ANGEL_FIGHT_H

#include "../mpog.hpp"

#define PLAYER_COUNT	2

enum ANGEL_FIGHT_PROTO
{
	AFP_CMD_HEAD				= 30500,
	AFP_NOTIFY_ACTION			= 30501,
	AFP_NOTIFY_GAME_INFO		= 30502,
	AFP_NOTIFY_ROUND_BEGIN		= 30503,
	AFP_NOTIFY_GAME_OVER		= 30504,
	AFP_NOTIFY_CHANGE_PLAYER	= 30505,
	AFP_NOTIFY_AWARD			= 30506,
	AFP_DB_OK					= 30507,
	AFP_PLAYER_LEAVE			= 30508,
};

enum ANGEL_FIGHT_CMD
{
	AFC_ACTION			= (1<<1),
	AFC_SELECT_MONSTER 	= (1<<2),
	AFC_QUIT			= (1<<3),
//	AFC_REMOVE_CARD		= (1<<4),
//	AFC_GET_AWARD		= (1<<5),
	AFC_DATA_OK			= (1<<6),
	AFC_QUICK_GAME		= (1<<7),
	AFC_ANI_OK			= (1<<8),
};

enum TIMER_EVENT
{
	TE_OPERATION		= 1,
	TE_SELECT_MONSTER,
	TE_WAIT_ANI,
	TE_LOAD_DATA,
	TE_CHANGE_PLAYER,
};

enum GAME_STATE
{
	GS_WAIT_DB		= 1,
	GS_WAIT_CLIENT,
	GS_WAIT_DB_FRIEND,
	GS_WAIT_DB_LEVEL,
	GS_OVER
};

enum GAME_TYPE
{
	GT_FRIEND		= 0,	//���Ѷ�ս
	GT_MONSTER,				//��ս����
	GT_GET_APPRENTICE,		//��ͽս��
	GT_GRAB_APPR,			//��ͽ�ܣ���ս�Է���ʦ��
	GT_PK_APPR,				//��սͽ��
	GT_PK_MASTER,			//��սʦ��
	GT_TRAIN,				//ʦͽ�д�
};

class Player;

int32_t GetExpAward( int32_t levelSelf, int32_t levelTar, bool isWin );
int32_t GetExpMAPK( LEVEL_TYPE lt, int32_t levelSelf,int32_t levelTar, bool isWin );
void InitializeExpAward();

class AngelFight:public mpog
{
public:
	int		handle_data( sprite_t* p, int cmd, const uint8_t body[], int len );
	int		handle_db_return( sprite_t* p, uint32_t id, const void* buf, int len, uint32_t ret_code );
	int		handle_timeout( void* data );
	void	init( sprite_t* p );

	AngelFight( game_group_t* grp );
	AngelFight( game_group_t* grp, Player* p1, Player* p2 );
	~AngelFight();

	void	TestLoop();
private:

	int		OnAction( Player* p, const uint8_t buf[], int len );
	int		OnSelectMonster( Player* p, const uint8_t buf[], int len );
	int		OnQuit( Player* p, const uint8_t buf[], int len );
	int		OnLoadDataOK( Player* p, const uint8_t buf[], int len );
	int		OnAniOK( Player* p, const uint8_t buf[], int len );
	int		OnQuickGame( Player* p, const uint8_t buf[], int len );

	int		UnPackDataForTest( uint8_t* data, int32_t len );
	void	TestInitialize();

	//����sprite_t��ȡPlayerָ��
	Player* GetPlayer( sprite_t* p );

	void	BeginTimer( TIMER_EVENT evt, uint32_t time );
	bool	EndTimer( bool force = false );

	//��Ϸ��ʼ
	void	GameStart();
	//��ȡ�������
	int		SetPlayerInfo( sprite_t* p, char* data, int len );

	int		SetFriendInfo( uint32_t id, char* data, int len );
	//һ�غϿ�ʼ
	int		RoundBegin();
	int		NotifyGameInfo();
	//����ҹ㲥�غϿ�ʼ
	int 	NotifyRoundBegin();
	//�㲥��Ҳ���
	int		ActionAndNotify();
	//�㲥 ��Ϸ����
	int		NotifyGameOver();
	//�����Ϸ�Ƿ����
	int		CheckGameOver();

	int		SelectMonster( Player* player );

private:
	int32_t			m_nWinnerTeam;
	game_group_t*	m_pGrp;
	Player*			m_pPlayers[PLAYER_COUNT];	//��ǰ���ɫ���������Զ���
	Player*			m_pTeam[PLAYER_COUNT];		//��ɫ���飬ÿ����������в�ֹһ����
	uint32_t		m_nPlayerCount;
	list_head_t		m_timer;
	uint32_t		m_nTimerID;
	uint32_t		m_nTimerCounter;
	GAME_STATE		m_nGameState;
	uint32_t 		m_nDBInfoCount;				//���ݿⷵ�ص������Ϣ����
	bool			m_bQuickGame;				//������Ϸ
	int32_t			m_nLevelID;					//�ؿ�ID
	uint32_t		m_nFriendID;				//����ID
	TIMER_EVENT		m_nTimerEvent;
	LEVEL_TYPE		m_nLevelType;				//��Ϸ����
	uint32_t		m_nTarApprID;				//��ͽ��ʱ��ͽ��ԭ��ʦ����ID
	bool			m_bAuto;
};

#endif
