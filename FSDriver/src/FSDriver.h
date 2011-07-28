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
public:
	Singleton()                                { clear(); }

    T* operator->()                     { return get0(); }
    const T* operator->() const         { return get0(); }
    void operator=(T* t)                { data = t; }

    bool isEmpty() const                { return data == 0; }
    void clear()                        { data = 0; }
    void init()                         { if (isEmpty()) reinit(); }
    void reinit()                       { SingletonFill(*this); }
    void SingletonFill(Singleton<T>& current)
    {
    	  //
    }
private:
    T* get0() const
    {
        const_cast<Singleton*>(this)->init();
        return data;
    }
    T* data;
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

template<>
void Singleton<FSDriver>::SingletonFill(Singleton<FSDriver>& current)
{
	static FSDriver_imp temp;
	current = &temp;
}

#endif /* DRIVERFS_H_ */
