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

typedef char*  BlockData;

class CrossFile
{
private:
	int _fileStreamId;
public:
	CrossFile(const char *fileName);
	~CrossFile();
	void Lseek(int pos);
	BlockData Read(int size);
	void Write(BlockData value,int size);
};
//#endif

#endif /* CROSSFILE_H_ */
