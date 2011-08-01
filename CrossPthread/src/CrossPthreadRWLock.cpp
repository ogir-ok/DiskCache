/*
 * CrossPthreadRWLock.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include "CrossPthreadRWLock.h"

//#ifdef LINUX

CrossPthreadRWLock::CrossPthreadRWLock()
{
	pthread_rwlock_init(&(this->_rwlock),NULL);
}


CrossPthreadRWLock::~CrossPthreadRWLock()
{
	pthread_rwlock_destroy(&(this->_rwlock));
}

void CrossPthreadRWLock::WrLock()
{
	pthread_rwlock_wrlock(&(this->_rwlock));
}

void CrossPthreadRWLock::RdLock()
{
	pthread_rwlock_rdlock(&(this->_rwlock));
}

void CrossPthreadRWLock::Unlock()
{
	pthread_rwlock_unlock(&(this->_rwlock));
}

//#endif
