/*
 * CrossPthreadRWLock.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include "CrossPthreadRWLock.h"
#include <pthread.h>

CrossPthreadRWLock_imp_unix::CrossPthreadRWLock_imp_unix()
{
	pthread_rwlock_init(&(this->_rwlock),NULL);
}


CrossPthreadRWLock_imp_unix::~CrossPthreadRWLock_imp_unix();
{
	pthread_rwlock_destroy(&(this->_rwlock),NULL);
}

void CrossPthreadRWLock_imp_unix::WrLock();
{
	pthrea(&(this->_rwlock),NULL);
}

void CrossPthreadRWLock_imp_unix::RdLock();
{
}
void CrossPthreadRWLock_imp_unix::Unlock();
{
	}
