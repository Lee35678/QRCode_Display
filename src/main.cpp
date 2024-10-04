#include <Arduino.h>
#include <TFT_eSPI.h>
#include <qrcode_espi.h>

TFT_eSPI display = TFT_eSPI();
QRcode_eSPI qrcode (&display);

void setup() {
  display.begin();
  qrcode.init();
  //char msg[] = "Hello World!";
  //char msg[] = "https://google.com/";
  //char msg[] = "WIFI:S:YourAP;;;;";
  char msg[] = "WIFI:S:MyAP;T:WEP;P:youdonknow;;";
  qrcode.create(msg);
}

void loop() {
}