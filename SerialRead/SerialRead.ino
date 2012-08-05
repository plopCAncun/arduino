void setup() {
  Serial.begin(9600);
}

void loop() {

  while(Serial.available()>0){
    char inByte = Serial.read();
      Serial.print((char)inByte);
  }
  //delay(100);        // delay in between reads for stability
}


