#include <ArduinoJson.h>

class utilsJsonFS {
  private:
    utilsSPIFFS thisUFS;  
    String _filePath;
  public:
    
    void begin(utilsSPIFFS u){
      thisUFS = u;
    }

    void fileTarget(String fPath){
      _filePath = fPath;      
    }

    

    

    
    
};
