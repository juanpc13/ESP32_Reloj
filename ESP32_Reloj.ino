#include "utilsSPIFFS.h"
#include "utilsJsonFS.h"

utilsSPIFFS uFS;
String filePath = "/data.txt";
#define formatSPIFFS true

utilsJsonFS uJF;

void setup() {
  Serial.begin(115200);
  uFS.begin(formatSPIFFS);
  uJF.begin(uFS);
  uJF.fileTarget(filePath);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
