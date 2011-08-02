/*
 * DiskBuffHashTable.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */


#include "DiskBuffHashTable.h"

DiskBuffHashTable::DiskBuffHashTable()
{
	for (int i = 0; i< HASH_SIZE;i++)
	{
		DiskBuffFullList temp;
		this->_hash.push_back(temp);
	}
}
DiskBuffHashTable::~DiskBuffHashTable()
{
}
void DiskBuffHashTable:: Add(DiskBuff* buff)
{
	this->_lock.WrLock();
	this->_hash[buff->fsBlockNum%HASH_SIZE].AddToTail(buff);
	this->_lock.Unlock();
}
void DiskBuffHashTable:: Del(DiskBuff* buff)
{
	this->_lock.WrLock();
	this->_hash[buff->fsBlockNum%HASH_SIZE].Delete(buff);
	this->_lock.RdLock();
}

DiskBuff* DiskBuffHashTable::Get(int fsId,int blockNum)
{
	this->_lock.RdLock();
	DiskBuff* temp;
	temp = this->_hash[blockNum%HASH_SIZE].Get(fsId,blockNum);
	this->_lock.Unlock();
	return temp;
}
