/*
 * DiskCache.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#include "DiskCache.h"

DiscCache::DiscCache()
{
}
DiscCache::~DiscCache()
{
}
void* DiscCache::read(int fsId, int pos, int len)
{
	//num block
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans = Get(fsId,block);
}
void* DiscCache::write()
{
}
