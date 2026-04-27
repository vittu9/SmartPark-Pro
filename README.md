# 🚗 SmartPark Pro – IoT Based Car Parking System

SmartPark Pro is an intelligent parking management system designed using **Arduino UNO** and **NodeMCU ESP8266**.
It automates vehicle entry/exit, monitors parking slots in real-time, and improves efficiency using IoT technology.

---

## 👨‍💻 Developer

**Vengala Vishnu**
🎓 B.Tech CSE (IoT)
🛠 Interested in IoT, Web Development, and Smart Systems
🌐 GitHub: https://github.com/vittu9

---

## 📌 Key Features

* 🚘 Automatic vehicle detection using IR sensors
* 🚧 Smart gate control using Servo motor
* 📟 Real-time slot availability displayed on LCD
* 📡 Live data transmission using NodeMCU
* 📱 Mobile monitoring using Blynk IoT app
* ✅ Tracks multiple parking slots efficiently

---

## 🛠️ Hardware Components

* Arduino UNO
* NodeMCU ESP8266
* IR Sensors (for entry, exit, and slots)
* Servo Motor (Gate control)
* 16x2 LCD with I2C module
* Jumper wires & Breadboard
* Power Supply

---

## 💻 Software Requirements

* Arduino IDE
* Blynk IoT Application
* ESP8266 Board Package
* Required Libraries (Servo, LiquidCrystal_I2C, SoftwareSerial)

---

## ⚙️ System Overview

* Entry sensor detects incoming vehicle
* Exit sensor detects outgoing vehicle
* Slot sensors monitor parking availability
* Servo motor controls gate opening/closing
* LCD displays available slots
* NodeMCU sends real-time updates to mobile app

---

## 🔌 Pin Configuration

### Arduino UNO

* Entry Sensor → D8
* Exit Sensor → D9
* Slot Sensors → D5, D6, D7
* Servo Motor → D10
* Communication with NodeMCU → D2 (TX), D3 (RX)

---

## 📲 Blynk Integration

* Displays real-time parking slot status
* Uses virtual pins for monitoring
* Helps users check availability remotely

---

## 🚦 Working Logic

* Vehicle at entry + slot available → Gate opens
* Slot occupied → Availability updated
* Vehicle exits → Slot becomes free
* No slots available → Entry denied

---

## 🚀 Enhancements Added

* Improved code readability and structure
* Better LCD display messages
* Faster response time (reduced delays)
* Clear modular functions for slot checking

---

## 🔮 Future Improvements

* 💳 Online payment integration
* 📷 License plate recognition system
* 📊 Web dashboard for analytics
* 🧠 AI-based parking prediction

---
## 📊 System Architecture Diagram

The following diagram represents the overall workflow of the Smart Parking System:

```text
          🚗 Vehicle
              │
      ┌───────────────┐
      │ IR Sensors    │
      │ (Entry/Exit & │
      │ Parking Slots)│
      └──────┬────────┘
             │
        ┌───────────┐
        │ Arduino   │
        │ UNO       │
        └────┬──────┘
             │
   ┌─────────┼─────────┐
   │         │         │
Servo      LCD     NodeMCU
Motor    Display   ESP8266
(Gate)   (Slots)      │
                      │
                📱 Blynk App
                (Real-time Status)
```


## 🙏 Acknowledgement

This project was rebuilt after loss of original files and inspired by similar IoT-based parking system implementations available on GitHub.
Additional improvements and modifications have been made for better performance and understanding.

---


## 📌 Conclusion

SmartPark Pro provides a simple and cost-effective solution for parking automation.
It demonstrates how IoT can be used to improve real-world systems with efficiency and accuracy.

---
