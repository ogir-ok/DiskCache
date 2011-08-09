/*
 * DiskBuffList.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#include"DiskBuffList.h"

DiskBuffList::DiskBuffList()
{
	_pHead = NULL;
	_pTail = NULL;
	_countElem = 0;
}

DiskBuffList::~DiskBuffList()
{
	delete _pHead;
	delete _pTail;
}

void DiskBuffList::AddToTail(DiskBuff* addBuff)
{
	DiskBuff* newElement = addBuff;
	newElement->pFreeNext = NULL;
	newElement->pFreePrev = _pTail;
	if (NULL != _pTail)
	{
		_pTail->pFreePrev = newElement;
	}
	_pTail = newElement;
	if (NULL == _pHead)
	{
		_pHead = newElement;
	}
	_countElem++;
}

void DiskBuffList::Delete(DiskBuff * currentElement)
{
	if (NULL != currentElement)
	{
		if (_pHead == currentElement)
		{
			_pHead = currentElement->pFreeNext;
			delete currentElement;
		}
		else
		if (_pTail == currentElement)
		{
			_pTail = currentElement->pFreePrev;
			delete currentElement;
		}
		else
		{
			currentElement->pFreeNext->pFreePrev = currentElement->pFreePrev;
			currentElement->pFreePrev->pFreeNext = currentElement->pFreeNext;
			_countElem--;
			delete currentElement;
		}
	}
}

DiskBuff* DiskBuffList::GetHead()
{
	DiskBuff * temp = NULL;
	temp = _pHead;
    return temp;
}



