#include <ArduinoJson.h>

class utilsJsonFS {
  private:
    utilsSPIFFS _uFS;
    String _dataFilePath;
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

        DynamicJsonDocument doc;
        JsonObject root = doc.to<JsonObject>();

        root["appName"] = "ESP32_Reloj";
        root["currentIP"] = "";
        root["hostName"] = "";
        root["targetIP"] = "";
        root["portNumber"] = "80";
        root["time"] = "";
        root["date"] = "";
        root["currentSSID"] = "";

        JsonArray wifiList = root.createNestedArray("wifiList");
        JsonObject wifi = wifiList.createNestedObject();
        wifi["ssid"] = "Esp32";
        wifi["password"] = "87654321";

        String json = "";
        serializeJson(root, json);
        //serializeJsonPretty(root, json);
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


    String getJsonDataFileNamed(String name) {
      if (_uFS.fileExits(_dataFilePath)) {
        String json = _uFS.readFile(_dataFilePath);
        DynamicJsonDocument doc;
        deserializeJson(doc, json);
        JsonObject object = doc.as<JsonObject>();
        JsonVariant property = object.get(name);
        return property.as<String>();
      } else {
        Serial.println("File not Exits");
        return "";
      }
    }

    void editJsonDataFileNamed(String name, String value) {
      if (_uFS.fileExits(_dataFilePath)) {
        String json = _uFS.readFile(_dataFilePath);
        DynamicJsonDocument doc;
        deserializeJson(doc, json);
        JsonObject root = doc.as<JsonObject>();
        JsonVariant property = root.get(name);
        if (!property.isNull()) {
          property.set(value);
          json = "";
          serializeJson(root, json);
          //serializeJsonPretty(root, json);
          if (_uFS.writeFile(_dataFilePath, json)) {
            Serial.print("done");
          }
        }else{
          Serial.print("property to edit not found");
        }
      } else {
        Serial.println("File not Exits");
      }
    }

    String getPasswordFromJsonFile(String wifiName) {
      if (_uFS.fileExits(_dataFilePath)) {
        String json = getJsonDataFileNamed("wifiList");
        DynamicJsonDocument doc;
        deserializeJson(doc, json);

        // extract the values
        JsonArray array = doc.as<JsonArray>();
        for (JsonVariant v : array) {
          String wifiJson = v.as<String>();
          StaticJsonDocument<64> w;
          deserializeJson(w, wifiJson);
          JsonObject wifi = w.as<JsonObject>();
          JsonVariant ssid = wifi.get("ssid");
          JsonVariant password = wifi.get("password");

          if (!ssid.isNull() && !password.isNull()) {
            if (ssid.as<String>() == wifiName) {
              return password.as<String>();
            }
          }
        }
      } else {
        Serial.println("File not Exits");
      }
      return "";
    }

    void addWifiJsonFile(String ssid, String password){
      if (_uFS.fileExits(_dataFilePath)) {
        String json = getJsonDataFileNamed("wifiList");
        DynamicJsonDocument doc;
        deserializeJson(doc, json);

        // extract the values
        JsonArray wifiList = doc.as<JsonArray>();
        JsonObject wifi = wifiList.createNestedObject();
        wifi["ssid"] = ssid;
        wifi["password"] = password;

        json = "";
        serializeJson(wifiList, json);
        editJsonDataFileNamed("wifiList",json);
      }else{
        Serial.println("File not Exits");
      }
    }





};
