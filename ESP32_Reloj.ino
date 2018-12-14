#include "myGlobalObjects.h"

void setup() {
  Serial.begin(115200);
  Serial.println();
  uFileS.begin(formatSPIFFS);
  uJsonF.begin(uFileS);
  uJsonF.dataFileTarget(dataFilePath);
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  now = rtc.now();

  //Cargando el wifi actual y contraseña actual
  SSID = uJsonF.getJsonDataFileNamed("currentSSID");
  PASSWORD = uJsonF.getPasswordFromJsonFile(SSID);

  //Configuracion de mi interfaz en OLED
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
    touchAttachInterrupt(T5, callback, 50);
    esp_sleep_enable_touchpad_wakeup();
    esp_deep_sleep_start();
  }else{
    display.displayOn();
  }
}

void callback(){
  
}

void touchInLoop() {
  int sesibility = 50;
  int pressedDelay = 100;
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
  } else if (touchRead(T6) < sesibility) {
    if (millis() - lastTouch > pressedDelay) {
      lastTouch = millis();
      lastInactiveScreen = millis();
      pushCount++;
    }
  } else if (touchRead(T9) < sesibility) {
    if (millis() - lastTouch > pressedDelay) {
      lastTouch = millis();
      lastInactiveScreen = millis();
      now = rtc.now();
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute() + 1, now.second()));
    }
  } else {
    lastTouch = millis();
  }
}
