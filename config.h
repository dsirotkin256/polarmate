// config.h

#ifndef CONFIG_H
#define CONFIG_H
#include <arduino.h>

unsigned short board_port = 9801;

// init analog inputs
const unsigned char thermistor = A1;

// init digital outputs
const unsigned char seg_a = 12;
const unsigned char seg_b = 8;
const unsigned char seg_c = 5;
const unsigned char seg_d = 3;
const unsigned char seg_e = 2;
const unsigned char seg_f = 11;
const unsigned char seg_g = 6;

const unsigned char digit_1 = 7;
const unsigned char digit_2 = 9;
const unsigned char digit_3 = 10;
const unsigned char digit_4 = 13;

const unsigned char dot = 4;

#endif // CONFIG_H
