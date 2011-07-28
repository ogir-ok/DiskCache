/*
 * DriverFS.h
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */


#ifndef DRIVERFS_H_
#define DRIVERFS_H_

#include "FSArea.h"
/**/

template<typename T>
class Singleton
{
private:
    T* get0() const;
    T* _data;

public:
	Singleton();

    T* operator->();
    const T* operator->() const;
    void operator=(T* t);

    bool isEmpty() const;
    void clear();
    void init();
    void reinit();
    void SingletonFill(Singleton<T>& current);

};

class FSDriver//virtual class
{
public:
	virtual void* GetBlock(int fsId, int BlockNum)=0;
	virtual void SetBlock(int fsId, int BlockNum, void* value)=0;
};

class FSDriver_imp: public FSDriver  //reload virtual class FSDriver
{
	int _areaCount;
	FSArea* _areaList[];
public:

	FSDriver_imp();
	~FSDriver_imp();

	void* GetBlock(int fsId, int BlockNum);
	void SetBlock(int fsId, int BlockNum, void* value);
};



#endif /* DRIVERFS_H_ */
