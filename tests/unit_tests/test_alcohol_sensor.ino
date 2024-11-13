// test_alcohol_sensor.ino

// Define the pin for the alcohol sensor
const int alcoholSensorPin = A0;  // Adjust if connected to a different analog pin

// Define the threshold value for detecting alcohol
const int alcoholThreshold = 500;  // Adjust this value based on sensor calibration

void setup() {
    Serial.begin(9600);
    pinMode(alcoholSensorPin, INPUT);
    Serial.println("Alcohol Sensor Test Initialized");
}

void loop() {
    // Read the alcohol sensor value
    int alcoholValue = analogRead(alcoholSensorPin);
    
    // Check if the alcohol level exceeds the threshold
    if (alcoholValue > alcoholThreshold) {
        Serial.print("Alcohol Level: ");
        Serial.print(alcoholValue);
        Serial.println(" - Alcohol detected! Warning: Do not start the bike.");
    } else {
        Serial.print("Alcohol Level: ");
        Serial.print(alcoholValue);
        Serial.println(" - No alcohol detected. Safe to start the bike.");
    }

    delay(1000);  // Delay for readability in serial output
}
