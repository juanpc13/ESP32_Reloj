//Variables de Pines
const int pinSDA = 18;
const int pinSCL = 19;

#include <Wire.h>
#include "RTClib.h"
//#include "SSD1306Wire.h"
#include "SH1106.h" #include "SH1106Wire.h"
//SSD1306Wire  display(0x3c, pinSDA, pinSCL);
#include "OLEDDisplayUi.h"
SH1106Wire display(0x3c, pinSDA, pinSCL);
OLEDDisplayUi ui(&display);

DateTime now;
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

//Variables de timmer millis
unsigned long lastTime = 0;
unsigned long lastInactiveScreen = 0;

//Importando mis Herramientas
#include "libraries/luzUtil.h"
#include "libraries/myTools.h"
#include "libraries/touchUtils.h"
Luz luz(2);
MyTools mytools;
TouchUtils touch1(T8);
TouchUtils touch2(T9);
TouchUtils touch3(T6);
TouchUtils touch4(T5);


//Extra
RTC_DATA_ATTR int pushCount = 0;
int hallValue() {
  int h = 0;
  int cicles = 32;
  for (int i = 0 ; i < cicles; i++) {
    if (i == 0) {
      h = hallRead();
    } else {
      h += hallRead();
    }
  }
  h = int(h / float(cicles));
  return h;
}

int frameCount = 5;
int overlaysCount = 1;
#include "progmem/images.h"
#include "myFrames.h"
OverlayCallback overlays[] = {timeOverlay};
FrameCallback frames[] = {frameWatch, drawFrame2, drawFrame3, drawFrame4, drawFrame5};
