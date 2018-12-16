#include "Reloj.h"

void setup() {
  // put your setup code here, to run once:

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
    touchAttachInterrupt(T5, callback, 40);
    esp_sleep_enable_touchpad_wakeup();
    esp_deep_sleep_start();
  } else {
    display.displayOn();
  }
}

void callback() {

}

void touchInLoop() {
  byte sesibility = 40;
  int pressedDelay = 100;
  touch1.update();

  if (touch1.isPressed()) {
    lastInactiveScreen = millis();
    pushCount++;
  }


  if (touchRead(T5) < sesibility) {
    if (millis() - lastTouch > pressedDelay) {
      lastTouch = millis();
      lastInactiveScreen = millis();
      ui.nextFrame();
    }
  } else if (touchRead(T8) < sesibility) {
    if (millis() - lastTouch > pressedDelay) {
      lastTouch = millis();
      lastInactiveScreen = millis();
      ui.previousFrame();
    }
  } else {
    lastTouch = millis();
  }
}
