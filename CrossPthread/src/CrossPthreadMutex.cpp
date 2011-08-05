/*
 * CrossPthreadMutex.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include <stdio.h>
#include "CrossPthreadMutex.h"

//#ifdef LINUX

CrossPthreadMutex::CrossPthreadMutex()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&(this->_mutex),&attr);
}

CrossPthreadMutex::~CrossPthreadMutex()
{
	pthread_mutex_destroy(&(this->_mutex));
}

void CrossPthreadMutex::Lock()
{

	printf("try lock \n");
	pthread_mutex_lock(&(this->_mutex));
	printf("ok\n");
}

void CrossPthreadMutex::Unlock()
{

	printf("unlock\n");
	pthread_mutex_unlock(&(this->_mutex));
}
//#endif
