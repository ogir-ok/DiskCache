/*
 * DiskBuff.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#include <stdlib.h>
#include "DiskBuff.h"

DiskBuff::DiskBuff()
{
	this->pFreeNext = NULL;
	this->pFreePrev = NULL;
	this->pFullNext = NULL;
	this->pFullPrev = NULL;
}
DiskBuff::~DiskBuff()
{
	delete this->pData;
}



