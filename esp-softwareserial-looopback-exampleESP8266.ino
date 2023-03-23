#include <SoftwareSerial.h>

// Connect PINS D2 and D3 with an Jumper. Upload and start the Example. In Serial Monitor, you can type in some text. 
// It will bee looped back, if jumper is set. And will not be loop back, if jumper is removed.
// For ESP8266 you need this library: https://github.com/plerup/espsoftwareserial

#define rxPin D2 // PINs according a new NodeMCU V3 Board, with an ESP8266 Chipset.
#define txPin D3
EspSoftwareSerial::UART victronSerial; // RX, TX Using Software Serial so we can use the hardware serial to check the ouput

void setup() {
  Serial.begin(19200);
  // victronSerial.begin(38400);
  victronSerial.begin(19200, SWSERIAL_8N1, rxPin, txPin, false);
//  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(1000);
  Serial.println("Loopback program started");
  if (!victronSerial) { // If the object did not initialize, then its configuration is invalid
  Serial.println("Invalid EspSoftwareSerial pin configuration, check config"); 
  while (1) { // Don't continue with invalid configuration
    delay (1000);
  }
}
}

void loop() {
  if(Serial.available()){
    // Serial.println("Serial.available");
    Serial.write("-");
    victronSerial.write(Serial.read());
    // Serial.write(victronSerial.available());
  }
  if(victronSerial.available()){
    // Serial.println("victronSerial.available");
    Serial.write(".");
    Serial.write(victronSerial.read());
  }
}
