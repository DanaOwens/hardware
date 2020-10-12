/*Arduino Code Used to Read MaxSonar MB1013Version 1Started 10/11/20*/void setup() {  // If the Analog Voltage is being read:  const int anPin = 0;  // If the Pulse Width is being read:  const int pwPin1 = 3;  /*  Any other variables used in the code.    Analog Voltage: long anVolt, mm, inches;  Pulse Width: long sensor, mm, inches;  */    // Reading Analog Voltage and Pulse Width   // 9600 sets the BAUD rate used to read the Arduino for software that can read a COM Port  Serial.begin(9600);    // Reading Analog Voltage Output  anVolt = analogRead(anPin);  // Reading Pulse Width Output  sensor = pulseIn(pwPin1, HIGH);  // Convert bit count to mm to inches  mmAV = anVolt*5;  inchAV = mmAV/25.4    mmPW = sensor;  inchPW = mmPW/25.4; }void loop() {  read_sensor()  print_range();  delay(100);}