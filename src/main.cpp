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
#include <Adafruit_SSD1306.h>   // OLED
#include "kl298.h"
#include "hcsr04.h" // (tr, echo)

// Configuración.
#define POSICION_CENTRAL_USERVO 75 // Posición que adquirira el servo al inciar.
#define MIN_USERVO 0
#define MAX_USERVO 170

// Definiciones.
// Oled reset.
#define OLED_RESET  4
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
#define VELOCIDAD 255
// Renombrando Serial a bluetooth
#define BT  Serial
#define BAUDRATE 9600

// Prototipos.
void DrawTitles(int posicion_y, String int_o_ext);

// Variables.
char dato = 'N';
int vLect1=0;
int vLect2=0;
int vLect3=0;
int velocidad;
int cont = 1;

// Instanciaciones.
kl298 jaeguer(EN_A, EN_B, IN_1, IN_2, IN_3, IN_4, VELOCIDAD);
hcsr04 distancia(TRIGGER, ECHO);
Adafruit_SSD1306 Display(OLED_RESET);  // pantalla
Servo uServo;

void setup() {
  // Pantalla oled
  Display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Inicializando la dirección i2c para la pantalla oled.
  Display.clearDisplay();// Limpiando pantall antes.
  Display.display();
  delay (1000);
  // Mensaje iniciando.
  Display.setTextSize(2);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 0);
  Display.print("I");
  Display.display();
  Display.print("n");
  Display.display();
  Display.print("i");
  Display.display();
  Display.print("c");
  Display.display();
  Display.print("i");
  Display.display();
  Display.print("a");
  Display.display();
  Display.print("n");
  Display.display();
  Display.print("d");
  Display.display();
  Display.print("o");
  Display.display();
  Display.fillRect(110, 0, 2, 14, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(110, 0, 2, 14, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(110, 0, 2, 14, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(110, 0, 2, 14, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(110, 0, 2, 14, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(110, 0, 2, 14, BLACK);
  Display.display();
  delay(200);



  // Inicializando comunicación serial con bluetooth.
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 20);
  Display.println("Abriendo SP: ");
  Display.display();

  BT.begin(BAUDRATE);
  delay(200);

  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(75, 20);
  Display.println("Hecho");
  Display.display();
  delay(100);

  // Pin de salida para buzzer.
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 30);
  Display.println("Config  E/S: ");
  Display.display();

  pinMode(BUZZER, OUTPUT);
  pinMode(13, OUTPUT);
  delay(200);

  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(75, 30);
  Display.println("Hecho");
  Display.display();
  delay(100);

  // Inicializando servo en pin correspondiente.
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 40);
  Display.println("Arranca  SM: ");
  Display.display();

  uServo.attach(SERVO);
  delay(200);

  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(75, 40);
  Display.println("Hecho");
  Display.display();
  delay(100);

  // Posicionanado servo en la posición central.
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 50);
  Display.println("Centrand SM: ");
  Display.display();

  int cnt = 0; // Contador para display.
  for (int i = uServo.read(); i >= POSICION_CENTRAL_USERVO; i--) {

    Display.setCursor(75+(cnt), 50);
    Display.println("-");
    Display.display();

    uServo.write(i);
    delay(70);
    cnt++;
  }
  Display.display();
  Display.fillRect(75, 50, 150, 7, BLACK);
  Display.display();
  delay(200);
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(75, 50);
  Display.println("Hecho");
  Display.display();
  Display.fillRect(105, 50, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, 50, 1, 7, BLACK);
  Display.display();
  delay(200);

  Display.clearDisplay();// Limpiando pantalla
  Display.display();
}

void loop() {

  if (BT.available()) {
    dato = BT.read();
  }

  switch (dato) {
    case 'R':
      digitalWrite(BUZZER, HIGH);
      break;
    case 'r':
      digitalWrite(BUZZER, LOW);
      break;
  }
}
