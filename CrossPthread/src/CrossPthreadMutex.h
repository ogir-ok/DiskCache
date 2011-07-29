/*
 * CrossPthreadMutex.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef CROSSPTHREADMUTEX_H_
#define CROSSPTHREADMUTEX_H_

#include <pthread.h>

class CrossPthreadMutex
{
public:
	virtual void Lock()=0;
	virtual void Unlock()=0;
};

class CrossPthreadMutex_imp_unix: public CrossPthreadMutex
{
private:
	pthread_mutex_t _mutex;
public:
	CrossPthreadMutex_imp_unix();
	~CrossPthreadMutex_imp_unix();
	void Lock();
	void Unlock();
};

#endif /* CROSSPTHREADMUTEX_H_ */
