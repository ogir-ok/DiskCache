/*
 * DiskBuffList.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#include"DiskBuffList.h"

DiskBuffList::DiskBuffList()
{
	this->_pHead=NULL;
	this->_pTail=NULL;
	this->_rwlock = new CrossPthreadRWLock();
	this->_countElemLock= new CrossPthreadMutex();
	this->_countElem=0;

}

DiskBuffList::~DiskBuffList()
{
	delete this->_pHead;
	delete this->_pTail;
	delete this->_countElemLock;
	delete this->_rwlock;
}

void DiskBuffList::AddToTail(DiskBuff* addBuff)
{
	this->_rwlock->WrLock();
	DiskBuff* newElement = addBuff;
	newElement->pFreeNext=NULL;
	newElement->pFreePrev = this->_pTail;
	if (NULL != this->_pTail)
	{
		_pTail->pFreePrev=newElement;
	}
	this->_pTail=newElement;
	if (NULL == this-> _pHead)
	{
		this->_pHead=newElement;
	}
	this->_countElemLock->Unlock();
	this->_countElemLock->Lock();
	_countElem++;
	this->_countElemLock->Unlock();
}

void DiskBuffList::Delete(DiskBuff * currentElement)
{
	this->_rwlock->WrLock();
	if (NULL!=currentElement)
	{
		if (this->_pHead == currentElement)
		{
			this->_pHead = currentElement->pFreeNext;
			delete currentElement;
		}
		else
		if (this->_pTail == currentElement)
		{
			this->_pTail = currentElement->pFreePrev;
			delete currentElement;
		}
		else
		{
			currentElement->pFreeNext->pFreePrev=currentElement->pFreePrev;
			currentElement->pFreePrev->pFreeNext=currentElement->pFreeNext;
			this->_countElemLock->Lock();
				_countElem--;
			this->_countElemLock->Unlock();
			delete currentElement;
		}
	}
	this->_countElemLock->Unlock();

}

DiskBuff* DiskBuffList::GetHead()
{
	DiskBuff *temp=NULL;
	this->_rwlock->RdLock();
	  	temp=this->_pHead;
    this->_rwlock->Unlock();
    return temp;
}



