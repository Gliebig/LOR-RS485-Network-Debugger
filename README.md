# LOR-RS485-Network-Debugger
This is an attempt to build a device to be used in the field to debug the setup of a Light O Rama network by reading the data coming from the computer to ensure the signals are getting to the light controllers. The inspiration came from our troubles with our light show https://youtu.be/uwNxAKr67RE and no way to easily debug the signals. I found some work has been started and have contacted the author in hopes we can collaborate on this project https://github.com/Cryptkeeper/lightorama-protocol

My setup uses an Aruduino Mega 2560 Outputting Serial to Monitor using Serial
There are two devices I'm trying to read the signal from the data line. First is a DSD TECH SH-U12 RS485 to TTL 5V Board with MAX13487 Chip connected to Serial1 and 
Max485 Chip RS-485 Module TTL to RS-485 Module with 120ohm R7 terminating resistor removed (Serial3)

Our hope is to eventually write meaningful data to a screen that can be read by a technician in the field.

Current testing has proven that either board can read the RS485 signal. I'm using a Light o Rama High Speed UART for the initial testing at 57.6k The initial results are just 5 cycles of the heartbeat signal with the sequencer off. 

|millis| Serial1 | Serial3 |
|---:|---:|---:|
| 433|    0 |      0 |
| 433|    FF|      FF |
| 434|    81|      81 |
| 434|    56|      56 |
| 434|    0 |      0 |
| 932|    0 |      0 |
| 932|    FF|      FF |
| 932|    81|      81 |
| 933|    56|      56 |
| 933|    0 |      0 |
|1481|    0 |      0 |
|1481|    FF|      FF |
|1482|    81|      81 |
|1482|    56|      56 |
|1483|    0 |      0 |
|1981|    0 |      0 |
|1981|    FF|      FF |
|1982|    81|      81 |
|1982|    56|      56 |
|1983|    0 |      0 |
|2530|    0 |      0 |
|2531|    FF|      FF |
|2531|    81|      81 |
|2532|    56|      56 |
|2532|    0 |      0 |
