/*
 * Mutex.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include <stdio.h>
#include "Mutex.h"

//#ifdef LINUX

Mutex::Mutex()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&(_mutex),&attr);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&(_mutex));
}

void Mutex::Lock()
{

	//printf("try lock \n");
	pthread_mutex_lock(&(_mutex));
	//printf("ok\n");
}

void Mutex::Unlock()
{

	//printf("unlock\n");
	pthread_mutex_unlock(&(_mutex));
}
//#endif
