/*
 * project2_nokia.c
 *
 * Created: 5/30/2018 9:24:50 PM
 * Author : David
 */ 

#include <timer.h>
#include <scheduler.h>
#include <functions.c>
#include <stdlib.h>
#include <time.h>
#include <String.h>


int score = 0;
unsigned long int lives = 3;

enum display1_states {display1_start, display1_delete, display1_over, display1_wait};
unsigned char y1_counter = 0;
unsigned long int mod1_counter = 0;
unsigned char indicator1 = 0;

unsigned char slot_1 = 0;
unsigned char slot_2 = 0;
unsigned char slot_3 = 0;

int display_tick1(int state) {
	unsigned char tempA = ~PINA;
	switch(state) {
		case display1_start: 
			if (lives == 0) {
				state = display1_over;
				break;
			}
			if (mod1_counter % 2 == 0) {
				state = display1_start;
			}
			else {
				state = display1_delete;
			}
			break;

		case display1_delete: 
			if (mod1_counter % 2 == 1) {
				state = display1_delete;
			}
			else {
				state = display1_start;
			}
			break;
		case display1_over: 
			if (tempA == 0x08) {
				state = display1_start;
			}
			else {
				state = display1_over;
			}
			break;
		default: state = display1_start; break;
			
	}
	
	switch(state) {
		case display1_start:
			if (y1_counter >= 37 && y1_counter < 41) {
				if (slot_1 == 1) {
					score++;
					display_score(score, lives);
					if (score > 9) {
						y1_counter = rand() % 20 + 1;
					}
					else {
						y1_counter = 0;
					}
					mod1_counter = 0;
					indicator1 = 1;
				}
			}
			if (y1_counter < 41) {
				set_pixel_square(10, y1_counter);
				nokia_lcd_render();
				mod1_counter++;
			}
			else {
				if (lives > 0) {
					lives--;
				}
				display_score(score, lives);
				if (lives == 0) {
					update_score(score);
					break;
				}
				y1_counter = 0;
				mod1_counter = 0;
				indicator1 = 1;
			}
			break;
		case display1_delete: 
			delete_pixel_square(10, y1_counter);
			mod1_counter++;
			y1_counter++;
			break;

		case display1_over: 
			game_over(); 
			score = 0;
			break;
		default: break;
	}
	
	return state;
}

enum display2_states {display2_start, display2_delete, display2_over, display2_wait};
unsigned char y2_counter = 0;
unsigned long int mod2_counter = 0;
unsigned char indicator2 = 0;

int display_tick2(int state) {
	unsigned char tempA = ~PINA;

	switch(state) {
		case display2_start:
			if (lives == 0) {
				state = display2_over;
				break;
			} 
			if (mod2_counter % 2 == 0) {
				state = display2_start;
			}
			else {
				state = display2_delete;
			}
			break;
		case display2_delete: 
			if (mod2_counter % 2 == 1) {
				state = display2_delete;
			}
			else {
				state = display2_start;
			}
			break;
		case display2_over:
			if (tempA == 0x08) {
				state = display2_start;
			} 
			else {
				state = display2_over;
			}
			break;
		default: state = display2_start; break;
	}

	switch(state) {
		case display2_start:
			if (y2_counter >= 37 && y2_counter < 41) {
				if (slot_2 == 1) {
					score++;
					display_score(score, lives);
					if (score > 9) {
						y2_counter = rand() % 20 + 1;
					}
					else {
						y2_counter = 0;
					}
					mod2_counter = 0;
					indicator2 = 1;
				}
			}
			if (y2_counter < 41) {
				set_pixel_square(30, y2_counter);
				nokia_lcd_render();
				mod2_counter++;
			}
			else {
				if (lives > 0) {
					lives--;
				}
				display_score(score, lives);
				if (lives == 0) {
					update_score(score);
					break;
				}
				y2_counter = 0;
				mod2_counter = 0;
				indicator2 = 1;
			}
			break;
		case display2_delete: 
			delete_pixel_square(30, y2_counter);
			mod2_counter++;
			y2_counter++;
			break;
		case display2_over:
			game_over();
			score = 0;
			break;
		case display2_wait: break;
		default: break;
	}

	return state;
}

enum display3_states {display3_start, display3_delete, display3_over, display3_wait};
unsigned char y3_counter = 0;
unsigned long int mod3_counter = 0;
unsigned char indicator3 = 0;

int display_tick3(int state) {
	unsigned char tempA = ~PINA;
	
    switch(state) {
        case display3_start:
			if (lives == 0) {
				state = display3_over;
				break;
			}
			if (mod3_counter % 2 == 0) {
				state = display3_start;
			}
			else {
				state = display3_delete;
			}
			break;
        case display3_delete:
			if (mod3_counter % 2 == 1) {
				state = display3_delete;
			}
			else {
				state = display3_start;
			}
			break;
        case display3_over: 
			if (tempA == 0x08) {
				state = display3_start;
			}
			else {
				state = display3_over;
			}
			break;
			
        default: state = display3_start; break;
    }

    switch(state) {
        case display3_start:

			if (y3_counter >= 37 && y3_counter < 41) {
				if (slot_3 == 1) {
					score++;
					display_score(score, lives);
					if (score > 9) {
						y3_counter = rand() % 20 + 1;
					}
					else {
						y3_counter = 0;
					}
					mod3_counter = 0;
					indicator3 = 1;
				}
			}
			if (y3_counter < 41) {
				set_pixel_square(50, y3_counter);
				nokia_lcd_render();
				mod3_counter++;
			}
			else {
				if (lives > 0) {
					lives--;
				}
				display_score(score, lives);
				if (lives == 0) {
					update_score(score);
					break;
				}
				y3_counter = 0;
				mod3_counter = 0;
				indicator3 = 1;
			}
			break;
        case display3_delete:
			delete_pixel_square(50, y3_counter);
			mod3_counter++;
			y3_counter++;
			break;
		case display3_over:
			game_over(); 
			score = 0;
			break;
        default: break;
    }

    return state;
}

