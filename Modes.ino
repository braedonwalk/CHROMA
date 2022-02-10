// Modes

long sleepTimer = 0;
long sleepInterval = 7000;

void fallAsleep() {
  if (millis() - sleepTimer > sleepInterval) {
    strip.clear(); strip.show();  // Clear out NeoPixel Display
    snore(5000);                 // Go to Sleep for 5 Seconds
    sleepTimer = millis();
    setSeconds += 5;
  }
}

void updateTime() {
    curSeconds = (millis() / 1000) + setSeconds;
    curMinutes = (curSeconds / 60) + setMinutes;
    curHours = (curMinutes / 60) + setHours;
}
//////////////////////////////////////////////
//SHOW TIME - MODE 0
//////////////////////////////////////////////

void showTime() {
  strip.clear();
  strip.show();

  //TURN ON THE 5 MINUTE LED WHEN THE MINUTE IS BETWEEN 5 AND 10
  if (curMinutes % 60 >= 5 && curMinutes % 60 < 10) {
    strip.setPixelColor(0, white);
  }
  else if (curMinutes % 60 >= 15 && curMinutes % 60 < 20) {
    strip.setPixelColor(0, white);
  }
  if (curMinutes % 60 >= 25 && curMinutes % 60 < 30) {
    strip.setPixelColor(0, white);
  }
  if (curMinutes % 60 >= 35 && curMinutes % 60 < 40) {
    strip.setPixelColor(0, white);
  }
  if (curMinutes % 60 >= 45 && curMinutes % 60 < 50) {
    strip.setPixelColor(0, white);
  }
  if (curMinutes % 60 >= 55 && curMinutes % 60 <= 59) {
    strip.setPixelColor(0, white);
  }

  //TURN ON THE 10 MINUTE LEDS
  if (curMinutes % 60 >= 10 && curMinutes % 60 < 60) {
    strip.setPixelColor(1, green);  //10 MINUTES
  }
  if (curMinutes % 60 >= 20 && curMinutes % 60 < 60) {
    strip.setPixelColor(2, lightBlue);  //20 MINUTES
  }
  if (curMinutes % 60 >= 30 && curMinutes % 60 < 60) {
    strip.setPixelColor(3, blue);  //30 MINUTES
  }
  if (curMinutes % 60 >= 40 && curMinutes % 60 < 60) {
    strip.setPixelColor(4, purple);  //40 MINUTES
  }
  if (curMinutes % 60 >= 50 && curMinutes % 60 < 60) {
    strip.setPixelColor(5, pink);  //50 MINUTES
  }

  //TURN ON THE HOUR LEDS
  if (curHours % 2 == 1) {      //light up led 13 when the hour is an odd number
    strip.setPixelColor(12, yellow);
  }

  if (curHours % 12 >= 2 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 2 or 12, light up
    strip.setPixelColor(11, red);
  }
  if (curHours % 12 >= 4 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 4 or 12, light up
    strip.setPixelColor(10, redOrange);
  }
  if (curHours % 12 >= 6 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 6 or 12, light up
    strip.setPixelColor(9, orange);
  }
  if (curHours % 12 >= 8 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 8 or 12, light up
    strip.setPixelColor(8, yellowOrange);
  }
  if (curHours % 12 >= 10 && curHours % 12 <= 12 || curHours % 12 == 0) { //if it is 10 or 12, light up
    strip.setPixelColor(7, yellow);
  }
  if (curHours % 12 == 0) {
    strip.setPixelColor(6, yellowGreen);  //if it is 12, light up
  }

  strip.show();
  mode = -1;        //GO BACK TO SLEEP
}

//////////////////////////////////////////////
//SET TIME - MODE 3
//////////////////////////////////////////////

void setTime() {
  if (setTimeBool) {
    strip.clear();
    strip.show();

    //TURN ON THE 5 MINUTE LED WHEN THE MINUTE IS BETWEEN 5 AND 10
    if (curMinutes % 60 >= 5 && curMinutes % 60 < 10) {
      strip.setPixelColor(0, white);
    }
    else if (curMinutes % 60 >= 15 && curMinutes % 60 < 20) {
      strip.setPixelColor(0, white);
    }
    if (curMinutes % 60 >= 25 && curMinutes % 60 < 30) {
      strip.setPixelColor(0, white);
    }
    if (curMinutes % 60 >= 35 && curMinutes % 60 < 40) {
      strip.setPixelColor(0, white);
    }
    if (curMinutes % 60 >= 45 && curMinutes % 60 < 50) {
      strip.setPixelColor(0, white);
    }
    if (curMinutes % 60 >= 55 && curMinutes % 60 <= 59) {
      strip.setPixelColor(0, white);
    }

    //TURN ON THE 10 MINUTE LEDS
    if (curMinutes % 60 >= 10 && curMinutes % 60 < 60) {
      strip.setPixelColor(1, white);  //10 MINUTES
    }
    if (curMinutes % 60 >= 20 && curMinutes % 60 < 60) {
      strip.setPixelColor(2, white);  //20 MINUTES
    }
    if (curMinutes % 60 >= 30 && curMinutes % 60 < 60) {
      strip.setPixelColor(3, white);  //30 MINUTES
    }
    if (curMinutes % 60 >= 40 && curMinutes % 60 < 60) {
      strip.setPixelColor(4, white);  //40 MINUTES
    }
    if (curMinutes % 60 >= 50 && curMinutes % 60 < 60) {
      strip.setPixelColor(5, white);  //50 MINUTES
    }

    //TURN ON THE HOUR LEDS
    if (curHours % 2 == 1) {      //light up led 13 when the hour is an odd number
      strip.setPixelColor(12, white);
    }

    if (curHours % 12 >= 2 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 2 or 12, light up
      strip.setPixelColor(11, white);
    }
    if (curHours % 12 >= 4 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 4 or 12, light up
      strip.setPixelColor(10, white);
    }
    if (curHours % 12 >= 6 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 6 or 12, light up
      strip.setPixelColor(9, white);
    }
    if (curHours % 12 >= 8 && curHours % 12 <= 12 || curHours % 12 == 0) {  //if it is 8 or 12, light up
      strip.setPixelColor(8, white);
    }
    if (curHours % 12 >= 10 && curHours % 12 <= 12 || curHours % 12 == 0) { //if it is 10 or 12, light up
      strip.setPixelColor(7, white);
    }
    if (curHours % 12 == 0) {
      strip.setPixelColor(6, white);  //if it is 12, light up
    }
    strip.show();
  }
}
