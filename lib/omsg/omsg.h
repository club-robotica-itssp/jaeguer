/*
  Libreria para guardar los mensajes que mostrara Jaeguer.

  Autor: Jesus David Salazar Garcia.   02/05/2018
*/

#ifndef OMSG_H
#define  OMSG_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>   // OLED

class omsg {
private:
public:
  omsg();
  void iniScreen();
  void cls();
  void iniciando();
  void iniSp();
  void iniEs();
  void iniSm();
  void cenCm();
  void progreso(int X);
  void hecho(int X);
  void hecho_cursor(int X);
  void corazon();
  void dtBmsg();
  void flechaA();
};

#endif
