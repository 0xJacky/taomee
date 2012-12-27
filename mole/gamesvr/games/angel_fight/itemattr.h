/*
 * =====================================================================================
 *
 *       Filename:  itemattr.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/14/2011 11:37:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ericlee, Ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */
#ifndef	ITEM_ATTR_H
#define	ITEM_ATTR_H

#define ITEM_HAS_ADDED		1

class ItemAttr
{
public:
	int32_t m_nType;				//1--��������  0--��ʹ(�����ܵ�����)
	int32_t m_nAddStr;				//����
	int32_t m_nAddInt;				//����
	int32_t m_nAddAgi;				//����
	int32_t m_nAddHab;				//����

	int32_t m_nAddAtk;				//������
	int32_t	m_nAddASD;				//�����ٶ�
	int32_t m_nAddEva;				//������
	int32_t	m_nAddCrit;				//������
	int32_t m_nAddBlock;			//��
	int32_t m_nAddHit;				//����
	int32_t	m_nAddCombo;			//����
	int32_t m_nAddDef;				//����
	int32_t m_nAddHp;
	int32_t m_nAddMp;
	int32_t m_nSkillID;				//��������
};

#endif

