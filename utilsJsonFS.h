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

        StaticJsonDocument<128> doc;
        JsonObject root = doc.to<JsonObject>();

        root["appName"] = "ESP32_Reloj";
        root["currentIP"] = "";
        root["hostName"] = "";
        root["targetIP"] = "";
        root["portNumber"] = "80";
        root["time"] = "";
        root["date"] = "";
        root["currentSSID"] = "";

        String json = "";
        serializeJson(root, json);
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

        StaticJsonDocument<32> doc;        
        JsonArray wifiList = doc.to<JsonArray>();
        JsonObject wifi = wifiList.createNestedObject();
        wifi["ESP32"]="87654321";

        String json = "";
        serializeJson(wifiList, json);
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

    String getJsonDataFileNamed(String name) {
      if (_uFS.fileExits(_dataFilePath)) {
        String json = _uFS.readFile(_dataFilePath);
        StaticJsonDocument<128> doc;
        deserializeJson(doc, json);
        JsonObject object = doc.as<JsonObject>();
        return object[name];
      } else {
        Serial.println("File not Exits");
        return "";
      }
    }





};
