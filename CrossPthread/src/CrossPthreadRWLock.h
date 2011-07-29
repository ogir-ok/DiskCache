/*
 * CrossPthreadRWLock.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef CROSSPTHREADRWLOCK_H_
#define CROSSPTHREADRWLOCK_H_

#include <pthread.h>

#ifdef LINUX

class CrossPthreadRWLock
{
private:
	pthread_rwlock_t _rwlock;
public:
	CrossPthreadRWLock();
	~CrossPthreadRWLock();
	void WrLock();
	void RdLock();
	void Unlock();
};

#elif WINDOWS

class CrossPthreadRWLock
{
private:
	pthread_rwlock_t _rwlock;
public:
	CrossPthreadRWLock();
	~CrossPthreadRWLock();
	void WrLock();
	void RdLock();
	void Unlock();
};

#endif

#endif /* CROSSPTHREADRWLOCK_H_ */
