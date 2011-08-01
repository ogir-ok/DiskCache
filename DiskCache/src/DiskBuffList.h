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

class DiskBuffList
{
private:
	DiskBuff* pHead;
	DiskBuff* pTail;
	CrossPthreadRWLock* rw_lock; 			//lock class
	CrossPthreadMutex* countElem_lock;	//mutex for variable countelement
public:
	DiskBuffList();
	~DiskBuffList();
	void AddToTail(int newFsId, int newFsBlockNum);
	void Delete(DiskBuff * el);
	DiskBuff* GetHead() ;

};



#endif /* DISKBUFFLIST_H_ */
