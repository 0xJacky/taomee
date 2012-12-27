/*
 * =====================================================================================
 * 
 *       Filename:  Cvalidationcode.h
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

#ifndef  CVALIDATIONCODE_INCL
#define  CVALIDATIONCODE_INCL
#include "Ctable.h"
#define  VALIDATIONCODE_LEN 	16 
#define  CHECK_VALIDATION_ERR 	5001 


class Cvalidationcode :Ctable{
	protected:
	public:
		Cvalidationcode(mysql_interface * db );
		int add( char * code,   uint32_t *p_id);
		int check( uint32_t id, char *code );
};



#endif   /* ----- #ifndef cvalidationcode_incl  ----- */

