/*
 * FSDriver.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef FSDRIVER_H_
#define FSDRIVER_H_


#include "FSArea.h"
/**/

template<typename T>
class Singleton
{
private:
    T* get0() const;
    T* _data;
    bool isEmpty() const;
    void clear();
    void init();
    void reinit();
    void SingletonFill(Singleton<T>& current);

public:
	Singleton();

    T* operator->();
    const T* operator->() const;
    void operator=(T* t);
};



class FSDriver  //reload virtual class FSDriver
{
private:
	int _areaCount;
	FSArea* _areaList[];

public:
	FSDriver();
	~FSDriver();

	void* GetBlock(int fsId, int BlockNum);
	void SetBlock(int fsId, int BlockNum, void* value);
};

#endif /* FSDRIVER_H_ */
