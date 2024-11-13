// test_accident_detection.ino

// Define pins for the accelerometer
const int accelXPin = A1;  // X-axis
const int accelYPin = A2;  // Y-axis
const int accelZPin = A3;  // Z-axis

// Define threshold for detecting an accident (tilt or sudden movement)
const int accidentThreshold = 600;  // Adjust based on calibration

// Status flag
bool accidentDetected = false;

void setup() {
    Serial.begin(9600);
    pinMode(accelXPin, INPUT);
    pinMode(accelYPin, INPUT);
    pinMode(accelZPin, INPUT);
    Serial.println("Accident Detection Test Initialized");
}

void loop() {
    // Read values from each axis of the accelerometer
    int xValue = analogRead(accelXPin);
    int yValue = analogRead(accelYPin);
    int zValue = analogRead(accelZPin);

    // Check if any axis exceeds the accident threshold
    accidentDetected = (xValue > accidentThreshold || yValue > accidentThreshold || zValue > accidentThreshold);

    // Print values for each axis and accident status
    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print(" | Y: ");
    Serial.print(yValue);
    Serial.print(" | Z: ");
    Serial.print(zValue);

    if (accidentDetected) {
        Serial.println(" - Accident Detected! Sending alert...");
        triggerAccidentAlert();
    } else {
        Serial.println(" - No accident detected.");
    }

    delay(1000);  // Delay for readability in serial output
}

// Function to trigger an accident alert (placeholder for SMS/GPS integration)
void triggerAccidentAlert() {
    // Placeholder code for accident alert (e.g., sending SMS with GPS location)
    Serial.println("Accident Alert Triggered! (Implement SMS/GPS here)");
    // Implement actual GSM or GPS alert sending here if integrated in the project
}
