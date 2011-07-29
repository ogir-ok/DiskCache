/*
 * CrossPthreadMutex.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#ifndef CROSSPTHREADMUTEX_H_
#define CROSSPTHREADMUTEX_H_

#ifndef LINUX

#include <pthread.h>

class CrossPthreadMutex
{
private:
	pthread_mutex_t _mutex;
public:
	CrossPthreadMutex();
	~CrossPthreadMutex();
	void Lock();
	void Unlock();
};

#elif WINDOWS
/*class CrossPthreadMutex
{
private:
	pthread_mutex_t _mutex;
public:
	CrossPthreadMutex();
	~CrossPthreadMutex();
	void Lock();
	void Unlock();
};*/
#endif

#endif /* CROSSPTHREADMUTEX_H_ */
