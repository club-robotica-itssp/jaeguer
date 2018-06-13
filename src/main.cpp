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

/*
  Mapa de pines.

   Pines del aruduino
   0 1 2 3 4 5 6 7 8 9 10 11 12 13 A0 A1 A2 A3 A4 A5
   B B U S U H H H H H H  Z

   B - Usados en modulo bluetooth.
   U - Usados en el sensor ultrasonico hcsr04.
   S - Usados en servomotor.
   H - Usados en puente h keyes kl298.
   Z - Usados en el buzze.
*/

// Librerias
#include <Arduino.h> // Arduino.
#include <Servo.h>// 883
#include "kl298.h"
#include "hcsr04.h" // (tr, echo)
#include "omsg.h"

// Configuración.
#define POSICION_CENTRAL_USERVO 75 // Posición que adquirira el servo al inciar.
#define MIN_USERVO 0
#define MAX_USERVO 170

// Definiciones.
// Pin para buzzer.
#define BUZZER 11
// Pin para servomotor.
#define SERVO 3
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
//#define VELOCIDAD 255
#define VELOCIDAD 255
// Renombrando Serial a bluetooth
#define BT  Serial
#define BAUDRATE 9600

// Prototipos.

// Variables.
char dato = 'S';
char mode = 'B';
int vLect1=0;
int vLect2=0;
int vLect3=0;
int velocidad;
int dist;
int cont = 1;

// Instanciaciones.
kl298 jaeguer(EN_A, EN_B, IN_1, IN_2, IN_3, IN_4, VELOCIDAD);
hcsr04 distancia(TRIGGER, ECHO);
Servo uServo;
omsg msg;

void setup() {
  // Inicializando pantalla.
  msg.iniScreen();

  // Limpinado pantalla
  msg.cls();

  // Mensaje iniciando.
  msg.iniciando();

  // Inicializando comunicación serial con bluetooth.
  msg.iniSp();
  BT.begin(BAUDRATE);
  msg.hecho(20);

  // Pin de salida para buzzer.
  msg.iniEs();
  pinMode(BUZZER, OUTPUT);
  pinMode(13, OUTPUT);
  msg.hecho(30);

  // Inicializando servo en pin correspondiente.
  msg.iniSm();
  uServo.attach(SERVO);
  msg.hecho(40);

  // Posicionanado servo en la posición central.
  msg.cenCm();
  int cnt = 0; // Contador para display.
  for (int i = uServo.read(); i >= POSICION_CENTRAL_USERVO; i--) {
    msg.progreso(cnt); // Escribiendo una linea en la barra de progreso.
    uServo.write(i); // Centrando cervo.
    delay(10);
    cnt++;
  }
  msg.hecho_cursor(50);
  msg.cls();
  msg.corazon();
  msg.cls();
  msg.drawInterfaz();

  //msg.modoRemotoBT();
  msg.ready();
  delay(250);
  msg.cls_header();
}

void loop() {
  // Revisando datos para selección de modo.
  if (BT.available()) {
    mode = BT.read();
  }

  // Selección de modos.
  switch (mode) {
    case 'B':
      while (mode == 'B') {
        msg.modoAuto();
        msg.cls_body();

        if (BT.available()) {
          dato = BT.read();
        }
        switch (dato) {
          case 'V':
            while (dato == 'V') {
              msg.selectMode();
              if (BT.available()) {
                mode = BT.read();
                msg.cls_header();
                dato = 'S';
              }
            }
        }

        //TODO CODIGO AQUI
        Serial.println(distancia.getDist());
      }
      break;
    case 'N':
      while (mode == 'N') {
        msg.modoAutoBT();
        msg.cls_body();

        if (BT.available()) {
          dato = BT.read();
        }
        switch (dato) {
          case 'V':
            while (dato == 'V') {
              msg.selectMode();
              if (BT.available()) {
                mode = BT.read();
                msg.cls_header();
                dato = 'S';
              }
            }
        }
      }
      break;
    case 'M':
      while (mode == 'M') {
        msg.modoRemotoBT();
        msg.cls_body();

        if (BT.available()) {
          dato = BT.read();
        }
        switch (dato) {
          case 'V':
            while (dato == 'V') {
              msg.selectMode();
              if (BT.available()) {
                mode = BT.read();
                msg.cls_header();
                dato = 'S';
              }
            }
            break;
          case 'W':
            jaeguer.adelante();
            break;
          case 'X':
            jaeguer.atras();
            break;
          case 'A':
            jaeguer.rotarIzquierda();
            break;
          case 'D':
            jaeguer.rotarDerecha();
            break;
          case 'Q':
            jaeguer.adelanteIzquierda();
            break;
          case 'E':
            jaeguer.adelanteDerecha();
            break;
          case 'C':
            jaeguer.atrasDerecha();
            break;
          case 'Z':
            jaeguer.atrasIzquierda();
            break;
          case 'S':
            jaeguer.alto();
            break;
          case 'P':
            digitalWrite(BUZZER, HIGH);
            msg.dtBmsg();
            break;
          case 'p':
            digitalWrite(BUZZER, LOW);
            break;
        }
    }
  }
}
