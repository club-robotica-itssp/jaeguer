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
	TRIG = tr;
	ECHO = ec;

	Serial.println("INICIO");

	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
}

int hcsr04::getDist() {
  long duration;
  int distance;

  // Asegurando estado bajo en TRIG.
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Poniendo en alto la terminal TRIG por 10 microsegundos.
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Obteniendo y almacenando el tiempo en el que ECHO conmuta de estado.
  duration = pulseIn(ECHO, HIGH);
  // Calculando distancia utilizando la velocidad del sonido (343m/s)
  // y dividiendo entre 2.
  distance= duration*0.034/2;

	Serial.println("CALCULAND");
	Serial.println(duration);
	Serial.println(distance);

  return distance;
}
