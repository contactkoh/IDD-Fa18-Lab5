// Useless Box Lab 5
//
// If we see a voltage change on pin 2 the toggle switch on top of the useless box has 
// changed position and we need to react!
//    A HIGH value on pin 2 means we should activate the servo to open the useless 
//    box and attempt to return the switch to the "off" position.
//    A LOW value on pin 2 means the switch is off and we should return to our 
//    inital (closed box) state.

#include <Servo.h> 

#define servoPin  10
#define switchPin 2

#define closePos  0
#define openPos   180

Servo servo;
int switchState;
int previousSwitchState;

int ledPin = 9;

// call this when the input on pin 2 changes (LOW to HIGH *or* HIGH to LOW)
void ToggleSwitch(int switchState)
{    
  if (switchState == HIGH)
  {
    
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED o  n (HIGH is the voltage level)
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    
    delay(2000); //me: added to close back

    servo.write(openPos);
    //Serial.println("switch state is HIGH.  servo.write(openPos) called to open useless box");

    delay(1000); //me: added to close back
    servo.write(closePos); // me: added to close back

  }
  else
  {
    //servo.write(closePos);  // me: TEST
    //Serial.println("switch state is LOW.   servo.write(closePos) called to close useless box");

    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(ledPin, LOW);   // turn the LED on (HIGH is the voltage level)

  }
  previousSwitchState = switchState;  // remember that the switch state has changed 
}

void setup()
{
  //Serial.begin(9600);
  //Serial.println("Useless Box Lab 5");

  //me: Testing LED
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);


  // start with the box closed and the switch in the off postion
  switchState = LOW;
  previousSwitchState = LOW;

  // connect to our servo and make sure it is in the closed position
  servo.attach(servoPin);
  servo.write(closePos);

  // we should probably pay attention to the switch
  pinMode(switchPin, INPUT); 
}

void loop()
{ 
  int switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState)
    ToggleSwitch(switchState);

  delay(20);
}
