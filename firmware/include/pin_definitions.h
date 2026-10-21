#pragma once

#include <stdint.h>

/**
 * @file pin_definitions.h
 * @brief Централізований мапінг апаратних пінів проєкту.
 */

namespace HardwareConfig {

    // Індикаторний світлодіод (Status LED)
    constexpr uint8_t PIN_STATUS_LED     = 2;

    // Кнопка користувача (User Button)
    constexpr uint8_t PIN_USER_BUTTON    = 0;

    // I2C шина для підключення датчиків та дисплеїв
    constexpr uint8_t PIN_I2C_SDA        = 21;
    constexpr uint8_t PIN_I2C_SCL        = 22;

    // SPI шина
    constexpr uint8_t PIN_SPI_MOSI       = 23;
    constexpr uint8_t PIN_SPI_MISO       = 19;
    constexpr uint8_t PIN_SPI_SCK        = 18;
    constexpr uint8_t PIN_SPI_CS         = 5;

    // Аналогові входи (ADC)
    constexpr uint8_t PIN_ADC_BATTERY    = 34; // Моніторинг напруги акумулятора (через дільник)

    // Налаштування швидкості UART
    constexpr uint32_t SERIAL_BAUD_RATE  = 115200;

} // namespace HardwareConfig
