// NeoPixel Functions

void initNeopixels(){
  strip.begin();
  strip.clear();
  strip.show();
  strip.setBrightness(15);
}

//////////////////////////////////////////////
//RANDOM COLOR - MODE 1 //SEE NEOPIXEL TAB
//////////////////////////////////////////////
void randomColor(){
  int c = random(0,255);
  for (int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, Wheel(c));
  }
  strip.show();
  mode = -1;
}

void allLedsRandom(){
  for (int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, Wheel(random(1,255)));
  }
  strip.show();
  mode = -1;
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

//////////////////////////////////////////////
//RAINBOW - MODE 2
//////////////////////////////////////////////
// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  if (millis() - startRainbow >= wait) {
    for (long firstPixelHue = 0; firstPixelHue < 10 * 65536; firstPixelHue += 256) {
      checkButtons(); //SOLVE SETTIME ISSUE?
      strip.rainbow(firstPixelHue);
      strip.setPixelColor(12, yellow);
      strip.show(); // Update strip with new contents
      startRainbow = millis();
    }
  }
  strip.clear();
  strip.show();
  mode = -1;        //GO BACK TO SLEEP
}

/////////////////////////////////
//TEST CODE
/////////////////////////////////

void allNeopixels(int c){
  for (int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, Wheel(c));
  }
  strip.show();
  mode = -1;
}
