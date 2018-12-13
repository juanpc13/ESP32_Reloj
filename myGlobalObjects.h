//Manejadores de JSON
utilsSPIFFS uFileS;
utilsJsonFS uJsonF;

//Usando I2C de un DS1307
RTC_DS1307 rtc;
DateTime now;
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
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
String dataFilePath = "/data.txt";
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

//Varibles Objects
//SSD1306Wire  display(0x3c, pinSDA, pinSCL);
SH1106Wire display(0x3c, pinSDA, pinSCL);
OLEDDisplayUi ui(&display);

//Arrays of Frames and Overlay
int frameCount = 5;
int overlaysCount = 1;
#include "myFrames.h"
OverlayCallback overlays[] = {timeOverlay};
FrameCallback frames[] = {frameWatch, drawFrame2, drawFrame3, drawFrame4, drawFrame5};
