#include "3140_concur.h"
#include <stdlib.h>
#include <fsl_device_registers.h>
#include "shared_structs.h"

//Tasks: write the three functions below, and update process_select with new functionality
//relating to locks

void l_init(lock_t* l) {
	//Initialize a lock to be open
	l->lock=0;
}

void l_lock(lock_t* l) {
	PIT->CHANNEL[0].TCTRL = 0x1; // disable interrupts
	
	if (l->lock == 0)
		//Acquire the lock if free
		l->lock = 1;
	else{
		//Block the process on the lock if not
		current_process->lock_pointer = l;
		process_blocked();
	}
	PIT->CHANNEL[0].TCTRL = 0x3; // enable interrupts
}

void l_unlock(lock_t* l) {
	//Free the lock
	l->lock = 0;
	}
