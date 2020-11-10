int sensorPin = A0; 
int pinout = 8;
int sensorValue = LOW; 

void setup() {
  Serial.begin(9600);
  pinMode(pinout, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);  
  Serial.println(sensorValue);

  digitalWrite(pinout, HIGH); 
  delay(1000);
  digitalWrite(pinout, LOW);
}
