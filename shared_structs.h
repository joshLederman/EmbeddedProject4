#ifndef __SHARED_STRUCTS_H__
#define __SHARED_STRUCTS_H__

/** Implement your structs here */

/**
 * This structure holds the process structure information
 */
struct process_state {
			unsigned int *sp;
			unsigned int *sp_original; //Original stack pointer
			unsigned int size; //Size of stack as initialized
			struct lock_state *lock_pointer;
			struct cond_var *cond_pointer; //Condition it is waiting on
			struct process_state *nextProcess;
}; 

/**
 * This defines the lock structure
 */
typedef struct lock_state {
	unsigned int lock; //0 = unlocked, 1 = locked;
} lock_t;

/**
 * This defines the conditional variable structure
 */


typedef struct cond_var {
	unsigned int waiting; //0 - no process waiting, 1 - process is waiting
} cond_t;

#endif
