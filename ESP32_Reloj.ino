#include "Reloj.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  myWiFi.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Millis=");
    Serial.println(millis());
  } else {
    Serial.println("No Conected");
    Serial.print("Millis=");
    Serial.println(millis());
  }
  delay(1000);
}
