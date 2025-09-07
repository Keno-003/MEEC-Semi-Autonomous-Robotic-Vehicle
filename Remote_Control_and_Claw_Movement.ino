#include <Keyboard.h>
#include <Servo.h>

// D-pad buttons
int LBUT = 2;
int RBUT = 3;
int TBUT = 4;
int BBUT = 5;

// Limit switches
int LLIMIT = 10;  // Left limit switch
int RLIMIT = 11;  // Right limit switch

// Motor A (for movement)
int IN1 = 6;
int IN2 = 7;
// Motor B (for movement)
int IN3 = 8;
int IN4 = 9;

// // Joystick pins
// int VRX = A0; // X-axis
// int VRY = A1; // Y-axis

// Servo motors
Servo clawServo;  // Moves claw up/down
Servo clampServo; // Opens/closes clamp

int clawPos = 90;   // Initial position for claw movement
int clampPos = 0;   // Initial position for clamp (0 = closed, 90 = open)
bool clampOpen = false; // Track clamp state

void setup() {
  // pinMode(VRX, INPUT);
  // pinMode(VRY, INPUT);
  pinMode(LBUT, INPUT_PULLUP);
  pinMode(RBUT, INPUT_PULLUP);
  pinMode(TBUT, INPUT_PULLUP);
  pinMode(BBUT, INPUT_PULLUP);
  pinMode(RLIMIT, INPUT_PULLUP);
  pinMode(LLIMIT, INPUT_PULLUP);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

  // // Attach servos
  // clawServo.attach(12);  // Servo that moves claw up/down
  // clampServo.attach(13); // Servo that opens/closes clamp

  // clawServo.write(clawPos);  // Set initial positions
  // clampServo.write(clampPos);
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

void loop() {
  // Read joystick values
  // int xValue = analogRead(VRX);
  // int yValue = analogRead(VRY);

  // Read D-pad buttons
  bool up = digitalRead(TBUT) == HIGH;
  bool down = digitalRead(BBUT) == HIGH;
  bool left = digitalRead(LBUT) == HIGH;
  bool right = digitalRead(RBUT) == HIGH;

  // Read limit switches
  bool leftLimitPressed = digitalRead(LLIMIT) == HIGH;
  bool rightLimitPressed = digitalRead(RLIMIT) == HIGH;

  // Serial.print("X: "); Serial.print(xValue);
  // Serial.print(" | Y: "); Serial.print(yValue);
  Serial.print(" | Up: "); Serial.print(up);
  Serial.print(" | Down: "); Serial.print(down);
  Serial.print(" | Right: "); Serial.print(right);
  Serial.print(" | left: "); Serial.println(left);
//   Serial.println(right);


  // ---- VEHICLE MOVEMENT ----
  if (up) {
    forward();
  } else if (down) {
    backward();
  } else if (left) {
    turnLeft();
  } else if (right) {
    turnRight();
  } else {
    stopMotors();
  }

  // ---- CLAW MOVEMENT (Up/Down) ----
  // if (leftLimitPressed) { // Only move claw when left limit switch is pressed
  //   if (up && clawPos < 180) {  // Move claw up
  //     clawPos += 5;
  //   } else if (down && clawPos > 0) {  // Move claw down
  //     clawPos -= 5;
  //   }
    // clawServo.write(clawPos);
    // delay(100); // Smooth movement
  


  // // ---- CLAMP TOGGLE (Open/Close) ----
  // if (rightLimitPressed) {  // Pressing right limit toggles clamp
  //   clampOpen = !clampOpen;  // Toggle state
  //   if (clampOpen) {
  //     clampPos = 90;  // closed position
  //   } else {
  //     clampPos = 0;   // open position
  //   }
  //   clampServo.write(clampPos);
  //   delay(300); // Prevent rapid toggling
  // } 

  delay(50);
}