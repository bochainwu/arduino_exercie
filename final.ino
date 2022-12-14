#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10,11,12,13};
  byte segmentPins[] = {9,2,3,5,6,8,7,4};
  pinMode(A0,OUTPUT);

  bool resistorsOnSegments = true;
  //bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);       
}

void loop() {
  // put your main code here, to run repeatedly:
  //long a =  random(1,1000);
  int a = analogRead(A0);
  for(int i=0;i<10000;i++){
    sevseg.setNumber(a, 0);
    sevseg.refreshDisplay();
  }
}
