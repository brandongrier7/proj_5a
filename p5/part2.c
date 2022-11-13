#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "locks.h"

#define THREAD_COUNT 20  //This must be less than or equal to the max number of processes that can be protected by a lock.
#define CONCURRENT_THREADS 5

semaphore_t sem;

/*
threadproc: A process to run to test our semaphores.  
Parameters: arg: A pointer to a thread_data structure
Returns: NULL in all cases
Note that the global semaphore 'sem' is used to limit how many concurrent copies of this may run.
*/
void* threadproc(void* arg){
	int pid=*((int*)arg);
	semaphore_wait(&sem,pid);
	printf("Thread number %d is starting\n",pid);
	sleep(3);
	printf("Thread number %d is exiting\n",pid);
	semaphore_signal(&sem,pid);
}

int main(int argc,char** argv){
	semaphore_init(&sem,CONCURRENT_THREADS);
	pthread_t threads[THREAD_COUNT];
	for (int i=0;i<THREAD_COUNT;i++)
		pthread_create(&threads[i],NULL,&threadproc,&i);
	for (int i=0;i<THREAD_COUNT;i++)
		pthread_join(threads[i],NULL);
	return 0;
}
