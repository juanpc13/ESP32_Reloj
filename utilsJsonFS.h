#include <ArduinoJson.h>

class utilsJsonFS {
  private:
    utilsSPIFFS thisUFS;  
  public:
    
    void begin(utilsSPIFFS u){
      thisUFS = u;
    }

    
    
};
