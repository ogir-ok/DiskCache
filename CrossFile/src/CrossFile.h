/*
 * CrossFile.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#ifndef CROSSFILE_H_
#define CROSSFILE_H_
//#ifdef LINUX

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


class CrossFile
{
private:
	int _fileStreamId;
public:
	CrossFile(char *fileName);
	~CrossFile();
	void Lseek(int pos);
	char* Read(int size);
	void Write(void* value,int size);
};
//#endif

#endif /* CROSSFILE_H_ */