enum reset_states{reset_start, reset_actual};

int reset_check(int state) {
	unsigned char tempA = ~PINA;
	tempA = tempA & 0x08;
	switch(state) {
		case reset_start:
			state = (tempA == 0x08) ? reset_actual : reset_start;
			break;
			
		case reset_actual:
			state = reset_start;
			break;
		default: state = reset_start; break;
	}
	switch(state) {
		case reset_start: break;
		case reset_actual:
			y3_counter = 0;
			mod3_counter = 0;
			indicator3 = 0;
			y1_counter = 0;
			mod1_counter = 0;
			indicator1 = 0;
			y2_counter = 0;
			mod2_counter = 0;
			indicator2 = 0;
			score = 0;
			lives = 3;
			nokia_lcd_clear();
			display_score(score, lives);
			set_boxes();
			break;
		default: break;
			
	}
}

enum joystick_states{joystick_start};

int joystick_control(int state) {
	ADMUX = 0;
	unsigned short read1 = ADC;
	delay_ms(1);
	ADMUX = 1;
	unsigned short read2 = ADC;
	delay_ms(1); 
	switch(state) {
		case joystick_start:
			if (read1 < 300) {
				slot_1 = 1;
			}
			else if (read1 > 700) {
				slot_3 = 1;
			}
			else {
				slot_1 = 0;
				slot_3 = 0;
			}
			if (read2 < 300) {
				slot_2 = 1;
			}
			else {
				slot_2 = 0;
			}
			break;
		default: state = joystick_start; break;
		
	}
	
	return state;
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	TimerSet(10);
	TimerOn();
    nokia_lcd_init();
	LCD_init();
	display_score(score, lives);
	set_boxes();
	
	static task task1, task2, task3, task4, task5;
	task *tasks[] = {&task1, &task2, &task3, &task4, &task5};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);
	
	unsigned long int task1_period = 60;
	unsigned long int task2_period = 70;
	unsigned long int task3_period = 65;
	unsigned long int task4_period = 30;
	unsigned long int task5_period = 30;
	unsigned long int GCD = 0;
	
	GCD = findGCD(task1_period, task2_period);
	GCD = findGCD(GCD, task3_period);
	
	task1_period = task1_period / GCD;
	task2_period = task2_period / GCD;
	task3_period = task3_period / GCD;
	
	task1.state = display1_start;
	task1.period = task1_period;
	task1.elapsedTime = task1_period;
	task1.TickFct = &display_tick1;
	
	task2.state = display2_start;
	task2.period = task2_period;
	task2.elapsedTime = task2_period;
	task2.TickFct = &display_tick2;

	task3.state = display3_start;
	task3.period = task3_period;
	task3.elapsedTime = task3_period;
	task3.TickFct = &display_tick3;
	
	task4.state = joystick_start;
	task4.period = task4_period;
	task4.elapsedTime = task4_period;
	task4.TickFct = &joystick_control;
	
	task5.state = reset_start;
	task5.period = task5_period;
	task5.elapsedTime = task5_period;
	task5.TickFct = &reset_check;
	srand(time(0));
	ADC_init();
	
    while (1)
    {		
	    for ( int i = 0; i < numTasks; i++ ) {
		    // Task is ready to tick
		    if ( tasks[i]->elapsedTime == tasks[i]->period ) {
			    // Setting next state for task
			    tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
			    // Reset the elapsed time for next tick.
			    tasks[i]->elapsedTime = 0;
		    }
		    tasks[i]->elapsedTime += 1;
	    }
		if (indicator1 == 1) {
			indicator1 = 0;
			if (score > 5) {
				task1.period = rand() % 5 + 2;
			}
			else if (score > 9) {
				task1.period = rand() % 3 + 1;
			}
			else {
				task1.period = rand() % 10 + 5;
			}
			task1.elapsedTime = task1.period;
		}
		if (indicator2 == 1) {
			indicator2 = 0;
			if (score > 5) {
				task2.period = rand() % 5 + 2;
			}
			else if (score > 9) {
				task2.period = rand() % 3 + 1;
			}
			else {
				task2.period = rand() % 10 + 5;
			}
			task2.elapsedTime = task2.period;
		}
		if (indicator3 == 1) {
			indicator3 = 0;
			if (score > 5) {
				task3.period = rand() % 5 + 2;
			}
			else if (score > 9) {
				task3.period = rand() % 3 + 1;
			}
			else {
				task3.period = rand() % 10 + 5;
			}
			task3.elapsedTime = task3.period;
		}
	    while(!TimerFlag) {}
	    TimerFlag = 0;
    }
}

