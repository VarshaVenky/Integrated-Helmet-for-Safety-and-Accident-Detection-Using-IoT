# ESP-01 WiFi Module

The ESP-01 is a WiFi module based on the ESP8266 chip, which adds internet connectivity to the project. This module enables the system to communicate over a WiFi network, allowing for remote alerts and data transmission, such as sending accident alerts or tracking information.

---

## Specifications

- **Chip**: ESP8266
- **Operating Voltage**: 3.3V (Do not connect to 5V; use a voltage regulator if needed)
- **WiFi Standards**: 802.11 b/g/n
- **Flash Memory**: 512 KB to 1 MB
- **I/O Pins**: 2 (GPIO0, GPIO2)
- **Baud Rate**: Default 115200 (can be changed if required)
- **Communication**: UART (TX/RX)

---

## Role in the Project

The ESP-01 module is used to send data to a remote server or a mobile device in cases such as:

1. **Accident Alerts**: Transmit location data to notify emergency contacts if an accident is detected.
2. **Remote Data Monitoring**: Enables remote monitoring by transmitting data like helmet status, alcohol detection, and location to a dashboard or cloud-based server.

---

## Pin Configuration

| Pin    | Function           |
|--------|---------------------|
| VCC    | Power (3.3V)       |
| GND    | Ground             |
| TX     | UART Transmit      |
| RX     | UART Receive       |
| GPIO0  | General I/O        |
| GPIO2  | General I/O        |
| RST    | Reset              |


**Important Note**: The ESP-01 operates at 3.3V. Connecting it directly to 5V (such as from the Arduino Uno) can damage the module. Use a voltage regulator or a logic level shifter if necessary.

---

## Setup Instructions

### Hardware Setup

1. **Power Supply**: Connect the VCC pin to a stable 3.3V power source and GND to ground.
2. **UART Communication**:
- Connect the TX pin of the ESP-01 to the RX pin of the Arduino (through a level shifter if necessary).
- Connect the RX pin of the ESP-01 to the TX pin of the Arduino (also through a level shifter).
3. **GPIO Pins**:
-For programming the ESP-01, pull GPIO0 to GND to enter programming mode.
-GPIO2 should be connected to VCC or left unconnected in most use cases.

### Programming the ESP-01

The ESP-01 can be programmed with the Arduino IDE using a USB-to-Serial adapter. Alternatively, it can communicate with the Arduino as a WiFi module through AT commands.

1. **Install ESP8266 Board**:

- In the Arduino IDE, go to File > Preferences.
- Add the URL http://arduino.esp8266.com/stable/package_esp8266com_index.json to the **Additional Boards Manager URLs**.
- Go to **Tools** > **Board** > **Boards Manager** and search for **ESP8266**. Install the ESP8266 board package.
2. **Basic Code Example** (if programming directly):

#include <ESP8266WiFi.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    // Code to handle data transmission, e.g., HTTP requests to a server
}

3. **Using AT Commands**:

- If using the ESP-01 in AT command mode, you can send commands from the Arduino to control it.
- Example AT commands:
	- AT: Test communication.
	- AT+RST: Reset the module.
	- AT+CWMODE=1: Set to station mode.
	- AT+CWJAP="SSID","PASSWORD": Connect to WiFi.
	- AT+CIPSTART="TCP","server",80: Start a TCP connection.

### Integration with the Project

The ESP-01 can be used in the main program to:

- **Send HTTP Requests**: Use the ESP-01 to send HTTP requests to a remote server to log data or alert emergency contacts.
- **Data Transmission**: Transmit sensor data (e.g., accident status and GPS coordinates) to a mobile app or cloud platform.

---

## Troubleshooting Tips

1. **Power Issues**: Ensure a stable 3.3V power source; using 5V will damage the module.
2. **UART Communication**: Check baud rate compatibility with the Arduino and the module. Default baud rate is often 115200, which can be set lower if necessary.
3. **Flashing Firmware**: If using the ESP-01 in programming mode, make sure GPIO0 is connected to GND during flashing and disconnected afterward.
