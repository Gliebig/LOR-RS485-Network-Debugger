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

Initial code to transpose hex values received from Serial1 into "command lines" 1/29/22
running into a problem since the heartbeat is constanly being transmitted with the pattern
0x00, 0xFF, 0X81, 0x56, 0x00
but the control data has an extra 0x00 at the end eg:
0x00, 0xA, 0x3, 0x1, 0x88, 0x00, 0x00
Start 0
UID
Action
Channel
Working for sequence output without motion FX 2/2/22. Buggy when it comes to caputuring sequence output with motion FX

*/

unsigned long byteReceived1;
unsigned long myTime = 0;
#define Start = 0
unsigned long PacketEnd = 0;
unsigned long PacketStart = 0;

 
void setup() {
  Serial.begin(57600);
  Serial1.begin(57600); // Mega pins 18 (Tx) and 19 (Rx) for SH-U12
  //Serial3.begin(57600); // Mega pins 14 (Tx) and 15 (Rx) for Max485
  Serial.println("RS485 LOR Read");
   // print Headers
  Serial.print("Flush"); 
  Serial.print("\t");         
  Serial.print("UID");  
  Serial.print("\t"); 
  Serial.print("Action");  
  Serial.print("\t"); 
  Serial.print("Channel");  
  Serial.print("\t");         
  Serial.println();       
}
 
void loop() {
//  myTime = millis();
//  Serial.print(myTime);
//  Serial.print("\t");
  // now we read from the RS485 bus
    if (Serial1.available()) {
      byteReceived1 = Serial1.read();
      Serial.print(byteReceived1, HEX);
      Serial.print("\t");
    
       if ((byteReceived1 == 0x00) & (Serial1.peek() != 0x00)) {
          if (PacketStart==1) {
          //End of Packet
          //Serial.print("0x00");
          Serial.println(); //Start New Packet
          }
          PacketStart = 0;
          PacketEnd = 1;
        }
      
        else {
          //Serial.print("Packet Start");
          //Serial.print("\t");
          //Serial.print(byteReceived1, HEX);
          //Serial.print("\t");
          PacketEnd = 0;
          PacketStart = 1;
        }
      if (PacketStart == 1) {
         //Serial.print(byteReceived1, HEX);
         //Serial.print("\t");
      }
    }    
}