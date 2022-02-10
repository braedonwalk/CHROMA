// Button Functions

void initButtons() {
  for (int i = 0; i < 3; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);                //bounce delay in ms
  }
}

void updateButtons() {
  if (!setTimeBool) {       //IF THE SET TIME BOOLEAN IS NOT TRUE
    for (int i = 0; i < 3; i++)  {  //UPDATE BUTTONS
      buttons[i].update();
      if (buttons[i].rose()) {
        mode = i;
      }
      if (buttons[0].rose()) {
        turnOnTimer = false;                      //CHECK WHAT THE EXACT TIME WAS WHEN THE BUTTON WAS PRESSED
      }
      if (buttons[0].fell()) {
        turnOnTimer = true;
      }
      if (millis() - startTimer >= timeInterval) { //IF THE AMOUNT OF TIME PASSED SINCE BUTTON PRESS IS 2 SECONDS, CHANGE MODE
        setTimeBool = true;
        mode = 3;
      }
    }
  } else {                  //IF THE SET TIME BOOLEAN IS TRUE
    for (int i = 0; i < 3; i++)  {  //UPDATE BUTTONS
      buttons[i].update();
    }

    if (buttons[1].rose()) {      //IF THE SECOND BUTTON IS PRESSED, ADD ONE MINUTE
      setMinutes++;
    }
    else if (buttons[2].rose()) { //IF THE THIRD BUTTON IS PRESSED, ADD ONE HOUR
      setHours++;
    }
    else if (buttons[0].rose()) {
//      allNeopixels(45);
      mode = 0;
      setTimeBool = false;
      turnOnTimer = true;
    }
  }
}

void checkButtons() {       //CALLED ABOVE
  if (turnOnTimer) {        //CHECK WHAT THE EXACT TIME WAS WHEN THE BUTTON WAS PRESSED
    startTimer = millis();
  }
}
