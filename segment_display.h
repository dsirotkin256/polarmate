// segment_display.h

#ifndef SEGMENT_DISPLAY_H
#define SEGMENT_DISPLAY_H

#include <config.h>

void print_1digit();
void print_2digit();
void print_3digit();
void print_4digit();

void print_seg_digit(const unsigned char);
void seg_print_minus();
void seg_print_dot();
void seg_print_0();
void seg_print_1();
void seg_print_2();
void seg_print_3();
void seg_print_4();
void seg_print_5();
void seg_print_6();
void seg_print_7();
void seg_print_8();
void seg_print_9();

void on_digit_slot(const unsigned char);
void off_all_digit_slots();

// turn on slots
void on_digit_slot(const unsigned char n) {
	switch(n) {
		case 4: print_4digit();
		break;
		case 3: print_3digit();
		break;
		case 2: print_2digit();
		break;
		case 1: print_1digit();
		break;
		default: off_all_digit_slots();
		return;
	}
}

void off_all_digit_slots() {
	digitalWrite(digit_1, HIGH);
	digitalWrite(digit_2, HIGH);
	digitalWrite(digit_3, HIGH);
	digitalWrite(digit_4, HIGH);
}

void print_1digit() {
	digitalWrite(digit_1, LOW);
	digitalWrite(digit_2, HIGH);
	digitalWrite(digit_3, HIGH);
	digitalWrite(digit_4, HIGH);
}

void print_2digit() {
	digitalWrite(digit_1, HIGH);
	digitalWrite(digit_2, LOW);
	digitalWrite(digit_3, HIGH);
	digitalWrite(digit_4, HIGH);
}

void print_3digit() {
	digitalWrite(digit_1, HIGH);
	digitalWrite(digit_2, HIGH);
	digitalWrite(digit_3, LOW);
	digitalWrite(digit_4, HIGH);
}

void print_4digit() {
	digitalWrite(digit_1, HIGH);
	digitalWrite(digit_2, HIGH);
	digitalWrite(digit_3, HIGH);
	digitalWrite(digit_4, LOW);
}

void print_seg_digit(const unsigned char n) {
	switch(n) {
		case 1: seg_print_1();
		break;
		case 2: seg_print_2();
		break;
		case 3: seg_print_3();
		break;
		case 4: seg_print_4();
		break;
		case 5: seg_print_5();
		break;
		case 6: seg_print_6();
		break;
		case 7: seg_print_7();
		break;
		case 8: seg_print_8();
		break;
		case 9: seg_print_9();
		break;
		default: seg_print_0();
		return;
	}
}

void seg_print_dot() {
	digitalWrite(seg_g, LOW);
	digitalWrite(seg_a, LOW);
	digitalWrite(seg_b, LOW);
	digitalWrite(seg_c, LOW);
	digitalWrite(seg_d, LOW);
	digitalWrite(seg_e, LOW);
	digitalWrite(seg_f, LOW);
	digitalWrite(dot, HIGH);
}

void seg_print_minus() {
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_a, LOW);
	digitalWrite(seg_b, LOW);
	digitalWrite(seg_c, LOW);
	digitalWrite(seg_d, LOW);
	digitalWrite(seg_e, LOW);
	digitalWrite(seg_f, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_0() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_e, HIGH);
	digitalWrite(seg_f, HIGH);
	digitalWrite(seg_g, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_1() {
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_a, LOW);
	digitalWrite(seg_d, LOW);
	digitalWrite(seg_e, LOW);
	digitalWrite(seg_f, LOW);
	digitalWrite(seg_g, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_2() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_e, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_c, LOW);
	digitalWrite(seg_f, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_3() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_e, LOW);
	digitalWrite(seg_f, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_4() {
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_f, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_a, LOW);
	digitalWrite(seg_d, LOW);
	digitalWrite(seg_e, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_5() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_f, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_b, LOW);
	digitalWrite(seg_e, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_6() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_e, HIGH);
	digitalWrite(seg_f, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_b, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_7() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, LOW);
	digitalWrite(seg_e, LOW);
	digitalWrite(seg_f, LOW);
	digitalWrite(seg_g, LOW);
	digitalWrite(dot, LOW);
}
void seg_print_8() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_e, HIGH);
	digitalWrite(seg_f, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(dot, LOW);
}
void seg_print_9() {
	digitalWrite(seg_a, HIGH);
	digitalWrite(seg_b, HIGH);
	digitalWrite(seg_c, HIGH);
	digitalWrite(seg_d, HIGH);
	digitalWrite(seg_f, HIGH);
	digitalWrite(seg_g, HIGH);
	digitalWrite(seg_e, LOW);
	digitalWrite(dot, LOW);
}

#endif // SEGMENT_DISPLAY_H
