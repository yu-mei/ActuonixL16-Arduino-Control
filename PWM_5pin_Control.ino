/*
  PWM control the DRV8871 to drive the 5-pin Linear Actuator 

  The circuit:
  - Use the L16-50-35-12-P Linear Actuator
  https://www.actuonix.com/L16-Linear-Actuators-p/l16-p.htm
  - Connect 2 to IN1 
  - Connect 3 to IN2

  created 28 Step 2021
  by Yu Mei 
*/

const int motorIn1 = 2;
const int motorIn2 = 3;
int positionValue = 0;
int actuatorSpeed = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  actuatorSpeed = 5;
}

void loop() {  
  positionValue = analogRead(A0);
  actuatorSpeed = map(actuatorSpeed, 0, 100, 0, 1023);
  
  // set up the PWM wave
  analogWrite(motorIn1, 0);
  analogWrite(motorIn2, actuatorSpeed);
  
  // read the position from serial(Tools->Signal Monitor)
  Serial.println(positionValue);

  delay(10);
}
