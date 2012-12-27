/*
 * =====================================================================================
 *
 *       Filename:  matcher.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/19/2011 10:07:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ericlee, Ericlee@taomee.com
 *        Company:  taomee
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstring>

extern "C" {
#include <time.h>
#include <libtaomee/log.h>
#include <libxml/tree.h>
#include <gameserv/dll.h>
#include <gameserv/timer.h>
#include <gameserv/proto.h>
#include <gameserv/config.h>
#include <gameserv/dbproxy.h>
#ifndef TW_VER
#include  <statistic_agent/msglog.h>
#endif
}

#include "ocean_match.h"
#include "adventure.h"


/* 
 * @brief ÿ����ҽ���
 * @param sprite_t* p ���ָ�� 
 * @return �� 
 */
void Omatch::init(sprite_t *p)
{
	DEBUG_LOG("p->id: %u", p->id);

	if( COMPETE_MODE_GAME(p->group->game)){
		if(m_wait_player == 0){
			m_wait_player = p;
		}
		else{
			if(p == m_wait_player){
				return;
			}
			else{

				DEBUG_LOG("wait_id: %u", m_wait_player->id);
				free_game_group( p->group );
				p->group = m_wait_player->group;
				m_wait_player->group->players[1] = p;
				m_wait_player->group->count = 2;

#ifndef TW_VER
				{
					//part in
					//uint32_t msgbuff[2]= { p->id, 1 };
					//msglog( statistic_file, 0x0409C3C0, get_now_tv()->tv_sec, &msgbuff, sizeof(msgbuff) );
				}
#endif
				adventure* game = new adventure(m_wait_player->group, p, m_wait_player);
				m_wait_player->group->game_handler = game;

				m_wait_player = 0;
			}
		}//else
	}//if
	else{
		adventure* game = new adventure( p->group, p, NULL );
		p->group->game_handler = game;
		p->waitcmd = 0;
	}
}

/*
 * @brief �����;�˳�����Ϸ��ָ����� 
 * @param sprite_t* p ���ָ�� 
 * @param uint8_t body[] ���ݰ�
 * @param int len  ���ݰ�����
 */
int  Omatch::handle_data(sprite_t* p, int cmd, const uint8_t body[], int len)
{

	// player leave game
   if(cmd == proto_player_leave){
	   if(m_wait_player == p){
		   m_wait_player = 0;
	   }
	  
	   p->group->game_handler = NULL;
	   for (int i = 0; i < p->group->count; i++) {
		   p->group->players[i]->waitcmd = 0;
	   }
	
	}
   	return  GER_end_of_game;
}


/*
 * @brief �����;�˳�����Ϸ��ָ����� 
 * @param sprite_t* p ���ָ�� 
 * @param uint32_t id ���ID
 * @param const void* buf ���ݰ�
 * @param int len  ���ݰ�����
 * @param uint32_t ret_code ����ֵ
 */

int  Omatch::handle_db_return(sprite_t* p, uint32_t id, const void* buf, int len, uint32_t ret_code)
{	
	return 0;
}

/*  
 * @brief �����;�˳�����Ϸ��ָ����� 
 * @param void* data 
 */
int Omatch::handle_timeout(void* data)
{

	//if (m_wait_player != 0) {
		//m_wait_player = 0;

	//} else {
		//ADD_TIMER_EVENT(p->group, on_game_timer_expire, u_info, now.tv_sec + 10);
	//}
	return 0;
}
