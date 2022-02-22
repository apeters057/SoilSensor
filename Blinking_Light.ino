//Anthony Peters

//This program is to make the light blink every passing two seconds

//Initialize NeoPixel Constraints//
#include <Adafruit_NeoPixel.h>

#define PIN 15
#define NUMPIXELS 1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 150 ; //debounce & color wipe delay

/// Initialize ADC GPIO Pin & Variable for Storing Sensor Value ///
const int moistPin = 39;
int percent = 0;

// const values for NeoPIxel Color
int rVal = 0;
int bVal= 0;
int gVal = 0;
int x = 5;
void setup() {
pixels.begin(); //Initializes the NeoPixel library.
Serial.begin(115200); // Initialize ESP32
delay(1000);
}

void loop() {
  { 
    pixels.setPixelColor(0,pixels.Color(rVal, gVal, bVal));
    pixels.setBrightness(40);
    pixels.show();
    delay(delayval);
   }
    
  if (x <=15) { //Value is Very Dry
    Serial.println("Planat is dying RED");
    //Red Color
    rVal=0;
    gVal=0;
    bVal=0;
    delay(500);
    pixels.setPixelColor(0, 255 , 0 , 0);
    pixels.show();
    delay(1000);
   } 
  else {
    //do nothing
  }
}

  
