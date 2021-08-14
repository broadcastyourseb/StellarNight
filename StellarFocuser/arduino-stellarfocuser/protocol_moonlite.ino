void moonlite() {
  // read the command until the terminating # character
  get_serial();

  // process the command we got
  process_command();

}

void get_serial() {
  // read the command until the terminating # character
  while (Serial.available() && !eoc) {
    inChar = Serial.read();
    if (inChar != '#' && inChar != ':') {
      line[idx++] = inChar;
      if (idx >= MAXCOMMAND) {
        idx = MAXCOMMAND - 1;
      }
    } 
    else {
      if (inChar == '#') {
        eoc = 1;
      }
    }
  } // end while Serial.available()
  // we may not have a complete command yet but there is no character coming in for now and might as well loop in case stepper needs updating
  // eoc will flag if a full command is there to act upon
}

void process_command() {
    // process the command we got
  if (eoc) {
    memset(cmd, 0, MAXCOMMAND);
    memset(param, 0, MAXCOMMAND);

    int len = strlen(line);
    if (len >= 2) {
      strncpy(cmd, line, 2);
    }

    if (len > 2) {
      strncpy(param, line + 2, len - 2);
    }

    memset(line, 0, MAXCOMMAND);
    eoc = 0;
    idx = 0;

    //now execute the command
   
    //Action commands
    
    if (!strcasecmp(cmd, "FD")) {
      // Halt Motor 1 move, position is retained, motor is stopped.
      stepper.stop(); // Sets a new target position that causes the stepper to stop as quickly as possible, using the current speed and acceleration parameters.
    }
    
    if (!strcasecmp(cmd, "FG")) {
      // Start a Motor 1 move, moves the motor to the New Position.
      if(!stepper.isRunning())
        {
          turnOn();
        }
      stepper.runToPosition();
    }
    
    //Get commands
    
    //Returns the temperature coefficient where XX is a two-digit signed (2’s complement) hex number.
    //hardcoded
    if (!strcasecmp(cmd, "GC")) {
      Serial.print("02#");      
    }

    //Returns the current stepping delay where XX is a two-digit unsigned hex number. See the :SD# command for a list of possible return values.
    //hardcoded for now
    // might turn this into AccelStepper acceleration at some point
    if (!strcasecmp(cmd, "GD")) {
      Serial.print("02#");      
    }

    //Returns "FF#" if the focus motor is half-stepped otherwise return "00#"
    //hardcoded
    if (!strcasecmp(cmd, "GH")) {
      Serial.print("00#");
    }

    //Returns "00#" if the focus motor is not moving, otherwise return "01#",
    //AccelStepper returns Positive as clockwise
    if (!strcasecmp(cmd, "GI")) {
      if (stepper.distanceToGo() == 0) {
        Serial.print("00#");
      } 
      else {
        Serial.print("01#");
      }
    }

    //Returns the new position previously set by a ":SNYYYY" command where YYYY is a four-digit unsigned hex number.
    if (!strcasecmp(cmd, "GN")) {
      pos = stepper.targetPosition();
      sprintf(tempString, "%04X", pos);
      Serial.print(tempString);
      Serial.print("#");
    }

    //Returns the current position where YYYY is a four-digit unsigned hex number.
    if (!strcasecmp(cmd, "GP")) {
      pos = stepper.currentPosition();
      sprintf(tempString, "%04X", pos);
      Serial.print(tempString);
      Serial.print("#");
    }

    //Returns the current temperature where YYYY is a four-digit signed (2’s complement) hex number.
    if (!strcasecmp(cmd, "GT")) {
      Serial.print("0024#");
    }

    //Get the version of the firmware as a two-digit decimal number where the first digit is the major version number, and the second digit is the minor version number.
    //hardcoded
    if (!strcasecmp(cmd, "GV")) {
      Serial.print("10#");
    }

    // Set commands

    //Set the new temperature coefficient where XX is a two-digit, signed (2’s complement) hex number.
    if (!strcasecmp(cmd, "SC")) {
      //do nothing yet
    }

    //Set the new stepping delay where XX is a two-digit,unsigned hex number.
    if (!strcasecmp(cmd, "SD")) {
      //do nothing yet
    }

    //Set full-step mode.
    if (!strcasecmp(cmd, "SF")) {
      //do nothing yet
    }

    //Set half-step mode.
    if (!strcasecmp(cmd, "SH")) {
      //do nothing yet
    }

    //Set the new position where YYYY is a four-digit
    if (!strcasecmp(cmd, "SN")) {
      pos = hexstr2long(param);
      // stepper.enableOutputs(); // turn the motor on here ??
      if(!stepper.isRunning())
      {
        turnOn();
      }
      stepper.moveTo(pos);
    }

    //Set the current position where YYYY is a four-digit unsigned hex number.
    if (!strcasecmp(cmd, "SP")) {
      pos = hexstr2long(param);
      stepper.setCurrentPosition(pos);
      // record the current position into arduino memory
      EEPROM.writeLong(ADDR, pos);
    }

  }// end if(eoc)
} // end loop

long hexstr2long(char *line) {
  long ret = 0;

  ret = strtol(line, NULL, 16);
  return (ret);
}
