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
FSDriver* FSDriver::Instance()
{
	if(NULL == _pInstance)
	{
		Create(DEFAULT_DISK_CONF_FILE);
	}
	return _pInstance;
}

FSDriver::FSDriver()
{
	this->_areaCount = 0;

}

FSDriver::FSDriver(char* DiskConfigFile)
{
	FILE* configFile = fopen(DiskConfigFile, "r");
	fscanf(configFile, "%d\n", &(this->_areaCount));
	for (int i = 0; i < this->_areaCount; i++)
	{
		char diskPath[1024];
		fscanf(configFile, "%s\n", &diskPath);
		printf("%s\n", diskPath);
		FSArea * area = new FSArea(diskPath);
		this->_areaList.push_back(area);
	}
}

FSDriver::~FSDriver()
{
	for (int i = 0; i < this->_areaCount; i++)
	{
		delete this->_areaList[i];
	}
}

char* FSDriver::GetBlock(int fsId, int BlockNum)
{
	return this->_areaList[fsId]->GetBlock(BlockNum);
}

void FSDriver::SetBlock(int fsId, int BlockNum, void* value)
{
	this->_areaList[fsId]->SetBlock(BlockNum,value);
}

