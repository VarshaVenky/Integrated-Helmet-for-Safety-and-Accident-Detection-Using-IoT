// test_helmet_connection.ino

// Define the pin for the helmet connection detection
const int helmetStatusPin = 2;  // Pin connected to the helmet detection button or switch

// Status flag
bool helmetOn = false;

void setup() {
    Serial.begin(9600);
    pinMode(helmetStatusPin, INPUT);
    Serial.println("Helmet Connection Test Initialized");
}

void loop() {
    // Read the helmet connection status
    helmetOn = digitalRead(helmetStatusPin) == HIGH;

    // Print the helmet status
    if (helmetOn) {
        Serial.println("Helmet is ON - Connection Established.");
    } else {
        Serial.println("Helmet is OFF - Connection Not Established.");
    }

    delay(1000);  // Delay for readability in serial output
}
