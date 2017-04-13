#include "3140_concur.h"
#include "utils.h"
#include "lock.h"
#include "cond.h"

lock_t l;
cond_t c1;
cond_t c2;

void p1 (){	
	LEDBlue_On();
	c_wait(&l, &c1);
	LEDBlue_Toggle();
	delay();
	if (c_waiting(&l,&c2))
		c_signal(&l,&c2);
}

void p2 () {
	delay();
	for (int i = 0; i < 10; i++) {
		LEDRed_Toggle();
		delay();
	}
	if (c_waiting(&l,&c1))
		c_signal(&l, &c1);
	c_wait(&l, &c2);
	for (int i = 0; i < 10; i++) {
		LEDRed_Toggle();
		delay();
	}
}
	
int main (void){
    LED_Initialize();

	l_init (&l);
	c_init (&l,&c1);
 
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
