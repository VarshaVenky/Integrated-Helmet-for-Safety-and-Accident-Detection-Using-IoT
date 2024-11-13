// rf_receiver.ino

#include <VirtualWire.h>  // Include VirtualWire library for RF communication

// Define pins
const int receivePin = 11;     // RF Receiver data pin
const int ignitionPin = 8;     // Ignition control pin (for starting/stopping the bike)

// Status flags received from helmet
bool helmetOn = false;
bool isDrunk = false;
bool accidentDetected = false;

void setup() {
    Serial.begin(9600);
    pinMode(ignitionPin, OUTPUT);
    digitalWrite(ignitionPin, LOW);  // Start with the ignition off
    
    // Initialize RF receiver
    vw_set_rx_pin(receivePin);
    vw_setup(2000);  // Transmission speed in bps (must match transmitter speed)
    vw_rx_start();   // Start the RF receiver
    Serial.println("RF Receiver Module Initialized");
}

void loop() {
    uint8_t buffer[3];
    uint8_t bufferLength = sizeof(buffer);
    
    // Check if a message was received
    if (vw_get_message(buffer, &bufferLength)) {
        // Decode the received message
        helmetOn = buffer[0] == '1';
        isDrunk = buffer[1] == '1';
        accidentDetected = buffer[2] == '1';
        
        // Print received data for debugging
        Serial.print("Received Data - Helmet: ");
        Serial.print(helmetOn ? "ON" : "OFF");
        Serial.print(", Alcohol: ");
        Serial.print(isDrunk ? "DETECTED" : "NOT DETECTED");
        Serial.print(", Accident: ");
        Serial.println(accidentDetected ? "YES" : "NO");
        
        // Take action based on the received data
        controlIgnition();
        
        // Handle accident detection if necessary
        if (accidentDetected) {
            sendAccidentAlert();
        }
    }
}

void controlIgnition() {
    // Control bike ignition based on helmet and alcohol status
    if (helmetOn && !isDrunk && !accidentDetected) {
        digitalWrite(ignitionPin, HIGH);  // Start the bike
        Serial.println("Ignition ON: Bike started.");
    } else {
        digitalWrite(ignitionPin, LOW);   // Stop the bike
        Serial.println("Ignition OFF: Bike cannot start.");
    }
}

void sendAccidentAlert() {
    // Implement code to send accident alert (e.g., via GSM module)
    Serial.println("Accident detected! Sending alert to emergency contact...");
    // Add code here to trigger GSM module for sending SMS with location details
}
