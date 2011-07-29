/*
 * CrossFile.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#ifdef LINUX
#include "CrossFile.h"
CrossFile::CrossFile(char *fileName)
{
	this->_fileStreamId=open(fileName,O_RDWR|O_SYNC);
}
CrossFile::~CrossFile()
{
	close(this->_fileStreamId);
}
void CrossFile::Lseek(int offset)
{
	lseek(this->_fileStreamId,offset,SEEK_SET);
}
void* CrossFile::Read(int size)
{
	void* temp;
	read(this->_fileStreamId,temp,size);
	return temp;
}
void CrossFile::Write(void* value,int size)
{
	write(this->_fileStreamId,value,size);
}
#endif
