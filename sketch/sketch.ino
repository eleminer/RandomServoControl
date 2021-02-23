#include <Servo.h>
Servo ServoOne; Servo ServoTwo;
int randNumber;
int angleDriveLow=90; //unterer Wert in Gradmaß
int angleDriveHigh=160; //oberer Wert in Gradmaß
int delaybetweenActions=5000; //Wartezeit in Millisekunden zwischen den "Events" zB. 5 Sekunden
int ServopinOne=9; //Servopin Servo 1
int ServopinTwo=10; //Servopin Servo 2
int delayServoTravel=500; //Zeit die der Servo zum Verfahren braucht in Millisekunden

void setup()
{
  Serial.begin(9600);
  ServoOne.attach(ServopinOne); ServoTwo.attach(ServopinTwo);
  ServoOne.write(angleDriveLow); ServoTwo.write(angleDriveLow);
  delay(3000);
}

void ServoOneFunc(int o)
{
  if(o==true)
  {
    ServoOne.write(angleDriveHigh);
  }
  else
  {
    ServoOne.write(angleDriveLow);
  }
}

void ServoTwoFunc(int o)
{
  if(o==true)
  {
    ServoTwo.write(angleDriveHigh);
  }
  else
  {
    ServoTwo.write(angleDriveLow);
  }
}

void OnlyOne()
{
  ServoOneFunc(1);
  delay(delayServoTravel);
  ServoOneFunc(0);
}

void OnlyTwo()
{
  ServoTwoFunc(1);
  delay(delayServoTravel);
  ServoTwoFunc(0);
}

void Both()
{
  ServoOneFunc(1); ServoTwoFunc(1);
  delay(delayServoTravel);
  ServoOneFunc(0); ServoTwoFunc(0);
}

void loop()
{
  randNumber = random(0,3);
  switch (randNumber)
  {
    case 0: Serial.println("Only One"); OnlyOne(); break;
    case 1: Serial.println("only Two"); OnlyTwo(); break;
    case 2: Serial.println("Both"); Both(); break;
  }
  delay(delaybetweenActions);
}
