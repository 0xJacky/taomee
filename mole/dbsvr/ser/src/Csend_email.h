/*
 * =====================================================================================
 * 
 *       Filename:  Csend_email.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  2007年11月06日 19时52分58秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xcwen (xcwen), xcwenn@gmail.com
 *        Company:  TAOMEE
 * 
 * =====================================================================================
 */

#ifndef  CSEND_EMAIL_INCL
#define  CSEND_EMAIL_INCL
#include "proto.h"
#include "Cclientproto.h"
#include "sys/socket.h"
#include <netinet/in.h>
#include "tcpip.h" 
struct  time_stamp_proto_stru{
	uint32_t	len; 
	char		version; 
	uint32_t	cmdid; 
	uint32_t	userid; 
	int32_t		result; 
} __attribute__((packed));
class Csend_email {
	protected:
		Cclientproto  *cp;
		Cclientproto  *switch_cp;
		char time_stamp_ip[100];
		int time_stamp_port;
		int time_stamp_sockid;
		struct sockaddr_in  time_stamp_addr;
	public:
		Csend_email( Cclientproto *cp ); 
		int send_time_stamp( userid_t userid );
		int send_email( userid_t userid,uint32_t vipflag, uint32_t month);
		int pp_sync_vip( userid_t userid,uint32_t vipflag);
};
#endif   /* ----- #ifndef CSEND_EMAIL_INCL  ----- */

