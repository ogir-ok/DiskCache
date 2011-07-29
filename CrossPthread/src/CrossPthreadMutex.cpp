/*
 * CrossPthreadMutex.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include "CrossPthreadMutex.h"

CrossPthreadMutex_imp_unix::CrossPthreadMutex_imp_unix()
{
	pthread_mutex_init(&(this->_mutex),NULL);
}
CrossPthreadMutex_imp_unix::~CrossPthreadMutex_imp_unix()
{
	pthread_mutex_destroy(&(this->_mutex));

}
void CrossPthreadMutex_imp_unix::Lock()
{
	pthread_mutex_lock(&(this->_mutex));

}
void CrossPthreadMutex_imp_unix::Unlock()
{
	pthread_mutex_unlock(&(this->_mutex));
}

