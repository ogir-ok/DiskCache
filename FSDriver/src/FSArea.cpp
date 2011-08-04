/*
 * FSArea.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
#include "FSArea.h"
#include <sys/types.h>
#include <unistd.h>

FSArea::FSArea(char* fileName)
{
	this-> _mutex = new CrossPthreadMutex();
	this->_fileStreamId = new CrossFile(fileName);
}

FSArea::~FSArea()
{
	delete (this->_mutex);
	delete (this->_fileStreamId);
}

void* FSArea::GetBlock(int BlockNum)
{


	this->_mutex->Lock();
	this->_fileStreamId->Lseek((BlockNum-1)*BLOCK_SIZE);
	void *buff = NULL;
	this->_fileStreamId->Read(BLOCK_SIZE);
	this->_mutex->Unlock();
	return buff;
}

void FSArea::SetBlock(int BlockNum,void* value)
{

	this->_mutex->Lock();
	this->_fileStreamId->Lseek((BlockNum-1)*BLOCK_SIZE);
	this->_fileStreamId->Write(value,BLOCK_SIZE);
	this->_mutex->Unlock();
}
//
FSArea::FSArea()
{
	this->_mutex = new CrossPthreadMutex();
	this->_fileStreamId = new CrossFile(NULL);
}
