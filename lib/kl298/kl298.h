/*
  Pequeña libreria para controlar de manera
  mas comada el puente h keyes l298.

  Autor: Jesus David Salazar Garcia.   25/03/2018
*/

/*
  La instanciacion recibe los siguientes argumentos.
  EN_A
  EN_B
  IN_1
  IN_2
  IN_3
  IN_4
  velocidad (puede ser modificada despues de la instanciacion)
*/
#ifndef KL298_H
#define  KL298_H

#include <Arduino.h>

class kl298 {
private:
  int _pinENA;
  int _pinENB;
  int _pinIN1;
  int _pinIN2;
  int _pinIN3;
  int _pinIN4;
  int _velocidad;
public:
  kl298(int, int , int , int, int, int, int);
  void adelante();
  void atras();
  void rotarIzquierda();
  void rotarDerecha();
  void adelanteIzquierda();
  void adelanteDerecha();
  void atrasIzquierda();
  void atrasDerecha();
  void alto();
  void setVelocidad(int);
};

#endif
