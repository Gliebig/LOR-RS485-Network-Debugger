#include <Arduino.h>
#include <SoftwareSerial.h>

// Code to read the output from Light O Rama S5 HS UART
// controller (RED) to develop a
// Debugging Device to use in the field to check
// signal transmission and hardware issues
// Greg Liebig 01/27/31 Initial commit and a work in progress

/*
Aruduino Mega 2560 Outputting Serial to Monitor using Serial
and using Serial1 for input from
DSD TECH SH-U12 RS485 to TTL 5V Board with MAX13487 Chip (Serial1) or
RS485 chip provided by LOR and uxcell a15080400ux1059 Solder Type Double Row 8PIN DIP Integrated Circuit IC Socket (Serial2) or
Max485 Chip RS-485 Module TTL to RS-485 Module with 120ohm RZ terminating resistor removed (Serial3)

with the hope to eventually write meaningful data to
ELEGOO UNO R3 2.8 Inches TFT Touch Screen shield with SD Card Socket 

*/

unsigned long byteReceived1;
unsigned long byteReceived3;
unsigned long myTime;

 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  Serial1.begin(57600); // Mega pins 18 (Tx) and 19 (Rx) for SH-U12
  Serial3.begin(57600); // Mega pins 14 (Tx) and 15 (Rx) for Max485
  Serial.println("RS485 LOR Read");
  //pinMode(SSerialTxControl, OUTPUT);
 
  // print Headers
  Serial.print("Time"); 
  Serial.print("\t");         
  
  
  Serial.print("Serial1");  
  Serial.print("\t");         

  Serial.print("Serial3");
  Serial.print("\t");

  //Serial.print("HEX");
  //Serial.print("\t");

  //Serial.print("OCT");
  //Serial.print("\t");

  //Serial.print("BIN");
  Serial.println();       
}
 
void loop() {
  myTime = millis();
  // now we read from the RS485 bus
  if (Serial1.available()) {
    byteReceived1 = Serial1.read();
 //.write(byteReceived );
   Serial.print(myTime);
   Serial.print("\t");
   //Serial.write(byteReceived1);
   //Serial.print("\t");
   //Serial.print(byteReceived1, DEC);
   //Serial.print("\t");
   Serial.print(byteReceived1, HEX);
   Serial.print("\t");
   //Serial.print(byteReceived1, OCT);
   //Serial.print("\t");
   //Serial.println(byteReceived1, BIN);
  }
  if (Serial3.available()) {
   byteReceived3 = Serial3.read();
   Serial.print(byteReceived3, HEX);
   Serial.print("\t");
   /*
   // Using the 485 Max Board
   Serial.print("Serial3");
   Serial.print("\t");
   Serial.write(byteReceived3);
   Serial.print("\t");
   Serial.print(byteReceived3, DEC);
   Serial.print("\t");
   Serial.print(byteReceived3, HEX);
   Serial.print("\t");
   Serial.print(byteReceived3, OCT);
   Serial.print("\t");
   Serial.println(byteReceived3, BIN);
   */
  }
  Serial.println();
}