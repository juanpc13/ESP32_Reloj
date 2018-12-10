class MyTools {
  private:

  public:

    String nowStringDate(MyTimeDate mt) {
      //Add ZeroNoFill
      //Agregando dias con ceros si es menor a 10
      String fecha = (mt.day() < 10 ? "0" : "") + String(mt.day());
      //Agregando meses con ceros si es menor a 10
      fecha += "/" + String(mt.month() < 10 ? "0" : "") + String(mt.month());
      fecha += "/" + String(mt.year());
      return fecha;
    }

    String nowStringTime(MyTimeDate mt) {
      byte h = (mt.hour() > 12 ? (mt.hour() - 12) : mt.hour());
      h = (h == 0 ? 12 : h);

      byte m = mt.minute();
      byte s = mt.second();

      String hora = String(h < 10 ? "0" : "") + h;
      hora += String(s % 2 == 0 ? ":" : " ") + String(m < 10 ? "0" : "") + m;
      //hora += String(s % 2 == 0 ? ":" : " ") + String(s < 10 ? "0" : "") + s;

      return hora;
    }

    String nowStringSegundo(MyTimeDate mt) {
      byte s = mt.second();
      String seg = String(s % 2 == 0 ? ":" : " ") + String(s < 10 ? "0" : "") + s;
      seg += "\n " + nowAMorPM(mt);
      return seg;
    }
    String nowAMorPM(MyTimeDate mt) {
      return (mt.hour() < 12 ? "AM" : "PM");
    }
};
