#include "3140_concur.h"
#include <stdlib.h>
#include <fsl_device_registers.h>
#include "shared_structs.h"
#include "cond.h"
//#include "lock.c"

void c_init(lock_t* l, cond_t* c) {
	//Initialize the condition
	c->waiting=0;
}

void c_wait(lock_t* l, cond_t* c) {
	PIT->CHANNEL[0].TCTRL = 0x1;
	
	c->waiting=1;
	current_process->cond_pointer = c;
	process_blocked();
	
	PIT->CHANNEL[0].TCTRL = 0x3;
}


int c_waiting(lock_t* l, cond_t* c) {
	return c->waiting;
}

void c_signal(lock_t* l, cond_t* c) {
	
	PIT->CHANNEL[0].TCTRL = 0x1;
	
	//Loops through all processes and removes waiting on this condition
	//The current process cannot be waiting on the same condition it signals
	struct process_state *tmp;
	tmp=current_process;
	while(tmp != NULL && tmp->nextProcess != NULL)
		tmp=tmp->nextProcess;
		if (tmp->cond_pointer == c)
			tmp->cond_pointer = NULL;
	//Releases the lock
	l->lock=0;
		
	PIT->CHANNEL[0].TCTRL = 0x3;
}
