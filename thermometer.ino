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
	short celcius = getCelciusFromRawADC(rawADC);
	print_number_on_display(celcius);
}

// 0.5 => true, 1.25 => float
bool is_float_zero(float n) {
	return (int)n == 0;
}

unsigned short length;

unsigned short* split_number(float n) {
	unsigned short* stack;
	// determine float e.g 0.5, -0.9
	bool isFloatZero = is_float_zero(n);
	// unsigned short absv = (isFloatZero ? abs(n * 10) : abs(n));
	unsigned short absv = abs(n) * 10;
		
	length = get_number_length(absv);
	length += isFloatZero ? 1 : 0;

	// allocate memory for decemal point and 0 e.g 0.5 => [0,5]
	stack = new unsigned short[length];

	// for decimal point with 0 e.g 0.5 use (absv * 10) otherwise use (absv)
	short count = 0;
	unsigned short digit = 0;
	if (isFloatZero) {
		stack[0] = absv;
		stack[1] = 0;
	} else {
		while (absv > 0) {
			digit = absv % 10;
			stack[count] = digit;
			absv /= 10;
			count++;
		}
	}
	return stack;
}

void print_number_on_display(float n) {
	unsigned short* stack = split_number(n);

	bool isLengthValid = length > MAX_DIGIT_SIGN;
	bool isLengthWithSignValid = length + 1 > MAX_DIGIT_SIGN && n < 0;

	if (isLengthValid || isLengthWithSignValid) {
		print_err();
	} else {
		// pop digits from stack and print
		for (short i = length - 1; i >= 0; i--) {
			// print digit
			on_digit_slot(i + 1);
			print_seg_digit(stack[i]);
			// print dot
			on_digit_slot(2);
			seg_print_dot();
			// print minus sign
			if (i == 0 && n < 0) {
				on_digit_slot(length + 1);
				seg_print_minus();
			}
		}
	}
	delete [] stack;
}

unsigned short get_number_length(short n) {
	unsigned short digit = 0;
	unsigned short length = 0;
	while (n > 0) {
		digit = n % 10; 
		n /= 10;
		length++;
	}
	return length;
}
