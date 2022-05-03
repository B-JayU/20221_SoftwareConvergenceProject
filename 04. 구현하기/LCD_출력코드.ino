#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 16,2);

void setup() {
  Serial.begin(9600);

  Serial.println("\nI2C Scanner");
  Serial.println("Scanning...");
  byte device_count = 0;

  Wire.begin();
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device found at address 0x");
      Serial.print(address, HEX);
      Serial.println("  !");
      device_count++;
      delay(1);
    }
  }
  Serial.println("Done");
  Serial.print("Found ");
  Serial.print(device_count);
  Serial.println(" device(s).");

  lcd.begin();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(2,0);
  lcd.print("Hello world!");
  lcd.setCursor(2,1);
  lcd.print("LCD Tutorial");
}

void loop() {

}
