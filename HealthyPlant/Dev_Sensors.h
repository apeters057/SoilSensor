 /////////////////////////////////
 //   DEVICE-SPECIFIC SERVICES //
 ////////////////////////////////
//Anthony Peters
#include <Adafruit_NeoPixel.h>
#define PIN 15
#define NUMPIXELS 1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/// Initialize ADC GPIO Pin & Variable for Storing Sensor Value ///
const int moistPin = 39;
int percent = 0;
int delayval = 150 ; //debounce & color wipe delay
int rVal = 255;
int bVal= 255;
int gVal = 255;
int brightness = 50 ;



// A standalone Humidity sensor
 struct Dev_Sensors : Service::HumiditySensor {    
   SpanCharacteristic *Sensors;  // reference to the Current Humidity Characteristic                            
   Dev_Sensors() : Service::HumiditySensor() {      // constructor() method                     
     Sensors = new Characteristic::CurrentRelativeHumidity(); // instantiate the Current humidity Characteristic
     Sensors->setRange(0, 100); // expand the range to 0%-100%                           ​
                                // initialization message
     Serial.print("Configuring Humidity Sensor");          
     Serial.print("\n");
  } // end constructor ​


  
void loop() {
  
    { 
    pixels.setPixelColor(0,pixels.Color(rVal, gVal, bVal));
    pixels.show();
    delay(delayval);
}

     if (Sensors->timeVal() > 1000) {
       int Value  = analogRead(moistPin);
       float percent =( (((3500.0 / (Value) ) *100L) ) -100) ; 
       
       if (percent >=0) {
        Sensors->setVal(percent);
       }
       else if (percent < 0 ){
          Sensors->setVal(0);
       }
       
       if (percent <=15) { //Value is Very Dry
       //Serial.println("Planat is dying RED");
       //Red Color
       rVal=255;
       gVal=0;
       bVal=0;
       pixels.setBrightness(brightness);
    } 
      else if ( 50 >=percent && percent >= 16) {
      //Serial.println("Moisture is dry YELLOW"); 
      //Yellow Value
      rVal=240;
      gVal=120;
      bVal=0;
      pixels.setBrightness(brightness);
    }
      else if ( 75 >= percent && percent >= 51){
      //Serial.println("Moisture is Good GREEN");
      //Green Value
      rVal=0;
      gVal=255;
      bVal=0;
      pixels.setBrightness(brightness);
    }   
      else if ( percent >= 76 ) {
      //Serial.println("IM DROWNING BLUE");
      //Blue Value
      rVal=0;
      gVal=0;
      bVal=255;
      pixels.setBrightness(brightness);
    }
      else { 
      //do nuthin
    }                              
    }
  } // loop
 };
