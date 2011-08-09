/*
 * CrossFile.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#include "CrossFile.h"
//#ifdef LINUX

CrossFile::CrossFile(const char *fileName)
{
	_fileStreamId = open(fileName,O_RDWR|O_SYNC);//func
}

CrossFile::~CrossFile()
{
	close(_fileStreamId);
}

void CrossFile::Lseek(int offset)
{
	lseek(_fileStreamId,offset,SEEK_SET);
}

BlockData CrossFile::Read(int size)
{
	BlockData temp = (char*)malloc(size * sizeof(char));//new

	if (temp == NULL) {//exception
		perror("malloc");
	}
	int ret = read(this->_fileStreamId,temp,size);
	if (ret == -1) {
		perror("read");
	}
	return (char*)temp;
}


void CrossFile::Write(BlockData value,int size)
{
	write(_fileStreamId,value,size);
}
//#endif
