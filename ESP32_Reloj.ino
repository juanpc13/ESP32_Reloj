#include <Wire.h>
#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"
#include "myTimeDate.h"
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

}
