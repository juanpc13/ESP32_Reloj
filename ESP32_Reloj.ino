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

  //Funcion
  String d = uFileS.readFile(dataFilePath);
  String w = uFileS.readFile(wifiListFilePath);

  Serial.println(d);
  Serial.println(w);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
