#define LEDC_TIMER_13_BIT  13
#define LEDC_BASE_FREQ     5000
class Luz {
  private:
    byte pinLuz;
    byte brightness;
    byte LEDChannel;
    byte pinGround;
  public:
    Luz(byte _pinLuz) {
      pinLuz = _pinLuz;
    }

    void setPinGround(byte _pinGround) {
      pinGround = _pinGround;
      pinMode(pinGround, OUTPUT);
      digitalWrite(pinGround, 0);
    }

    void begin(byte _LEDChannel) {
      LEDChannel = _LEDChannel;
      ledcSetup(LEDChannel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
      ledcAttachPin(pinLuz, LEDChannel);
    }

    void on() {
      brightness = 255;
      ledcAnalogWrite(LEDChannel, brightness);
    }

    void off() {
      brightness = 0;
      ledcAnalogWrite(LEDChannel, brightness);
    }

    void setBrightness(byte _brightness) {
      brightness = _brightness;
      ledcAnalogWrite(LEDChannel, brightness);
    }

    byte getBrightness() {
      return brightness;
    }

    byte getBrightnessPorcent() {
      byte brightnessPorcent = map(brightness, 0, 255, 0, 100);
      return brightnessPorcent;
    }

    void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
      // calculate duty, 8191 from 2 ^ 13 - 1
      uint32_t duty = (8191 / valueMax) * min(value, valueMax);

      // write duty to LEDC
      ledcWrite(channel, duty);
    }



};
