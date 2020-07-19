// Based on Atlas Scientific Arduino Uno pH Sample Code, adapted for ESP8266.
// Source: https://www.atlas-scientific.com/files/Arduino-Uno-pH-sample-code.pdf

#include <SoftwareSerial.h>
#define RX 13 // GPIO13 (D7)
#define TX 12 // GPIO15 (D6)

SoftwareSerial ezoSerial(RX, TX);

String command = "";
String output = "";
boolean isInputComplete = false;
boolean isOutputComplete = false;
float pH;

void setup() {
  Serial.begin(9600);
  ezoSerial.begin(9600);
  command.reserve(10);
  output.reserve(30);
}

void loop() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    command += inChar;
    if (inChar == '\n') {
      isInputComplete = true;
      Serial.println("Sending command: " + command);
      ezoSerial.print(command);
      command = "";
    }
  }

  if (ezoSerial.available() > 0) {
    char inchar = (char)ezoSerial.read();
    output += inchar;
    if (inchar == '\r') {
      isOutputComplete = true;
    }
  }

  if (isOutputComplete == true) {
    Serial.println(output);
    output = "";
    isOutputComplete = false;
  }
}
