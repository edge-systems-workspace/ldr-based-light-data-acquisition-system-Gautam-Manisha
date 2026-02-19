#include <Arduino.h>
#define LDR_PIN A0
int ldrValue = 0;

/**
 * @file main.ino
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author YOUR_NAME
 * @date YYYY-MM-DD
 *
 * @details
 * Reads analog brightness data from LDR sensor
 * and displays structured output via Serial Monitor.
 */

 // TODO 1:
 // Define LDR analog pin (Use A0)

 // TODO 2:
 // Create variable to store sensor reading

void setup() {

    Serial.begin(9600);

    Serial.println("LDR Light Monitoring System Initialized...");
    Serial.println("----------------------------------------");

}

void loop() {

    // Read analog value from LDR (Range: 0 - 1023)
    ldrValue = analogRead(LDR_PIN);

    // Print raw ADC value to Serial Monitor
    Serial.print("Raw LDR Value: ");
    Serial.print(ldrValue);

    // Threshold logic for brightness detection
    // Typical values: < 300 Dark, 300-700 Dim, > 700 Bright
    if (ldrValue < 300) {
        Serial.println(" - Status: [DARK]");
    } else if (ldrValue < 700) {
        Serial.println(" - Status: [DIM]");
    } else {
        Serial.println(" - Status: [BRIGHT]");
    }

    // Stability delay
    delay(500);

}
