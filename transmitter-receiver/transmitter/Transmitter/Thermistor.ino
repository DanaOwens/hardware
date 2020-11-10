// Code used for Thermistors

//Function that takes the pin number as an input and returns T 
float readTemp(int thermistorPin) {
  Vo = analogRead(thermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  return T;
}

// minT and maxT for each thermistor, A0, A1, A2
float minT[3] = {100000, 100000, 100000};
float maxT[3] = {-1, -1, -1};
// Sum of T, to print mean at end
float sumT[3] = {0, 0, 0};
int numTrials = 10;

float maxTherm = maxT[0]; 
  int maxThermNum = 0;
  for (int i = 0; i < thermistorNum; i ++){
    if ( maxT[i] >= maxTherm ){
      maxTherm = maxT[i];
      maxThermNum = i;
    }
  }
  
  float minTherm = minT[0]; 
  int minThermNum = 0;
  for (int i = 0; i < thermistorNum; i ++){
    if ( minT[i] <= minTherm ){
      minTherm = minT[i];
      minThermNum = i;
    }
  }
  Serial.print("Max: ");
  Serial.print(maxTherm);
  Serial.print(" occured in thermistor at pin A");
  Serial.println(maxThermNum);
  Serial.print("Min: ");
  Serial.print(minTherm);
  Serial.print(" occured in thermistor at pin A");
  Serial.println(minThermNum);
  Serial.print("Avg A0: ");
  Serial.println(sumT[0]/numTrials);
  Serial.print("Avg A1: ");
  Serial.println(sumT[1]/numTrials);
  
}