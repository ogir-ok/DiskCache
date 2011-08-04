/*
 * DiskCache.h
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#ifndef DISKCACHE_H_
#define DISKCACHE_H_

#define MAX_BUFF_COUNT 256

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
	FSDriver _fsDriver;
	CrossPthreadMutex* _mutex;
	int _buffCount;
public:
	DiskCache(char* DiskConfigFile);
	~DiskCache();
	char* read(int fsId, int pos, int len);
	void write(int fsId, int pos, int len, char* value);
};


#endif /* DISKCACHE_H_ */
