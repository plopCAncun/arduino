#include <CapSense.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4);
/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapSense   cs_0_1 = CapSense(0,1);        // 10M resistor between pins 5 & 6, pin 6 is sensor pin, add a wire and or foil if desired
CapSense   cs_0_2 = CapSense(0,2);        // 10M resistor between pins 5 & 7, pin 7 is sensor pin, add a wire and or foil

void setup()                    
{
  cs_0_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_0_1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_0_1.capSense(50);
    long total2 =  cs_0_2.capSense(50);

    mySerial.print("test :");
    mySerial.print(millis() - start);        // check on performance in milliseconds
    mySerial.print("\t");                    // tab character for debug windown spacing

    mySerial.print(total1);                  // print sensor output 1
    mySerial.print("\t");
    mySerial.println(total2);                  // print sensor output 2


    delay(10);                             // arbitrary delay to limit data to serial port 
}

