/*
 * FSArea.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
#include "FSArea.h"
#include <sys/types.h>
#include <unistd.h>

FSArea::FSArea(const char* fileName)
{
	//this->_fileStreamId=open(fileName,O_RDWR|O_SYNC);
	_mutex = new CrossPthreadMutex();
}

FSArea::~FSArea()
{
	delete *_mutex;
	close(this->_fileStreamId);
}

void* FSArea::GetBlock(int BlockNum)
{
	_mutex.Lock();
	lseek(this->_fileStreamId,BlockNum*BLOCK_SIZE,SEEK_SET);
	void *buff = NULL;
	read(this->_fileStreamId,buff,BLOCK_SIZE);
	_mutex.Unlock();

	//pthread_mutex_unlock(&(this->_lock));
	return buff;
}

void FSArea::SetBlock(int BlockNum,void* value)
{
	//pthread_mutex_lock(&(this->_lock));
	lseek(this->_fileStreamId,BlockNum*BLOCK_SIZE,SEEK_SET);
	write(this->_fileStreamId,value,BLOCK_SIZE);
	//pthread_mutex_unlock(&(this->_lock));
}
