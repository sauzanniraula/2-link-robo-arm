#include <Servo.h>

Servo servo1;  // Base joint
Servo servo2;  // Link-2 joint

int angle1 = 90;  // Base initial angle
int angle2 = 90;  // Link-2 initial angle
int step = 5;     // Default step size (° per press)
int delayTime = 10; // Movement smoothness (ms delay per degree)

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(angle1);
  servo2.write(angle2);

  Serial.begin(9600);
  printMenu();
}

void loop() {
  if (Serial.available() > 0) {
    char key = Serial.read();

    switch (key) {

      // Base joint control
      case 'q':
        moveServoSmooth(servo1, angle1, constrain(angle1 + step, 0, 180));
        break;
      case 'a':
        moveServoSmooth(servo1, angle1, constrain(angle1 - step, 0, 180));
        break;

      // Link-2 control
      case 'w':
        moveServoSmooth(servo2, angle2, constrain(angle2 + step, 0, 180));
        break;
      case 's':
        moveServoSmooth(servo2, angle2, constrain(angle2 - step, 0, 180));
        break;

      // Reset and park
      case 'r':
        goToPosition(90, 90);
        Serial.println("Reset to 90°, 90°");
        break;
      case 'h':
        goToPosition(0, 0);
        Serial.println("Moved to Home (0°, 0°)");
        break;
      case 'p':
        goToPosition(180, 180);
        Serial.println("Moved to Park (180°, 180°)");
        break;

      // Step size control
      case '+':
        step = constrain(step + 1, 1, 30);
        Serial.print("Step size: ");
        Serial.println(step);
        break;
      case '-':
        step = constrain(step - 1, 1, 30);
        Serial.print("Step size: ");
        Serial.println(step);
        break;

      // Speed control
      case '>':
        delayTime = constrain(delayTime - 2, 2, 50);
        Serial.print("Speed increased (delay = ");
        Serial.print(delayTime);
        Serial.println(" ms)");
        break;
      case '<':
        delayTime = constrain(delayTime + 2, 2, 50);
        Serial.print("Speed decreased (delay = ");
        Serial.print(delayTime);
        Serial.println(" ms)");
        break;

      // Show help
      case '?':
        printMenu();
        break;

      // Stop program
      case 'x':
        Serial.println("Stopping control loop...");
        while (true);
        break;
    }

    Serial.print("Current Angles -> θ1: ");
    Serial.print(angle1);
    Serial.print("°, θ2: ");
    Serial.println(angle2);
  }
}

// Smooth motion between two angles
void moveServoSmooth(Servo &servo, int &currentAngle, int targetAngle) {
  if (targetAngle == currentAngle) return;
  int stepDir = (targetAngle > currentAngle) ? 1 : -1;

  for (int pos = currentAngle; pos != targetAngle; pos += stepDir) {
    servo.write(pos);
    delay(delayTime);
  }
  currentAngle = targetAngle;
}

// Move both servos together
void goToPosition(int a1, int a2) {
  moveServoSmooth(servo1, angle1, a1);
  moveServoSmooth(servo2, angle2, a2);
}

// Display menu
void printMenu() {
  Serial.println("\n=== Advanced 2-Link Robot Arm Control ===");
  Serial.println("Base joint (θ1):  q -> +   |  a -> -");
  Serial.println("Link-2 (θ2):      w -> +   |  s -> -");
  Serial.println("r -> Reset (90°,90°)");
  Serial.println("h -> Home (0°,0°)   p -> Park (180°,180°)");
  Serial.println("+ / - -> Change step size");
  Serial.println("> / < -> Change speed (faster/slower)");
  Serial.println("? -> Show this help menu");
  Serial.println("x -> Stop program");
  Serial.println("-----------------------------------------");
}
