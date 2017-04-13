#include "3140_concur.h"
#include "utils.h"
#include "lock.h"


lock_t l;
lock_t a;
void p1(void){
	int i= 0;
	while(i < 3){
		/*NCS*/
		delay();
		i++;
		/*CS*/
		l_lock(&l);
		LEDBlue_Toggle();
		delay();
		LEDBlue_Toggle();
		delay();
		l_unlock(&l);
		l_lock(&a);
		LEDBlue_Toggle();
		delay();
		LEDBlue_Toggle();
		delay();
		l_unlock(&a);
		
	}
}

void p2(void){
	int i= 0;
	while(i < 3){
		/*NCS*/
		delay();
		i++;
		/*CS*/
		l_lock(&a);
		LEDRed_Toggle();
		delay();
		LEDRed_Toggle();
		delay();
		l_unlock(&a);
		l_lock(&l);
		LEDRed_Toggle();
		delay();
		LEDRed_Toggle();
		delay();
		l_unlock(&l);
		
	}
}

void p3(void){
	int i= 0;
	while(i < 3){
		/*NCS*/
		delay();
		i++;
		/*CS*/
		l_lock(&a);
		LEDGreen_Toggle();
		delay();
		LEDGreen_Toggle();
		delay();
		l_lock(&l);
		l_unlock(&a);
		LEDGreen_Toggle();
		delay();
		LEDGreen_Toggle();
		delay();
		l_unlock(&l);
		
	}
}

int main(void){
	LED_Initialize();           /* Initialize the LEDs           */	

	l_init (&l);
	
	l_init (&a);
	
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

	while(1);
}
