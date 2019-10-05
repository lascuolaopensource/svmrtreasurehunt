#include <Servo.h>
Servo myservo;
Servo myservo1;
int btn1 = 5;
int btn2 = 6;
int btn3 = 7;

void setup() {
  Serial.begin(115200);
  myservo.attach(3); 
  myservo1.attach(4);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);  
  pinMode(btn3, INPUT_PULLUP);
}

void loop() {
  int pos, c, reach;
  c = 0;
  if (!digitalRead(btn1)) c++;
  if (!digitalRead(btn2)) c++;
 // if (!digitalRead(btn3)) c++;
    
  if (c == 0) reach = 0;
  else if (c == 1)reach = 76;
  else if (c == 2) reach = 76;
  else if (c == 3) reach = 180;
 
  while(myservo.read() != reach){
    if (myservo.read() < reach) myservo.write(myservo.read() + 1);
    else myservo.write(myservo.read() - 1);
    delay(4);
  }
  Serial.println(myservo.read());

  delay(10);
 }
