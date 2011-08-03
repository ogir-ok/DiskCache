/*
 * FSDriver.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
#include "FSDriver.h"

FSDriver* FSDriver::_pInstance = NULL;

void FSDriver::Create(char* DiskConfigFile)
{
	_pInstance= new FSDriver(DiskConfigFile);
}

FSDriver* FSDriver::operator->()
{
	return _pInstance;
}

FSDriver::FSDriver(char* DiskConfigFile)
{
	FILE* configFile = fopen(DiskConfigFile,"r");
	fscanf(configFile,"%d",&(this->_areaCount));
	for (int i=0;i<this->_areaCount;i++)
	{
		char* diskPath=NULL;
		fscanf(configFile,"%s",diskPath);
		const FSArea temp(diskPath);
		this->_areaList.push_back(temp);
	}
}
FSDriver::~FSDriver()
{
	for (int i =0;i<this->_areaCount;i++)
	{
		delete &(this->_areaList[i]);
	}
}
void* FSDriver::GetBlock(int fsId, int BlockNum)
{
	return this->_areaList[fsId].GetBlock(BlockNum);
}
void FSDriver::SetBlock(int fsId, int BlockNum, void* value)
{
	this->_areaList[fsId].SetBlock(BlockNum,value);
}

