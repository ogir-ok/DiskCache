/*
 * FSDriver.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
# include "FSDriver.h"

template<typename T>
T* Singleton<T>::get0() const
{
    const_cast<Singleton<T>*>(this)->init();
    return this->data;
}

template<typename T>
Singleton<T>::Singleton()
{
	clear();
}

template<typename T>
T* Singleton<T>::operator->()
{
	return get0();
}

template<typename T>
const T* Singleton<T>::operator->() const
{
	return get0();
}

template<typename T>
void Singleton<T>::operator=(T* t)
{
	this->data = t;
}

template<typename T>
bool Singleton<T>::isEmpty() const
{
	return this->data == 0;
}

template<typename T>
void Singleton<T>::clear()
{
	this->data = 0;
}

template<typename T>
void Singleton<T>::init()
{
	if (this->isEmpty())
		this->reinit();
}

template<typename T>
void Singleton<T>::reinit()
{
	this->SingletonFill(*this);
}

template<typename T>
void Singleton<T>::SingletonFill(Singleton<T>& current)
{
	//
}

template<>
void Singleton<FSDriver>::SingletonFill(Singleton<FSDriver>& current)
{
	static FSDriver_imp temp;
	current = &temp;
}

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


