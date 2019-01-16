#include "Reloj.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  myWiFi.begin();

  Serial.println("Wifi Manager use: \n(addWifi ssidName,passWord)\n(delWifi ssidName)\n(showWifiList)");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String s = Serial.readString();

    if (s.length() > 8) {

      if (s.substring(0, 7) == "addWifi") {

        myWiFi.addWifi(s.substring(8, s.indexOf(",")), s.substring(s.indexOf(",") + 1));

      } else if (s.substring(0, 7) == "delWifi") {

        myWiFi.deleteWifi(s.substring(8));

      } else if (s.substring(0, 12) == "showWifiList") {

        Serial.println(myWiFi.showWifiList());

      }

    }

  }

  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("WiFi connected"); Serial.println("IP address: "); Serial.println(WiFi.localIP());
    Serial.print("Millis="); Serial.println(millis());
  } else {
    Serial.println("No Conected");
    Serial.print("Millis="); Serial.println(millis());
  }




}
