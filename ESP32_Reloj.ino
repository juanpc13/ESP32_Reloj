#include <Wire.h>
//#include "SSD1306Wire.h"
#include "SH1106Wire.h", legacy include: `#include "SH1106.h"`
#include "OLEDDisplayUi.h"
#include "RTClib.h"
#include "myTools.h"
#include "utilsSPIFFS.h"
#include "utilsJsonFS.h"
#include "images.h"
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
  int remainingTimeBudget = ui.update();  
}


void timingInLoop() {
  if (millis() - lastTime >= 1000) {
    lastTime =  millis();
    now = rtc.now();
  }
}

void touchInLoop() {
  int sesibility = 20;
  int pressedDelay = 100;
  if (touchRead(T6) < sesibility) {
    if(millis() - lastTouch > pressedDelay){
      lastTouch = millis();
      ui.nextFrame();
    }    
  } else if (touchRead(T9) < sesibility) {
    if(millis() - lastTouch > pressedDelay){
      lastTouch = millis();
      ui.previousFrame();
    }    
  }else if(touchRead(T5) < sesibility){
    if(millis() - lastTouch > pressedDelay){
      lastTouch = millis();
      pushCount++;
    }
  }else if(touchRead(T8) < sesibility){
    if(millis() - lastTouch > pressedDelay){
      lastTouch = millis();
      now = rtc.now();      
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute()+5, now.second()));
    }
  }else{
    lastTouch = millis();
  }
}
