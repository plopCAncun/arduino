#include <MANCHESTER.h>

void setup() 
{  
  MANCHESTER.SetTxPin(4);
  MANCHESTER.SetTimeOut(1000);
}

void loop()
{
 unsigned int data = 1234;
 MANCHESTER.Transmit(data); 
}
