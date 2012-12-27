/*
 * =====================================================================================
 *
 *       Filename:  spring_couplets.c
 *
 *    Description:  ����ħ��ǽ
 *
 *        Version:  1.0
 *        Created:  01/09/2012 02:20:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  alexhe, alexhe@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#ifndef COUPLETS_H__
#define COUPLETS_H__

#include "sprite.h"
#include "item.h"

#define MAX_COUPLETS_WORD_ID	53

#define MAX_COUPLETS_TITLE_SIZE		4
#define MAX_COUPLETS_WORD_SIZE		7

typedef struct {
	uint32_t couplets_id;
	uint8_t couplets_title[MAX_COUPLETS_TITLE_SIZE];
	uint8_t first_line[MAX_COUPLETS_WORD_SIZE];
	uint8_t second_line[MAX_COUPLETS_WORD_SIZE];
}__attribute__((packed)) spring_couplets_info_t;

//����ħ��ǽ:�ύ���� 4124
int user_submit_spring_couplets_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_submit_spring_couplets_callback(sprite_t* p, uint32_t id, char* buf, int len);

//����ħ��ǽ:�鿴�û������д��� 4125
int user_get_spring_couplets_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_get_spring_couplets_callback(sprite_t* p, uint32_t id, char* buf, int len);

//����ħ��ǽ:�鿴ǽ�ϵĴ����б� 4126
int user_get_couplets_userid_list_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_get_couplets_userid_list_callback(sprite_t* p, uint32_t id, char* buf, int len);

//����ħ��ǽ:���˴�������Ը 4128
int user_set_couplets_prize_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_set_couplets_prize_callback(sprite_t* p, uint32_t id, char* buf, int len);

//����ħ��ǽ:��ȡ���� 4127
int user_get_couplets_prize_cmd(sprite_t *p, const uint8_t *buf, int len);
int user_get_couplets_prize_callback(sprite_t* p, uint32_t id, char* buf, int len);

#endif
