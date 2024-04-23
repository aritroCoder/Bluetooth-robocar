#include <SoftwareSerial.h>


char t;
 
void setup() {
pinMode(5,OUTPUT);   //left motors forward
pinMode(4,OUTPUT);   //left motors reverse
pinMode(3,OUTPUT);   //right motors forward
pinMode(2,OUTPUT);   //right motors reverse  
Serial.begin(9600);
digitalWrite(12, HIGH);
SoftwareSerial Serial(10,11);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  Serial.println("Forward");
  digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(4,HIGH);
  digitalWrite(2,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(3,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(5,HIGH);
}


 
else if(t == 'S'){      //STOP (all motors stop)
  Serial.println("Stop");
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}
delay(100);
}
