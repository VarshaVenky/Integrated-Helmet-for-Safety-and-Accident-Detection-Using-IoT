// gps_module.ino

#include <TinyGPS.h>
#include <SoftwareSerial.h>

// Define GPS serial pins
const int gpsRxPin = 4;   // GPS module RX
const int gpsTxPin = 3;   // GPS module TX

TinyGPS gps;               // Create GPS object
SoftwareSerial gpsSerial(gpsRxPin, gpsTxPin); // Initialize SoftwareSerial for GPS

// Variables to store GPS data
float latitude, longitude;
unsigned long age;

void setup() {
    Serial.begin(9600);
    gpsSerial.begin(9600);  // GPS module baud rate
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

// Function to display GPS information
void displayGPSInfo() {
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
