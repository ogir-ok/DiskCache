/*
 * FSDriver.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef FSDRIVER_H_
#define FSDRIVER_H_


#include "FSArea.h"
#include <iostream>
#include <vector>
using namespace std;
class FSDriver  //reload virtual class FSDriver
{
private:
	int _areaCount;
	vector<FSArea> _areaList;

public:
	FSDriver();
	~FSDriver();
	void* GetBlock(int fsId, int BlockNum);
	void SetBlock(int fsId, int BlockNum, void* value);
};

template<typename T>
class Singleton
{
private:
    T* get0() const;
    static T* _data;
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

#endif /* FSDRIVER_H_ */
