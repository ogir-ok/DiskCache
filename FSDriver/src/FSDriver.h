/*
 * FSDriver.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef FSDRIVER_H_
#define FSDRIVER_H_


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
	static FSDriver* Instance();
protected:
	FSDriver(char* DiskConfigFile);
public:
	static void Create(char* DiskConfigFile);
	FSDriver* operator->();
	~FSDriver();
	void* GetBlock(int fsId, int BlockNum);
	void SetBlock(int fsId, int BlockNum, void* value);
};

#endif /* FSDRIVER_H_ */
