# ⚡ Electronics & Embedded Project

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![KiCad](https://img.shields.io/badge/EDA-KiCad%20v8%2B-blue.svg)](https://kicad.org/)
[![PlatformIO](https://img.shields.io/badge/Firmware-PlatformIO-orange.svg)](https://platformio.org/)

Комплексний репозиторій для розробки апаратної частини (Hardware / PCB) та вбудованого програмного забезпечення (Firmware / Embedded).

---

## 📁 Структура репозиторію

```text
electronics-project/
├── .gitignore               # Налаштовані виключення для KiCad, PlatformIO, збірок та ОС
├── LICENSE                  # Ліцензія проєкту
├── README.md                # Головний опис та документація проєкту
├── docs/                    # Документація, схеми у PDF, розпіновка, рендери
│   ├── images/              # Фото готового пристрою, 3D-рендери та діаграми
│   ├── pinouts/             # Графічні або табличні описи розпіновок
│   └── schematics/          # Експортовані схеми у форматі PDF для швидкого перегляду
├── hardware/                # Проєкт друкованої плати та апаратна частина
│   ├── 3d_models/           # 3D моделі компонентів і корпусу (.STEP, .STL)
│   ├── bom/                 # Специфікація компонентів (Bill of Materials) у CSV
│   ├── gerber/              # Файли для виробництва (Gerber RS-274X, Drill, Pick & Place)
│   └── kicad/               # Вихідні файли KiCad (*.kicad_sch, *.kicad_pcb, *.kicad_pro)
├── firmware/                # Вбудоване ПЗ (код мікроконтролера)
│   ├── include/             # Заголовні файли (пінаут, константи, налаштування)
│   ├── lib/                 # Локальні бібліотеки та кастомні драйвери
│   ├── src/                 # Основний вихідний код прошивки (.cpp / .c)
│   └── platformio.ini       # Конфігурація середовища PlatformIO (ESP32, STM32, Arduino)
├── simulation/              # Симуляції схем (LTspice, Falstad, QSPICE)
└── tools/                   # Допоміжні скрипти, генератори BOM, утиліти для прошивки
```

---

## 🔌 Технічні характеристики

| Параметр | Значення / Опис |
| :--- | :--- |
| **Мікроконтролер (MCU)** | ESP32-WROOM-32 / STM32 / RP2040 / ATmega328P |
| **Напруга живлення (Vcc)** | 5V DC (USB-C) / 3.3V логіка |
| **Споживання струму** | ~50–150 mA (типове) |
| **Інтерфейси зв'язку** | I2C, SPI, UART, Wi-Fi / Bluetooth |
| **Габарити друкованої плати** | 50 × 50 мм (2 шари) |

---

## 🛠️ Апаратна частина (Hardware)

### Проєктування в KiCad
Вихідні файли проєкту знаходяться в директорії [`hardware/kicad/`](./hardware/kicad/):
- **Схема:** `hardware/kicad/*.kicad_sch`
- **Трасування плати:** `hardware/kicad/*.kicad_pcb`

### Замовлення плат (PCB Manufacturing)
Для швидкого замовлення (JLCPCB, PCBWay тощо):
1. Скористайтеся архівом з Gerber-файлами в папці [`hardware/gerber/`](./hardware/gerber/).
2. Специфікація компонентів для замовлення та монтажу (SMT) доступна у файлі [`hardware/bom/bom_template.csv`](./hardware/bom/bom_template.csv).
3. PDF-версія схеми для зручного монтажу розміщена в [`docs/schematics/`](./docs/schematics/).

---

## 💻 Прошивка (Firmware)

Прошивка організована для роботи з **VS Code + розширення PlatformIO**.

### Збірка та прошивка

1. Відкрийте папку `firmware/` у Visual Studio Code з установленим розширенням **PlatformIO IDE**.
2. У файлі `platformio.ini` оберіть необхідну платформу (за замовчуванням налаштовано ESP32, також додані готові профілі для STM32 та Arduino).
3. Збірка проєкту:
   ```bash
   pio run
   ```
4. Завантаження у мікроконтролер:
   ```bash
   pio run --target upload
   ```
5. Монітор послідовного порту:
   ```bash
   pio device monitor
   ```

---

## 📌 Карта розпіновки (Pinout)

Детальний мапінг пінів описано у файлі [`firmware/include/pin_definitions.h`](./firmware/include/pin_definitions.h).

| Функція | Пін MCU | Тип / Нотатки |
| :--- | :--- | :--- |
| **Status LED** | GPIO 2 | Активний високий рівень (Built-in LED) |
| **User Button** | GPIO 0 | Підтяжка до VCC (Active LOW) |
| **I2C SDA** | GPIO 21 | Шина датчиків (Pull-up 4.7kΩ) |
| **I2C SCL** | GPIO 22 | Шина датчиків (Pull-up 4.7kΩ) |
| **UART TX / RX** | GPIO 1 / 3 | Налагоджувальний порт (115200 baud) |

---

## 📄 Ліцензія

Цей проєкт поширюється під ліцензією **MIT** — див. файл [LICENSE](./LICENSE).
Ви можете вільно використовувати, модифікувати та виготовляти пристрої як для некомерційних, так і для комерційних цілей.
