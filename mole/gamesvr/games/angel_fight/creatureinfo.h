/*
 * =====================================================================================
 *
 *       Filename:  creatureinfo.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/14/2011 10:13:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ericlee, Ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef CREATURE_INFO_H
#define CREATURE_INFO_H

#define MAX_SKILL_COUNT		5				//�������
#define MAX_ITEM_COUNT		5				//��������Ʒ��

class CreatureInfo
{
public:
	CreatureInfo();
	~CreatureInfo();
	void AddSkill( int32_t idx );
	void AddItem( int32_t idx );

	void XmlSetStr( char* val );
	void XmlSetInt( char* val );
	void XmlSetAgile( char* val );
	void XmlSetHabitus( char* val );
	void XmlSetLevel( char* val );
	void XmlAddItem( char* val );
	void XmlAddSkill( char* val );

	void XmlSetAtk( char* val );
	void XmlSetAspd( char* val );
	void XmlSetEvad( char* val );
	void XmlSetBlock( char* val );
	void XmlSetCrit( char* val );
	void XmlSetHit( char* val );
	void XmlSetCombo( char* val );
	void XmlSetDef( char* val );
	void XmlSetIsBoss( char* val );
public:
	int32_t m_nLevel;				//�ȼ�
	int32_t	m_nCreatureID;
	bool	m_bIsBoss;
	int32_t m_nStr;					//����
	int32_t m_nInt;					//����
	int32_t m_nAgile;				//����
	int32_t m_nHabitus;				//����

	int32_t m_nAttack;				//������
	int32_t	m_nActSpeed;			//�ж��ٶ�
	int32_t m_nEvasion;				//������
	int32_t	m_nBlock;				//����
	int32_t	m_nCritical;			//������
	int32_t m_nHit;					//������
	int32_t	m_nCombo;				//����
	int32_t m_nDef;					//����

	int32_t m_nSkill[MAX_SKILL_COUNT];	//��������
	int32_t m_nSkillCount;
	int32_t m_nItem[MAX_ITEM_COUNT];
	int32_t m_nItemCount;
};

#endif
