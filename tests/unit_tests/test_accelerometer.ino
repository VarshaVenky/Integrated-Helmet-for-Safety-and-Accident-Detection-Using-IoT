// test_accelerometer.ino

// Define pins for the accelerometer
const int accelXPin = A1;  // X-axis
const int accelYPin = A2;  // Y-axis
const int accelZPin = A3;  // Z-axis

// Define threshold for detecting tilt or sudden movement
const int tiltThreshold = 600;  // Adjust based on calibration

void setup() {
    Serial.begin(9600);
    pinMode(accelXPin, INPUT);
    pinMode(accelYPin, INPUT);
    pinMode(accelZPin, INPUT);
    Serial.println("Accelerometer Test Initialized");
}

void loop() {
    // Read values from each axis of the accelerometer
    int xValue = analogRead(accelXPin);
    int yValue = analogRead(accelYPin);
    int zValue = analogRead(accelZPin);
    
    // Print the values for each axis
    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print(" | Y: ");
    Serial.print(yValue);
    Serial.print(" | Z: ");
    Serial.println(zValue);

    // Check if any axis exceeds the tilt threshold
    if (xValue > tiltThreshold || yValue > tiltThreshold || zValue > tiltThreshold) {
        Serial.println("Warning: Tilt threshold exceeded! Possible accident detected.");
    } else {
        Serial.println("No excessive tilt detected. All clear.");
    }

    delay(1000);  // Delay for readability in serial output
}
