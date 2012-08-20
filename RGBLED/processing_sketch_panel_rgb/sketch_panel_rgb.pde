/**
 * Controller LED RGB
 */

import processing.serial.*;

Serial port;

void setup() {
  size(500, 550);
  noStroke();
 
  // Background
  colorMode(HSB, 500,300,100,100);
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 500; j++) {
      stroke(i, j, 500);
      point(i, j);
    }
  }
 
  // Select port
  println(Serial.list());
  port = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  // Only to enable the method mouseDragged
}

void mouseClicked() {
  processColor();
}

void mouseDragged() {
  processColor();
}

void processColor() {
  color c = get(mouseX, mouseY);
  noStroke();
  fill(c);
  rect(0, 500, 500, 50);
  sendColorToSerial(c);
}

void sendColorToSerial(color colour) {
  // Get HEX
  String hexColor = hex(colour, 6);
 
  // Convert HEX to Number
  long numColor = unhex(hexColor);
  // Send color number to serial port
  long redd =  numColor >> 16 & 0xFF;
  long greenn =  numColor >> 8 & 0xFF;
  long bluee =  numColor >> 0 & 0xFF;
  println(colour + " " + redd + " " + greenn + " " + bluee);
  port.write("^" + numColor + "$");
}
