/*
  Pequeña libreria para controlar de manera
  mas comada el puente h keyes l298.

  Autor: Jesus David Salazar Garcia.   25/03/2018
*/

#include "kl298.h"

kl298::kl298(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4, int vel) {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  _pinENA = ENA;
  _pinENB = ENB;
  _pinIN1 = IN1;
  _pinIN2 = IN2;
  _pinIN3 = IN3;
  _pinIN4 = IN4;
  _velocidad = vel;
}

void kl298::adelante() {
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, LOW);
  digitalWrite(_pinIN3, HIGH);
  digitalWrite(_pinIN4, LOW);

  analogWrite(_pinENA, _velocidad);
  analogWrite(_pinENB, _velocidad);
}


void kl298::atras() {
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, HIGH);
  digitalWrite(_pinIN3, LOW);
  digitalWrite(_pinIN4, HIGH);

  analogWrite(_pinENA, _velocidad);
  analogWrite(_pinENB, _velocidad);
}

void kl298::giroIzquierda() {
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, LOW);
  digitalWrite(_pinIN3, LOW);
  digitalWrite(_pinIN4, HIGH);

  analogWrite(_pinENA, _velocidad);
  analogWrite(_pinENB, _velocidad);
}

void kl298::giroDerecha() {
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, HIGH);
  digitalWrite(_pinIN3, HIGH);
  digitalWrite(_pinIN4, LOW);

  analogWrite(_pinENA, _velocidad);
  analogWrite(_pinENB, _velocidad);
}

void kl298::giroMedioIzquierda() {
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, LOW);
  digitalWrite(_pinIN3, LOW);
  digitalWrite(_pinIN4, LOW);

  analogWrite(_pinENB, _velocidad);
}

void kl298::giroMedioDerecha() {
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, LOW);
  digitalWrite(_pinIN3, HIGH);
  digitalWrite(_pinIN4, LOW);

  analogWrite(_pinENA, _velocidad);
}

void kl298::alto() {
  digitalWrite(_pinENA, LOW);
  digitalWrite(_pinENB, LOW);
}

void kl298::setVelocidad(int vel) {
  _velocidad = vel;
}
