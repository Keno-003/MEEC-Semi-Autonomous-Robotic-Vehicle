#include <Keyboard.h>

// D-pad buttons
int LBUT = 2;
int RBUT = 3;
int TBUT = 4;
int BBUT = 5;
// Limit buttons
int LLIMIT = 10;
int RLIMIT = 11;
// Motor A 
int IN1 = 6;
int IN2 = 7;
// Motor B
int IN3 = 8;
int IN4 = 9;

// Ultrasonic Sensor Pins
const int trigPin = 12;
const int echoPin = 13;

void setup() {
  pinMode(LBUT, INPUT_PULLUP);
  pinMode(RBUT, INPUT_PULLUP);
  pinMode(TBUT, INPUT_PULLUP);
  pinMode(BBUT, INPUT_PULLUP);
  pinMode(RLIMIT, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to measure distance
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Convert to cm

  return distance;
}

void loop() {
  long distance = measureDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) {  // If an obstacle is closer than 30 cm
    stopMotors();
    delay(500);
    backward();  // Move backward
    delay(1000);
    turnRight(); // Turn to avoid obstacle
    delay(1000);
    stopMotors();
  } else {
    forward();  // Move forward if no obstacle
  }
}
