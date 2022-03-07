#include <NewPing.h>
#include <Servo.h>
#define triPin 12
#define echoPin 13
#define MAXIMUM_DISTANCE 100
NewPing sonar(triPin, echoPin, MAXIMUM_DISTANCE);
int LED2= 3, LED1 = 2;
Servo myservo;

void setup() {
  
  
  Serial.begin (115200);
    pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(triPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  myservo.attach(9);

}

void loop() {
  
int Threshold,posisi=0,i;
int duration;
  digitalWrite(triPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  Threshold = (duration/2)/29.1;
    Serial.print(Threshold);
    Serial.println(" cm");

    //condition for output
if(Threshold<= 5)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    myservo.write(180);
}
  else{
    digitalWrite(LED2, LOW);
      digitalWrite(LED1, HIGH);
      myservo.write(90);
  }
  delay(200);

  

}
