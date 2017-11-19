/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.
 
 A good test for this is to try it with a GPS receiver
 that sends out NMEA 0183 sentences.
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */
 
//#include <Servo.h>
#include <SoftwareServo.h>
 
//Servo myservo;  // create servo object to control a servo
SoftwareServo myservo;  // create servo object to control a servo 
String inputString = "";
String outputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int statuss = 2, statusr = 0, statusq = 0, brightness = 128, firmware = 123, led = 3;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
 
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(led, OUTPUT);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
      // check if the line is a valid line
      if (inputString[0] == 62) {
        // what kind of message     
        switch (inputString[1]) {
          case 'P':
              // Ping
              classicOutput();
              break;
          case 'O':
              // Open
              flip(false);
              classicOutput();
              break;
          case 'C':
              // Close
              flip(true);
              classicOutput();
              break;
          case 'L':
              // Light on
              if (statuss == 1) {
                light(true);
                classicOutput();
              }
              break;
          case 'D':
              // Light off
              light(false);
              classicOutput();
              break;
          case 'B':
              // Set Brightness
              brightness = (inputString[2] -48) * 100 + (inputString[3] - 48) * 10 + (inputString[4] - 48);
              if (statusr == 1) {
                light(true);
              }
              classicOutput();
              break;
          case 'J':
            // Get Brightness
            getBrightness();
            break;
          case 'S':
            statut();
            break;
          case 'V':
            getFirmware();
            break;
          default:
            break;          
        }
      }
  // clear the string:
  inputString = "";
  outputString = "";
  stringComplete = false;
  }
}

void classicOutput() {
  outputString += "*";
  outputString += inputString[1];
  outputString += "99";
  outputString += inputString[2];
  outputString += inputString[3];
  outputString += inputString[4];
  Serial.println(outputString);
  // clear the string:
  outputString = "";
}

void statut() {
  outputString += "*";
  outputString += inputString[1];
  outputString += "99";
  outputString += statusq;
  outputString += statusr;
  outputString += statuss;
  Serial.println(outputString);
  // clear the string:
  outputString = "";
}

void getBrightness() {
  outputString += "*";
  outputString += inputString[1];
  outputString += "99";
  if (brightness < 10) {
    outputString += "00";
    outputString += brightness;
  }
  if (brightness > 9 && brightness < 100 ) {
    outputString += "0";
    outputString += brightness;
  }
  if (brightness > 99 ) {
    outputString += brightness;
  }
  Serial.println(outputString);
  // clear the string:
  outputString = "";
}

void getFirmware() {
  outputString += "*";
  outputString += inputString[1];
  outputString += "99";
  outputString += firmware;
  Serial.println(outputString);
  // clear the string:
  outputString = "";
}

void light(boolean mode) {
  if (mode) {
    analogWrite(led, brightness);
    statusr = 1;
  } else {
    analogWrite(led, 0);
    statusr = 0;
  }
}

void flip(boolean mode) {
   //myservo.attach(9);
   // le flip est ouvert (statut s=2), on souhaite le fermer (mode = true)
   if (mode == true && statuss == 2) {
     statuss = 0; // flip not open/closed
     statusq = 1; // motor on
     classicOutput();
     //myservo.write(180);  // sets the servo position to 180°
     //delay(300);
     //statusq = 0; // motor off
     //statuss = 1; // flip close
     classicOutput();
   }
   // le flip est fermé (statut s=1), on souhaite l'ouvrir (mode = false)
   if (mode == false && statuss == 1) {
     // on vérifie l'état de la lumière
     if (statusr == 1) {
       light(false);
     }
     statuss = 0; // flip not open/closed
     statusq = 1; // motor on
     classicOutput();
     //myservo.write(0);  // sets the servo position to 0
     //delay(300);
     //statusq = 0; // motor on
     //statuss = 2; // flip open
     //classicOutput();
   }
   // on attend 0,2s avant de déconnecter le servo
   //delay(500);
   //myservo.detach();
   SoftwareServo::refresh();
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
