const int analog_in_pin = A0; // A0 pin for analog input


int raw_value = 0; // output from sensor
double voltage = 0;             
double temp_celsius = 0;        
double temp_fahrenheit = 0;     

void setup() {
 // i'm using serial to show output
  Serial.begin(9600);
}

void loop() {
  // getting raw analog value from the sensor
  raw_value = analogRead(analog_in_pin);
  
  // converting raw value to voltage assuming 5v as reference
  voltage = (raw_value / 1023.0) * 5000; 
  
  // converting the voltage to temperature in Celsius (sensor offset is 500)
  temp_celsius = (voltage - 500) * 0.1;  // 500 is the offset value for DHT11
  
  // converting temperature from Celsius to Fahrenheit
  temp_fahrenheit = (temp_celsius * 1.8) + 32;
  
  // output through serial
//   Serial.print("Raw Value = ");
//   Serial.print(raw_value);
//   Serial.print("\t Voltage = ");
//   Serial.print(voltage, 0);  
  Serial.print("\t Temp in C = ");
  Serial.print(temp_celsius, 1); 
  Serial.print("\t Temp in F = ");
  Serial.println(temp_fahrenheit, 1); 
  delay(1000);
}
