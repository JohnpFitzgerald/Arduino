Servo myServo; // create a servo object

//set up global values
int const potPin = A0; // analog pin used to connect the potentiometer
int potVal; // variable to read the value from the analog pin
int angle; // variable to hold the angle for the servo motor
//Lab4Task2 Add a LED
//const int LED_PIN = 3;
void setup() 
{
pinMode(3, OUTPUT);
pinmode(4, OUTPUT);
//digitalWrite(LED_PIN, HIGH);  
myServo.attach(9); // attaches the servo on pin 9 to the servo object
Serial.begin(9600); // open a serial connection to your computer

// turn the LED off, signaling the end of the calibration period
//digitalWrite(LED_PIN, LOW);
}

void loop() 
{
   potVal = analogRead(potPin); // read the value of the potentiometer
   // print out the value to the serial monitor
   Serial.print("potVal: ");
   Serial.print(potVal);
   // scale the numbers from the pot
   angle = map(potVal, 0, 1023, 0, 179);
   //TASK 2 CODE HERE
   if (angle == 0) {
      analogWrite(3,0);
   }
   else if (angle > 50 && angle<90){
     analogWrite(3,100);
   }else if (angle > 90 && angle<179){
     analogWrite(3,255);
   }
   //Task 3 Code here
    if (angle < 10  && angle > 170) {
      analogWrite(4,255);
   }
   else {
     analogWrite(4,0);
   }
   // print out the angle for the servo motor
   Serial.print(", angle: ");
   Serial.println(angle);
   // set the servo position
   myServo.write(angle);
   // wait for the servo to get there
   delay(15);

}
