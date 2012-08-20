/**
 * Controller LED RGB
 *
 * @author  Bruno Soares
 * @website www.bsoares.com.br
 */

#define START_COLOR_CHAR '^'
#define END_COLOR_CHAR '$'
#define COLOR_SIZE 8
#define PIN_RED 6
#define PIN_GREEN 3
#define PIN_BLUE 5

char serialMessage[COLOR_SIZE];
unsigned int readChar;
unsigned int count;
unsigned long color;
unsigned int r;
unsigned int g;
unsigned int b;
boolean readingSerial;

void setup() {
  Serial.begin(9600);
  readingSerial = false;
}

void loop() {
  if (Serial.available() > 0 && !readingSerial) {
    if (Serial.read() == START_COLOR_CHAR) {
      serialReadColor();
    }
  }
}

void serialReadColor() {
  readingSerial = true;
  count = 0;
 
  iniReading:
  if (Serial.available() > 0) {
    readChar = Serial.read();
    if (readChar == END_COLOR_CHAR || count == COLOR_SIZE) {
      goto endReading;
    } else {
      serialMessage[count++] = readChar;
      goto iniReading;
    }
  }
  goto iniReading;
 
  endReading:
  readingSerial = false;
  serialMessage[count] = '\0';
 
  setColor(serialMessage);
}

void setColor(char* value)
{
  // Convert Char* to Long
  color = atol(value);
 
  // Extract RGB
  r = color >> 16 & 0xFF;
  g = color >>  8 & 0xFF;
  b = color >>  0 & 0xFF;
 
  // Send values to analog pins
  analogWrite(PIN_RED, 255- r);
  analogWrite(PIN_GREEN, 255- g);
  analogWrite(PIN_BLUE, 255- b);
}
