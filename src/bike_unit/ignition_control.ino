// ignition_control.ino

// Define the pin for controlling the ignition relay
const int ignitionPin = 8;  // Pin connected to the relay for bike ignition

// Status flags for conditions
bool helmetOn = false;
bool isDrunk = false;
bool accidentDetected = false;

void setup() {
    Serial.begin(9600);
    pinMode(ignitionPin, OUTPUT);
    digitalWrite(ignitionPin, LOW);  // Start with ignition off
    Serial.println("Ignition Control Module Initialized");
}

void loop() {
    // Placeholder for updating status flags from received data
    // In the main program, these values would be updated from the RF receiver
    updateStatusFlags();

    // Control ignition based on status flags
    controlIgnition();

    delay(1000);  // Delay for readability
}

// Function to control ignition based on status flags
void controlIgnition() {
    if (helmetOn && !isDrunk && !accidentDetected) {
        digitalWrite(ignitionPin, HIGH);  // Turn on ignition
        Serial.println("Ignition ON: Bike started.");
    } else {
        digitalWrite(ignitionPin, LOW);   // Turn off ignition
        Serial.println("Ignition OFF: Bike cannot start.");
    }
}

// Placeholder function to update status flags (to be replaced with actual RF receiver data)
void updateStatusFlags() {
    // Simulated conditions for testing (update these based on RF receiver in main program)
    helmetOn = true;         // Simulate helmet worn
    isDrunk = false;         // Simulate no alcohol detected
    accidentDetected = false; // Simulate no accident detected

    // Log the status for debugging
    Serial.print("Helmet Status: ");
    Serial.println(helmetOn ? "ON" : "OFF");
    Serial.print("Alcohol Status: ");
    Serial.println(isDrunk ? "DETECTED" : "NOT DETECTED");
    Serial.print("Accident Status: ");
    Serial.println(accidentDetected ? "YES" : "NO");
}
