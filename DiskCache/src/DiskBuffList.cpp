/*
 * DiskBuffList.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#include"DiskBuffList.h"

DiskBuffList::DiskBuffList()
{
	this->pHead=NULL;
	this->pTail=NULL;
	this->rw_lock = new CrossPthreadRWLock();
	this->countElem_lock= new CrossPthreadMutex();

}

DiskBuffList::~DiskBuffList()
{
	delete this->pHead;
	delete this->pTail;
	delete this->countElem_lock;
	delete this->rw_lock;
}

void DiskBuffList::AddToHead(DiskBuff el)
{
	this->rw_lock->Lock();
	DiskBuff newElement= new DiskBuff();


}

void DiskBuffList::AddToTail(DiskBuff el)
{

}

void DiskBuffList::Delete(DiskBuff * el)
{

}

DiskBuff* DiskBuffList::GetHead()
{

}


