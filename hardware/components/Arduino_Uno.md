# Arduino Uno

The **Arduino Uno** is the main microcontroller used in this project to control and integrate various modules such as the alcohol sensor, accelerometer, RF transmitter/receiver, and GPS module. This document provides an overview of the Arduino Uno’s specifications and its role in this smart helmet and bike system.

---

## Specifications

- **Microcontroller**: ATmega328P
- **Operating Voltage**: 5V
- **Input Voltage (recommended)**: 7-12V
- **Digital I/O Pins**: 14 (6 with PWM output)
- **Analog Input Pins**: 6
- **Flash Memory**: 32 KB (0.5 KB used by bootloader)
- **SRAM**: 2 KB
- **EEPROM**: 1 KB
- **Clock Speed**: 16 MHz

---

## Role in the Project

The **Arduino Uno** acts as the central controller that:

1. **Collects data from various sensors**:
   - **Alcohol Sensor**: Detects the presence of alcohol.
   - **Accelerometer**: Detects tilt or sudden movement for accident detection.
2. **Communicates with the bike unit**:
   - **RF Transmitter/Receiver**: Sends and receives helmet status data (helmet detection, alcohol detection, accident status).
3. **Processes GPS Data**:
   - **GPS Module**: Provides location data for accident alerts.
4. **Controls the Ignition**:
   - Turns the bike ignition on or off based on the conditions set by the system (e.g., helmet worn, no alcohol detected, no accident detected).

---

## Connections

### Sensor and Module Connections

- **Alcohol Sensor**:
  - Connected to **A0** (Analog Pin 0).
- **Accelerometer**:
  - Connected to **A1, A2, A3** for X, Y, and Z axes, respectively.
- **RF Module (Transmitter)**:
  - Data Pin connected to **Pin 12**.
- **RF Module (Receiver)**:
  - Data Pin connected to **Pin 11**.
- **GPS Module**:
  - RX and TX pins connected to **Pins 3 and 4** for Software Serial communication.
- **Ignition Control (Relay)**:
  - Relay control pin connected to **Pin 8**.

### Power Requirements

The Arduino Uno is powered by an external 9V battery or a 5V USB power supply. Ensure that all connected modules are compatible with 5V logic levels or use appropriate level shifters if necessary.

---

## Code Integration

Each module is managed in separate `.ino` files to modularize the code:

- **alcohol_sensor.ino**: Reads and processes data from the alcohol sensor.
- **accelerometer.ino**: Detects tilt and potential accidents using accelerometer data.
- **rf_transmitter.ino** and **rf_receiver.ino**: Handle RF communication between helmet and bike unit.
- **gps_module.ino**: Reads GPS data for location tracking.
- **ignition_control.ino**: Manages the ignition control based on received data.

---

## Notes

- Ensure proper grounding for all sensors and modules to avoid inconsistencies.
- Regularly calibrate sensors (e.g., alcohol and accelerometer) to ensure accurate data collection.
- Use a voltage regulator if powering multiple components to prevent power fluctuations.
