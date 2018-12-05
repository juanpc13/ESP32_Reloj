void dataFileTest() {
  String d = uFileS.readFile(dataFilePath);
  Serial.println(d);
}

void getJsonDataFileNamedTest() {
  String property = uJsonF.getJsonDataFileNamed("appName");
  Serial.println(property);

  if (property != "ESP32_Reloj") {
    Serial.println("getJsonDataFileNamedTest ERROR");
    return; //STOP
  }
  Serial.println("getJsonDataFileNamedTest PASS");
}

void getPasswordFromJsonFileTest() {
  String pass = uJsonF.getPasswordFromJsonFile("Esp32");
  if (pass != "") {
    Serial.println("");
    Serial.println("SSID Found");
    Serial.println(pass);
  } else {
    Serial.print("No Password for");
    Serial.println(" ESP32");
  }
}
