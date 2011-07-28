/*
 * DiskBuff.h
 *
 *  Created on: Jul 28, 2011
 *      Author: user
 */

#include <pthread.h>

#ifndef DISKBUFF_H_
#define DISKBUFF_H_

#define BUFF_STATE_FREE 0;


class DiskBuffer
{
private:
	pthread_mutex_t _state_locker; //mutex for locking state of the buffer
public:
	int fsId;
	int fsBlockNum;
	int state;
	void* pData;
	DiskBuffer();
	~DiskBuffer();
};

#endif /* DISKBUFF_H_ */
