#include <ArduinoJson.h>
#include "SPIFFS.h"
#include <WiFiMulti.h>

#define wifiFile "/wifi_list.json"

class MyWiFi {
  private:
    String wFilePath = wifiFile;
    utilsSPIFFS *_uFS;
    WiFiMulti *_wifiMulti;
  public:

    MyWiFi(utilsSPIFFS *u, WiFiMulti *w) {
      _uFS = u;
      _wifiMulti = w;
    }

    void setWifiDataFile(String _wFilePath) {
      wFilePath = _wFilePath;
    }

    void setFileSystem(utilsSPIFFS *u) {
      _uFS = u;
    }

    void setWifiMulti(WiFiMulti *w) {
      _wifiMulti = w;
    }

    bool begin() {
      _uFS->begin(FORMAT_SPIFFS);
      
      File file = _uFS->file(wFilePath);
      DynamicJsonDocument doc;
      deserializeJson(doc, file);
      file.close();

      JsonArray wifiList = doc.as<JsonArray>();
      for (JsonVariant wifi : wifiList) {
        if (wifi["password"].isNull()) {
          _wifiMulti->addAP(wifi["ssid"].as<String>().c_str());
        } else {
          _wifiMulti->addAP(wifi["ssid"].as<String>().c_str(), wifi["password"].as<String>().c_str());
        }
      }

      return true;
    }

};
