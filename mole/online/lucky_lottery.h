/*
 * =====================================================================================
 *
 *       Filename:  lucky_lottery.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2011 11:24:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  alexhe, alexhe@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef LUCKY_LOTTERY_H
#define LUCKY_LOTTERY_H

#define MAX_PRIZE_LEVEL		3
#define MAX_PRIZE_ITEM_CNT	4

typedef struct {
	uint32_t date;
	uint32_t ticket;
	uint32_t prize_level;
}__attribute__((packed)) get_lucky_ticket_package_t;

typedef struct {
	uint32_t ticket;
	uint32_t prize_level;
	uint32_t is_get;
}__attribute__((packed)) check_ticket_ckb_pack_t;

//��ȡ��Ʊ 4103
int user_get_lucky_ticket_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_get_lucky_ticket_callback(sprite_t* p, uint32_t id, char* buf, int len);

//check������û�������callback
int user_check_get_ticket_callback(sprite_t* p, uint32_t id, char* buf, int len);

//�һ���Ʊ 4104
int user_swap_ticket_prize_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_swap_ticket_prize_callback(sprite_t* p, uint32_t id, char* buf, int len);

//�鿴���ղ�Ʊ�н����� 4105
int user_look_today_prize_ticket_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_look_today_prize_ticket_callback(sprite_t* p, uint32_t id, char* buf, int len);

//�鿴��ʷ��Ʊ�н����뼰�Լ����õĲʵ���Ϣ 4106
int user_look_history_prize_ticket_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_look_history_prize_ticket_callback(sprite_t* p, uint32_t id, char* buf, int len);

//����7��������½����ѯ��½��� 4108
int user_get_national_day_login_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_get_national_day_login_callback(sprite_t* p, uint32_t id, char* buf, int len);

//Online Э�飺����7��������½����ȡ��� 4109
int user_get_national_day_gift_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_get_national_day_gift_callback(sprite_t* p, uint32_t id, char* buf, int len);
#endif
