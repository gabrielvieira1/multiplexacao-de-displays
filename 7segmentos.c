/*
 Copyright 2017 Dean Reading
 https://blog.moduloeletronica.com.br/display-7-segmentos-multiplexado-arduino/
 
 https://www.tinkercad.com/things/aTuHLTppoHv
 */
  
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
 
void setup() {
   
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_CATHODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;
  bool disableDecPoint = true;
   
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(85);
}
 
void loop() {
   
  static unsigned long tempo = millis();
  static int contador = 0;
   
  if (millis() - timer >= 500) {
    timer += 500;
    contador++; 
     
    if (contador == 8888) {
      contador=0;
    }
    sevseg.setNumber(contador, 1);
  }
 
  sevseg.refreshDisplay();
}