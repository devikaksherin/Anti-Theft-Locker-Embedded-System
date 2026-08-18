# Testing Documentation

## Test Cases

| Test Case | Input | Expected Result |
|---|---|---|
| Correct Password | 1234# | Access Granted |
| Wrong Password | Incorrect password + # | Access Denied |
| Three Wrong Attempts | Three incorrect passwords | Security Alarm |
| Clear Password | * | Password cleared |
| Submit Password | # | Password verification |
| Auto Lock | Correct password | Locker locks automatically |
| Servo Unlock | Correct password | Servo moves to unlocked position |
| Servo Lock | After delay | Servo returns to locked position |

## Testing Result

The system is tested using the Wokwi virtual simulation.

Each feature should be marked as PASS only after it has been successfully verified.

## Demonstration Password

1234

## Keypad Controls

- 0-9 → Enter password
- * → Clear password
- # → Submit password
