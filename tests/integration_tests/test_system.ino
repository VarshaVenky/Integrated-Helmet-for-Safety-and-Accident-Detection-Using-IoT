// test_system.ino

// Define pins for components
const int helmetStatusPin = 2;        // Helmet detection (push button) pin
const int alcoholSensorPin = A0;      // Alcohol detection sensor pin
const int accelXPin = A1;             // Accelerometer X-axis
const int accelYPin = A2;             // Accelerometer Y-axis
const int accelZPin = A3;             // Accelerometer Z-axis
const int ignitionPin = 8;            // Ignition control pin (for relay)

// Thresholds
const int alcoholThreshold = 500;     // Alcohol detection threshold
const int tiltThreshold = 600;        // Tilt threshold for accident detection

// Status flags
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
    pinMode(ignitionPin, OUTPUT);
    digitalWrite(ignitionPin, LOW);   // Start with ignition off
    Serial.println("System Test Initialized");
}

void loop() {
    // Check each component's status
    checkHelmetStatus();
    checkAlcoholStatus();
    checkAccidentStatus();
    
    // Control ignition based on component statuses
    controlIgnition();

    delay(1000);  // Delay for readability in serial output
}

// Function to check if the helmet is worn
void checkHelmetStatus() {
    helmetOn = digitalRead(helmetStatusPin) == HIGH;
    Serial.print("Helmet Status: ");
    Serial.println(helmetOn ? "ON" : "OFF");
}

// Function to check for alcohol detection
void checkAlcoholStatus() {
    int alcoholValue = analogRead(alcoholSensorPin);
    isDrunk = alcoholValue > alcoholThreshold;
    Serial.print("Alcohol Level: ");
    Serial.print(alcoholValue);
    Serial.println(isDrunk ? " - Alcohol detected!" : " - No alcohol detected.");
}

// Function to check for excessive tilt indicating an accident
void checkAccidentStatus() {
    int xValue = analogRead(accelXPin);
    int yValue = analogRead(accelYPin);
    int zValue = analogRead(accelZPin);

    accidentDetected = (xValue > tiltThreshold || yValue > tiltThreshold || zValue > tiltThreshold);
    Serial.print("Tilt Status - X: ");
    Serial.print(xValue);
    Serial.print(" | Y: ");
    Serial.print(yValue);
    Serial.print(" | Z: ");
    Serial.println(zValue);
    Serial.println(accidentDetected ? "Warning: Accident detected!" : "No excessive tilt detected.");
}

// Function to control bike ignition based on conditions
void controlIgnition() {
    if (helmetOn && !isDrunk && !accidentDetected) {
        digitalWrite(ignitionPin, HIGH);  // Turn on ignition
        Serial.println("Ignition ON: Bike started.");
    } else {
        digitalWrite(ignitionPin, LOW);   // Turn off ignition
        Serial.println("Ignition OFF: Bike cannot start.");
    }
}
