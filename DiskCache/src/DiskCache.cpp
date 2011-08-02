/*
 * DiskCache.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */

#include "DiskCache.h"

DiskCache::DiskCache()
{
	this->_diskBuffHashTable = new DiskBuffHashTable();
	this->_diskBuffFreeList = new DiskBuffList();
	this->_fsDriver = new FSDriver();
	this->_mutex= new CrossPthreadMutex();
}
DiskCache::~DiskCache()
{
	delete this->_diskBuffHashTable;
	delete this->_diskBuffFreeList;
	delete this->_fsDriver;
	delete this->_mutex;
}
void* DiskCache::read(int fsId, int pos, int len)
{
	//num block
	this->_mutex->Lock();
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 this->_diskBuffHashTable->Get(fsId,block);
	if(NULL==ans)
	{
		do
		{
			ans = this->_diskBuffFreeList->GetHead();
		}while(NULL==ans);
		this->_diskBuffFreeList->Delete(ans);
		if(DISK_BLOCK_CHANGED==ans->state)
		{
			this->_fsDriver->SetBlock(fsId,block, ans->pData);
		}
		ans->pData = this->_fsDriver->GetBlock(fsId, block);
		this->_diskBuffHashTable->Add(ans);
	}
	else
	{

		this->_diskBuffFreeList->Delete(ans);
	}
	void *temp=NULL;
	temp = ans->pData;
	this->_diskBuffFreeList->AddToTail(ans);
	this->_mutex->Unlock();
	return temp;
}

void* DiskCache::write(int fsId, int pos, int len, void* value)
{
	//num block
	this->_mutex->Lock();
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 this->_diskBuffHashTable->Get(fsId,block);
	if(NULL==ans)
	{
		do
		{
			ans = this->_diskBuffFreeList->GetHead();
		}while(NULL==ans);
		this->_diskBuffFreeList->Delete(ans);
		if(DISK_BLOCK_CHANGED==ans->state)
		{
			this->_fsDriver->SetBlock(fsId,block, ans->pData);
		}
		ans->pData = this->_fsDriver->GetBlock(fsId, block);
		this->_diskBuffHashTable->Add(ans);
	}
	else
	{
		this->_diskBuffFreeList->Delete(ans);
	}
	void *temp=NULL;
	temp = ans->pData;
	ans->state=DISK_BLOCK_CHANGED;
	this->_diskBuffFreeList->AddToTail(ans);
	this->_mutex->Unlock();
	return temp;
}
