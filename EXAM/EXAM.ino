//servo
#include <Servo.h>
Servo myservo;                                                      // change servo to my servo
int ServoPin = 9;                                                   // change servo pin to 9
int anglestep = 30;                                                 // set what 1 step push to be
int angle = 90;                                                     // initial angle  for servo
int Minangle = 0;                                                   // set minimum to 0 degrees
int Maxangle = 180;                                                 // set maximun to 180 degrees

//7segment
#include "TM1637.h"
const int DIO = 16;                                                 // setup 7-segment to A2
const int CLK = 17;                                                 // setup 7-segment to A3
TM1637 sevenSegment(CLK, DIO);                                      // 7-segment

bool lastState = true;                                              // set button state

int ButtonPin = 2;

void setup()
{
    pinMode(ButtonPin, INPUT_PULLUP);                               // button setup
    
    //servo
    Serial.begin(9600);                                             // show in the monitor screen
    myservo.attach(ServoPin);                                       // choose which pin to go to

    //7segment
    sevenSegment.init();                                            // start the 7segment
    sevenSegment.set(7);                                            // bright between 0-7;

    //1
    tone(8, 600, 300);                                              // sound check

    //2
    Serial.println("Hello MDT!!!");                                 // show in monitor screen

    //3
    myservo.write(0);                                               // change servo to 0 degree
    myservo.write(150);                                             // change servo to 150 degree
    Serial.println("Servo : 150 degrees");                          // show in monitor screen
    delay(800);                                                     // wait 0.8 sec

    //4
    myservo.write(150);                                             // change servo to 150 degree
    myservo.write(0);                                               // change servo to 0 degree
    Serial.println("Servo : 0 degrees");                            // show in monitor screen
    delay(800);                                                     // wait 0.8 sec

    //5
    sevenSegment.displayStr("0000");                                // show in 7segment screen
    delay(800);                                                     // wait 0.8 sec
    sevenSegment.displayStr("");                                    // clear 7segment screen
    
    //6
    delay(600);                                                     // wait 0.6 sec
    tone(8, 600, 500);                                              // sound beep

    sevenSegment.displayStr("   0");                                // show in 7segment screen
}

int ButtonCount = 1;

void loop()
{
    //7 
    bool currentState = digitalRead(ButtonPin);
    //8
    if(lastState < currentState)
    {   
        //9
        switch (ButtonCount) 
        {
        case 1:
        myservo.write(30);                                          // change servo to 30 degree
        sevenSegment.displayNum(30);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 2:
        myservo.write(60);                                          // change servo to 60 degree
        sevenSegment.displayNum(60);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 3:
        myservo.write(90);                                          // change servo to 90 degree
        sevenSegment.displayNum(90);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 4:
        myservo.write(120);                                         // change servo to 120 degree
        sevenSegment.displayNum(120);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 5:
        myservo.write(150);                                         // change servo to 150 degree
        sevenSegment.displayNum(150);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 6:
        myservo.write(180);                                         // change servo to 180 degree
        sevenSegment.displayNum(180);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 7:
        myservo.write(150);                                         // change servo to 150 degree
        sevenSegment.displayNum(150);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 8:
        myservo.write(120);                                         // change servo to 120 degree
        sevenSegment.displayNum(120);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 9:
        myservo.write(90);                                          // change servo to 90 degree
        sevenSegment.displayNum(90);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 10:
        myservo.write(60);                                          // change servo to 60 degree
        sevenSegment.displayNum(60);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 11:
        myservo.write(30);                                          // change servo to 30 degree
        sevenSegment.displayNum(30);
        tone(8, 900, 800);                                          // sound beep
        break;
        case 12:
        myservo.write(0);                                           // change servo to 0 degree
        sevenSegment.displayStr("   0");                            // show in 7segment screen
        tone(8, 900, 800);                                          // sound beep
        ButtonCount = 0;
        break;
        }
        ButtonCount++;
    }

    lastState = currentState;
}
