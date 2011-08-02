/*
 * DiskBuffList.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#ifndef DISKBUFFLIST_H_
#define DISKBUFFLIST_H_

#include "DiskBuff.h"
#include <CrossPthreadMutex.h>
#include <CrossPthreadRWLock.h>
#include <FSDriver.h>
#include <stdlib.h>

class DiskBuffList
{
private:
	DiskBuff* _pHead;
	DiskBuff* _pTail;
	CrossPthreadRWLock* _rwlock; 			//lock class
	CrossPthreadMutex* 	_countElemLock;	//mutex for variable countelement
	int _countElem;
public:
	DiskBuffList();
	~DiskBuffList();
	void AddToTail(DiskBuff* addBuff);
	void Delete(DiskBuff * el);
	DiskBuff* GetHead() ;

};



#endif /* DISKBUFFLIST_H_ */
