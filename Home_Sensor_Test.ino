/* HomeSpan Soil_Sensor_Test using relative humidity charactistic Example */

//wifi set up

#include "HomeSpan.h" // include the HomeSpan library
#include "DEV_Identify.h" 
#include "DEV_Sensors.h" //include Sensors Function



//Wifi Credentials and Home Kit code//
const char *ssid = "NETGEAR88";
const char *pwd = "curlysheep484";
const char *CODE = "11223345";
//Soil Sensor Constants

void setup(){
  Serial.begin(115200);
  pixels.begin();
  homeSpan.begin(Category::Sensors,"Anthony Plant Readings");
  
  new SpanAccessory();  
    new Dev_Identify("PapiSensor","APFactory","123-ABC","HS Bridge","1",3);
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
  new SpanAccessory();
    new Dev_Identify("PapiSoilSensor","ApFactory","123-ABC","Sensor","1",0);// Create a Humidity Sensor (see DEV_Sensors.h for definition)
    new Dev_Sensors();
}


void loop(){
 homeSpan.setWifiCredentials( ssid , pwd);
 homeSpan.setPairingCode(CODE) ;
 homeSpan.poll(); 
} // end of loop()
