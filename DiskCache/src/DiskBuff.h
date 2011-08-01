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
	int fsId;
	int fsBlockNum;
	void* pData;
	DiskBuff* FreeNext;
	DiskBuff* FreePrev;
	DiskBuff* FullNext;
	DiskBuff* FullPrev;
};


#endif /* DISKBUFF_H_ */
