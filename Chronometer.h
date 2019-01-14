class Chronometer {
  private:
    boolean _enable = false;
    unsigned long _chronoTime = 0;
    unsigned long _lastChronoTime = 0;

  public:

    Chronometer() {
    }

    void start() {
      _enable = true;
    }

    void stop() {
      _enable = false;
    }

    void restart() {
      _enable = false;
      _chronoTime = 0;
    }

    void Chronoloop() {
      if (_enable) {
        _chronoTime += millis() - _lastChronoTime;
      }
      _lastChronoTime = millis();
    }

    boolean isRunning() {
      return _enable;
    }

    float time() {
      return (_chronoTime / 1000.0);
    }

    String timeWatchFormat() {
      String s = "";
      int decisec = (int) (_chronoTime % 100);
      int seconds = (int) (_chronoTime / 1000) % 60 ;
      int minutes = (int) ((_chronoTime / (1000 * 60)) % 60);
      int hours   = (int) ((_chronoTime / (1000 * 60 * 60)) % 24);

      s += String(hours < 10 ? "0" : "") + hours;
      s += ":";

      s += String(minutes < 10 ? "0" : "") + minutes;
      s += ":";

      s += String(seconds < 10 ? "0" : "") + seconds;
      s += ":";

      s += String(decisec < 10 ? "0" : "") + decisec;

      return s;
    }

};
