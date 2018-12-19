#include <ArduinoJson.h>
#include "SPIFFS.h"

#define FORMAT_SPIFFS_IF_FAILED true

class MyWiFi {
  private:
    String wFilePath;
    utilsSPIFFS _uFS;
  public:

    void setWifiFile(String _wFilePath) {
      wFilePath = _wFilePath;
    }

    void setFileSystem(utilsSPIFFS u) {
      _uFS = u;
    }

    bool begin() {
      //Convirtiendo archivo en JsonArray
      String json = _uFS.readFile(wFilePath);
      DynamicJsonDocument doc;
      deserializeJson(doc, json);

      JsonArray wifiList = doc.as<JsonArray>();
      for (JsonVariant wifi : wifiList) {
        if (wifi["password"].isNull()) {
          wifiMulti.addAP(wifi["ssid"].as<String>().c_str());
        } else {
          wifiMulti.addAP(wifi["ssid"].as<String>().c_str(), wifi["password"].as<String>().c_str());
        }
      }

      return true;
    }

};
