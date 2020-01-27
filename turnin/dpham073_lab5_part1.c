/*	Author: dukeph0 - Duke Pham
 *  Partner(s) Name: Juvenal Ortega - Email: jorte057@ucr.edu
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

/*
 * (From an earlier lab) A car has a fuel-level sensor that sets PA3..PA0
 * to a value between 0 (empty) and 15 (full).
 * A series of LEDs connected to PC5..PC0 should light to graphically indicate the fuel level.
 * If the fuel level is 1 or 2, PC5 lights. 
 * If the level is 3 or 4, PC5 and PC4 light. 5-6 lights PC5..PC3.
 * 7-9 lights PC5..PC2. 10-12 lights PC5..C1. 13-15 lights PC5..PC0.
 * Also, PC6 connects to a "Low fuel" icon, which should light if the level is 4 or less.
 * Use buttons on PA3..PA0 and mimic the fuel-level sensor with presses. 
 */

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // configure port A's pins as inputs initialize with 1s
	DDRC = 0xFF; PORTC = 0x00; // configure port C's pins as outputs initialize to 0s

	unsigned char tmpA = 0x00;

    /* Insert your solution below */
    while (1) {
	    tmpA = ~PINA;

	    switch (tmpA){

		    case (0x00) : PORTC = 0x40; // no light, low fuel warning (PC^)
		    break;

			case (0x01) : PORTC = 0x60; // PC5 lights on, low fuel warning (PC6)
			break;

			case (0x02) : PORTC = 0x60; //PC5 lights, low fuel warning (PC6)
            break;
		
			case (0x03) : PORTC = 0x70; //PC5, PC4 lights on, low fuel warning (PC6)
            break;
		
			case (0x04) : PORTC = 0x70; //PC5, PC4 lights on, low fuel warning (PC6)
            break;
			
			case (0x05) : PORTC = 0x38; //PC5, PC4, PC3  lights on, no fuel warning (PC6)
            break;
			
			case (0x06) : PORTC = 0x38; //PC5, PC4, PC3  lights on, no fuel warning (PC6)
            break;
		
			case (0x07) : PORTC = 0x3C; //PC5, PC4, PC3, PC2  lights on, no fuel warning (PC6)
            break;
		
			case (0x08) : PORTC = 0x3C; //PC5, PC4, PC3, PC2  lights on, no fuel warning (PC6)
            break;

			case (0x09) : PORTC = 0x3C; //PC5, PC4, PC3, PC2  lights on, no fuel warning (PC6)
            break;

			case (0x0A) : PORTC = 0x3E; //PC5, PC4, PC3, PC2, PC1 lights on, no fuel warning
            break;
			
			case (0x0B) : PORTC = 0x3E; //PC5, PC4, PC3, PC2, PC1  lights on, no fuel warning
            break;
			
			case (0x0C) : PORTC = 0x3E; //PC5, PC4, PC3, PC2, PC1  lights on, no fuel warning
            break;

			//13+ fuel
			default : PORTC = 0x3F; // PC5, PC4, PC3, PC2, PC1 light no warning
			break;



	    
	    
	    
	    }
    }
    return 1;
}
