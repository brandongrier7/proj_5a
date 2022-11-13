#define NPROC 20

typedef struct {
	//put what you need in here
	int unknown;
}mutex_t;

typedef struct{
	//put what you need in here
	int unknown;
}semaphore_t;

void mutex_init(mutex_t* mutex);
void mutex_lock(mutex_t* mutex,int pid);
void mutex_unlock(mutex_t* mutex,int pid);

void semaphore_init(semaphore_t* semaphore,int initial_value);
void semaphore_wait(semaphore_t* semaphore,int pid);
void semaphore_signal(semaphore_t* semaphore,int pid);
