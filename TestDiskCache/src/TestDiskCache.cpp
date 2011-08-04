//============================================================================
// Name        : TestDiskCache.cpp
// Author      : Garagatyy Igor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define DISK_CONF_FILE "/home/user/workspace/cpp/DiskCache/.disk.conf"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <DiskCache.h>

DiskCache* cache;
pthread_t* readers;
pthread_t* writers;
/*void* f_readers(void* arg)
{

}
int main()
{
	readers = new pthread_t[10];
	writers = new pthread_t[10];
	for (int i=0;i< 10;i++)
	{
		pthread_create(&readers[i],NULL,f_readers,NULL);
	}
	cache = new DiskCache((char*)DISK_CONF_FILE);
	return 0;
	delete[] readers;
	delete[] writers;
}*/
int main()
{
 	cache = new DiskCache((char*)DISK_CONF_FILE);
     printf("%d",cache->read(1,1,1));
	printf("1111");
	return 0;
}
