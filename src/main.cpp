/*
  Codigo principal de control para el robot "Jaeguer" el cual esta dedicado
  a interactuar con todos y cada uno de los componenetes que lo conforman
  (sensores, acctuadores y modulos de comunicación).

  El principio de funcionamiento buscado es el siguiente:
    *Dotar al robot de dos modos de control;
      -Control manual desde un telefono celular utilizando android y bluetoooth.
      -Control de exploración autonomo en el cual de manera autonoma podra explorar espacios
       por los que pueda desplazarse evadiendo obstaculos.
      -Control de identificación de objetos autonomo en cula sera capaz de identificar
       y aproximarse a cierto tipo de obejetos definidos y realizar ciertas acciones
       al estar proximo a los mismos.

  Autores:
  Jeselyn Yerany Salas Lara, AKA: Jess.
  Jesús David Salazar García, AKA: Deivid.

  08/03/2018
*/

// Librerias
#include <Arduino.h> // Arduino.
#include "kl298.h"
#include "hcsr04.h" // (tr, echo)

// Descomentar para depuración por puerto serial.
#define DEPURACION
#define BAUDRATE 9600

// Definiciones.
// Pines sensor ultrasonico.
#define TRIGGER 2
#define ECHO    4
// Pines puente h keyes kl298
#define EN_A  6
#define EN_B  5
#define IN_1  10
#define IN_2  9
#define IN_3  8
#define IN_4  7
#define VELOCIDAD 255

// Pines del aruduino  //
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// B B U S U H H H H H H
// A0 A1 A2 A3 A4 A5 //
//
//////////////////////

kl298 jaeguer(EN_A, EN_B, IN_1, IN_2, IN_3, IN_4, VELOCIDAD);
hcsr04 ulstrasonico(TRIGGER, ECHO);

void setup() {
  #ifdef DEPURACION
    Serial.begin(BAUDRATE);
  #endif
}

void loop() {
  #ifdef DEPURACION
    Serial.println(ulstrasonico.getDist());
    delay(1000);
  #endif
}
