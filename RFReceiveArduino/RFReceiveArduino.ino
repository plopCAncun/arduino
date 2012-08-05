#include <MANCHESTER.h>

void setup()
{
  // Set digital TX pin
  MANRX_SetRxPin(4);
  // Prepare interrupts
  MANRX_SetupReceive();
  // Begin receiving data
  MANRX_BeginReceive();
  
  Serial.begin(9600);
  Serial.println("Hello world !");
}

void loop()
{
  
  if (MANRX_ReceiveComplete())
  {
  unsigned int data = MANRX_GetMessage();
  MANRX_BeginReceive();
  Serial.println(data);
  }
}


