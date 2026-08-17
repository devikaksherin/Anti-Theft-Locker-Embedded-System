# 🔐 Anti-Theft Locker System using Arduino

## 📌 Project Overview

The Anti-Theft Locker System is an embedded security system designed to protect a locker using password-based authentication.

The user enters a password through a 4×4 keypad. The Arduino verifies the entered password and controls a servo motor that represents the locker locking mechanism.

If the password is correct, the locker unlocks and the green LED indicates successful authentication. If the password is incorrect, access is denied and the red LED indicates an invalid attempt. After three consecutive incorrect attempts, a buzzer alarm is activated as a security alert.

This project was developed and tested as a virtual simulation using Wokwi.

## 🎯 Objectives

- Implement password-based locker authentication.
- Control a servo motor as the locker lock mechanism.
- Display system status using a 16×2 I2C LCD.
- Indicate access status using red and green LEDs.
- Detect repeated incorrect password attempts.
- Activate an alarm after three failed attempts.
- Automatically lock the locker after successful access.
- Test and validate the system using virtual simulation.

## ⚙️ Features

- 4×4 matrix keypad for password input
- Password authentication
- 16×2 I2C LCD display
- Servo-based lock control
- Green LED for access granted
- Red LED for access denied
- Buzzer alarm
- Three-attempt security mechanism
- Automatic re-locking
- `*` key for clearing entered password
- `#` key for submitting the password
- Serial Monitor for debugging and status information

## 🧰 Components Used

| Component | Quantity |
|---|---:|
| Arduino UNO | 1 |
| 4×4 Matrix Keypad | 1 |
| 16×2 I2C LCD | 1 |
| Servo Motor | 1 |
| Green LED | 1 |
| Red LED | 1 |
| 220Ω Resistor | 2 |
| Buzzer | 1 |
| Jumper Wires | As required |

## 🔌 Pin Configuration

| Component | Arduino Pin |
|---|---|
| Keypad R1 | D2 |
| Keypad R2 | D3 |
| Keypad R3 | D4 |
| Keypad R4 | D5 |
| Keypad C1 | D6 |
| Keypad C2 | D7 |
| Keypad C3 | D8 |
| Keypad C4 | D9 |
| Servo Signal | D10 |
| Green LED | D11 |
| Red LED | D12 |
| Buzzer | D13 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## 🔐 Authentication Logic

The default password used for the simulation is:

`1234`

### Correct Password

User enters the password → Password verification → Password correct → Access Granted → Green LED ON → Servo unlocks → Locker remains open temporarily → Servo automatically returns to the locked position.

### Incorrect Password

User enters the password → Password verification → Password incorrect → Access Denied → Red LED ON → Failed-attempt counter increases.

### Three Failed Attempts

Wrong password → Attempt 1/3 → Wrong password → Attempt 2/3 → Wrong password → Attempt 3/3 → Security Alarm → Buzzer activated → Locker remains locked.

## 🖥️ LCD Messages

The LCD displays system status such as:

- `LOCKER LOCKED`
- `Enter Password:`
- `Access Granted`
- `Locker Open`
- `Access Denied`
- `Attempt 1/3`
- `Attempt 2/3`
- `Attempt 3/3`
- `TOO MANY ATTEMPTS!`

## 🧪 Testing

The system was tested using the Wokwi virtual simulation environment.

| Test | Expected Result | Status |
|---|---|---|
| Correct password `1234#` | Locker unlocks | Passed |
| Wrong password | Access denied | Passed |
| Three wrong attempts | Alarm activates | Passed |
| `*` key | Clears entered password | Passed |
| `#` key | Submits password | Passed |
| Automatic locking | Servo returns to locked position | Passed |
| Green LED | Indicates successful access | Passed |
| Red LED | Indicates denied access | Passed |
| Buzzer | Activates after three failed attempts | Passed |

## 🖥️ Simulation

The project was implemented and tested using Wokwi, an online electronics simulation platform.

The simulation demonstrates:

- Password entry through the keypad
- LCD status display
- Password verification
- Servo-based locking and unlocking
- LED status indication
- Failed-attempt detection
- Buzzer alarm
- Automatic locking

Screenshots demonstrating the different operating states are included in this repository.

🚀 Future Improvements

The system can be further enhanced by adding:

RFID authentication
Fingerprint authentication
GSM/SMS security alerts
IoT-based monitoring
Mobile application control
Tamper detection
Multiple user authentication
Remote locker status monitoring
📚 Learning Outcomes

Through this project, the following concepts were practiced:

Arduino programming
Embedded C/C++ programming
Keypad interfacing
LCD interfacing
Servo motor control
LED and buzzer control
Password authentication
Security logic implementation
Failed-attempt detection
Virtual hardware simulation
Embedded-system testing and debugging
👩‍💻 Project Information

Project: Anti-Theft Locker System
Project Type: Embedded Systems Course Project
Platform: Arduino UNO
Simulation: Wokwi

📜 License

This project is created for educational and academic purposes.
├── docs/
├── README.md
└── .gitignore
