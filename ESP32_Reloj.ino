#include "Reloj.h"

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 265520; ++i){
    dacWrite(25, undertaleMelody[i]);
    delayMicroseconds(38); // ((1/22050)*1000000) - 7
  }
}
