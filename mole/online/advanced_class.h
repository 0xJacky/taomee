/*
 * =====================================================================================
 *
 *       Filename:  advanced_class.h
 *
 *    Description:  �Ƚ��༶
 *
 *        Version:  1.0
 *        Created:  02/13/2012 02:41:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericlee (), ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef _ADVANCED_CLASS_
#define _ADVANCED_CLASS_


//�任ͷ�ϵı��
int ac_change_flag_cmd(sprite_t *p, const uint8_t *buf, int bodylen);
//�任��ǻ�ȡ��Ʒ��ÿ�����Ʒ���
int ac_change_flag_award_day_limit_callback( sprite_t* p, uint32_t user_id );
//ѡ��վ̨
int ac_set_sit_cmd(sprite_t *p, const uint8_t *buf, int bodylen);
//��ȡ��Ϸ��Ϣ
int ac_get_game_info_cmd(sprite_t *p, const uint8_t *buf, int bodylen);
int ac_get_game_info_callback(sprite_t* p, uint32_t red_score, uint32_t blue_score);
//��ȡ��Ʒ
int ac_get_award_cmd(sprite_t *p, const uint8_t *buf, int bodylen);

int ac_player_leave( uint32_t id );

#endif
