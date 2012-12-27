/*
 * =====================================================================================
 *
 *       Filename:  CtableRoute100x100_ex.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007��11��06�� 19ʱ52��56�� CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xcwen (xcwen), xcwenn@gmail.com
 *        Company:  TAOMEE
 *
 * =====================================================================================
 */
#include "CtableRoute100x100_ex.h"

#include "common.h"
#include "proto.h"
#include "benchapi.h"
	// id_name : ����id_is_existed������
CtableRoute100x100_ex::CtableRoute100x100_ex(mysql_interface * db, const char * db_name_pre,  
		 const char * table_name_pre,const char* id_name )
	: CtableRoute(db, db_name_pre, table_name_pre, id_name )
{

}

char * CtableRoute100x100_ex::get_table_name(uint32_t id)
{
	sprintf (this->db_table_name,"%s_%d.%s_%d",
	this->db_name_pre, (id/100)%100, this->table_name_pre, id%100);
	return this->db_table_name;
}

