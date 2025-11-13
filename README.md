 🦾 2-Link Robotic Arm (Arduino Project)

An Arduino sketch to control a 2-link robotic arm using two servo motors.  
The system supports serial-based manual control, smooth angle movement, adjustable speed, and step size customization.

---

## 📄 Overview
This project demonstrates basic 2-joint robotic arm control using Arduino.  
The code allows smooth servo movement and keyboard-driven joint control over the Serial Monitor.

- **Servo 1:** Base joint (θ1)  
- **Servo 2:** Link-2 joint (θ2)  
- **Control Input:** Serial Monitor (9600 baud)

---

## 🛠 Hardware Requirements
- Arduino Uno / Nano / Mega  
- 2 × Servo motors (SG90 / MG90S / MG996R etc.)  
- 5–6V external servo power supply  
- Jumper wires  
- 2-link mechanical arm structure  

---

## 🔌 Wiring
- **Servo 1 (Base):** Signal → Pin **9**  
- **Servo 2 (Link-2):** Signal → Pin **10**  
- Servo VCC → 5–6V external supply  
- Servo GND → Arduino GND (must be common)

---

## 🎮 Serial Control Commands
Open **Serial Monitor @ 9600 baud**.  
Use the following keys:

### **Joint Control**
| Key | Action |
|-----|--------|
| `q` | Increase θ1 (Base) |
| `a` | Decrease θ1 (Base) |
| `w` | Increase θ2 (Link-2) |
| `s` | Decrease θ2 (Link-2) |

### **Preset Positions**
| Key | Action |
|-----|--------|
| `r` | Reset to 90°, 90° |
| `h` | Home (0°, 0°) |
| `p` | Park (180°, 180°) |

### **Step Size**
| Key | Action |
|-----|--------|
| `+` | Increase step size |
| `-` | Decrease step size |

### **Movement Speed**
| Key | Action |
|-----|--------|
| `>` | Faster (lower delay) |
| `<` | Slower (higher delay) |

### **Other**
| Key | Action |
|-----|--------|
| `?` | Show help menu |
| `x` | Stop program |

---

## ⚙️ Code Behavior
- Smooth movement between angles using controlled delay per degree.  
- Angle limits enforced between **0°–180°**.  
- Adjustable step size (default: 5°).  
- Adjustable speed (default delay: 10 ms per degree).  
- Displays current angles after each move.

---

## 📜 Main Functions

### **Smooth Servo Movement**
Moves servo 1 degree at a time:
```cpp
void moveServoSmooth(Servo &servo, int &currentAngle, int targetAngle);
