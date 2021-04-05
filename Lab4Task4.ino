// include the servo library
#include <Servo.h>
Servo myServo; // create a servo object

//set up global values
int const potPin = A0; // analog pin used to connect the potentiometer

//task 4 add a switch control
int switchstate = 0; //set switch to 0
 
int potVal; // variable to read the value from the analog pin
int angle; // variable to hold the angle for the servo motor


void setup() 
{
pinMode(3, OUTPUT);  
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
//digitalWrite(LED_PIN, HIGH);  
myServo.attach(9); // attaches the servo on pin 9 to the servo object
Serial.begin(9600); // open a serial connection to your computer

}

void loop() 
{
   potVal = analogRead(potPin); // read the value of the potentiometer
   // print out the value to the serial monitor
   Serial.print("potVal: ");
   Serial.print(potVal);
   switchstate = digitalRead(4); 
   // scale the numbers from the pot
   angle = map(potVal, 0, 1023, 0, 179);
   //task 2 code here 0 is OFF and 255 is ON
   if (angle == 0) {
      analogWrite(3,0);
   }
   else if (angle > 50 && angle<90){
     analogWrite(3,100);
   }else if (angle > 90 && angle<179){
     analogWrite(3,255);
   }
      //Task 3 Code here
   if (angle>10  && angle<170) {
      analogWrite(5,0);
   }
   else {
     analogWrite(5,255);
   }

   // print out the angle for the servo motor
   Serial.print(", angle: ");
   Serial.println(angle);
   // set the servo position
   // myServo.write(angle);
   // wait for the servo to get there
       delay(15);

   //task 4 add a switch to control the Servo
    if (switchstate == HIGH) {
        myServo.write(angle);
     }
}
