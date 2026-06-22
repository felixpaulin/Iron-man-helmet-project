#include <ESP32Servo.h>
#include <Arduino.h>

const int BUTTON_PIN = 12;
const int SERVO_PIN = 18;

Servo right_cheek;

bool servoAt10 = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  right_cheek.attach(SERVO_PIN);
  right_cheek.write(120);
  delay(500);
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(20);
    if (digitalRead(BUTTON_PIN) == LOW) {
      servoAt10 = !servoAt10;
      right_cheek.write(servoAt10 ? 10 : 120);
    }
  }

  lastButtonState = buttonState;
}
