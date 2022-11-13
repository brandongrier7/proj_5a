#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "locks.h"

#define MAX_STRING 255

typedef struct {
	char val[MAX_STRING];
	int pid;
} thread_data;

mutex_t mutex;

/*
threadproc: A process to run to test our locking meachinism
Parameters: arg: A pointer to a thread_data structure
Returns: NULL in all cases
*/
void* threadproc(void* arg){
	thread_data* data=(thread_data*) arg;
	char* str=data->val;
	mutex_lock(&mutex,data->pid);
	while (*str){
		printf("%c",*(str++));
		fflush(stdout);
		sleep(.1);
	}
	mutex_unlock(&mutex,data->pid);
	return NULL;
}


int main(int argc,char** argv){
	pthread_t thread_id;
	thread_data data1,data2;
	mutex_init(&mutex);
	strcpy(data1.val,"I am the child thread.\n");
	strcpy(data2.val,"I am the parent thread.\n");
	data1.pid=1;
	data2.pid=2;
	pthread_create(&thread_id,NULL,&threadproc,&data1);
	threadproc(&data2);
	pthread_join(thread_id,NULL);
	return 0;
}
