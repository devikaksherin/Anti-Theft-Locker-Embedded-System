#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------- Keypad ----------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ---------- Components ----------
Servo lockServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int servoPin = 10;
const int greenLED = 11;
const int redLED = 12;
const int buzzer = 13;

// ---------- Security ----------
const String correctPassword = "1234";
String enteredPassword = "";

int failedAttempts = 0;
const int maxAttempts = 3;

// Servo positions
const int LOCKED_ANGLE = 0;
const int UNLOCKED_ANGLE = 90;

// ---------- Setup ----------
void setup() {
  Serial.begin(9600);

  lockServo.attach(servoPin);
  lockServo.write(LOCKED_ANGLE);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  lcd.init();
  lcd.backlight();

  showLockedScreen();

  Serial.println("Anti-Theft Locker System");
  Serial.println("System Ready");
}

// ---------- Main Loop ----------
void loop() {

  char key = keypad.getKey();

  if (key) {

    Serial.print("Key pressed: ");
    Serial.println(key);

    // Clear password
    if (key == '*') {
      enteredPassword = "";

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
      lcd.setCursor(0, 1);

      Serial.println("Password cleared");
    }

    // Enter / verify password
    else if (key == '#') {
      checkPassword();
    }

    // Add digit
    else {
      if (enteredPassword.length() < 8) {
        enteredPassword += key;

        lcd.setCursor(0, 1);

        for (int i = 0; i < enteredPassword.length(); i++) {
          lcd.print("*");
        }
      }
    }
  }
}

// ---------- Password Verification ----------
void checkPassword() {

  if (enteredPassword.length() == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Password");
    delay(1500);
    showLockedScreen();
    return;
  }

  // Correct password
  if (enteredPassword == correctPassword) {

    failedAttempts = 0;

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    lcd.setCursor(0, 1);
    lcd.print("Locker Open");

    Serial.println("ACCESS GRANTED");
    Serial.println("Locker unlocked");

    lockServo.write(UNLOCKED_ANGLE);

    delay(5000);

    // Auto-lock
    lockServo.write(LOCKED_ANGLE);

    digitalWrite(greenLED, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Locker Locked");

    Serial.println("Locker automatically locked");

    delay(2000);

    showLockedScreen();
  }

  // Wrong password
  else {

    failedAttempts++;

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
    lcd.setCursor(0, 1);
    lcd.print("Attempt ");
    lcd.print(failedAttempts);
    lcd.print("/3");

    Serial.print("ACCESS DENIED - Attempt ");
    Serial.println(failedAttempts);

    delay(2000);

    digitalWrite(redLED, LOW);

    // Three wrong attempts
    if (failedAttempts >= maxAttempts) {

      alarm();

      failedAttempts = 0;
    }

    enteredPassword = "";

    showLockedScreen();
  }
}

// ---------- Alarm ----------
void alarm() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TOO MANY");
  lcd.setCursor(0, 1);
  lcd.print("ATTEMPTS!");

  Serial.println("!!! SECURITY ALARM !!!");

  digitalWrite(redLED, HIGH);

  for (int i = 0; i < 10; i++) {

    digitalWrite(buzzer, HIGH);
    delay(200);

    digitalWrite(buzzer, LOW);
    delay(200);
  }

  digitalWrite(redLED, LOW);

  Serial.println("Alarm stopped");
}

// ---------- Locked Screen ----------
void showLockedScreen() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LOCKER LOCKED");

  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}
