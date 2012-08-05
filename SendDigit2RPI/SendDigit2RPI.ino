// Send a digit to RPI GPIO via capsense


#define SIGNALPIN 7
#include <CapSense.h>

CapSense   cs_4_2 = CapSense(4,2);        // 1M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapSense   cs_4_6 = CapSense(4,6);        // 5M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapSense   cs_4_8 = CapSense(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

int prev3 = 0;

void setup()
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
  pinMode(SIGNALPIN,OUTPUT); 
}

void loop()
{
  long start = millis();
  long total1 =  cs_4_2.capSense(30);
  long total2 =  cs_4_6.capSense(30);
  long total3 =  cs_4_8.capSense(30);
  
  //Serial.print(millis() - start);        // check on performance in milliseconds
  //Serial.print("\t");                    // tab character for debug windown spacing
  //Serial.print(total1);                  // print sensor output 1
  //Serial.print("\t");
  //Serial.print(total2);                  // print sensor output 2
  //Serial.print("\t");
  Serial.println(total3);                // print sensor output 3

  delay(10);                             // arbitrary delay to limit data to serial port 
  if ( total3 > 500 && prev3 == 0 )
  { 
    digitalWrite(SIGNALPIN,HIGH);
    prev3 = 1;
    delay(500);
  }
  else if ( total3 < 500 && prev3 == 1)
  {
    digitalWrite(SIGNALPIN,LOW);
    prev3 = 0;
    delay(500);
  }
}
