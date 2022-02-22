//Loop to run for Blinking to happen

#include <Adafruit_NeoPixel.h>

#define PIN        15
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800)
//code
void NeoBlink(int num, int wait)
{
for (int i = 0; i < num; i++)
{
pixels.setPixelColor(i, 35, 35, 35);
}
pixels.show();
delay(wait);
for (int j = 0; j < num; j++)
{
pixels.setPixelColor(j, 0, 255, 0);
}
pixels.show();
delay(wait);
}
void setup()
{
pixels.begin();
pixels.setBrightness(50);
}
void loop()
{
NeoBlink(1, 500);
}
