/*
  Echo text back on serial
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 14); // RX, TX
String inputString = "";         // a String to hold incoming data
boolean stringComplete = false; 

uint16_t checksum(String thestring)
{
    uint8_t d, e, f;
    uint16_t c, r, crccalc;
    c = 0xffff;

    for (unsigned int i = 0; i < thestring.length(); i++)
    {
        d = thestring[i];
        e = c ^ d;
        f = e ^ (e << 4);
        r = (c >> 8) ^ (f << 8) ^ (f << 3) ^ (f >> 4);
        c = r;
    }
    c ^= 0xffff;
    crccalc = c;
    return crccalc;
}
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

void loop() // run over and over
{
   
  while (mySerial.available()) {
    char inChar = (char)mySerial.read();
    if (inChar == '\n') {
      // if the incoming character is a newline, set a flag 
      stringComplete = true;
    } else{
      // add it to the inputString:
      inputString += inChar;
    }
  

    if (stringComplete) {
      Serial.println(inputString);   // executes incoming message, send answer    
      mySerial.write(inputString.c_str());
      Serial.println(checksum(inputString.c_str()));
      inputString = "";  // clear the string:
      stringComplete = false;    
    }
  }
}

