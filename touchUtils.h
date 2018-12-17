class TouchUtils {
  private:
    byte touchP;
    int sesibility = 40;
    int multiPushDelay = 50;
    unsigned long pressedTime = 0;
    boolean singlePush = true;
    boolean multiPush = true;
  public:
    TouchUtils(byte _touchP) {
      touchP = _touchP;
    }

    void update() {
      if (touchRead(touchP) >= sesibility) {
        pressedTime = millis();
        singlePush = true;
        multiPush = true;
      }
    }

    byte getTouchPin(){
      return touchP;
    }

    void setMultiPushDelay(int _multiPushDelay) {
      multiPushDelay = _multiPushDelay;
    }

    void setSesibility(int _sesibility) {
      sesibility = _sesibility;
    }

    boolean isPressed() {
      unsigned long delta = millis() - pressedTime;
      if (delta >= 100) {
        if (delta >= 600) { //Devolver multipush cada multiPushDelay
          delta = map(delta, 600, 600 + multiPushDelay, 0, 1);
          if (delta % 2 == 0) {
            if (multiPush) {
              multiPush = false;
              return true;
            }
          } else {
            multiPush = true;
          }
        } else { //Devolver un solo push
          if (singlePush) {
            singlePush = false;
            return true;
          }
        }
      }
      return false;
    }



};
