/*
 * DriverFS.h
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */

#ifndef DRIVERFS_H_
#define DRIVERFS_H_

#include "FSArea.h"

class FSDriver//virtual class
{
public:
	virtual void* GetBlock(int fsId, int fsBlockNum)=0;
	virtual void SetBlock(int fsId, int fsBlockNum, void* value)=0;
};

class FSDriver_imp: public FSDriver  //reload virtual class FSDriver
{
	int _areaCount;
	FSArea* _areaList[];
public:

	FSDriver_imp();
	~FSDriver_imp();

	void* GetBlock(int fsId, int fsBlockNum);
	void SetBlock(int fsId, int fsBlockNum, void* value);
};
#endif /* DRIVERFS_H_ */
