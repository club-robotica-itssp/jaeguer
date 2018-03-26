/*
 * Simple libreria para usar de manera mas comoda
 * el sensor de distancia HCSR04.
 *
 * Autor: Jesus David Salazar Garcia.
 *
 */

 /*
  * Al instanciar el objeto los argumentos recividos
	* corresponden a "triger" y "echo" del sensor
	* respectivamento.
*/

#ifndef HCSR04_H
#define HCSR04_H

#include <Arduino.h>

class hcsr04 {
	private:
		int trig;
		int echo;
		int dist;
		void calcDist();
	public:
		hcsr04(int, int);
		int getDist();
};

#endif
