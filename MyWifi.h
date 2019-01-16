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

    void addWifi(String ssid, String password) {

      File file = _uFS->file(wFilePath);
      DynamicJsonDocument doc;
      deserializeJson(doc, file);

      JsonArray wifiList = doc.as<JsonArray>();
      JsonObject wifi = wifiList.createNestedObject();

      wifi["ssid"] = ssid;
      if (password == "") {
        _wifiMulti->addAP(ssid.c_str());
      } else {
        wifi["password"] = password;
        _wifiMulti->addAP(ssid.c_str(), password.c_str());
      }

      file.close();
      file = SPIFFS.open(wFilePath, FILE_WRITE);
      if (serializeJsonPretty(doc, file) == 0) {
        Serial.println("Failed to write to file");
      } else {
        Serial.println("Wifi Added");
      }
      file.close();

    }

    void deleteWifi(String ssid) {
      boolean found = false;
      File file = _uFS->file(wFilePath);
      DynamicJsonDocument doc;
      deserializeJson(doc, file);

      JsonArray wifiList = doc.as<JsonArray>();
      int i = 0;
      for (JsonVariant wifi : wifiList) {
        if (wifi.as<JsonObject>().get("ssid") == ssid) {
          found = true;
          wifiList.remove(i);
          Serial.println("SSID Found");
          break;
        }
        i++;
      }

      if (found) {
        file.close();
        file = SPIFFS.open(wFilePath, FILE_WRITE);
        if (serializeJsonPretty(doc, file) == 0) {
          Serial.println("Failed to write to file");
        } else {
          Serial.println("Erase Done");
        }
      } else {
        Serial.println("No ssid found");
      }
      file.close();

    }

    String showWifiList() {
      String s = "";
      s = _uFS->readFile(wFilePath);
      return s;
    }

};
