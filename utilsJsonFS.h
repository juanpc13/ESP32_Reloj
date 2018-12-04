#include <ArduinoJson.h>

class utilsJsonFS {
  private:
    utilsSPIFFS _uFS;
    String _dataFilePath;
    String _wifiListFilePath;
  public:

    void begin(utilsSPIFFS u) {
      _uFS = u;
    }

    void dataFileTarget(String f) {
      _dataFilePath = f;
      if (!_uFS.fileExits(_dataFilePath)) {
        Serial.print("No File ");
        Serial.print(_dataFilePath);
        Serial.print(" Found...Creating....");

        StaticJsonBuffer<128> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

        root["appName"] = "ESP32_Reloj";
        root["currentIP"] = "";
        root["hostName"] = "";
        root["targetIP"] = "";
        root["portNumber"] = "80";
        root["time"] = "";
        root["date"] = "";
        root["currentSSID"] = "";

        String json = "";
        root.printTo(json);
        if (_uFS.writeFile(_dataFilePath, json)) {
          Serial.print("done");
        }
      } else {
        Serial.print("File ");
        Serial.print(_dataFilePath);
        Serial.print(" Found...Using File");
      }
      Serial.println();
    }

    void wifiListFileTarget(String f) {
      _wifiListFilePath = f;
      if (!_uFS.fileExits(_wifiListFilePath)) {
        Serial.print("No File ");
        Serial.print(_wifiListFilePath);
        Serial.print(" Found...Creating....");
        
        StaticJsonBuffer<32> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();
        root["ESP32"] = "87654321";

        String json = "";
        root.printTo(json);
        if (_uFS.writeFile(_wifiListFilePath, json)) {
          Serial.print("done");
        }        
      } else {
        Serial.print("File ");
        Serial.print(_wifiListFilePath);
        Serial.print(" Found...Using File");
      }
      Serial.println();
    }

    



};
