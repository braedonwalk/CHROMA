// CHROMA Code
// Braedon Walkenhorst

// States
#include <tinysnore.h>
int mode = -1;              //SET TO SPECIFIC MODES FOR TESTING - DEFAULT SHOULD BE -1

// Neopixels
#include <Adafruit_NeoPixel.h>
int npPixelCount = 13;
int pixelPin = 0;
Adafruit_NeoPixel strip(npPixelCount, pixelPin, NEO_GRB + NEO_KHZ800);

// Buttons
#include <Bounce2.h>
int buttonPins[] = {1, 2, 3};
Bounce * buttons = new Bounce[3];

// Time
long curHours = 0;
long curMinutes = 0;
long curSeconds = 0;

int setSeconds;
int setMinutes;
int setHours;

bool setTimeBool;

//Timer
unsigned long startTimer;
int timeInterval = 2000;
bool turnOnTimer = true;

//RAINBOW
unsigned long startRainbow;

/////////////////////
// COLORS
uint32_t red = strip.Color(255, 0, 0); //red
uint32_t redOrange = strip.Color(255, 69, 0); //red
uint32_t orange = strip.Color(255,120,0); //orange
uint32_t yellowOrange = strip.Color(255,180,0); //yellow orange
uint32_t yellow = strip.Color(255,255,0); //yellow
uint32_t yellowGreen = strip.Color(190,255,0); //yellow green

uint32_t green = strip.Color(0, 200, 0); //green
uint32_t lightBlue = strip.Color(0, 255, 255); //light blue
uint32_t blue = strip.Color(0, 0, 255); //blue
uint32_t purple = strip.Color(120, 0, 255); //purple
uint32_t pink = strip.Color(255, 0, 120); //pink

uint32_t white = strip.Color(255,255,255); //white


void setup() {
  initButtons();
  initNeopixels();
  randomSeed(analogRead(0));
}

void loop() {
  updateTime();
  updateButtons();
  checkButtons();
  
  switch (mode) {
    case -1: fallAsleep(); break;
    case 0: showTime(); break;
    case 1: randomColor(); break; //optional: allLedsRandom();
    case 2: rainbow(1000); break;   //rainbow(10);
    case 3: setTime(); break;     //setTime();
  }
  
  strip.show();
}
