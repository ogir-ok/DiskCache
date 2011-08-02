/*
 * DiskBuff.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#ifndef DISKBUFF_H_
#define DISKBUFF_H_

class DiskBuff
{
	public:
	int fsId;
	int fsBlockNum;
	void* pData;
	DiskBuff* pFreeNext;
	DiskBuff* pFreePrev;
	DiskBuff* pFullNext;
	DiskBuff* pFullPrev;
	DiskBuff();
	~DiskBuff();
};


#endif /* DISKBUFF_H_ */
