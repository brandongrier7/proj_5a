#include "locks.h"
tNode *running;
tNode *ready;
/*
mutex_init: sets up a mutex to be used for locking
Paramters: mutex: A pointer to a mutex structure
Returns: none
*/
void mutex_init(mutex_t* mutex){
	mutex->sleep = 1;
	mutex->lock = 0;
	mutex->id = 0;
}

/*
mutex_lock: attempts to lock the mutex and blocks until the mutex can be locked
Paramters:	mutex: A mutex structure specifying the particular lock
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the mutex
Returns: none
*/
void mutex_lock(mutex_t* mutex,int pid){
	mutex->id=pid;
	if(mutex->id != pthread_self())
	{
		while(mutex->lock == 1)
		{
			usleep(mutex->sleep);
			mutex->sleep *= 2;
		}
		if(mutex->lock == 0)
		{
			mutex->id = pthread_self();
		}
	}
}
/*
mutex_unlock: frees the mutex allowing other processes to lock it
Paramters: 	mutex: A mutex structure specifying the particular lock
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the mutex
*/
void mutex_unlock(mutex_t* mutex,int pid){
	mutex->sleep = 1;
	mutex->lock = 0;
	mutex->id = 0;
}

/*
semaphore_init: sets up a new semaphore
Paramters: 	semaphore: A pointer to a semaphore structure specifying the particular semaphore
			initial_value: The start value of the semaphore (1 for binary, 0 for event, >1 for counting)
Returns: 	none
*/
void semaphore_init(semaphore_t* semaphore,int initial_value){
	semaphore = malloc(sizeof(semaphore_t));
	semaphore->count=initial_value;
	semaphore->q=NULL;
}

/*
semaphore_wait: attempts to down the semaphore and blocks until the semaphore can be downed
Paramters: 	semaphore: A pointer to a semaphore structure specifying the particular semaphore
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the semaphore
Returns: none
*/
void semaphore_wait(semaphore_t* semaphore,int pid){
	while(semaphore->count<1){
		tNode *past, *pres;
		past=running;
		running=pres;
		ready=ready->next;
		tNode *temp = semaphore->q;
		if (temp == NULL) {
			semaphore->q = past;
		} 
		else {
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = past;
		}
		pres->next = NULL;
	}
	semaphore->count--;
	}

/*
semaphore_signal: ups the semaphore allowing other processes waiting to down the semaphore to continue
Paramters: 	semaphore: A pointer to a semaphore structure specifying the particular semaphore
			pid: A unique integer identifier for the process.  Can be anything as long as it is unique amoung the processes
				Using the mutex
*/
void semaphore_signal(semaphore_t* semaphore,int pid){
	semaphore->count++;
	if (semaphore->q != NULL) {
	  // Dequeues a thread from the waiting queue, and adds it to the ready queue
	  tNode *temp = ready;
	  tNode *temp2 = semaphore->q;
	  semaphore->q = semaphore->q->next; // Removes thread from semaphore queue
	  temp2->next = NULL;
	  if (temp == NULL) {
		  ready = temp2;
	  } else {
		  while (temp->next != NULL) {
			  temp = temp->next;
		  }
		  temp->next = temp2; // add thread to ready queue
	  }
  }
}
