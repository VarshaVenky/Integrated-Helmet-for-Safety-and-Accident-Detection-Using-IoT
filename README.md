# 🚴 Smart Helmet and Bike Safety System

This project is a **Smart Helmet and Bike Safety System** designed to enhance safety for motorcyclists by ensuring that a bike can only be started if the helmet is worn, no alcohol is detected, and no accident is detected. In the event of an accident, the system can send an alert with GPS coordinates to a predefined emergency contact.

---

## 🌟 Features

- **Helmet Detection**: Ensures the helmet is worn before the bike can start.
- **Alcohol Detection**: Prevents the bike from starting if alcohol is detected.
- **Accident Detection**: Uses an accelerometer to detect sudden tilt or impact.
- **GPS and GSM Integration**: Sends location-based accident alerts to emergency contacts via SMS.

---

## 📦 Components

- **Arduino Uno**: Main microcontroller used to integrate all modules.
- **ESP-01 WiFi Module**: Adds WiFi connectivity for remote data transmission (if needed).
- **GSM Module**: Sends SMS alerts to emergency contacts.
- **GPS Module**: Provides real-time location coordinates.
- **RF Transmitter and Receiver**: Communicates helmet and bike unit status wirelessly.
- **Sensors**:
  - **Alcohol Sensor**: Detects alcohol presence.
  - **Accelerometer**: Detects tilt and potential accidents.

---

## 📁 Folder Structure

Project-Name/ ├── README.md ├── LICENSE ├── docs/ │ ├── Project_Report.pdf │ └── images/ │ ├── helmet_diagram.png │ ├── bike_diagram.png ├── src/ │ ├── main_code.ino │ ├── sensors/ │ │ ├── alcohol_sensor.ino │ │ ├── accelerometer.ino │ │ └── rf_transmitter.ino │ └── bike_unit/ │ ├── rf_receiver.ino │ ├── gps_module.ino │ └── ignition_control.ino ├── hardware/ │ ├── schematics/ │ └── components/ │ ├── Arduino_Uno.md │ ├── ESP_01.md │ ├── GSM_Module.md │ └── GPS_Module.md └── tests/ ├── unit_tests/ │ ├── test_alcohol_sensor.ino │ ├── test_accelerometer.ino ├── integration_tests/ │ ├── test_system.ino └── system_tests/ ├── test_accident_detection.ino └── test_helmet_connection.ino


---

## 🔧 Setup Instructions

### Hardware Setup

1. **Connect Components**:
   - Connect the alcohol sensor, accelerometer, GPS module, GSM module, and RF transmitter/receiver as specified in the schematics.
   - Ensure that the helmet detection mechanism (e.g., a button or switch) is properly connected.
2. **Power Requirements**:
   - Use a 9V power supply for the Arduino Uno.
   - Use a 3.3V regulator for the ESP-01, GSM, and GPS modules if necessary.

### Software Setup

1. **Arduino IDE**:
   - Install the Arduino IDE if not already installed.
   - Install necessary libraries:
     - [TinyGPS](https://github.com/mikalhart/TinyGPS) for GPS parsing.
     - [VirtualWire](https://www.airspayce.com/mikem/arduino/VirtualWire/) for RF communication.
2. **Upload Code**:
   - Load the main code (`main_code.ino`) and other modules onto the Arduino.
   - Upload test files in `tests/` to verify each component.

---

## 🚀 Usage

1. **Run System Tests**:
   - Start with the individual component tests in the `tests/` folder (e.g., `test_alcohol_sensor.ino`, `test_accelerometer.ino`).
   - Run `test_system.ino` to test integrated functionality.
2. **Main Operation**:
   - Ensure the helmet is worn, no alcohol is detected, and the accelerometer is in a safe position to allow the bike to start.
   - In case of an accident, the GPS location is sent via SMS using the GSM module.

---

## 🔧 Troubleshooting

- **Power Issues**: Ensure components receive the correct voltage, especially the GSM and ESP-01 modules.
- **Serial Communication**: Verify baud rates match across components like the GPS, GSM, and RF modules.
- **Signal Issues**: Use an external antenna for GPS and GSM modules to improve reception.

---
## Contributors

- **Varsha Venkatesh** - [varshavenkatesh3798@gmail.com](mailto:varshavenkatesh3798@gmail.com)
- **Priyanka B Kattimani**
- **Seema R**
- **Shaheen M**
---
## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---


