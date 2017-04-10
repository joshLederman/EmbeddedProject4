#include "3140_concur.h"
#include <stdlib.h>
#include <fsl_device_registers.h>
#include "shared_structs.h"

//Tasks: write the three functions below, and update process_select with new functionality
//relating to locks

void l_init(lock_t* l) {
	//Allocates space for the struct representing the lock
}

void l_lock(lock_t* l) {
	if (l->lock == 0)
		l->lock = 1;
	else{
		current_process->lock_pointer = l;
		process_blocked();
	}
	//May need to start by turning off interrupts to ensure atomicity
	//If the lock is free, take the lock
	//If the lock is not free, call process_blocked 
	//process_blocked will call process_select with a non-zero argument
	//A hint in the handout indicates that we should save something to current_state before calling process_blocked
	//I think there should be something in the struct like blocked_lock which is null if not blocked
	//	and a pointer to the appropriate lock if it is blocked.
}

void l_unlock(lock_t* l) {
	//It doesn't specify in detail how this should work
	//In particular, if there is a process blocked on this lock, should
	//we run that process first, or run the next process in the queue until we get to that process?
	//I think the former would work more efficiently, but the latter is simpler and less error-prone
	//In the latter situation, we would keep looping through the queue and for each process check;
	//if its blocked it will only run if the lock is free
	}