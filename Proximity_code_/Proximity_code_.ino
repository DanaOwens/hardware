#define SENSOR_PIN   2

int sensor_value;

int i = 0;
int dashes = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 sensor_value = digitalRead(SENSOR_PIN);

  // printing output and choosing number of dashes to display
  if (sensor_value == HIGH) {
    Serial.print("High");
    dashes = 50;
  } else {
    Serial.print("Low");
    dashes = 5;
  } 

  // display dashes for easy visual record
  while (i < dashes) {
    Serial.print("_");
    i++;
  } 
  i = 0;

  Serial.println(' ');

  delay(50);

}
