

#include "omsg.h"
#include "hxbmp.h"
Adafruit_SSD1306 Display(4);  // pantalla

omsg::omsg() {}

void omsg::iniScreen() {
  // Inicializando la dirección i2c para la pantalla oled.
  Display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void omsg::cls() {
  Display.clearDisplay();
  Display.display();
}

void omsg::iniciando() {
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
}

void omsg::iniSp() {
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 20);
  Display.println("Abriendo SP: ");
  Display.display();

}

void omsg::iniEs() {
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 30);
  Display.println("Config  E/S: ");
  Display.display();
}

void omsg::iniSm() {
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 40);
  Display.println("Arranca  SM: ");
  Display.display();
}

void omsg::cenCm() {
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 50);
  Display.println("Centrand SM: ");
  Display.display();
}

void omsg::corazon() {
  Display.drawBitmap(32, 0,CORAZON_0 , 64, 64, 1);
  Display.display();
  delay(200);
  Display.drawBitmap(32, 0,CORAZON_1, 64, 64, 1);
  Display.display();
  delay(200);
  Display.drawBitmap(32, 0,CORAZON_2, 64, 64, 1);
  Display.display();
  delay(200);
  Display.drawBitmap(32, 0,CORAZON_3, 64, 64, 1);
  Display.display();
  delay(200);
  Display.clearDisplay();
  Display.display();
  Display.drawBitmap(0, 0,CORAZON_4, 128, 64, 1);
  Display.display();

  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(78, 52);
  Display.println("Online");
  Display.display();
  Display.fillRect(114, 52, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(114, 52, 1, 7, BLACK);
  Display.display();
  delay(200);
}

void omsg::progreso(int x_pos) {
  Display.setCursor(75 + x_pos, 50);
  Display.println("-");
  Display.display();
}

void omsg::hecho(int x_pos) {
  delay(200);
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(75, x_pos);
  Display.println("Hecho");
  Display.display();
  delay(100);
}

void omsg::hecho_cursor(int x_pos) {
  Display.display();
  Display.fillRect(75, x_pos, 150, 7, BLACK);
  Display.display();
  delay(200);
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(75, x_pos);
  Display.println("Hecho");
  Display.display();
  Display.fillRect(105, x_pos, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, BLACK);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, WHITE);
  Display.display();
  delay(200);
  Display.fillRect(105, x_pos, 1, 7, BLACK);
  Display.display();
  delay(200);
}

void omsg::dtBmsg() {
  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 20);
  Display.println("Hola Mundo");
  Display.display();
}

 void omsg::flechaA(){
   Display.drawBitmap(32, 0,FLECHA_ATRAS , 128, 64, 1);
   Display.display();
 }

 void omsg::drawInterfaz() {
   for (int i = 0; i < 160; i += 20) {
     // Horizontales.
     Display.fillRect(0, 1, i, 1, WHITE);
     Display.fillRect(0, 19, i, 1, WHITE);
     Display.fillRect(0, 63, i, 1, WHITE);

     // Verticales
     Display.fillRect(0, 1, 1, i, WHITE);
     Display.fillRect(127, 1, 1, i, WHITE);

     Display.display();
   }

 }

void omsg::cls_header() {
  Display.fillRect(10, 2, 100, 15, BLACK);
  Display.display();
}

void omsg::cls_body(){
  Display.fillRect(1, 20, 126, 43, BLACK);
  Display.display();
}

 void omsg::modoRemotoBT() {
   Display.setTextSize(2);
   Display.setTextColor(WHITE);
   Display.setCursor(27, 3);
   Display.println("BT MODE");
   Display.display();
 }

 void omsg::modoAutoBT() {
   Display.setTextSize(2);
   Display.setTextColor(WHITE);
   Display.setCursor(7, 3);
   Display.println(" BT AUTO");
   Display.display();
 }

 void omsg::modoAuto() {
   Display.setTextSize(2);
   Display.setTextColor(WHITE);
   Display.setCursor(7, 3);
   Display.println("   AUTO");
   Display.display();
 }

 void omsg::ready() {
   Display.setTextSize(2);
   Display.setTextColor(WHITE);
   Display.setCursor(7, 3);
   Display.println("  READY");
   Display.display();
 }

 void omsg::selectMode() {
   Display.setTextSize(2);
   Display.setTextColor(WHITE);
   Display.setCursor(3, 21);
   Display.println("Enter mode");
   Display.display();
 }
