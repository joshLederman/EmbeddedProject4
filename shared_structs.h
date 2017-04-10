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

} cond_t;

#endif
