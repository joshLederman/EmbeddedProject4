#include "3140_concur.h"
#include "utils.h"
#include "lock.h"
#include "cond.h"

lock_t l;
cond_t c;

unsigned int nr= 0;
unsigned int nw= 0;

void p1 (){	
	LEDBlue_On();
	c_wait(&l, &c);
	LEDBlue_Toggle();
	delay();
}

void p2 () {
	delay();
	for (int i = 0; i < 10; i++) {
		LEDRed_Toggle();
		delay();
	}
	c_signal(&l, &c);
}
	
int main (void){
    LED_Initialize();

	l_init (&l);
	c_init (&l,&c);
 
	if (process_create (p1,20) < 0) {
	 	return -1;
	}
	if (process_create (p2,20) < 0) {
	 	return -1;
	}

	process_start();

  LEDGreen_On();
	while (1) ;

}
