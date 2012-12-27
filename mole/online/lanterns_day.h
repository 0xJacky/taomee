/*
 * =====================================================================================
 *
 *       Filename:  lanterns_day.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/31/2012 05:13:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericlee (), ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef _LANTERNS_DAY_H
#define _LANTERNS_DAY_H

//ˢ�³����е�������Բ
int ld_timer_initialize();
int ld_update_sp_lanterns( void* onwer, void* data );

//��ȡ�����е�������Բ��Ϣ
int ld_get_sp_lanterns_info_cmd(sprite_t* p, const uint8_t* body, int len);

//����������Բ
int ld_attack_sp_lanterns_cmd(sprite_t* p, const uint8_t* body, int len);
int ld_attack_sp_lanterns_callback(sprite_t* p);

//�������
int ld_attack_player(sprite_t* p_attacker, sprite_t* p_tar);

#endif
