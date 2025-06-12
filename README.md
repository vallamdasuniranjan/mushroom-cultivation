# 🍄 Mushroom Kothi IoT Simulation – Wokwi

This project simulates a basic IoT prototype to monitor and control temperature and humidity in a 10x10 ft mushroom cultivation room using Wokwi.

---

## ✅ Components Used

- **ESP32 Dev Module**
- **DHT22 Sensor** (for temperature and humidity)
- **Relay Module** (to control fan)
- **1 LED** (to simulate humidifier)
- **LCD 20x4 with I2C interface** (for live data display)

---

## 🔩 Wokwi Search Terms

- `ESP32 Dev Module`
- `DHT22`
- `Relay`
- `LED`
- `LCD 20x4 I2C`

---

## 🔌 Circuit Connections

### 🧪 DHT22 Sensor

| DHT22 Pin | ESP32 Pin |
|-----------|------------|
| VCC       | 3.3V       |
| GND       | GND        |
| DATA      | GPIO 15    |

---

### 🌬 Relay Module (Fan Control)

| Relay Pin | ESP32 Pin |
|-----------|------------|
| VCC       | 3.3V       |
| GND       | GND        |
| IN        | GPIO 2     |

> 💡 *Note: Connect relay output to a dummy load or LED in Wokwi to visualize effect.*

---

### 💧 Humidifier (LED2 Simulation)

| LED Pin    | ESP32 Pin |
|------------|------------|
| Anode (+)  | GPIO 4 (via 220Ω resistor) |
| Cathode (–)| GND        |

---

### 📺 LCD 20x4 I2C Display

| LCD Pin | ESP32 Pin |
|---------|------------|
| VCC     | 3.3V       |
| GND     | GND        |
| SDA     | GPIO 21    |
| SCL     | GPIO 22    |

---

## 📚 Required Libraries

### 1. **DHT Sensor Library**
- **Author:** Adafruit
- **Usage:** Handles DHT22 sensor readings

### 2. **LiquidCrystal_I2C**
- **Author:** Frank de Brabander
- **Usage:** Interfaces with 20x4 I2C LCD

---

## 🧠 How to Install Libraries in Wokwi

1. Open your Wokwi project.
2. Click the **“Libraries”** tab on the left toolbar.
3. Search and install:
   - `DHT sensor library`
   - `LiquidCrystal_I2C`
Once installed, add to your code:
```cpp
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
---
## 💡 Functional Logic

- If **Temperature > 28°C**, the **fan (Relay + LED1)** is turned ON.
- If **Humidity < 70%**, the **humidifier (LED2)** is turned ON.
- Sensor readings are **updated and displayed every second** on the LCD screen.

---

## 🖥️ Output Example (Serial/LCD)
![Screenshot 2025-06-12 102918](https://github.com/user-attachments/assets/7e1ae53b-fc65-4df7-a350-b6d6390724f5)
![Screenshot 2025-06-12 102939](https://github.com/user-attachments/assets/3240e9c1-7150-427e-be02-aaedb229f775)

