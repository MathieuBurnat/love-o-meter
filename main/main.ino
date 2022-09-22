const int sensorTMP = A0; //set tmp sensor to the a0 pin
const float baselineTemp = 21.0; // room temperature

void setup() {
  Serial.begin(9600); // open se port to comunicate with Arduino

  //set LED as output and its state to LOW 
  for(int pn = 2; pn<5; pn++){
    pinMode(pn, OUTPUT);
    digitalWrite(pn, LOW);
  }
}

void loop() {
  int sensorValue = analogRead(sensorTMP); //in celcius
  float voltage = (sensorValue / 1024.0) * 5.0; // Convert ADC(Analog to Digital Converter) as tension
  float temperature = (voltage - 0.5) * 100;

  Serial.print("sensor value :");
  Serial.print(sensorValue);
  
  Serial.print(", volts :");
  Serial.print(voltage);
  
  Serial.print(", Current temperature :");
  Serial.print(temperature);

  Serial.print(", baline temperature :");
  Serial.println(baselineTemp);
  
    if(temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);    
  }
  else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);    
  }
  
  delay(2000);
}
