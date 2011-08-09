/*
 * FSArea.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
#include <cstdio>
#include "FSArea.h"
#include <sys/types.h>
#include <unistd.h>

FSArea::FSArea(const char* fileName)
{
	_fileStreamId = new CrossFile(fileName);
}

FSArea::~FSArea()
{
	delete _fileStreamId;
}

BlockData FSArea::GetBlock(int BlockNum)
{
	this->_fileStreamId->Lseek((BlockNum-1)*BLOCK_SIZE);
	BlockData buff;
	buff = this->_fileStreamId->Read(BLOCK_SIZE);
	printf("%s\n", buff);
	return buff;
}

void FSArea::SetBlock(int BlockNum,BlockData value)
{
	_fileStreamId->Lseek((BlockNum-1)*BLOCK_SIZE);
	_fileStreamId->Write(value,BLOCK_SIZE);
}

FSArea::FSArea()
{
	_fileStreamId = new CrossFile(NULL);
}
