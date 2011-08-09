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
	_file = new File(fileName);
}

FSArea::~FSArea()
{
	delete _file;
}

BlockData FSArea::GetBlock(int BlockNum)
{
	_file->Lseek((BlockNum-1)*BLOCK_SIZE);
	BlockData buff;
	buff = _file->Read(BLOCK_SIZE);
	printf("%s\n", buff);
	return buff;
}

void FSArea::SetBlock(int BlockNum,BlockData value)
{
	_file->Lseek((BlockNum-1)*BLOCK_SIZE);
	_file->Write(value,BLOCK_SIZE);
}

FSArea::FSArea()
{
	_file = new File(NULL);
}
