/*
 * CrossPthreadRWLock.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef CROSSPTHREADRWLOCK_H_
#define CROSSPTHREADRWLOCK_H_

#include <pthread.h>

class CrossPthreadRWLock
{
public:
	virtual void WrLock()=0;
	virtual void RdLock()=0;
	virtual void Unlock()=0;
};

class CrossPthreadRWLock_imp_unix: public CrossPthreadRWLock
{
private:
	pthread_rwlock_t _rwlock;
public:
	CrossPthreadRWLock_imp_unix();
	~CrossPthreadRWLock_imp_unix();
	void WrLock();
	void RdLock();
	void Unlock();
};

#endif /* CROSSPTHREADRWLOCK_H_ */
