# GSM Module

The **GSM module** (e.g., SIM800L or similar) is used in this project to enable cellular communication, allowing the system to send SMS alerts in case of an accident or emergency. This module connects to the cellular network and can send SMS messages or even make calls if required.

---

## Specifications

- **Operating Voltage**: 3.4V - 4.4V (typically powered with a 3.7V Li-Ion battery)
- **Communication**: UART (TX/RX)
- **Frequency Bands**: Quad-band 850/900/1800/1900 MHz (check module specs)
- **Features**:
  - SMS sending and receiving
  - Voice call capability
  - GPRS data connectivity

---

## Role in the Project

The **GSM module** is used to:

1. **Send SMS Alerts**: Transmit accident alert messages to a predefined emergency contact with GPS coordinates if an accident is detected.
2. **Remote Communication**: Allows for real-time alerts and remote status updates through cellular networks.

---

## Pin Configuration

| Pin | Function           |
|-----|---------------------|
| VCC | Power (3.7V - 4.4V)|
| GND | Ground             |
| TXD | Transmit Data      |
| RXD | Receive Data       |
| RST | Reset (optional)   |

> **Important Note**: The GSM module operates at 3.3V for communication pins, so use a level shifter if connecting to a 5V microcontroller like the Arduino Uno.

---

## Setup Instructions

### Hardware Setup

1. **Power Supply**: The GSM module requires a stable power source in the range of 3.7V to 4.4V. A 3.7V Li-Ion battery is often used, or a dedicated power regulator circuit if connecting to a higher voltage source.
2. **UART Communication**:
   - Connect the TX pin of the GSM module to the RX pin of the Arduino (through a level shifter if necessary).
   - Connect the RX pin of the GSM module to the TX pin of the Arduino (also through a level shifter).
3. **Antenna**: Ensure that an antenna is connected to improve signal reception.

---

## Programming the GSM Module

The GSM module can be controlled using AT commands sent from the Arduino. Here’s a basic setup:

1. **Initialize Communication**:
   - Set up serial communication with the GSM module using `Serial.begin()` at the required baud rate (usually 9600 or 115200).
2. **Send SMS**:
   - The following AT commands are used to send an SMS:
     - `AT`: Test communication with the GSM module.
     - `AT+CMGF=1`: Set the module to SMS text mode.
     - `AT+CMGS="+911234567890"`: Specify the recipient’s phone number (replace with actual number).
     - Send the message text, followed by `Ctrl+Z` (ASCII code 26) to send the SMS.

---

## Code Example to Send SMS

Here’s a basic code snippet to send an SMS with an accident alert message and GPS coordinates.

```cpp
#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(5, 6);  // RX, TX pins for GSM module

void setup() {
    Serial.begin(9600);       // For debugging
    gsmSerial.begin(9600);    // GSM module baud rate
    Serial.println("GSM Module Initialized");

    sendSMS("Accident detected! Latitude: 12.3456, Longitude: 65.4321");  // Example GPS data
}

void loop() {
    // Placeholder for any continuous operations
}

void sendSMS(String message) {
    gsmSerial.println("AT");                 // Check communication
    delay(100);
    gsmSerial.println("AT+CMGF=1");          // Set SMS mode to text
    delay(100);
    gsmSerial.println("AT+CMGS=\"+911234567890\"");  // Replace with emergency contact
    delay(100);
    gsmSerial.print(message);                // Send the message
    gsmSerial.write(26);                     // ASCII code for Ctrl+Z to send the SMS
    Serial.println("SMS Sent: " + message);
}

## Integration with the Project

The **GSM module** integrates with the accident detection system in this project. When an accident is detected by the accelerometer, the Arduino will:

1. **Obtain GPS coordinates** from the GPS module.
2. **Format a message** with the accident alert and GPS location.
3. **Send the alert message** via SMS to the predefined emergency contact using the GSM module.

---

## Troubleshooting Tips

- **Power Issues**: The GSM module requires a stable power supply, preferably a Li-Ion battery. Ensure adequate power, as insufficient power can lead to module restarts.
- **Antenna Placement**: Use a proper antenna to improve network reception, especially in low-signal areas.
- **Serial Communication**: Verify the baud rate of the GSM module and ensure it matches the software serial setup on the Arduino.
- **AT Commands**: If AT commands do not respond, double-check the wiring and make sure the GSM module is powered correctly.
