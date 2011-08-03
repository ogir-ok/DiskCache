/*
 * FSDriver.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */



#ifndef FSDRIVER_H_
#define FSDRIVER_H_


#define DEFAULT_DISK_CONF_FILE "/home/user/workspace/cpp/DiskCache/.disk.conf"

#include "FSArea.h"
#include <iostream>
#include <vector>
using namespace std;

class FSDriver  //reload virtual class FSDriver
{
private:
	int _areaCount;
	vector<FSArea> _areaList;
	static FSDriver* _pInstance;
	FSDriver (char* DiskConfigFile);
public:
	FSDriver();
	static void Create(char* DiskConfigFile);
	static FSDriver* Instance();
//	FSDriver* operator->();
	~FSDriver();
	void* GetBlock(int fsId, int BlockNum);
	void SetBlock(int fsId, int BlockNum, void* value);
};

#endif /* FSDRIVER_H_ */
