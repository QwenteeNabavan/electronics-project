/**
 * @file main.cpp
 * @brief Головний файл прошивки з базовою ініціалізацією та циклом опитування.
 */

#include <Arduino.h>
#include "pin_definitions.h"

// Період блимання статусного світлодіода (мс)
static constexpr unsigned long BLINK_INTERVAL_MS = 1000;
static unsigned long previousMillis = 0;
static bool ledState = false;

void setup() {
    // Ініціалізація послідовного порту для логів
    Serial.begin(HardwareConfig::SERIAL_BAUD_RATE);
    delay(500);

    Serial.println();
    Serial.println(F("========================================"));
    Serial.println(F("   Electronics Project Firmware Start   "));
    Serial.println(F("========================================"));

    // Налаштування пінів
    pinMode(HardwareConfig::PIN_STATUS_LED, OUTPUT);
    digitalWrite(HardwareConfig::PIN_STATUS_LED, LOW);

    pinMode(HardwareConfig::PIN_USER_BUTTON, INPUT_PULLUP);

    Serial.println(F("[INFO] Hardware pins initialized successfully."));
}

void loop() {
    unsigned long currentMillis = millis();

    // Неблокуюче миготіння світлодіодом (Heartbeat)
    if (currentMillis - previousMillis >= BLINK_INTERVAL_MS) {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(HardwareConfig::PIN_STATUS_LED, ledState ? HIGH : LOW);
        Serial.printf("[HEARTBEAT] System uptime: %lu sec\n", currentMillis / 1000);
    }

    // Перевірка стану кнопки (Active LOW)
    if (digitalRead(HardwareConfig::PIN_USER_BUTTON) == LOW) {
        Serial.println(F("[BUTTON] User button pressed!"));
        delay(200); // Простий антибряскіт
    }
}
