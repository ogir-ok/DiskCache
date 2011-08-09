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
#include <Mutex.h>
#include <RWLock.h>
#include "DiskBuffHashTable.h"
#include "DiskBuffList.h"

class DiskCache
{
private:
	DiskBuffHashTable* _diskBuffHashTable;
	DiskBuffList* _diskBuffFreeList;
	FSDriver _fsDriver;
	Mutex* _mutex;
	int _buffCount;
public:
	DiskCache(char* DiskConfigFile);
	~DiskCache();
	char* Read(int fsId, int pos, int len);
	void Write(int fsId, int pos, int len, char* value);
};


#endif /* DISKCACHE_H_ */
