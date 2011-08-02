/*
 * DiskBuffFullList.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#include "DiskBuffFullList.h"
DiskBuffFullList::DiskBuffFullList()
{
	this->_pHead=NULL;
	this->_pTail=NULL;
	this->_rwlock = new CrossPthreadRWLock();
	this->_countElemLock= new CrossPthreadMutex();
	this->_countElem=0;

}

DiskBuffFullList::~DiskBuffFullList()
{
	delete this->_pHead;
	delete this->_pTail;
	delete this->_countElemLock;
	delete this->_rwlock;
}

void DiskBuffFullList::AddToTail(DiskBuff* addBuff)
{
	this->_rwlock->WrLock();
	DiskBuff* newElement = addBuff;
	newElement->pFullNext=NULL;
	newElement->pFullPrev = this->_pTail;
	if (NULL != this->_pTail)
	{
		_pTail->pFullPrev=newElement;
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

void DiskBuffFullList::Delete(DiskBuff * currentElement)
{
	this->_rwlock->WrLock();
	if (NULL!=currentElement)
	{
		if (this->_pHead == currentElement)
		{
			this->_pHead = currentElement->pFullNext;
			delete currentElement;
		}
		else
		if (this->_pTail == currentElement)
		{
			this->_pTail = currentElement->pFullPrev;
			delete currentElement;
		}
		else
		{
			currentElement->pFullNext->pFullPrev=currentElement->pFullPrev;
			currentElement->pFullPrev->pFullNext=currentElement->pFullNext;
			this->_countElemLock->Lock();
				_countElem--;
			this->_countElemLock->Unlock();
			delete currentElement;
		}
	}
	this->_countElemLock->Unlock();

}

DiskBuff* DiskBuffFullList::Get(int fsId,int blockNum)
{
	this->_rwlock->RdLock();
	DiskBuff *temp=this->_pHead;
	  	temp=this->_pHead;
	    while (temp!=NULL)
	    {
	    	if ((temp->fsId==fsId)&&(temp->fsBlockNum==blockNum))
	    	{
	    		break;
	    	}
	    	temp = temp->pFullNext;
	    }
    this->_rwlock->Unlock();
    return temp;
}




