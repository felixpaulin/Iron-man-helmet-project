#ifdef ARDUINO
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#else
#include <cstdint>
#include <iostream>

struct TwoWire {
  void begin(int, int) {}
} Wire;

class LiquidCrystal_I2C {
public:
  LiquidCrystal_I2C(uint8_t, uint8_t, uint8_t) {}
  void init() {}
  void backlight() {}
  void setCursor(int, int) {}
  void print(const char*) {}
};
#endif

// Set the LCD address to 0x27.
// Change to 0x3F if the backlight turns on but no text appears.
LiquidCrystal_I2C lcd(0x3F, 16, 2);  

void setup() {
  // Target the hardware lines directly wired to that bottom-left 4-pin port
  Wire.begin(21, 22);
 
  // Initialize the screen module
  lcd.init();                      
  lcd.backlight();                
 
  // Line 1 text output
  lcd.setCursor(0, 0);            
  lcd.print("Hello, World!");      
 
  // Line 2 text output
  lcd.setCursor(0, 1);            
  lcd.print("I2C Bus Header OK");
}

void loop() {
  // No loops required for a static text statement
}