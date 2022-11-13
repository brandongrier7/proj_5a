#include "locks.h"
/*
mutex_init: sets up a mutex to be used for locking
Paramters: mutex: A pointer to a mutex structure
Returns: none
*/
void mutex_init(mutex_t* mutex){
}

/*
mutex_lock: attempts to lock the mutex and blocks until the mutex can be locked
Paramters:	mutex: A mutex structure specifying the particular lock
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the mutex
Returns: none
*/
void mutex_lock(mutex_t* mutex,int pid){
}
/*
mutex_unlock: frees the mutex allowing other processes to lock it
Paramters: 	mutex: A mutex structure specifying the particular lock
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the mutex
*/
void mutex_unlock(mutex_t* mutex,int pid){
}

/*
semaphore_init: sets up a new semaphore
Paramters: 	semaphore: A pointer to a semaphore structure specifying the particular semaphore
			initial_value: The start value of the semaphore (1 for binary, 0 for event, >1 for counting)
Returns: 	none
*/
void semaphore_init(semaphore_t* semaphore,int initial_value){
}

/*
semaphore_wait: attempts to down the semaphore and blocks until the semaphore can be downed
Paramters: 	semaphore: A pointer to a semaphore structure specifying the particular semaphore
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the semaphore
Returns: none
*/
void semaphore_wait(semaphore_t* semaphore,int pid){
}

/*
semaphore_signal: ups the semaphore allowing other processes waiting to down the semaphore to continue
Paramters: 	semaphore: A pointer to a semaphore structure specifying the particular semaphore
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the mutex
*/
void semaphore_signal(semaphore_t* semaphore,int pid){
}
