
#include <nokia5110.c>
#include <avr/eeprom.h>
#include "io.c"

void set_pixel_square(int x, int y) {	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			nokia_lcd_set_pixel(x + i, y + j, 1);
		}	
	}
	
	return;
}

void delete_pixel_square(int x, int y) {
	
	for (int i = 0; i < 4; i++) {
    	for (int j = 0; j < 4; j++) {
        	nokia_lcd_set_pixel(x + i, y + j, 0);
    	}
	}

	for (int i = 0; i < 7; i++) {
		nokia_lcd_set_pixel(8 + i, 37, 1);	
		nokia_lcd_set_pixel(28 + i, 37, 1);
		nokia_lcd_set_pixel(48 + i, 37, 1);
	}
	
	return;
}

void set_boxes() {
	
	for (int i = 0; i < 8; i++) {
		nokia_lcd_set_pixel(8 + i, 37, 1);
		nokia_lcd_set_pixel(8 + i, 44, 1);
		nokia_lcd_set_pixel(28 + i, 37, 1);
		nokia_lcd_set_pixel(28 + i, 44, 1);
		nokia_lcd_set_pixel(48 + i, 37, 1);
		nokia_lcd_set_pixel(48 + i, 44, 1);
	}
	for (int i = 0; i < 7; i++) {
		nokia_lcd_set_pixel(8, 37 + i, 1);
		nokia_lcd_set_pixel(15, 37 + i, 1);
		nokia_lcd_set_pixel(28, 37 + i, 1);
		nokia_lcd_set_pixel(35, 37 + i, 1);
		nokia_lcd_set_pixel(48, 37 + i, 1);
		nokia_lcd_set_pixel(55, 37 + i, 1);
	}
	
	nokia_lcd_render();
	return;
}


unsigned char tempscore = 0;
void game_over() {
	nokia_lcd_clear();
	nokia_lcd_set_cursor(14, 0);
	nokia_lcd_write_string("Game over!!", 1);
	nokia_lcd_render();
	
	display_hiscore(tempscore);
	
	return;
}


void update_score(int x) {
	uint16_t data_score;
	
	data_score = eeprom_read_word((uint16_t*) 50);
	
	if (data_score > 9000) {
		eeprom_update_word(50, 0);
	}
	
	if (x > data_score) {
		eeprom_update_word(50, x);
	}
	
	return;
}

void display_hiscore(int x) {
	
	uint16_t data_score = eeprom_read_word((uint16_t*) 50);
	
	LCD_ClearScreen();
	
	char buffer[15];
	sprintf(buffer, "Hiscore: %d", data_score);
	
	LCD_DisplayString(1, buffer);
	
	return;
}

void display_score(int x, int y) {
	LCD_ClearScreen();
	
	char buffer[15];
	sprintf(buffer, "Score: %d", x);
	LCD_DisplayString(1, buffer);
	
	char lives_buffer[15];
	sprintf(lives_buffer, "Lives: %d", y);
	LCD_DisplayString(17, lives_buffer);
	
	if (x > 9) {
		LCD_DisplayString(12, "LVL:3");
	}
	else if (x > 4) {
		LCD_DisplayString(12, "LVL:2");
	}
	else {
		LCD_DisplayString(12, "LVL:1");
	}
	return;
}

void level2_display() {
	nokia_lcd_clear();
	nokia_lcd_set_cursor(14, 0);
	nokia_lcd_write_string("Level 2", 1);
	nokia_lcd_render();
	
	return;
}

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}
