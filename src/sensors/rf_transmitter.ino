// rf_transmitter.ino

#include <VirtualWire.h>  // Include VirtualWire library for RF communication

// Define pins and variables
const int transmitPin = 12;           // RF Transmitter data pin
const int helmetStatusPin = 2;        // Helmet detection (push button) pin
const int alcoholSensorPin = A0;      // Alcohol sensor analog pin
const int accelXPin = A1;             // Accelerometer X-axis
const int accelYPin = A2;             // Accelerometer Y-axis
const int accelZPin = A3;             // Accelerometer Z-axis

// Threshold values for detection
const int alcoholThreshold = 500;     // Alcohol detection threshold
const int tiltThreshold = 600;        // Tilt threshold for accident detection

// Status variables
bool helmetOn = false;
bool isDrunk = false;
bool accidentDetected = false;

void setup() {
    Serial.begin(9600);
    pinMode(helmetStatusPin, INPUT);
    pinMode(alcoholSensorPin, INPUT);
    pinMode(accelXPin, INPUT);
    pinMode(accelYPin, INPUT);
    pinMode(accelZPin, INPUT);
    
    // Initialize RF transmitter
    vw_set_tx_pin(transmitPin);
    vw_setup(2000);  // Transmission speed in bps (adjust if needed)
    Serial.println("RF Transmitter Module Initialized");
}

void loop() {
    readSensors();
    transmitData();
    delay(1000);  // Adjust delay for desired transmission frequency
}

// Function to read sensor values and set status flags
void readSensors() {
    helmetOn = digitalRead(helmetStatusPin) == HIGH;
    isDrunk = analogRead(alcoholSensorPin) > alcoholThreshold;
    
    int x = analogRead(accelXPin);
    int y = analogRead(accelYPin);
    int z = analogRead(accelZPin);
    accidentDetected = (x > tiltThreshold || y > tiltThreshold || z > tiltThreshold);
}

// Function to transmit helmet status data
void transmitData() {
    // Create message to send (1 for true, 0 for false)
    char message[3];
    message[0] = helmetOn ? '1' : '0';          // Helmet status
    message[1] = isDrunk ? '1' : '0';           // Alcohol status
    message[2] = accidentDetected ? '1' : '0';  // Accident status

    vw_send((uint8_t *)message, sizeof(message));
    vw_wait_tx();  // Wait until the message is sent
    
    // Debug output
    Serial.print("Transmitting Data - Helmet: ");
    Serial.print(helmetOn ? "ON" : "OFF");
    Serial.print(", Alcohol: ");
    Serial.print(isDrunk ? "DETECTED" : "NOT DETECTED");
    Serial.print(", Accident: ");
    Serial.println(accidentDetected ? "YES" : "NO");
}
