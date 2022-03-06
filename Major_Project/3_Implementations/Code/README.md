#include <NewPing.h>
#include <Servo.h>
#define triPin 12
#define echoPin 13
#define MAX_DISTANCE 50
NewPing sonar(triPin, echoPin, MAX_DISTANCE);
int LEDhijau = 3, LEDmerah = 2;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  pinMode(triPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDmerah, OUTPUT);
  pinMode(LEDhijau, OUTPUT);
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
int duration,jarak,posisi=0,i;
  digitalWrite(triPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2)/29.1;
    Serial.print(jarak);
    Serial.println(" cm");
if(jarak>=5)
  {
    digitalWrite(LEDmerah, LOW);
    digitalWrite(LEDhijau, HIGH);
    myservo.write(180);
}
  else{
    digitalWrite(LEDhijau, LOW);
      digitalWrite(LEDmerah, HIGH);
      myservo.write(90);
  }
  delay(450);

  

}
