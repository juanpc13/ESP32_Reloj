#include "utilsSPIFFS.h"
#include "utilsJsonFS.h"

utilsSPIFFS uFileS;
utilsJsonFS uJsonF;

String dataFilePath = "/data.txt";
#define formatSPIFFS true //Formatear memoria antes de usar

void setup() {
  Serial.begin(115200);
  Serial.println();
  uFileS.begin(formatSPIFFS);
  uJsonF.begin(uFileS);
  uJsonF.dataFileTarget(dataFilePath);  

  //TEST
  dataFileTest();
  getJsonDataFileNamedTest();
  getPasswordFromJsonFileTest();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
