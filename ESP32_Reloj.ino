#include "utilsSPIFFS.h"
#include "utilsJsonFS.h"

utilsSPIFFS uFileS;
String dataFilePath = "/data.txt";
String wifiListFilePath = "/wifilist.txt";
#define formatSPIFFS false

utilsJsonFS uJsonF;

void setup() {
  Serial.begin(115200);
  Serial.println();
  uFileS.begin(formatSPIFFS);
  uJsonF.begin(uFileS);
  uJsonF.dataFileTarget(dataFilePath);
  uJsonF.wifiListFileTarget(wifiListFilePath);

  //TEST
  getJsonDataFileNamedTest();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
