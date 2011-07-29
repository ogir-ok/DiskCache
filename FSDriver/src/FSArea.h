/*
 * FSArea.h
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */

#ifndef FSAREA_H_
#define FSAREA_H_

#ifndef LINUX
#define LINUX
#endif

#include <stdlib.h>
#include <stdio.h>

#include <CrossPthreadMutex.h>

#define DISKS_CONFIG_FILE "./.disks.conf"
#define BLOCK_SIZE 4


class FSArea
{
private:
	CrossPthreadMutex _mutex;
	int _fileStreamId;  //Id of filestream
public:
	FSArea(const char* fileName);
	~FSArea();
	void* GetBlock(int BlockNum);
	void SetBlock(int BlockNum,void* value);
};

#endif /* FSAREA_H_ */
