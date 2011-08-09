//============================================================================
// Name        : TestDiskCache.cpp
// Author      : Garagatyy Igor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define DISK_CONF_FILE "/home/user/workspace/cpp/DiskCache/.disk.conf"
#define READERS_COUNT 1000
#define WRITERS_COUNT 1000
#define FS_COUNT 6
#define MAX_BLOCK 100
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <DiskCache.h>
#include <ctime>
DiskCache* cache;
pthread_t* readers;
pthread_t* writers;
pthread_mutex_t rand_mutex;
pthread_mutex_t console_mutex;

void* f_readers(void* arg)
{

	pthread_mutex_lock(&rand_mutex);
	srand(time(NULL));
	int dr = rand() % MAX_BLOCK;
	int fr = rand() % FS_COUNT;
	pthread_mutex_unlock(&rand_mutex);
	char* ret = cache->Read(fr, dr * BLOCK_SIZE, BLOCK_SIZE);
	pthread_mutex_lock(&console_mutex);
	printf("readed:%s\n",ret);
	pthread_mutex_unlock(&console_mutex);

	return (void*)0;
}
void* f_writers(void* arg)
{
	pthread_mutex_lock(&rand_mutex);
	srand(time(NULL));
	int dr = rand() % MAX_BLOCK;
	int fr = rand() % FS_COUNT;
	pthread_mutex_unlock(&rand_mutex);
	char *a=(char*)malloc(BLOCK_SIZE*sizeof(char));
	cache->Write(fr, dr * BLOCK_SIZE, BLOCK_SIZE,(char*)a);
	free(a);
	pthread_mutex_lock(&console_mutex);
	printf("writed\n");
	pthread_mutex_unlock(&console_mutex);

	return (void*)0;
}

int main()
{
	cache = new DiskCache((char*)DISK_CONF_FILE);
	readers = new pthread_t[READERS_COUNT];
	writers = new pthread_t[WRITERS_COUNT];
	pthread_mutex_init(&rand_mutex,NULL);
	pthread_mutex_init(&console_mutex,NULL);

	for (int i=0;i<READERS_COUNT;i++)
 	{
 		pthread_create(&readers[i],NULL,f_readers,NULL);
 		printf(" reader thread created\n");
 	}

	for (int i=0;i<WRITERS_COUNT;i++)
 	{
 		pthread_create(&writers[i],NULL,f_writers,NULL);
 		printf("writer thread created\n");
 	}


 	for (int i=0;i<READERS_COUNT;i++)
	{
		void* tr_ret=NULL;
		pthread_join(readers[i],&tr_ret);
	}

	for (int i=0;i<WRITERS_COUNT;i++)
	{
		void* tr_ret=NULL;
		pthread_join(writers[i],&tr_ret);
	}

 	delete[] writers;
 	delete[] readers;
 	printf("exit\n");
 	pthread_mutex_destroy(&rand_mutex);
 	pthread_mutex_destroy(&console_mutex);
	return 0;
}
