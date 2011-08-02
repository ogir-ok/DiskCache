/*
 * DiskBuff.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
# define DISK_BLOCK_CHANGED 1
# define DISK_BLOCK_NOT_CHANGED 0
#ifndef DISKBUFF_H_
#define DISKBUFF_H_

class DiskBuff
{
	public:
	int fsId;
	int fsBlockNum;
	void* pData;
	int state;
	DiskBuff* pFreeNext;
	DiskBuff* pFreePrev;
	DiskBuff* pFullNext;
	DiskBuff* pFullPrev;
	DiskBuff();
	~DiskBuff();
};


#endif /* DISKBUFF_H_ */
