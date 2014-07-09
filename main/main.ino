
// sensors
#define TOP_SENSOR 1
#define BOTTOM_SENSOR 6
#define HALL_SENSOR 2  
  
// actionner
#define LOCKER 3
#define MOTOR_UP 4
#define MOTOR_DOWN 5


void setup() {

  // INPUT_PULLUP ??? 
  pinMode(TOP_SENSOR, INPUT_PULLUP);
  pinMode(BOTTOM_SENSOR, INPUT_PULLUP);
  pinMode(HALL_SENSOR, INPUT_PULLUP);
    
  pinMode(LOCKER, OUTPUT); // max 40mA
  pinMode(MOTOR_DOWN, OUTPUT);
  pinMode(MOTOR_UP, OUTPUT);
  
  // attach events handler
  attachInterrupt(0, unlockShutter, FALLING); // 0 for digital pin 2
  attachInterrupt(1, closeAndLockShutter, RISING); // 1 for digital pin 3
}

void loop() {
  // put your main code here, to run repeatedly:

}


/**
 * close and lock the shutter
 */
void closeAndLockShutter() {
  
  noInterrupts();
  // critical, time-sensitive code here
  
  digitalWrite(MOTOR_DOWN, HIGH);
  
  while(digitalRead(BOTTOM_SENSOR) != !HIGH) {
      // wait until shutter reach the sensor ....
  }
  
  digitalWrite(MOTOR_DOWN, LOW); // stop closing the shutter

  // close the locker
  digitalWrite(LOCKER, HIGH);
  
  delay(1000);                  // waits for a second (no effect as we are in interruption)

  digitalWrite(MOTOR_UP, HIGH);

  while(digitalRead(TOP_SENSOR) != !HIGH) {
      // wait until shutter reach the sensor ....
  }
  
  digitalWrite(MOTOR_UP, LOW); // stop the motor
  
  interrupts();
}


void unlockShutter() {
    digitalWrite(LOCKER, LOW);
}
