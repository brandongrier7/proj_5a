#define NPROC 20
#include <pthread.h>

struct tNode {
    int thread_id;
	int thread_priority;
    struct tNode *next;
}; typedef struct tNode tNode;

typedef struct {
	//put what you need in here
	long lock;
	int sleep;
	pthread_t id;
}mutex_t;

typedef struct{
	//put what you need in here
	int count;
	tNode *q;
}semaphore_t;

void mutex_init(mutex_t* mutex);
void mutex_lock(mutex_t* mutex,int pid);
void mutex_unlock(mutex_t* mutex,int pid);

void semaphore_init(semaphore_t* semaphore,int initial_value);
void semaphore_wait(semaphore_t* semaphore,int pid);
void semaphore_signal(semaphore_t* semaphore,int pid);
