//Manejadores de JSON
#include "utilsSPIFFS.h"
utilsSPIFFS uFileS;
#include "utilsJsonFS.h"
utilsJsonFS uJsonF;

//Usando I2C de un DS1307
#include "RTClib.h"
DateTime now;
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

//Tool para convertir las fechas
#include "myTools.h"
MyTools mytools;

//Variables del WIFI
String SSID = "";
String PASSWORD = "";

//Varibleas Constantes
const int pinSDA = 18;
const int pinSCL = 19;

//Variables de timmer millis
unsigned long lastTime = 0;
unsigned long lastTouch = 0;
unsigned long lastInactiveScreen = 0;

//Variables de Configuracion
String dataFilePath = "/data.json";
#define formatSPIFFS false //Formatear memoria antes de usar

//Extra
int pushCount = 0;
int hallValue() {
  int h = 0;
  int cicles = 32;
  for (int i = 0 ; i < cicles; i++) {
    if(i == 0){
      h = hallRead();
    }else{
      h += hallRead();
    }
  }
  h = int(h / float(cicles));
  return h;
}

//Pantalla OLED Importes
#include <Wire.h>
//#include "SSD1306Wire.h"
#include "SH1106Wire.h", legacy include: `#include "SH1106.h"`
#include "OLEDDisplayUi.h"
//SSD1306Wire  display(0x3c, pinSDA, pinSCL);
SH1106Wire display(0x3c, pinSDA, pinSCL);
OLEDDisplayUi ui(&display);

//Arrays of Frames and Overlay
int frameCount = 5;
int overlaysCount = 1;
#include "images.h"
#include "myFrames.h"
OverlayCallback overlays[] = {timeOverlay};
FrameCallback frames[] = {frameWatch, drawFrame2, drawFrame3, drawFrame4, drawFrame5};
