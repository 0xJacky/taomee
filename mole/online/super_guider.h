/*
 * =====================================================================================
 *
 *       Filename:  super_mogu.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2011 11:12:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jim (xcwen), jim@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef SUPER_GUIDER_H
#define SUPER_GUIDER_H

#include "sprite.h"
#include "item.h"

//Ѳ�������ȡ 4113
int sg_get_patrol_tast_cmd(sprite_t* p, const uint8_t* body, int len);
int sg_get_patrol_tast_callback(sprite_t * p, uint32_t id, char * buf, int len);

//СĦ������Ѱ����� 4114
int sg_user_ask_for_help_cmd(sprite_t* p, const uint8_t* body, int len);

//����Ģ���򵼻�ӦСĦ��Ѱ����� 4115
int sg_guider_help_others_cmd(sprite_t* p, const uint8_t* body, int len);

//��óɾͽ��� 4116
int sg_get_guider_prize_cmd(sprite_t* p, const uint8_t* body, int len);
int sg_get_guider_prize_callback(sprite_t * p, uint32_t id, char * buf, int len);

//��ѯ��õĳɾͽ��� 4117
int sg_look_guider_prize_cmd(sprite_t* p, const uint8_t* body, int len);
int sg_look_guider_prize_callback(sprite_t * p, uint32_t id, char * buf, int len);

#endif
