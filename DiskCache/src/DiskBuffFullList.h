/*
 * DiskBuffFullList.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#ifndef DISKBUFFFULLLIST_H_
#define DISKBUFFFULLLIST_H_


#include "DiskBuff.h"
#include <CrossPthreadMutex.h>
#include <CrossPthreadRWLock.h>
#include <FSDriver.h>
#include <stdlib.h>

class DiskBuffFullList
{
private:
	DiskBuff* _pHead;
	DiskBuff* _pTail;
	//CrossPthreadRWLock* _rwlock; 			//lock class
	//CrossPthreadMutex* 	_countElemLock;	//mutex for variable countelement
	int _countElem;
public:
	DiskBuffFullList();
	~DiskBuffFullList();
	void AddToTail(DiskBuff* addBuff);
	void Delete(DiskBuff * el);
	DiskBuff* Get(int fsId,int blockNum) ;

};



#endif /* DISKBUFFFULLLIST_H_ */
