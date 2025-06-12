Great! Here’s the full end-to-end setup for your Mushroom Kothi IoT simulation on Wokwi, using:

✅ ESP32

✅ DHT22 Sensor

✅ 1 Relay Module for Fan control

✅ 1 LED to simulate Humidifier

✅ LCD 20x4 (I2C) to show temperature & humidity

🔩 Components Required (Wokwi Search Terms):
ESP32 Dev Module

DHT22 Sensor

Relay Module (search: "Relay")

LED

LCD 20x4 with I2C (search: "LCD 20x4 I2C")

🔌 Connections:
DHT22:
DHT22 Pin	ESP32 Pin
VCC	3.3V
GND	GND
DATA	GPIO 15

Relay Module (Fan Control):
Relay Pin	ESP32 Pin
VCC	3.3V
GND	GND
IN	GPIO 2

Note: Connect the relay output to a dummy load or LED in simulation to see the effect.

Humidifier (LED2):
LED Pin	ESP32 Pin
+ (Anode)	GPIO 4 (via 220Ω resistor)
- (Cathode)	GND

LCD 20x4 I2C:
LCD Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
