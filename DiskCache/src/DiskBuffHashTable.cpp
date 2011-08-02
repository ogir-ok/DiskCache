/*
 * DiskBuffHashTable.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */


#include "DiskBuffHashTable.h"

DiskBuffHashTable::DiskBuffHashTable()
{
	this->_hash.

}
DiskBuffHashTable::~DiskBuffHashTable();
void DiskBuffHashTable:: Add(DiskBuff* buff);
void DiskBuffHashTable:: Del(DiskBuff* buff);
DiskBuff* DiskBuffHashTable::Get(int fsId,int blockNum);
