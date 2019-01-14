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
#include "Chronometer.h"
#include "libraries/luzUtil.h"
#include "libraries/myTools.h"
#include "libraries/touchUtils.h"
Luz luz(2);
Chronometer cronometro;
MyTools mytools;
TouchUtils touch1(T8);
TouchUtils touch2(T9);
TouchUtils touch3(T6);
TouchUtils touch4(T5);

int frameCount = 3;
int overlaysCount = 1;
#include "progmem/images.h"
#include "myFrames.h"
OverlayCallback overlays[] = {timeOverlay};
FrameCallback frames[] = {chronometerFrame, frameWatch, lightFrame};
