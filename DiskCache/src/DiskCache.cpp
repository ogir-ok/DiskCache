/*
 * DiskCache.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#include "DiskCache.h"
DiskCache::DiskCache(char* DiskConfigFile)
{
	_diskBuffHashTable = new DiskBuffHashTable();
	_diskBuffFreeList = new DiskBuffList();
	FSDriver::Create(DiskConfigFile);
	_mutex = new Mutex();
	_buffCount = 0;
}

DiskCache::~DiskCache()
{
	delete _diskBuffHashTable;
	delete _diskBuffFreeList;
	delete _mutex;
	FSDriver::Destroy();
}

char* DiskCache::Read(int fsId, int pos, int len)
{
	this->_mutex->Lock();
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 _diskBuffHashTable->Get(fsId,block);

	if(NULL == ans)
	{
		if (_buffCount < MAX_BUFF_COUNT)
		{
			ans = new DiskBuff();
		}
		else
		{
			do
			{
				ans = ->_diskBuffFreeList->GetHead();
			}
			while(NULL == ans);

			_diskBuffHashTable->Del(ans);
			_diskBuffFreeList->Delete(ans);

			if(DISK_BLOCK_CHANGED == ans->state)
			{
				 FSDriver::Instance()->SetBlock(fsId,block, ans->pData);
			}
		}
		ans->pData = FSDriver::Instance()->GetBlock(fsId, block);
		_diskBuffHashTable->Add(ans);
	}
	else
	{
		_diskBuffFreeList->Delete(ans);
	}
	char *temp = NULL;

	temp = ans->pData;
	_diskBuffFreeList->AddToTail(ans);
	_mutex->Unlock();
	return temp;
}

void DiskCache::Write(int fsId, int pos, int len, char* value)
{
	_mutex->Lock();
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 _diskBuffHashTable->Get(fsId,block);
	if(NULL == ans)
	{
		if (_buffCount < MAX_BUFF_COUNT)
		{
			ans=new DiskBuff();
		}
		else
		{
			do
			{
				ans = _diskBuffFreeList->GetHead();
			}while(NULL==ans);

			_diskBuffHashTable->Del(ans);
			_diskBuffFreeList->Delete(ans);

			if(DISK_BLOCK_CHANGED == ans->state)
			{
				 FSDriver::Instance()->SetBlock(fsId,block, ans->pData);
			}
		}
		_diskBuffHashTable->Add(ans);

	}
	else
	{
		_diskBuffFreeList->Delete(ans);
	}
	ans->pData = value;
	ans->state = DISK_BLOCK_CHANGED;
	this->_diskBuffFreeList->AddToTail(ans);
	this->_mutex->Unlock();
}


