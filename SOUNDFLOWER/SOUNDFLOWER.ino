#include "secrets.h"
AdafruitIO_Feed *words = io.feed("project1.yellow-soundflower", "jubnuggets");

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int lastVolt;
 
void setup() 
{
   Serial.begin(115200);

   //while(! Serial);

   Serial.print("Connecting to Adafruit IO");

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}
 
 
void loop() 
{
  io.run();

  unsigned long startMillis= millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
 
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
 
   // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
   
   if (volts != lastVolt){
    lastVolt = volts;
    if (volts > 10){
      volts = 0;
    }
    Serial.println(volts);
    words -> save(volts);
    //delay(2000);
   }
}
