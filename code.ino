#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

#define FAN_RELAY 2
#define HUMIDIFIER_LED 4

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(FAN_RELAY, OUTPUT);
  pinMode(HUMIDIFIER_LED, OUTPUT);
  digitalWrite(FAN_RELAY, LOW);
  digitalWrite(HUMIDIFIER_LED, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mushroom Kothi");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor Error");
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error      ");
    delay(1000);
    return;
  }

  // Display values on LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C  ");

  lcd.setCursor(0, 2);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print(" %  ");

  // Fan Control
  if (temp > 28) {
    digitalWrite(FAN_RELAY, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("Fan: ON ");
  } else {
    digitalWrite(FAN_RELAY, LOW);
    lcd.setCursor(0, 3);
    lcd.print("Fan: OFF");
  }

  // Humidifier Control
  if (hum < 70) {
    digitalWrite(HUMIDIFIER_LED, HIGH);
    lcd.setCursor(10, 3);
    lcd.print("Hum: ON ");
  } else {
    digitalWrite(HUMIDIFIER_LED, LOW);
    lcd.setCursor(10, 3);
    lcd.print("Hum: OFF");
  }

  delay(1000);
}
