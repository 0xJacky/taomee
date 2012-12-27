/*
 * =====================================================================================
 *
 *       Filename:  linker.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2012 02:32:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericlee (), ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef LINKER_H
#define LINKER_H

#include "../mpog.hpp"

class Linker:public mpog
{
public:
	//�����Ϣ
	struct PlayerInfo
	{
		sprite_t*	m_pSprite;
		uint32_t	m_nChessCntIni;		//��ʼ������Ŀ
		uint32_t	m_nChessCntCur;		//��ǰ������Ŀ
		int32_t		m_nChessUsed;		//�Ѿ�ʹ�õ���Ŀ
		uint32_t	m_nGoldAdd;			//��ȡ����Ϸ��
		char		m_cFlag;
		bool		m_bGetRes;
		bool		m_bHasItem[4];		//���͵� ����ֻ��Ϊһ���������Ʒ ��1��2���죬�֡�
	};
	//��ǰϵͳ״̬
	enum GameState
	{
		GS_INI,
		GS_RESOUCE_LOAD,
		GS_INGAME,
		GS_OVER,
	};
	//��Ϸ�ڲ�Э��
	enum LINKER_GAME_PROTO
	{
		LGP_GAME_START	= 0,
		LGP_SITTING,
		LGP_WIN,
		LGP_GAMEOVER,
		LGP_RAND_AWARD,
		LGP_GAME_INFO,
		LGP_LOAD_OK,
		LGP_GET_AWARD,
	};
	//���̱��
	enum CELL_FLAG
	{
		CF_BLANK		= 0,
		CF_WINTER		= 1,
		CF_SPRING		= 2,
		CF_GOLD200,
		CF_GOLD500,
		CF_GOLD1000,
		CF_CHESS_W_10,
		CF_CHESS_S_10,
		CF_CHESS_W_25,
		CF_CHESS_S_25,
		CF_CHESS_W_50,
		CF_CHESS_S_50,
		CF_BE_ADD		= (1<<7),		//ʤ�����ʱ�Ѽ�������еı��
	};

	//ʤ�������
	enum WINNER
	{
		W_HAVNT_OVER	= 0,
		W_WINTER		= 1,
		W_SPRING		= 2,
		
	};
	enum ResultReason
	{
		RR_NORMAL		= 0,
		RR_LEAVE,
		RR_TIMEOUT,
	};

	enum TimerEvent
	{
		TE_PLAYER_SIT	= 0,		//�ȴ��������
		TE_PLAYER_LOAD,				//�ȴ���Ҽ�����Դ
	};

public:
	int		handle_data( sprite_t* p, int cmd, const uint8_t body[], int len );
	int		handle_db_return( sprite_t* p, uint32_t id, const void* buf, int len, uint32_t ret_code );
	int		handle_timeout( void* data );
	void	init( sprite_t* p );
	Linker( game_group_t* grp );
	~Linker();

private:
	void	SendGameInfo();
	void	GameStart();
	int		GameOver( int winner, int reason = RR_NORMAL );
	int		Sitting( PlayerInfo* player, int pos );		//���� �����µ�����ΪY����������������Ϊx����
	int		CheckGameOver();							//�����Ϸ�Ƿ����
	int		IsPass( CELL_FLAG flag, int pos );			//���ָ���㵽Ŀ�ĵ��Ƿ���ͨ
	int		GetGameInfo(sprite_t* p);					//��ȡ��ǰ��Ϸ��Ϣ
	void	TestAdd( char pos );
	void	TestListClear();
	void	CreateRandomAward();						//���������Ʒ
	Linker::PlayerInfo* GetPlayer( sprite_t* p );

	void	BeginTimer( TimerEvent evt, uint32_t time );
	bool	EndTimer( bool force = false );

	game_group_t*	m_pGrp;
	list_head_t		m_timer;
	uint32_t		m_nTimerID;
	uint32_t		m_nTimerCounter;
	TimerEvent		m_nTimerEvent;
	PlayerInfo		m_player[2];
	char*			m_pMap;				//����
	char*			m_pTestList;
	char			m_cTestListCnt;
	int				m_nMapSize;			//���̱߳� 3*3 5*5 7*7
	uint32_t		m_nDBRetCntNeed;	//db��Ҫ���ص���������
	GameState		m_nGameState;
	char			m_cStepCnt;
	char			m_cCurOperator;		//��ǰ�ȴ����������	ȡֵΪ CF_WINTER,CF_SPRING
	char			m_cResloadCnt;		//�ȴ�������Դ���������
};

#endif
