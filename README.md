# FreeRTOS LED Blinking with Multitasking

## Description
This project demonstrates multitasking using FreeRTOS on an ESP32. Two LEDs blink independently at different time intervals, showcasing the real-time task scheduling capabilities of FreeRTOS.

## Required Components
- ESP32 (38-pin) WiFi + Bluetooth NodeMCU-32 Development Board
- Two LEDs
- Two Resistors (220Ω)
- Breadboard
- Jumper Wires
- ESP-IDF with FreeRTOS

## Software Used
- ESP-IDF FreeRTOS Software
- Kinemaster (for video editing)

## Wiring Connections
| ESP32 Pin | Component |
|-----------|-----------|
| GPIO18    | LED1 (+)  |
| GPIO19    | LED2 (+)  |
| GND       | LED1 & LED2 (-) via Resistors |

## Code
```c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED1_GPIO 18
#define LED2_GPIO 19

void blink_led1(void *pvParameter) {
    gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED1_GPIO, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(LED1_GPIO, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void blink_led2(void *pvParameter) {
    gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED2_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED2_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main() {
    xTaskCreate(&blink_led1, "blink_led1", 1024, NULL, 5, NULL);
    xTaskCreate(&blink_led2, "blink_led2", 1024, NULL, 5, NULL);
}
```

## How to Run
1. Set up ESP-IDF on your system.
2. Clone this repository.
3. Connect your ESP32 to your PC.
4. Compile and flash the code using:
   ```sh
   idf.py set-target esp32
   idf.py build
   idf.py flash
   idf.py monitor
   ```
5. Observe the LEDs blinking at different intervals.

## Demo Video
[Watch Here](#) *(Upload and update the link)*

## License
This project is open-source under the MIT License.
