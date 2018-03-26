/*
 * Simple libreria para usar de manera mas comoda
 * el sensor de distancia HCSR04.
 *
 * Autor: jesus David Salazar Garcia.
 *
 */

#include "hcsr04.h"

// Constructor, pines de conexion
hcsr04::hcsr04(int tr, int ec) {
	trig = tr;
	echo = ec;

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

void hcsr04::calcDist() {
	long time; // Para guardar el tiempo de viaje del ultrasonido.

	// Preparando el sensor.
	digitalWrite(trig, LOW);
	delayMicroseconds(2);

	// Poniendo en alto trigger para iniciar la medicion con el sensor.
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

	// Leyento el tiempo en que el sonido tardda en regresar.
	time = pulseIn(echo, HIGH);

	// Calculando la distancia.
	dist = time*0.034/2;
}

int hcsr04::getDist() {
	calcDist();
	return dist;
}
