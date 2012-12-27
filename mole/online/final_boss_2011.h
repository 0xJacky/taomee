/*
 * =====================================================================================
 *
 *       Filename:  final_boss_2011.h
 *
 *    Description:  2011��������BOSS
 *
 *        Version:  1.0
 *        Created:  08/15/2011 03:01:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ericlee, Ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef FINAL_BOSS_2011_H
#define FINAL_BOSS_2011_H

#define FB_MAP_ID				225

enum WEAPON_TYPE
{
	WT_MAGIC_ICE		= 0,//ˮ
	WT_MAGIC_NATURE,		//ľ
	WT_MAGIC_FIRE,			//��
	WT_MAGIC_SPIRIT,		//����
	WT_WATER_BOMB,			//ˮ��
	WT_BLUE_BOMB,			//��ɫը��
	WT_MAX
};

typedef struct weapon_info_s
{
	int				damage;		//�����˺�
	int				cd;			//����ʩ��ʱ��
	timer_struct_t*	timer;		//������ʱ��
} weapon_info_t;

int fb_initialize();

void fb_water_bomb_attack(sprite_t*p, uint32_t x, uint32_t y);

//��ȡbossѪ��������
int	fb_get_boss_info_cmd(sprite_t* p, const uint8_t* body, int len);
//������̨
int fb_enter_turret_cmd(sprite_t* p, const uint8_t* body, int len);
int fb_enter_bomb_trret(sprite_t* p, int bomb_count);
//�뿪��̨
int fb_leave_turret_cmd(sprite_t* p, const uint8_t* body, int len);

#endif
