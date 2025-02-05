// Automatic Drunken Driver Detecting System for Autonomous Vehicles
// Developed for NodeMCU (ESP8266/ESP32)

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MQ3_PIN A0  // Alcohol sensor connected to analog pin
#define RELAY_PIN D1  // Relay connected to digital pin
#define BUZZER_PIN D2  // Buzzer for alert
#define BUTTON_PIN D3  // Emergency override button

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    lcd.begin();
    lcd.backlight();
    pinMode(MQ3_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    lcd.setCursor(0, 0);
    lcd.print("System Ready");
}

void loop() {
    Blynk.run();
    int alcoholLevel = analogRead(MQ3_PIN);
    Serial.print("Alcohol Level: ");
    Serial.println(alcoholLevel);
    
    lcd.setCursor(0, 1);
    lcd.print("Alcohol: ");
    lcd.print(alcoholLevel);
    
    if (alcoholLevel > 500) {  // Threshold level
        digitalWrite(RELAY_PIN, LOW); // Turn off ignition
        digitalWrite(BUZZER_PIN, HIGH); // Activate buzzer
        lcd.setCursor(0, 1);
        lcd.print("Access Denied");
        Blynk.notify("Alcohol detected! Ignition disabled.");
    } else {
        digitalWrite(RELAY_PIN, HIGH); // Allow ignition
        digitalWrite(BUZZER_PIN, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Safe to Drive  ");
    }
    
    if (digitalRead(BUTTON_PIN) == LOW) {
        digitalWrite(RELAY_PIN, HIGH); // Manual override
        digitalWrite(BUZZER_PIN, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Override Enabled");
        Blynk.notify("Emergency override activated.");
    }
    
    delay(1000);
}
