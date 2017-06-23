/*
 *  =====================================================================================
 *  
 *  Filename:  main.c
 *  
 *  Description:  
 *  
 *  Version:  1.0
 *          Created:  06/21/2017 10:14:12 PM
 *  Revision:  v1.0.0 
 *  Compiler:  gcc
 * 
 *      Author:  Zhenghui Lee (lizh), leezhenghui@gmail.com
 * 
 * =====================================================================================
 */

#include	<stdlib.h>
#include  <stdio.h>
#include  <dlfcn.h> 
#include  "../deps/simplelogger/simplog.h"
#include "hello_world.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	void *lib_handle_en;
	void *lib_handle_cn;
	double (*fn)();
	char *error;

	simplog.writeLog( SIMPLOG_INFO, "main [Enter]");
	printf("   >>>   Hello World; 世界，你好 >>>   <<< \n");
	
	/**
	 * Dynamical Loading shared object
	 */
	simplog.writeLog( SIMPLOG_INFO, "main [Enter] [Dynamical Call Shared Object]");
	lib_handle_cn = dlopen("/home/lizh/playground/c-workspace/c-plugin/build/out/Debug/lib.target/libhelloworld_cn.so", RTLD_LAZY);
	if (!lib_handle_cn)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	
	lib_handle_en = dlopen("/home/lizh/playground/c-workspace/c-plugin/build/out/Debug/lib.target/libhelloworld_en.so", RTLD_LAZY);
	if (!lib_handle_en)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	fn = dlsym(lib_handle_en, "sayHello");
	if ((error = dlerror()) != NULL) 
	{
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	(*fn)();
	

	fn = dlsym(lib_handle_cn, "sayHello");
	if ((error = dlerror()) != NULL) 
	{
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	(*fn)();

	simplog.writeLog( SIMPLOG_INFO, "main [Exit] [Dynamical Call Shared Object]");
	simplog.writeLog( SIMPLOG_INFO, "main [Exit]");
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
