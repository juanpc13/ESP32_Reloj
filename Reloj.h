//Importes para el ESP32
#include <WiFi.h>

//Mi gestor de Wifi
#include "utilsSPIFFS.h"
#include "MyWiFi.h"
utilsSPIFFS uFileS;
WiFiMulti wifiMulti;
MyWiFi myWiFi(&uFileS, &wifiMulti);

