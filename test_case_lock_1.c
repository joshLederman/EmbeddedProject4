#include "3140_concur.h"
#include "utils.h"
#include "lock.h"

lock_t l;
lock_t m;

void p1 (){	
	l_lock(&l);
	
	delay();
	LEDRed_Toggle();
	delay();
	LEDRed_Toggle();
	delay();
	
	l_lock(&m);
	
	LEDRed_Toggle();
	delay();
	LEDRed_Toggle();
	delay();
	
	l_unlock(&l);
	
	LEDRed_Toggle();
	delay();
	LEDRed_Toggle();
	delay();
	
	l_unlock(&m);
}

void p2 () {
	
	l_lock(&m);
	
	LEDBlue_Toggle();
	delay();
	LEDBlue_Toggle();
	delay();
	
	l_unlock(&m);	
	
	l_lock(&l);
	
	LEDBlue_Toggle();
	delay();
	LEDBlue_Toggle();
	delay();
	
	l_unlock(&l);
}

void p3 () {
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
}
	
int main (void){
    LED_Initialize();

	l_init (&l);
	l_init (&m);
 
	if (process_create (p1,20) < 0) {
	 	return -1;
	}
	if (process_create (p2,20) < 0) {
	 	return -1;
	}
	if (process_create (p3,20) < 0) {
	 	return -1;
	}

	process_start();

  LEDGreen_On();
	while (1) ;

}
