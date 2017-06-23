/*
 * =====================================================================================
 *
 *       Filename:  hello_world_en.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/22/2017 09:15:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghui Lee (lizh), leezhenghui@gmail.com
 *
 * =====================================================================================
 */

#include "hello_world.h"
#include "../deps/simplelogger/simplog.h"
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sayHello
 *  Description:  
 * =====================================================================================
 */
void sayHello ()
{
	simplog.writeLog( SIMPLOG_INFO, "hellow_world_en sayHello [Enter]");
	printf("   >>>   Hello World   <<< \n");
	simplog.writeLog( SIMPLOG_INFO, "hellow_world_en sayHello [Exit]");
}		/* -----  end of function sayHello  ----- */
