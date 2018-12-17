#include "Reloj.h"

void setup() {
  // put your setup code here, to run once:

  //Luz
  luz.setPinGround(15);
  luz.begin(0);// FirstChannel is 0
  

  //Cargando el reloj
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  now = rtc.now();

  //Configuracion de mi interfaz UI
  ui.setTargetFPS(60);
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);
  ui.setIndicatorPosition(BOTTOM);
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setFrames(frames, frameCount);
  ui.setOverlays(overlays, overlaysCount);
  ui.disableAutoTransition();
  ui.init();
  display.flipScreenVertically();

}

void loop() {
  // put your main code here, to run repeatedly:
  timingInLoop();
  touchInLoop();
  inactiveScreen();
  int remainingTimeBudget = ui.update();  
}

void timingInLoop() {
  if (millis() - lastTime >= 1000) {
    lastTime =  millis();
    now = rtc.now();
  }
}

void inactiveScreen() {
  int inactiveTime = 10000;
  if (millis() - lastInactiveScreen > inactiveTime) {
    display.displayOff();
    touchAttachInterrupt(touch4.getTouchPin(), callback, 40);
    esp_sleep_enable_touchpad_wakeup();
    esp_deep_sleep_start();
  } else {
    display.displayOn();
  }
}

void callback() {

}

void touchInLoop() {
  touch1.update();
  touch4.update();

  if (touch1.isPressed()) {
    lastInactiveScreen = millis();
    ui.previousFrame();
  }  

  if (touch4.isPressed()) {
    lastInactiveScreen = millis();
    ui.nextFrame();
  }
  
}
