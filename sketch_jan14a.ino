#include <TimerOne.h> //This part of the code is where I included the timer interrupt library
int LDR_pin = A0; //pin that is used to read the voltage changes
int sensor_reading; //keeps track of the voltage values mapped to the 10-bit ADC
int REDLED1 = 13;
int YELLOWLED1 = 12;
int GREENLED1 = 11; //This is the part where I created variables and set them to specific pins
int REDLED2 = 9;
int YELLOWLED2 = 8;
int GREENLED2 = 7;
int RailRoadLED1 = 3;
int RailRoadLED2 = 2;
void setup()
{
  Serial.begin(9600);
  Serial.println("The program has started …");
  pinMode(REDLED1, OUTPUT);
  pinMode(YELLOWLED1, OUTPUT);
  pinMode(GREENLED1, OUTPUT);
  pinMode(REDLED2, OUTPUT); //This is the part of the code where I initialized each variable associated with a pin to output and I also initialized the times for the timer interrupt
  pinMode(YELLOWLED2, OUTPUT);
  pinMode(GREENLED2, OUTPUT);
  pinMode(RailRoadLED1, OUTPUT);
  pinMode(RailRoadLED2, OUTPUT);
  Timer1.initialize(1600000);
  Timer1.setPeriod(1600000);
  Timer1.attachInterrupt(function);
}
void loop()
{
  Serial.println("The Red LEDs are on …");
  digitalWrite(REDLED1, HIGH);
  digitalWrite(REDLED2, HIGH);
  delay(3000); //This is the loop which the Arduino starts off with. This loop tell the
  //arduino to turn the Red LEDs to low for 3 seconds and the one high and on low for 750
  //millisecond. After one is high and one is low, one green light turns high and on the other traffic
  //light, the red led is the only one on. Then, 15 seconds later, the green led switches to low and the
  //yellow led turns to high for 1150 milliseconds. Later the yellow led turns to low and then both
  //red leds are high until the same code is run for the second traffic light.
  digitalWrite(REDLED1, LOW);
  Serial.println("The Red LED is off …");
  delay(750);
  digitalWrite(GREENLED1, HIGH);
  Serial.println("The Green LED is on …");
  delay(15000);
  digitalWrite(GREENLED1, LOW);
  Serial.println("The Green LED is off …");
  delay(250);
  digitalWrite(YELLOWLED1, HIGH);
  Serial.println("The Yellow LED is on …");
  delay(1150);
  digitalWrite(YELLOWLED1, LOW);
  Serial.println("The Yellow LED is off and The Red LEDs are on");
  digitalWrite(REDLED1, HIGH);
  digitalWrite(REDLED2, HIGH);
  delay(5000);
  digitalWrite(REDLED2, LOW);
  Serial.println("The Red LED is off …");
  delay(750);
  digitalWrite(GREENLED2, HIGH);
  Serial.println("The Green LED is on …");
  delay(15000);
  digitalWrite(GREENLED2, LOW);
  Serial.println("The Green LED is off …");
  delay(250);
  digitalWrite(YELLOWLED2, HIGH);
  Serial.println("The Yellow LED is on …");
  delay(1150);
  digitalWrite(YELLOWLED2, LOW);
  Serial.println("The Yellow LED is off");
}
void function()
{
  Serial.print("delay 100 \n");
  sensor_reading = analogRead(LDR_pin); //this will read the LDRs input
  Serial.println(sensor_reading); //this will print a value between 0 and 1023
  if (sensor_reading <= 517) { //This is the function. This function contains an if statement
    //for the railroad crossing lights so that they turn on if the reading it 517 and less and they turn off
    //if its above 517. This function is attached to the timer interrupt and that interrupt checks the
    //code every 1600 milliseconds and runs one of the two parts of the if statement.
    digitalWrite(RailRoadLED1, HIGH); // Turns ledPin1 High for 400 milliseconds
    digitalWrite(RailRoadLED2, LOW); // Turns ledPin2 Low for 50 milliseconds
    delay(1000000);
    digitalWrite(RailRoadLED1, LOW); // Turns ledPin1 Low for 50 milliseconds
    digitalWrite(RailRoadLED2, HIGH); // Turns ledPin1 High for 400 milliseconds
    delay(1000000);
    digitalWrite(RailRoadLED1, HIGH); // Turns ledPin1 High for 400 milliseconds
    digitalWrite(RailRoadLED2, LOW); // Turns ledPin2 Low for 50 milliseconds
    delay(1000000);
    digitalWrite(RailRoadLED1, LOW); // Turns ledPin1 Low for 50 milliseconds
    digitalWrite(RailRoadLED2, HIGH); // Turns ledPin1 High for 400 milliseconds
    delay(1000000);
  }
  else {
    digitalWrite(RailRoadLED1, LOW);
    digitalWrite(RailRoadLED2, LOW);
  }
  delay(400)
}