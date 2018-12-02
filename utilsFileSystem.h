#include "FS.h"
#include "SPIFFS.h"

#define FORMAT_SPIFFS_IF_FAILED true

class utilsFileSystem {
  private:
  public:

    utilsFileSystem(){
      SPIFFS.begin();
    }

    String readFile(String path) {
      String dataText = "";
      File file = SPIFFS.open(path);
      if (!file || file.isDirectory()) {
        Serial.println("- failed to open file for reading");
        return dataText;
      }
      //Storing to dataText
      while (file.available()) {
        char c = file.read();
        dataText += dataText + c;
      }
      return dataText;
    }

};
