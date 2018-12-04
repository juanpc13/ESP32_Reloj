void dataFileTest(){
  String d = uFileS.readFile(dataFilePath);
  Serial.println(d);  
}

void wifiListFileTest(){
  String w = uFileS.readFile(wifiListFilePath);
  Serial.println(w);
}

void getJsonDataFileNamedTest(){
  String property = uJsonF.getJsonDataFileNamed("appName");
  Serial.println(property);

  if(property != "ESP32_Reloj"){
    Serial.println("getJsonDataFileNamedTest ERROR");
    return; //STOP
  }
  Serial.println("getJsonDataFileNamedTest PASS");
}

void getPasswordFromJsonFileTest(){
  String s = uJsonF.getPasswordFromJsonFile("ESP32");
  if(s!=""){
    Serial.println(s);    
  }else{
    Serial.print("No Password for");
    Serial.println(" ESP32");    
  }
}
