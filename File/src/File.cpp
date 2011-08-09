/*
 * File.cpp
 *
 *  Created on: Aug 9, 2011
 *      Author: user
 */

#include "File.h"
//#ifdef LINUX

File::File(const char *fileName)
{
	_fileStreamId = open(fileName,O_RDWR|O_SYNC);//func
}

File::~File()
{
	close(_fileStreamId);
}

int File::Lseek(int offset)
{
	int error = lseek(_fileStreamId,offset,SEEK_SET);
	return error;
}

int File::Read(BlockData* container, int size)
{
	int error = read(_fileStreamId,*(container),size);
	return error;
}
int File::Write(BlockData value,int size)
{
	int error = write(_fileStreamId,value,size);
	return error;
}
