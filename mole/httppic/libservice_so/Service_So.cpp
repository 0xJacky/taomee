/**
 * =====================================================================================
 *       @file  Service_So.cpp
 *      @brief  ����socket���ӣ������ַܷ�
 *
 *   @internal
 *     Created  2008��10��22�� 17ʱ20��23�� 
 *    Revision  1.0.0.0
 *    Compiler  gcc/g++
 *     Company  TaoMee .Inc
 *   Copyright  Copyright (c) 2008, aceway
 *
 *     @author  aceway (�������), aceway@taomee.com
 * This source code is wrote for TaoMee,Inc. ShangHai CN.
 * =====================================================================================
 */

#include "./Service_So.h"
#include "./http_processer.h"
#include "./safe_socket.h"


/** 
 * @brief  ���ϲ���õ��ĸ��ӿ�֮һ���������߳�ģ��
 * @param  None 
 * @return void 
 */
extern "C" void fini ()
{
  LOG(NORMAL, "main process:%d stopped\n", getpid());
}

//��ʼ��ģ��

/** 
 * @brief  ���ϲ���õ��ĸ��ӿ�֮һ����ʼ�����߳�ģ��
 * @param  int argc, ��Ӧ��main()�����Ĳ���int argc 
 * @param  char* argv[], ��Ӧ��main()�����Ĳ���char* argv[] 
 * @return �����롣�÷��أ�1, ��ʾ��Ҫ�ϲ�������߳�ģ�飬0������������ 
 */
extern "C" int init (int argc, char* argv[])
{
    signal(SIGPIPE,SIG_IGN);

    char image_default_path[1024]={0};

    sprintf(image_default_path, "%s", RELOCATE_DEFAULT_SAVE_FILE_PATH);
    int nret = mkdir(image_default_path, 0777); 
    if(nret != 0)
    { 
        if(errno != 17)
        {
            LOG(ERROR, "create folder [%s] failed! error %d, info: %s.\r\n", 
                    image_default_path, errno, strerror(errno));
        }
    }

    if(!make_folders_in_dir(image_default_path, MAX_SAVING_SUBFOLDER_COUNT))
    {
        LOG(ERROR, "create %d subfolders in [%s] failded! \nerror info: %s.\n", 
                MAX_SAVING_SUBFOLDER_COUNT, image_default_path, strerror(errno));
    }
    return 0;
} 

/** 
 * @brief  �ϲ���õ��ĸ��ӿ�֮һ��֪ͨ��ģ�鴦����ܵ�socket
 * @param  int fd, ���ܵ�socket������ 
 * @return �����롣����-1����ʾ��Ҫ�ϲ�������߳�ģ��, 0���������� 
 */
extern "C" int handle_accept (int fd)  
{
    struct timeval tv = {5, 0};
    int corked = 1;
    //���÷�����ģʽ
//    int flags = fcntl(fd, F_GETFL, 0);
//    fcntl (fd, F_SETFL, O_NONBLOCK| flags);

    setsockopt(fd, IPPROTO_TCP, TCP_CORK, &corked, sizeof(corked));
    //���ó�ʱ5s
    setsockopt (fd, SOL_SOCKET, SO_RCVTIMEO, &tv,sizeof(tv));
    setsockopt (fd, SOL_SOCKET, SO_SNDTIMEO, &tv,sizeof(tv));
    //����������Ϊ240K
//	int nbuflen = 240*1024;
//  setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char*)&nbuflen, sizeof(int));
//  setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char*)&nbuflen, sizeof(int));

    //��¼�ͻ��˵�����Ϣ
    struct sockaddr_in add;
    socklen_t len = sizeof(add);
    int ret =-1;
    ret = getpeername(fd, (sockaddr*)&add, &len);
    char *padd =NULL; 
    if(ret ==0)
    {
        padd = inet_ntoa(add.sin_addr);
        LOG(DEBUG, "handle accept, client: IP[%s]--PORT[%d].", padd, ntohs(add.sin_port));
    }
    else
    {
        LOG(ERROR, "can not get the peer address, ip and port. info:%s", strerror(errno));
    }
    return 0;
}

/** 
 * @brief  ����socket�¼��������ݵ�������Ҫ���գ��Լ����պ�Ļ�Ӧ
 * @param  int fd, Ҫ�����socket�������� 
 * @return �����롣����-1����ʾ��Ҫ�ϲ�������߳�ģ��, 0����������  
 */
extern "C" int handle_socket (int fd)//��������fd��һ���Ϸ���Ҫ�����ж�	
{
    if(fd < 0)
    {
        LOG(ERROR, "handle socket fd error, fd=%d\n", fd);
        //sleep(1);
        return -1;
    }
    char buf[SOCKET_BUFFER_SIZE]={0};
    struct http_header header;
    int recv_len = 0;
    struct sockaddr_in add;
    memset(&header, 0, sizeof(http_header));

    //��ÿͻ���IP�� �˿�
    socklen_t len = sizeof(add);
    int ret =-1;
    ret = getpeername(fd, (sockaddr*)&add, &len);
    char *padd =NULL; 
    if(ret ==0)
    {
        padd = inet_ntoa(add.sin_addr);
        LOG(DEBUG, "handle socket, client IP[%s]--PORT[%d].", padd, ntohs(add.sin_port));
    }
    else
    {
        LOG(ERROR, "can not get the peer address, ip and port. info:%s", strerror(errno));
    }

    //����HTTPͷ
    recv_len = recv_until_chars(fd, buf, SOCKET_BUFFER_SIZE, "\r\n\r\n",
                                header.parameter, MAX_CONTENT_LEN, header.parameter_len);

    if(recv_len >= 16)
    {
        header.header_info_len = recv_len - header.parameter_len;
        //2---��������ͷ
        header = parse_http_header(buf, recv_len);  
        if(padd != NULL)
        {
            sprintf(header.user_ip, "%s", padd);
            header.user_port = ntohs(add.sin_port);
        }
        //3---���ݽ������ִ�в���
        if(header.is_valid)
        {
            int ret_code = -1;
            ret_code = process_request(fd, header);  
            LOG(DEBUG, "Process The HTTP method OK!");
            LOG(DEBUG, "close client, IP:[%s]--PORT:[%d].\n", padd, ntohs(add.sin_port));
            //sleep(3);
            return -1;
        }
        else
        {
            LOG(ERROR, "******received unknon data, I can not parse it********");
            LOG(DEBUG, "close client, IP:[%s]--PORT:[%d].\n", padd, ntohs(add.sin_port));
            response_unkown_method(fd, header);
            //sleep(2);
            return -1;
        }
    }
    LOG(ERROR, "Receive data Error, %s, %d!", __FILE__, __LINE__);
    padd = inet_ntoa(add.sin_addr);
    LOG(ERROR, "close client, IP:[%s]--PORT:[%d].\n", padd, ntohs(add.sin_port));
    //sleep(1);
    return -1;
}
