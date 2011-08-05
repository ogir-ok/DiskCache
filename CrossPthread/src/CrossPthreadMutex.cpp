/*
 * CrossPthreadMutex.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include "CrossPthreadMutex.h"

//#ifdef LINUX

CrossPthreadMutex::CrossPthreadMutex()
{
	pthread_mutex_init(&(this->_mutex),NULL);
}

CrossPthreadMutex::~CrossPthreadMutex()
{
	pthread_mutex_destroy(&(this->_mutex));
}

void CrossPthreadMutex::Lock()
{
	pthread_mutex_lock(&(this->_mutex));

}

void CrossPthreadMutex::Unlock()
{
	pthread_mutex_unlock(&(this->_mutex));
}
//#endif
