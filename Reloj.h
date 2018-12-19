//Importes para el ESP32
#include <WiFi.h>
#include <WiFiMulti.h>

//Mi Gestor de archivos
#include "utilsSPIFFS.h"
#define FORMAT_SPIFFS false
utilsSPIFFS uFileS;

//Archivo con la lista de Wifis
const String wifiFile = "/wifi_list.json";

//Iniciando wifiMulti
WiFiMulti wifiMulti;

//Mi gestor de Wifi
#include "MyWiFi.h"
MyWiFi myWiFi;

