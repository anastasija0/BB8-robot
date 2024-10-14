#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
void setup() {
Serial.begin(9600);
 pinMode(5, OUTPUT); // put your setup code here, to run once:
 }

void loop() {
  // put your main code here, to run repeatedly:
 
 if(Serial.available()>0)
   {     
      int data = Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '1': digitalWrite(5, HIGH);break; // when a is pressed on the app on your smart phone
        case '2': digitalWrite(5, LOW);break; // when d is pressed on the app on your smart phone
        default : break;
      }
   }
   delay(50);
}
