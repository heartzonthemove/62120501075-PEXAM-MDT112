//servo
#include <Servo.h>
Servo myservo;                                  // change servo to my servo
int ServoPin = 9;                               // change servo pin to 9

//7segment
#include "TM1637.h"
const int DIO = 16;                             // setup 7-segment to A2
const int CLK = 17;                             // setup 7-segment to A3
TM1637 sevenSegment(CLK, DIO);                  // 7-segment

void setup()
{
    //servo
    Serial.begin(9600);                         // show in the monitor screen
    myservo.attach(ServoPin);                   // choose which pin to go to

    //7segment
    sevenSegment.init();
    sevenSegment.set(7);                        // BRIGHT 0-7;

    //1
    tone(8, 600, 300);

    //2
    Serial.println("Hello MDT!!!");

    //3
    myservo.write(0);                           // change servo to 0 degree
    myservo.write(150);                         // change servo to 150 degree
    Serial.println("Servo : 150 degrees");
    delay(800);
}

void loop()
{

}