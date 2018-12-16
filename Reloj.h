//Variables de Pines
const int pinSDA = 18;
const int pinSCL = 19;

//Añadiendo Libreria I2C
#include <Wire.h>

//Libreria de reloj DS1307
#include "RTClib.h"
DateTime now;
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

//Libreria de pantalla Oled
//#include "SSD1306Wire.h"
#include "SH1106Wire.h", legacy include: `#include "SH1106.h"`
//SSD1306Wire  display(0x3c, pinSDA, pinSCL);
SH1106Wire display(0x3c, pinSDA, pinSCL);

//Libreria de Interfaz UI
#include "OLEDDisplayUi.h"
OLEDDisplayUi ui(&display);