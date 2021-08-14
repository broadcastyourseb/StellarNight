// Moonlite-compatible stepper controller
//
// Uses AccelStepper (http://www.airspayce.com/mikem/arduino/AccelStepper/)
//
// Inspired by (http://orlygoingthirty.blogspot.co.nz/2014/04/arduino-based-motor-focuser-controller.html)
// orly.andico@gmail.com, 13 April 2014
//
// Modified for indilib, easydriver by Cees Lensink
// Added sleep function by Daniel Franzén
// Added eeprom function by Sébastien Leclerc
// Modified for cheap cheap 28BYJ-48 stepper motor by Sébastien Leclerc


#include <AccelStepper.h>

#include <EEPROMex.h>

#define HALFSTEP 8

// Protocol type
#define PROTOCOL 1 // 1 for moonlite

// Motor pin definitions
#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  7     // IN2 on the ULN2003 driver 1
#define motorPin3  6     // IN3 on the ULN2003 driver 1
#define motorPin4  5    // IN4 on the ULN2003 driver 1

// maximum speed is 300pps which should be OK for most
// tin can steppers
#define MAXSPEED 300
#define ACCELERATION 50

// the current address in the EEPROM
#define ADDR 0

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

#define MAXCOMMAND 8

char inChar;
char cmd[MAXCOMMAND];
char param[MAXCOMMAND];
char line[MAXCOMMAND];
long pos;
int eoc = 0;
int idx = 0;
//boolean isRunning = false;
boolean powerIsOn = false;
long timerStartTime = 0;

//Define the period to wait before turning power off (in milliseconds)
const int activeTimePeriod = 10000;

char tempString[10];


void setup()
{  
  Serial.begin(9600);
  // we ignore the Moonlite speed setting because Accelstepper implements
  // ramping, making variable speeds un-necessary
  stepper.setSpeed(MAXSPEED);
  stepper.setMaxSpeed(MAXSPEED);
  stepper.setAcceleration(ACCELERATION);
  memset(line, 0, MAXCOMMAND);
  
  // set the value stored into memory
  stepper.setCurrentPosition(EEPROM.readLong(ADDR));
}

void loop(){

  // process focuser
  switch (PROTOCOL) {
  case 1:
    // Moonlite protocol
    moonlite();
    break;
  default:
    // Moonlite protocol
    moonlite();
    break;
}
  // energy power saving
  energy_saving();
  
}

void energy_saving() {
  if (stepper.isRunning()) { // only have to do this is stepper is on
      stepper.run();
      if (stepper.distanceToGo() == 0) {
        //start timer to decide when to power off the board.
        timerStartTime = millis();
        // record the current position into arduino memory
        EEPROM.writeLong(ADDR, stepper.currentPosition());
      }
  }
  else if(powerIsOn)
  {
     //Turn power off if active time period has passed.
    if(millis() - timerStartTime > activeTimePeriod)
    {
      turnOff();
    }
  }
}

void turnOn() {
  stepper.enableOutputs();
  powerIsOn = true;
}

void turnOff() {
  stepper.disableOutputs();
  powerIsOn = false;
}
