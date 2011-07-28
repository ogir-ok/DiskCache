/*
 * FSArea_imp.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
#include "FSArea.h"
#include <sys/types.h>
#include <unistd.h>

FSArea_imp::FSArea_imp(const char* fileName)
{
	this->_fileStreamId=open(fileName,O_RDWR|O_SYNC);
	pthread_mutex_init(&(this->_lock),NULL);
}

FSArea_imp::~FSArea_imp()
{
	pthread_mutex_destroy(&(this->_lock));
	close(this->_fileStreamId);
}

void* FSArea_imp::GetBlock(int BlockNum)
{
	pthread_mutex_lock(&(this->_lock));
	lseek(this->_fileStreamId,BlockNum*BLOCK_SIZE,SEEK_SET);
	void *buff = NULL;
	read(this->_fileStreamId,buff,BLOCK_SIZE);
	pthread_mutex_unlock(&(this->_lock));
	return buff;
}

void FSArea_imp::SetBlock(int BlockNum,void* value)
{
	pthread_mutex_lock(&(this->_lock));
	lseek(this->_fileStreamId,BlockNum*BLOCK_SIZE,SEEK_SET);
	write(this->_fileStreamId,value,BLOCK_SIZE);
	pthread_mutex_unlock(&(this->_lock));
}
