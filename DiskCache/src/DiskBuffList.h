/*
 * DiskBuffList.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#ifndef DISKBUFFLIST_H_
#define DISKBUFFLIST_H_

#include "DiskBuff.h"
#include <Mutex.h>
#include <RWLock.h>
#include <FSDriver.h>
#include <stdlib.h>

class DiskBuffList
{
private:
	DiskBuff* _pHead;
	DiskBuff* _pTail;
	int _countElem;
public:
	DiskBuffList();
	~DiskBuffList();
	void AddToTail(DiskBuff* addBuff);
	void Delete(DiskBuff * el);
	DiskBuff* GetHead() ;

};



#endif /* DISKBUFFLIST_H_ */
