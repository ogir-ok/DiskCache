/*
 * FSDriver.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
# include "FSDriver.h"






FSDriver_imp::FSDriver_imp()
{
	FILE* configFile = fopen(DISKS_CONFIG_FILE,"r");
	int disksCount = 0;
	fscanf(configFile,"%d",&disksCount);
//	this->_areaList = FSArea[disksCount];
	for (int i=0;i<disksCount;i++)
	{
		char* diskPath=NULL;
		fscanf(configFile,"%s",diskPath);
//		this->_areaList[i] = new FSArea(diskPath);
	}
}

FSDriver_imp::~FSDriver_imp()
{
}

void* FSDriver_imp::GetBlock(int fsId, int BlockNum)
{
	return this->_areaList[fsId]->GetBlock(BlockNum);
}

void FSDriver_imp::SetBlock(int fsId, int BlockNum,void* value)
{
	return this->_areaList[fsId]->SetBlock(BlockNum,value);
}


