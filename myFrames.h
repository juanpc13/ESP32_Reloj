void timeOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  if (state->currentFrame != 0) {//Dont Show in Time Frame
    display->drawString(128, 0, mytools.nowStringTime(now));
  }
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

void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  if (touch2.isPressed()) {
    lastInactiveScreen = millis();
    pushCount--;
  }

  if (touch3.isPressed()) {
    lastInactiveScreen = millis();
    pushCount++;
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
  display->setFont(ArialMT_Plain_24);
  display->drawString(64 + x, 20 + y, String(pushCount));
}

void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  //Main Touch Control
  if (touch1.isPressed()) {
    lastInactiveScreen = millis();
    ui.previousFrame();
  }
  if (touch4.isPressed()) {
    lastInactiveScreen = millis();
    ui.nextFrame();
  }

  // Text alignment demo
  display->setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0 + x, 11 + y, "Left aligned (0,10)");

  // The coordinates define the center of the text
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(64 + x, 22 + y, "Center aligned (64,22)");

  // The coordinates define the right end of the text
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->drawString(128 + x, 33 + y, "Right aligned (128,33)");
}

void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

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
  display->drawString(64 + x, 4 + y, "Hall Sensor");
  display->setFont(ArialMT_Plain_24);
  display->drawString(64 + x, 20 + y, String(hallValue()));
}

void drawFrame5(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
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
