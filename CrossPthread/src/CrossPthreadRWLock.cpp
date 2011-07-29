/*
 * CrossPthreadRWLock.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include "CrossPthreadRWLock.h"

CrossPthreadRWLock_imp_unix::CrossPthreadRWLock_imp_unix()
{
	pthread_rwlock_init(&(this->_rwlock),NULL);
}


CrossPthreadRWLock_imp_unix::~CrossPthreadRWLock_imp_unix()
{
	pthread_rwlock_destroy(&(this->_rwlock));
}

void CrossPthreadRWLock_imp_unix::WrLock()
{
	pthread_rwlock_wrlock(&(this->_rwlock));
}

void CrossPthreadRWLock_imp_unix::RdLock()
{
	pthread_rwlock_rdlock(&(this->_rwlock));
}

void CrossPthreadRWLock_imp_unix::Unlock()
{
	pthread_rwlock_unlock(&(this->_rwlock));
}
