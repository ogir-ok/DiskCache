/*
 * CrossFile.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#include "CrossFile.h"
//#ifdef LINUX
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
char* CrossFile::Read(int size)
{
	char* temp = (char*)malloc(size * sizeof(char));
	if (temp == NULL) {
		perror("malloc");
	}
	int ret = read(this->_fileStreamId,temp,size);
	if (ret == -1) {
		perror("read");
	}
	return (char*)temp;
}
void CrossFile::Write(void* value,int size)
{
	write(this->_fileStreamId,value,size);
}
//#endif
