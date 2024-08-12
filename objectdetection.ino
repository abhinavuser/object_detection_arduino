#include <Servo.h>

int servoPin = 3;
float servPos;

Servo myServo;

int xpin = A0;
int ypin = A1;
int spin = 2;

int xval;
int yval;
int sval;

int dt = 200;
int trigPin = 12;
int echoPin = 11;

int pingTravelTime;
int distInCms;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    pinMode(xpin, INPUT);
    pinMode(ypin, INPUT);
    digitalWrite(spin, HIGH);
    pinMode(spin, INPUT);

    myServo.attach(servoPin);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // put your main code here, to run repeatedly
    xval = analogRead(xpin);
    yval = analogRead(ypin);
    sval = analogRead(spin);

    servPos = (180. / 1023.) * xval;
    myServo.write(servPos);
    delay(dt);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pingTravelTime = pulseIn(echoPin, HIGH);
    distInCms = (171.5 / 10000) * pingTravelTime;

    Serial.print("The object is away at ");
    Serial.print("->");
    Serial.println(distInCms);

    delay(dt);
}
