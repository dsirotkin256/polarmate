#include <math.h>
#include <config.h>
#include <segment_display.h>
#include <thermistor.h>

void setup() {
	// init port
	Serial.begin(board_port);
	// init segment pin
	pinMode(seg_a, OUTPUT);
	pinMode(seg_b, OUTPUT);
	pinMode(seg_c, OUTPUT);
	pinMode(seg_d, OUTPUT);
	pinMode(seg_e, OUTPUT);
	pinMode(seg_f, OUTPUT);
	pinMode(seg_g, OUTPUT);
	pinMode(dot, OUTPUT);
	// init digit pin
	pinMode(digit_1, OUTPUT);
	pinMode(digit_2, OUTPUT);
	pinMode(digit_3, OUTPUT);
	pinMode(digit_4, OUTPUT);
}

void loop() {
	short rawADC = analogRead(thermistor);
	short celcius = getCelciusFromRawADC(rawADC) * 10;
	print_number_on_display(celcius);
}

void print_number_on_display(float number) {
	unsigned char digit = 0;
	short abs_val = abs(number);
	unsigned char length = get_number_length(abs_val);
	unsigned char* stack = new unsigned char[length];

	// push digits to stack
	for (short i = 0; i < length; i++) {
		digit = abs_val % 10;
		abs_val /= 10;
		stack[i] = digit;
	}

	// pop digits from stack and print
	for (short i = length - 1; i >= 0; i--) {
		// print digit
		on_digit_slot(i + 1);
		print_seg_digit(stack[i]);
		delay(5);
		on_digit_slot(2);
		seg_print_dot();
		if (i == 0 && number < 0) {
			// print minus sign
			on_digit_slot(length + 1);
			seg_print_minus();
			delay(5);
		}
	}
	delete [] stack;
}

unsigned char get_number_length(short n) {
	unsigned char digit = 0;
	unsigned char length = 0;
	while (n > 0) {
		digit = n % 10; 
		n /= 10;
		length++;
	}
	return length;
}
