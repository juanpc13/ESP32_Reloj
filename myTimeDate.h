class MyTimeDate {
  private:
    byte hora, minuto, segundo;
    byte dia, mes;
    int anio;
  public:

    void setTime(byte _hora, byte _minuto, byte _segundo) {
      hora = _hora;
      minuto = _minuto;
      segundo = _segundo;
    }

    void setDate(byte _dia, byte _mes, int _anio) {
      dia = _dia;
      mes = _mes;
      anio = _anio;
    }

    void setTimeDate(byte _hora, byte _minuto, byte _segundo, byte _dia, byte _mes, int _anio) {
      hora = _hora;
      minuto = _minuto;
      segundo = _segundo;
      dia = _dia;
      mes = _mes;
      anio = _anio;
    }

    void oneSecond() {
      segundo++;
      if (segundo >= 60) {
        segundo = 0;
        oneMinute();
      }
    }

    void oneMinute() {
      minuto++;
      if (minuto >= 60) {
        minuto = 0;
        hora++;
        if (hora >= 24) {
          hora = 0;
          oneDay();
        }
      }
    }

    void oneDay() {
      dia++;
      if (dia > daysOfMonth(mes)) {
        dia = 1;
        oneMont();
      }
    }

    void oneMont(){
      mes++;
        if (mes > 12) {
          mes = 1;
          oneYear();
        }
    }

    void oneYear(){
      anio++;
    }

    boolean isLeapYear(int year) {
      return ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    }

    byte daysOfMonth(byte month) {
      byte monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if (isLeapYear(anio)) {
        //Febrero bisiesto son 29 dias
        monthDays[1] = 29;
      }
      return monthDays[month - 1];
    }

    byte getHoras() {
      return hora;
    }

    byte hour() {
      return hora;
    }

    byte getMinutos() {
      return minuto;
    }

    byte minute() {
      return minuto;
    }

    byte getSegundo() {
      return segundo;
    }

    byte second() {
      return segundo;
    }

    byte getDia() {
      return dia;
    }

    byte day() {
      return dia;
    }

    byte getMes() {
      return dia;
    }

    byte month() {
      return mes;
    }

    int getAnio() {
      return anio;
    }

    int year() {
      return anio;
    }

};
