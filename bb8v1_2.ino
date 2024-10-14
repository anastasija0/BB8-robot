#include <SoftwareSerial.h>
SoftwareSerial ble_device(2,3); //2 je TX a 3 RX
char a;

void setup() {  
  pinMode(8,OUTPUT);  //prvi motor napred
  pinMode(9,OUTPUT);  //prvi motor nazad
  pinMode(10,OUTPUT); //drugi motor napred
  pinMode(11,OUTPUT); //drugi motor nazad
  ble_device.begin(9600);
}

void loop() {
  if (ble_device.available()>0)
  {
    a=ble_device.read();
    ble_device.println(a);
  }
  if (a=='F') //forward
  {
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
   //f forward
   //B back
   //L left                              
   //forwar right I                     
  }                                      
  else if (a=='B') //back                
  {                                      
    digitalWrite(8,LOW);                
    digitalWrite(9,HIGH);                
    digitalWrite(10,HIGH);                 
    digitalWrite(11,LOW);                
  }
  else if (a=='R') //forward right
  {
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if (a=='L') //forward left
  {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }

  else if (a=='S')
  {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  delay(100);

}
