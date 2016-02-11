// thermistor.h

#ifndef THERMISTOR_H
#define THERMISTOR_H

float getCelciusFromRawADC(unsigned short);

float getCelciusFromRawADC(unsigned short rawADC) {
	double temperature = 0.0d;
	double resistance = 0.0d;

	rawADC = map(rawADC, 0, 1023, 1023, 0);
	resistance = ((10240000 / rawADC) - 10000);
  	temperature = log(resistance);
  	temperature = 1 / (0.001129148 + (0.000234125 * temperature) + (0.0000000876741 * temperature * temperature * temperature));
	temperature -= 273.15;

	return temperature;
}

#endif // THERMISTOR_H
