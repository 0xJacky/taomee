/**
 * =====================================================================================
 *       @file  base64.h
 *      @brief  ���ַ������м��룬����֤���ܺ��������Ȼ���ַ������Ȳ������Ǵ�ӡ�ַ�����Ӧ���ܡ�
 *
 *  Detailed description starts here.
 *
 *   @internal
 *     Created  2008��10��22�� 16ʱ22��13�� 
 *    Revision  1.0.0.0
 *    Compiler  gcc/g++
 *     Company  TaoMee .Inc
 *   Copyright  Copyright (c) 2008, aceway
 *
 *     @author  aceway (�������), aceway@taomee.com
 * This source code is wrote for TaoMee,Inc. ShangHai CN.
 * =====================================================================================
 */
#ifndef __BASE64__H_
#define __BASE64__H_

int Base64Enc(char *buf, char*text, int size);
int Base64Dec(char *buf,char*text,int size); 
char GetBase64Value(char ch);

#endif
