// alcohol_sensor.ino

// Define the pin for the alcohol sensor
const int alcoholSensorPin = A0;

// Define the threshold value for detecting alcohol
const int alcoholThreshold = 500;  // Adjust this value based on your sensor calibration

bool isDrunk = false;

void setup() {
    Serial.begin(9600);
    pinMode(alcoholSensorPin, INPUT);
    Serial.println("Alcohol Sensor Module Initialized");
}

void loop() {
    checkAlcoholLevel();
    delay(1000);  // Delay for readability in serial output
}

// Function to check alcohol levels
void checkAlcoholLevel() {
    int alcoholValue = analogRead(alcoholSensorPin);
    isDrunk = alcoholValue > alcoholThreshold;
    
    if (isDrunk) {
        Serial.println("Warning: Alcohol detected! Bike cannot start.");
    } else {
        Serial.println("No alcohol detected. Safe to start the bike.");
    }
}
