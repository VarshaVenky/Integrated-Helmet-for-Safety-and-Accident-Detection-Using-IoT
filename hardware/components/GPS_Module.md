# GPS Module

The **GPS module** (e.g., NEO-6M, SIM28, or similar) provides geographic location data to the system, including latitude, longitude, and sometimes altitude. This information is essential for sending the user’s location in case of an accident or emergency.

---

## Specifications

- **Operating Voltage**: 3.3V - 5V
- **Communication Protocol**: UART (TX/RX)
- **Positioning Accuracy**: 2.5 meters CEP (circular error probable)
- **Cold Start Time**: 27 seconds (varies by model)
- **Hot Start Time**: 1 second (varies by model)
- **Output Format**: NMEA 0183 (standard GPS output format)

---

## Role in the Project

The **GPS module** is used to:

1. **Provide Location Data**: Collects real-time GPS coordinates (latitude and longitude) for tracking.
2. **Accident Alert Integration**: Transmits location data with accident alerts sent via the GSM module.
3. **Remote Monitoring**: Enables remote users to access location data for tracking the bike’s position.

---

## Pin Configuration

| Pin | Function               |
|-----|-------------------------|
| VCC | Power (3.3V - 5V)      |
| GND | Ground                 |
| TX  | UART Transmit          |
| RX  | UART Receive           |
| PPS | Pulse per second (optional, for timing) |

> **Note**: The GPS module typically supports 3.3V or 5V input, but check your module specifications.

---

## Setup Instructions

### Hardware Setup

1. **Power Supply**: Connect the VCC pin to a 3.3V or 5V power supply, depending on the module specifications. Connect the GND to the common ground.
2. **UART Communication**:
   - Connect the TX pin of the GPS module to the RX pin of the Arduino.
   - Connect the RX pin of the GPS module to the TX pin of the Arduino.
3. **Antenna**: Some GPS modules have a built-in antenna, while others require an external antenna. Make sure the antenna is connected for optimal satellite reception.

---

## Programming the GPS Module

The GPS module communicates using standard NMEA sentences (e.g., `$GPGGA`, `$GPRMC`), which provide latitude, longitude, and other data. The **TinyGPS** or **TinyGPS++** library can be used in Arduino to parse these sentences.

### Basic Code Example for GPS Data

Here’s a basic code example to retrieve and display latitude and longitude data.

```cpp
#include <TinyGPS.h>
#include <SoftwareSerial.h>

TinyGPS gps;
SoftwareSerial gpsSerial(4, 3); // RX, TX pins for GPS module

void setup() {
    Serial.begin(9600);
    gpsSerial.begin(9600);   // GPS module baud rate
    Serial.println("GPS Module Initialized");
}

void loop() {
    while (gpsSerial.available()) {
        char c = gpsSerial.read();
        if (gps.encode(c)) {
            displayGPSInfo();
        }
    }
}

void displayGPSInfo() {
    float latitude, longitude;
    unsigned long age;
    gps.f_get_position(&latitude, &longitude, &age);

    if (latitude == TinyGPS::GPS_INVALID_F_ANGLE) {
        Serial.println("Latitude: Invalid");
    } else {
        Serial.print("Latitude: ");
        Serial.println(latitude, 6);
    }

    if (longitude == TinyGPS::GPS_INVALID_F_ANGLE) {
        Serial.println("Longitude: Invalid");
    } else {
        Serial.print("Longitude: ");
        Serial.println(longitude, 6);
    }

    if (age == TinyGPS::GPS_INVALID_AGE) {
        Serial.println("GPS data is invalid.");
    } else {
        Serial.print("GPS data age (ms): ");
        Serial.println(age);
    }

    delay(2000);  // Delay for readability
}

## Integration with the Project

The **GPS module** can be used in conjunction with the GSM module to send location-based accident alerts:

1. **Accident Detection**: If an accident is detected, retrieve the GPS coordinates.
2. **Send Alert**: Format the location data and send it via SMS using the GSM module to notify emergency contacts.
3. **Remote Tracking**: Allows real-time tracking of the bike’s location for safety monitoring.

---

## Troubleshooting Tips

- **Signal Acquisition**: GPS modules require an unobstructed view of the sky. Use an external antenna if the signal is weak.
- **Power Stability**: GPS modules can be power-hungry, especially during cold starts. Ensure a stable power source.
- **Data Parsing**: Use the TinyGPS or TinyGPS++ library to parse NMEA sentences and obtain clean latitude and longitude data.
- **Cold vs. Hot Start**: Cold starts take longer to acquire a signal. If possible, keep the module powered for faster positioning.
