/*	Author: dukeph0 - Duke Pham
 *  Partner(s) Name: Juvenal Ortega - Email: jorte057@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 5  Exercise 2
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
 * (From an earlier lab) Buttons are connected to PA0 and PA1. 
 * Output for PORTC is initially 0.
 * Pressing PA1 decrements PORTC (stopping at 0).
 * If both buttons are depressed (even if not initially simultaneously), PORTC resets to 0.
 * If a reset occurs, both buttons should be fully released before additional increments or decrements are allowed to happen.
 * Use LEDs (and resistors) on PORTC. Use a state machine (not synchronous) captured in C.  
 */

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // configure port A's pins as inputs initialize with 1s
	DDRC = 0xFF; PORTC = 0x00; // configure port C's pins as outputs initialize to 0s

	addsm = init;

    /* Insert your solution below */
    while (1) {
		tick();
	    }
    }
}

void tick(){
	switch(addsm) {
		case init:
			PORTC = 0x07;
			addsm = interphase;
			break;
		case interphase:
			//PA0 & !PA1 go to inc
			if ((~PINA & 0x03) == 0x01){
				addsm = inc;
			}
			//PA1 & !PA0 go to dec
			else if ((~PINA & 0x03) == 0x02){
				addsm = dec;
			}
			//!PA0 and !PA1 go to reset
			else if ((~PINA & 0x03) == 0x03){
				addsm = reset;
			} else {// stay in interphase for anyrthing else
				addsm = interphase;
			}
			break;
		case inc:
			addsm = incWait;
			break;
		case incWait:
			//wait for button release 
			if ((~PINA & 0x03) == 0x01){
				addsm = incWait;
			}else if ((~PINA & 0x03) == 0x03){
				addsm = reset;
			}else{
				addsm = interphase;
			}
			break;
		case dec:
			addsm = decWait;
			break;
		case decWait:
			// wait for button release
                        if ((~PINA & 0x03) == 0x02){
                                addsm = decWait;
			} else if ((~PINA & 0x03) == 0x03){
                                addsm = reset;
                        }else{
                                addsm = interphase;
                        }

			break;
		case reset:
			if ((~PINA & 0x03) == 0x00){
				addsm = interphase;
			} else {
				addsm = reset;
			}
			break;
		default:
			addsm = interphase;
			break;
	}//transitions
	
	//state actions
	switch(addsm) {
                case init:
                        break;
                case interphase:
			break;
                case inc:
			// Add 1 to PORTC but doesn't surpass 9
			if (PORTC < 0x09)
				PORTC = (PORTC + 0x01);
                        break;
		case incWait:
			break;
                case dec:
			//Subtract 1 to PORTC but doesn't go below 0
			if (PORTC > 0x00)
                        	PORTC = (PORTC - 0x01);
                        break;
		case decWait:
			break;
                case reset:
			PORTC = 0x00;
                        break;
                default:
                        break;
	}
}
