#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Pins for sensors
const int pushButtonPin = 2;    // Helmet detection
const int alcoholSensorPin = A0; // Alcohol detection
const int accelerometerXPin = A1; // Accelerometer X-axis
const int accelerometerYPin = A2; // Accelerometer Y-axis
const int accelerometerZPin = A3; // Accelerometer Z-axis

// Thresholds
const int alcoholThreshold = 500;  // Alcohol threshold (adjust based on sensor calibration)
const int tiltThreshold = 600;     // Tilt threshold for accident detection

// Communication modules
SoftwareSerial gpsSerial(4, 3);    // GPS module connected to pins 4 (RX) and 3 (TX)
SoftwareSerial gsmSerial(5, 6);    // GSM module connected to pins 5 (RX) and 6 (TX)
TinyGPS gps;

// Variables
bool helmetOn = false;
bool isDrunk = false;
bool accidentDetected = false;

void setup() {
    pinMode(pushButtonPin, INPUT);
    pinMode(alcoholSensorPin, INPUT);
    pinMode(accelerometerXPin, INPUT);
    pinMode(accelerometerYPin, INPUT);
    pinMode(accelerometerZPin, INPUT);
  
    Serial.begin(9600);           // Debugging
    gpsSerial.begin(9600);        // GPS baud rate
    gsmSerial.begin(9600);        // GSM baud rate
  
    Serial.println("Smart Helmet System Initialized");
}

void loop() {
    checkHelmetStatus();
    checkAlcoholStatus();
    checkAccidentStatus();
  
    if (helmetOn && !isDrunk && !accidentDetected) {
        startBike();
    } else {
        stopBike();
    }
  
    if (accidentDetected) {
        sendAccidentAlert();
    }
  
    delay(1000); // Delay for readability and to avoid excessive loop iterations
}

void checkHelmetStatus() {
    helmetOn = digitalRead(pushButtonPin) == HIGH;
    if (helmetOn) {
        Serial.println("Helmet is on.");
    } else {
        Serial.println("Helmet is off. Bike cannot start.");
    }
}

void checkAlcoholStatus() {
    int alcoholValue = analogRead(alcoholSensorPin);
    isDrunk = alcoholValue > alcoholThreshold;
    if (isDrunk) {
        Serial.println("Alcohol detected! Bike cannot start.");
    } else {
        Serial.println("No alcohol detected.");
    }
}

void checkAccidentStatus() {
    int x = analogRead(accelerometerXPin);
    int y = analogRead(accelerometerYPin);
    int z = analogRead(accelerometerZPin);

    accidentDetected = (x > tiltThreshold || y > tiltThreshold || z > tiltThreshold);
    if (accidentDetected) {
        Serial.println("Accident detected!");
    } else {
        Serial.println("No accident detected.");
    }
}

void startBike() {
    Serial.println("Bike started successfully.");
    // Code to engage ignition (e.g., activate relay)
}

void stopBike() {
    Serial.println("Bike cannot start. Check requirements.");
    // Code to disengage ignition
}

void sendAccidentAlert() {
    // Get GPS coordinates
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
  
    // Send SMS via GSM
    gsmSerial.println("AT+CMGF=1");  // Set SMS to text mode
    delay(100);
    gsmSerial.println("AT+CMGS=\"+911234567890\"");  // Replace with emergency contact number
    delay(100);
    gsmSerial.print("Accident detected at location: ");
    gsmSerial.print("Latitude: ");
    gsmSerial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    gsmSerial.print(" Longitude: ");
    gsmSerial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    gsmSerial.write(26);  // ASCII code for Ctrl+Z to send the message
    Serial.println("Accident alert sent!");
}
