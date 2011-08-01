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
	this->FreeNext = NULL;
	this->FreePrev = NULL;
	this->FullNext = NULL;
	this->FullPrev = NULL;
}
DiskBuff::~DiskBuff()
{
	delete this->pData;
}



