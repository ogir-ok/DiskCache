/*
 * DiskCache.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#include "DiskCache.h"
DiskCache::DiskCache(char* DiskConfigFile)
{
	this->_diskBuffHashTable = new DiskBuffHashTable();
	this->_diskBuffFreeList = new DiskBuffList();
	FSDriver::Create(DiskConfigFile);
	this->_mutex= new CrossPthreadMutex();
	this->_buffCount=0;
}

DiskCache::~DiskCache()
{
	delete this->_diskBuffHashTable;
	delete this->_diskBuffFreeList;
	delete this->_mutex;
	FSDriver::Destroy();
}

char* DiskCache::Read(int fsId, int pos, int len)
{
	//num block
	this->_mutex->Lock();

	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 this->_diskBuffHashTable->Get(fsId,block);

	if(NULL == ans)
	{
		if (this->_buffCount < MAX_BUFF_COUNT)
		{
			ans = new DiskBuff();
		}
		else
		{
			do
			{
				ans = this->_diskBuffFreeList->GetHead();
			}
			while(NULL == ans);

			this->_diskBuffHashTable->Del(ans);
			this->_diskBuffFreeList->Delete(ans);

			if(DISK_BLOCK_CHANGED == ans->state)
			{
				 FSDriver::Instance()->SetBlock(fsId,block, ans->pData);
			}
		}
		ans->pData = FSDriver::Instance()->GetBlock(fsId, block);
		this->_diskBuffHashTable->Add(ans);
	}
	else
	{
		this->_diskBuffFreeList->Delete(ans);
	}
	char *temp = NULL;

	temp = ans->pData;
	this->_diskBuffFreeList->AddToTail(ans);

	this->_mutex->Unlock();
	return temp;
}

void DiskCache::Write(int fsId, int pos, int len, char* value)
{
	//num block
	this->_mutex->Lock();
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 this->_diskBuffHashTable->Get(fsId,block);
	if(NULL==ans)
	{
		if (this->_buffCount<MAX_BUFF_COUNT)
		{
			ans=new DiskBuff();
		}
		else
		{
			do
			{
				ans = this->_diskBuffFreeList->GetHead();
			}while(NULL==ans);

			this->_diskBuffHashTable->Del(ans);
			this->_diskBuffFreeList->Delete(ans);

			if(DISK_BLOCK_CHANGED==ans->state)
			{
				 FSDriver::Instance()->SetBlock(fsId,block, ans->pData);
			}
		}
		this->_diskBuffHashTable->Add(ans);

	}
	else
	{
		this->_diskBuffFreeList->Delete(ans);
	}
	ans->pData=value;
	ans->state = DISK_BLOCK_CHANGED;
	this->_diskBuffFreeList->AddToTail(ans);
	this->_mutex->Unlock();
}


