/*
 * FSArea.h
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */

#ifndef FSAREA_H_
#define FSAREA_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define DISKS_CONFIG_FILE "./.disks.conf"
#define BLOCK_SIZE 4

class FSArea
{
public:
/*
 * 	virtual FSArea();
 	virtual ~FSArea();
*/
	virtual void* GetBlock(int BlockNum)=0;
	virtual void SetBlock(int BlockNum,void* value)=0;
};

class FSArea_imp: public FSArea
{
private:
	pthread_mutex_t _lock;
	int _fileStreamId;  //Id of filestream
public:
	FSArea_imp(const char* fileName);
	~FSArea_imp();
	void* GetBlock(int BlockNum);
	void SetBlock(int BlockNum,void* value);
};
#endif /* FSAREA_H_ */
