const int trigPin = 7;
const int echoPin = 8;
const int enaPin = 2;
const int enbPin = 3;
int flameSensorPin =0; //  a0 
int transmit_gas = 12;
int vibrationSensorPin = 1; //  a1
int flameSensorReading; 
int vibrationSensorReading; 
int buzzerPin=4; 
int timer=5000;
long duration;
int distance;

void obstacle_avoidance()
{
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
if(distance<40)
{
  digitalWrite(enaPin, LOW);
  digitalWrite(enbPin, LOW);
  delay(3000);
  digitalWrite(enaPin, HIGH);
  digitalWrite(enbPin, HIGH);
  delay(1000);
}

else
{

  digitalWrite(enaPin, HIGH);
  digitalWrite(enbPin, HIGH);
}
}
void read_gas_sensor()
{
   flameSensorReading = analogRead(flameSensorPin);  
  if(flameSensorReading<100)
  {
    digitalWrite(buzzerPin,LOW);
    digitalWrite(transmit_gas,LOW);  
  }
  else
  {
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(transmit_gas,HIGH);
  }
}
void read_vibration_sensor()
{
  vibrationSensorReading = analogRead(vibrationSensorPin);  
  if(vibrationSensorReading<900)
{
  digitalWrite(buzzerPin,HIGH);
  delay(300);
  digitalWrite(buzzerPin,LOW);
}
}
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(transmit_gas, OUTPUT); 

pinMode(enaPin, OUTPUT);
pinMode(enbPin, OUTPUT);

pinMode(buzzerPin,OUTPUT);

pinMode(flameSensorPin,INPUT);

pinMode(vibrationSensorPin,INPUT);

digitalWrite(enaPin, HIGH);
digitalWrite(enbPin, HIGH);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
obstacle_avoidance();
delay(50);
read_gas_sensor();
delay(50);
read_vibration_sensor();
delay(50);
//Serial.println("flame value:");
//Serial.println(analogRead(flameSensorPin));
Serial.println("pin value:");
Serial.println(digitalRead(transmit_gas));
}
