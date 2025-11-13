Description

This project demonstrates basic servo control and simple coordinated motion for a planar 2-joint arm (base + link-2). The Arduino reads single-character commands from the Serial Monitor and moves servos smoothly between target angles. It’s suitable for learning kinematics basics, servo control and interactive demos.

Features

Two-servo control (base and link-2).

Smooth incremental motion between angles.

Interactive serial control with single-key commands.

Adjustable step size (angle increment) and motion speed.

Preset positions: Reset (90°,90°), Home (0°,0°), Park (180°,180°).

Hardware

Arduino Uno / Nano / Mega

2 × Servo motors (e.g., SG90, MG90S, MG996R depending on torque needs)

External servo power supply recommended (do NOT power high-torque servos from Arduino 5V)

Jumper wires and mechanical links for a 2-link arm

Wiring

servo1 (base joint) → Arduino digital pin 9

servo2 (link-2 joint) → Arduino digital pin 10

Connect servo GND to Arduino GND and to external power supply GND

Connect servo VCC to external 5–6V supply (if required)

Serial Controls (open Serial Monitor at 9600 baud)

Single characters (no Enter required for many terminals; Serial Monitor may require newline depending on setting):

q — Increase base joint (θ1) by current step.

a — Decrease base joint (θ1) by current step.

w — Increase link-2 joint (θ2) by current step.

s — Decrease link-2 joint (θ2) by current step.

r — Reset to (90°, 90°).

h — Home (0°, 0°).

p — Park (180°, 180°).

+ — Increase step size (angle increment) by 1° (max 30°).

- — Decrease step size by 1° (min 1°).

> — Increase speed (reduce per-degree delay by 2 ms, min 2 ms).

< — Decrease speed (increase per-degree delay by 2 ms).

? — Show help menu.

x — Stop program (enters infinite loop).

After each command the sketch prints the current θ1/θ2 values.

Tunable parameters (in 2armlinkrobo.ino)

int angle1 = 90; — initial base angle

int angle2 = 90; — initial link-2 angle

int step = 5; — degrees moved per keypress (adjustable with + / -)

int delayTime = 10; — ms delay per degree for smooth motion (adjustable with > / <)

How it works (brief)

moveServoSmooth(servo, currentAngle, targetAngle) increments servo angle one degree at a time and delays delayTime ms between degrees to create smooth motion.

goToPosition(a1, a2) moves both servos sequentially to target positions (first servo1 then servo2).

Serial input is polled in loop() and mapped to actions via a switch statement.

Calibration tips

Start with step = 1 and delayTime = 10 to observe small, slow movements.

If servos jitter, increase delayTime slightly.

If movements are too slow, reduce delayTime but ensure servos can keep up.

Check joint physical limits to avoid mechanical binding — software constrains angles to 0–180.
