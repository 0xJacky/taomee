/*
 * =====================================================================================
 *
 *       Filename:  levelinfo.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/20/2011 03:59:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ericlee, Ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef LEVEL_INFO_H
#define LEVEL_INFO_H

#define LEVEL_DROP_ITEM_MAX_COUNT	5

enum LEVEL_TYPE
{
	LT_NORMAL	= 0,
	LT_BOSS,
	LT_BOSS_TIME,
	LT_BOSS_VIP,
	LT_BOSS_COST,
	LT_FRIEND,
	LT_GET_APPRENTICE,		//��ͽ��
	LT_GRAB_APPRENTICE,		//��ͽ��
	LT_PK_MASTER,			//��սʦ��
	LT_PK_APPRENTICE,		//��սͽ��
	LT_TRAIN,				//ʦͽ�д�
	LT_PK,
	LT_BOSS_ACTIVE,			//�BOSS
	LT_MAX,
	LT_MAKE_DWARD		= 0xFFFFFFF,
};

class LevelInfo
{
public:
	LevelInfo( int id );
	~LevelInfo();

	void	GetRandMonsterID( int* id, int& count );
	bool	CheckTimeRange();
	int		GetLevelType();
	int		GetKey();
	int		GetCard();

	void	XmlAddMonsterID( char* val );
	void	XmlSetCreatureCount( char* val );
	void	XmlSetExpLose( char* val );
	void	XmlSetExpWin( char* val );
	void	XmlSetCPoint( char* val );
	void	XmlSetCondLvlID( char* val );
	void	XmlSetCondPLevel( char* val );
	void	XmlSetConsume( char* val );
	void	XmlSetTimeBegin( char* val );
	void	XmlSetTimeEnd( char* val );
	void	XmlSetKey( char* val );
	void	XmlSetCard( char* val );
	void	XmlSetType( char* val );
public:
	typedef std::vector<int>			VecMonsterID_t;
	typedef VecMonsterID_t::iterator 	VecMonsterIDIt_t;

	VecMonsterID_t	m_vecMonster;
	int				m_nLevelID;
	int				m_nCreatureCount;			//һ�γ��ֵĹ�����Ŀ
	int				m_nExpWin;					//ʤ�����齱��
	int				m_nExpLose;					//ʧ�ܾ��齱��
	int				m_nCompletePoint;			//��ͼ��ɶȼӳ�
	int				m_nCondLevelID;				//Ҫ����ɵĹؿ�
	int				m_nCondPLevel;				//Ҫ����ҵȼ�
	int				m_nConsume;					//��������
	int				m_nTimeBegin;				//ʱ����������
	int				m_nTimeEnd;
	int				m_nKeyNeed;					//����Կ��
	int				m_nCardNeed;				//�����ſ�
	int				m_nType;
};

inline int	LevelInfo::GetLevelType()
{
	return m_nType;
}

inline int LevelInfo::GetKey()
{
	return m_nKeyNeed;
}

inline int LevelInfo::GetCard()
{
	return m_nCardNeed;
}

#endif

