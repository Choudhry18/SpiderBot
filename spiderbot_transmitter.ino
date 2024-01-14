//https://forum.arduino.cc/index.php?topic=557447.0

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
const int num = 2;  // Declare array size
int Array[num];  // Declare array as global variable
int joy1x = A0;
int joy1y = A1;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  pinMode(joy1x,INPUT);
  pinMode(joy1y,INPUT);
}
void loop() {
  Array[0] = analogRead(joy1x);  
  Array[1] = analogRead(joy1y);
Serial.println(Array[1]);
radio.write( &Array, sizeof(Array) );  
  

  delay(500);
Serial.println("Done");
}

