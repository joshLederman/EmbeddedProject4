#include "3140_concur.h"
#include <stdlib.h>
#include <fsl_device_registers.h>
#include "shared_structs.h"
#include "cond.h"

void c_init(lock_t* l, cond_t* c) {
	
}

void c_wait(lock_t* l, cond_t* c) {
	c->waiting=1;
	current_process->cond_pointer = c;
	process_blocked();
}


int c_waiting(lock_t* l, cond_t* c) {
	return c->waiting;
}

void c_signal(lock_t* l, cond_t* c) {
	//Loops through all processes and removes waiting on this condition
	//The current process cannot be waiting on the same condition it signals
	struct process_state *tmp;
	tmp=current_process;
	while(tmp != NULL && tmp->nextProcess != NULL)
		tmp=tmp->nextProcess;
		if (tmp->cond_pointer == c)
			tmp->cond_pointer = NULL;
}
