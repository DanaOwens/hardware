/*
This code helps with distance detection using a MaxSonar ultrasonic rangefinder
A library is available at: https://github.com/Diaoul/arduino-Maxbotix
This code's original author belongs to Bruce Allen

Date: October 18, 2020
*/

// This code will use the PulseWidth (PW) to detect range

// Use digital pin 7 to read PW from the device. Pin number does not change in this code
const int pwPin = 7;

// Store calculated value
long pW, inches, cm, meters; 

void setup() {
  // Creates serial connection to send results back to PC Console 
  Serial.begin(9600);
}

void loop() {
  pinMode(pwPin, INPUT);
  
  // Read pulse sent by device
  // Conversion for PW: 147 uS per Inch
  
  pW = pulseIn(pwPin, HIGH);
  // Convert to appropriate units
  
  inches = pW/147;
  cm = inches * 2.54;
  meters = cm/100;
  
  Serial.print("Distance from object is: ");
  Serial.print(meters);
  
  // Delays reading by 500 milliseconds
  delay(500);
}
