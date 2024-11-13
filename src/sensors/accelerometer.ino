// accelerometer.ino

// Define the pins for the accelerometer
const int accelXPin = A1;  // X-axis
const int accelYPin = A2;  // Y-axis
const int accelZPin = A3;  // Z-axis

// Define threshold for detecting an accident based on tilt or sudden movement
const int tiltThreshold = 600;  // Adjust this based on calibration

bool accidentDetected = false;

void setup() {
    Serial.begin(9600);
    pinMode(accelXPin, INPUT);
    pinMode(accelYPin, INPUT);
    pinMode(accelZPin, INPUT);
    Serial.println("Accelerometer Module Initialized");
}

void loop() {
    checkForAccident();
    delay(1000);  // Delay for readability in serial output
}

// Function to check accelerometer values and detect accident
void checkForAccident() {
    int xValue = analogRead(accelXPin);
    int yValue = analogRead(accelYPin);
    int zValue = analogRead(accelZPin);
    
    // Accident detected if any axis exceeds the tilt threshold
    accidentDetected = (xValue > tiltThreshold || yValue > tiltThreshold || zValue > tiltThreshold);

    if (accidentDetected) {
        Serial.println("Accident detected! Alert will be sent.");
    } else {
        Serial.println("No accident detected.");
    }
}
