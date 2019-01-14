void timeOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  if (state->currentFrame != 1) {//Dont Show in Time Frame
    display->drawString(128, 0, mytools.nowStringTime(now));
  }
}

void chronometerFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  //Evitar que se apague la pantalla
  lastInactiveScreen = millis();

  //Iniciar Cronometro
  if (touch2.isPressed()) {
    cronometro.start();
  }else if(touch2.longPress(1000)){
    cronometro.restart();
  }

  //Aumentar la intensidad
  if (touch3.isPressed()) {
    if(cronometro.isRunning()){
      cronometro.stop();
    }else{
      cronometro.start();
    }
  }

  //Main Touch Control
  if (touch1.isPressed()) {
    lastInactiveScreen = millis();
    ui.previousFrame();
  }
  if (touch4.isPressed()) {
    lastInactiveScreen = millis();
    ui.nextFrame();
  }

  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 4 + y, "Cronometro");
  display->setFont(ArialMT_Plain_24);
  display->drawString(64 + x, 20 + y, cronometro.timeWatchFormat());

}

void frameWatch(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  //Editar la Fecha y Hora
  if (touch3.isPressed()) {
    lastInactiveScreen = millis();
    int m = now.minute();
    int h = now.hour();
    m++;
    if (m > 59) {
      m = 0;
      h++;
      if (h > 23) {
        h = 0;
      }
    }
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), h, m, now.second()));
    now = rtc.now();
  }

  if (touch2.isPressed()) {
    lastInactiveScreen = millis();
    int m = now.minute();
    int h = now.hour();
    m--;
    if (m < 0) {
      m = 59;
      h--;
      if (h < 0) {
        h = 23;
      }
    }
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), h, m, now.second()));
    now = rtc.now();
  }

  //Main Touch Control
  if (touch1.isPressed()) {
    lastInactiveScreen = millis();
    ui.previousFrame();
  }
  if (touch4.isPressed()) {
    lastInactiveScreen = millis();
    ui.nextFrame();
  }


  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 0 + y, mytools.nowStringDate(now));

  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_24);
  display->drawString(56 + x, 18 + y, mytools.nowStringTime(now));

  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(98 + x, 18 + y, mytools.nowStringSegundo(now));
}

void lightFrame(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  //Evitar que se apague la pantalla
  lastInactiveScreen = millis();

  //Cambiar de encendido a apagado y viceversa
  if (touch2.isPressed()) {
    if (luz.getBrightness() == 0) {
      luz.on();
    } else {
      luz.off();
    }
  }

  //Aumentar la intensidad
  if (touch3.isPressed()) {
    luz.setBrightness(constrain(luz.getBrightness() + 3, 0, 255));
  }

  //Main Touch Control
  if (touch1.isPressed()) {
    lastInactiveScreen = millis();
    ui.previousFrame();
  }
  if (touch4.isPressed()) {
    lastInactiveScreen = millis();
    ui.nextFrame();
  }

  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64 + x, 4 + y, "Luz");
  display->setFont(ArialMT_Plain_24);
  display->drawString(64 + x, 20 + y, String(luz.getBrightnessPorcent()) + "%");

}
