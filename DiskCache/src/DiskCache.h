/*
 * DiskCache.h
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#ifndef DISKCACHE_H_
#define DISKCACHE_H_

#include <FSDriver.h>
#include <CrossPthreadMutex.h>
#include <CrossPthreadRWLock.h>
#include "DiskBuffHashTable.h"
#include "DiskBuffList.h"

class DiskCache
{
private:
	DiskBuffHashTable* _diskBuffHashTable;
	DiskBuffList* _diskBuffFreeList;
	Singleton<FSDriver> _fsDriver;
	CrossPthreadMutex* _mutex;
public:
	DiskCache();
	~DiskCache();
	void* read(int fsId, int pos, int len);
	void* write(int fsId, int pos, int len, void* value);
};


#endif /* DISKCACHE_H_ */
