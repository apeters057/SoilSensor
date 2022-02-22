
// Documents/Arduino/test/Read_ADC
//AnthonyPeters
//Baseline code to read Adc from ESP-32 were using a capacitive Moisture Sensor here
//SetUp ADC GPIO Pin
const int moistPin = 39;
int percent = 0;
//Variable for storing Sensor Value

void setup() {
  Serial.begin(115200);
  delay(1000);
}

//Loop that outputs sensor values
//Create an algo that outputs values from 0 - 100 ( 100 = completley Wet , 0 = completley dry)
//Sensor ADC values ->[ 100 = 3300 (+- 10) , 0 = 1300 (+- 10) ]
//
void loop() {
  int Value  = analogRead(moistPin);
  float percent =( (((3500.0 / (Value) ) *100L) ) -100) ;
  Serial.println(percent, 3);
  delay(1000);
  }
    
