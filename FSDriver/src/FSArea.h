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
#include <File.h>

#define DISKS_CONFIG_FILE "./.disks.conf"
#define BLOCK_SIZE 4


class FSArea
{
private:
	File* _file;
public:
	FSArea(const char* fileName);
	FSArea()  ;
	~FSArea();
	BlockData GetBlock(int BlockNum);
	void SetBlock(int BlockNum,BlockData value);
};

#endif /* FSAREA_H_ */
