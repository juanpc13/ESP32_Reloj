#include "Reloj.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  myWiFi.begin();
  xTaskCreatePinnedToCore(coreCeroLoop, "coreCeroLoop", 1000, NULL, 1, &taskCore0, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  wifiMulti.run();  
}

void coreCeroLoop( void * parameter ) {
  // put your main code here, to run repeatedly:
  while (true) {
    Serial.println("WiFi connected"); Serial.println("IP address: "); Serial.println(WiFi.localIP());
  }
}
