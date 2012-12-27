/*
 * =====================================================================================
 * 
 *       Filename:  CtableRoute.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  2007��11��06�� 19ʱ52��58�� CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xcwen (xcwen), xcwenn@gmail.com
 *        Company:  TAOMEE
 * 
 * =====================================================================================
 */

#ifndef  CTABLEROUTE_INCL
#define  CTABLEROUTE_INCL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "proto.h"
#include "Ctable.h"


class CtableRoute : public Ctable {
	protected:
		char table_name_pre[40];
		char db_name_pre[40];
		char id_name[20];
		enum enum_db_type db_type;
		//ͨ�� id �õ�����(��ʽ�� dbname.table, ��: USER_00.t_user_pet_00 )
		// �õ��ı��������� this->tmp_table_name
		// ���� ����
		virtual char*  get_table_name(uint32_t id);
	public:
		//�жϼ�¼�Ƿ���� ͨ�� ID 
		virtual int id_is_existed(uint32_t id, bool * existed);
		// db_type : ���ݿ����� 
		// table_name_pre : ������ǰ�沿�֣��磺 t_user_pet_00 --  t_user_pet_99, д�����t_user_pet 
		// id_name : ����id_is_existed������
		CtableRoute(mysql_interface * db, const char * db_name_pre,  
		 const char * table_name_pre,const char* id_name ) ;


		int set_int_value(userid_t userid ,const char * field_type , uint32_t  value);
		int get_int_value(userid_t userid ,const char * field_type ,  uint32_t * p_value);
		int change_int_field(userid_t userid ,const char * field_type ,
			   	int32_t changevalue, uint32_t max_value ,uint32_t *p_value );

		int set_int_value_bit(uint32_t userid ,
				const char * field_type ,uint32_t bitid ,uint32_t  value);

		virtual ~CtableRoute(void){} 

};

#endif   /* ----- #ifndef CTABLEROUTE_INCL  ----- */

