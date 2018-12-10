#include "myTimeDate.h"
#include "utilsSPIFFS.h"
#include "utilsJsonFS.h"


utilsSPIFFS uFileS;
utilsJsonFS uJsonF;

String SSID = "";
String PASSWORD = "";
String dataFilePath = "/data.txt";
#define formatSPIFFS false //Formatear memoria antes de usar

void setup() {
  Serial.begin(115200);
  Serial.println();
  uFileS.begin(formatSPIFFS);
  uJsonF.begin(uFileS);
  uJsonF.dataFileTarget(dataFilePath);  
  
  //Cargando el wifi actual y contraseña actual
  SSID = uJsonF.getJsonDataFileNamed("currentSSID");
  PASSWORD = uJsonF.getPasswordFromJsonFile(SSID);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
