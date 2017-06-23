/*
 * =====================================================================================
 *
 *       Filename:  module.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/22/2017 09:05:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghui Lee (lizh), leezhenghui@gmail.com
 *
 * =====================================================================================
 */

#ifndef CPLUGIN_H
#define CPLUGIN_H
 
#ifdef __cplusplus
extern "C" {
#endif

#include<stdio.h>

	extern void init(); 
	extern void start(); 
	extern void stop(); 
	extern void destory(); 

#ifdef __cplusplus
}
#endif

#endif
