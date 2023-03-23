# esp-softwareserial-looopback-exampleESP8266
The ESP8266 has only one Fullduplex serial port. Serial1 is only TX. It used a lot of time for research for me, to successful establishe a SoftwareSerial.h connection for the board. 

Here is an example, how to use SoftwareSerial with an ESP8266.

Connect PINS D2 and D3 with an Jumper. Upload and start the Example. In Serial Monitor, you can type in some text. 
It will bee looped back, if jumper is set. And will not be loop back, if jumper is removed.
For ESP8266 you need this library: https://github.com/plerup/espsoftwareserial

If you send looooop ti the USB serial connection, it will transmit it to the Software RX Pin, ant Software TX Pin will read it. The Output from TX will be send back to the USB Serial.

input: looooop
output: -.l-.o-.o-.o-.o-.o-.o-.p-.
