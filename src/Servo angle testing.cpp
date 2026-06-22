#include <ESP32Servo.h>

const int BUTTON_PIN = 12;
const int SERVO_PIN = 18;

Servo myServo;

bool servoAt90 = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  myServo.attach(SERVO_PIN);
  myServo.write(90);
  delay(500);
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(20);
    if (digitalRead(BUTTON_PIN) == LOW) {
      servoAt90 = !servoAt90;
      myServo.write(servoAt90 ? 90 : 40);
    }
  }

  lastButtonState = buttonState;
}
