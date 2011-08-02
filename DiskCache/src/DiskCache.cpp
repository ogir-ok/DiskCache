/*
 * DiskCache.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#include "DiskCache.h"

DiskCache::DiskCache()
{
	_diskBuffHashTable = new DiskBuffHashTable();
	_diskBuffFreeList = new DiskBuffList();
	_fsDriver = new FSDriver();
}
DiskCache::~DiskCache()
{
}
void* DiskCache::read(int fsId, int pos, int len)
{
	//num block
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 this->_diskBuffHashTable->Get(fsId,block);
	if(NULL==ans)
	{
		ans = this->_diskBuffFreeList->GetHead();
		this->_diskBuffFreeList->Delete(ans);
		if(DISK_BLOCK_CHANGED==ans->state)
		{
			_fsDriver->SetBlock(fsId,block, ans->pData);
		}
		ans->pData = _fsDriver->GetBlock(fsId, block);

	}
	else
	{

	}

}
void* DiskCache::write()
{
}


