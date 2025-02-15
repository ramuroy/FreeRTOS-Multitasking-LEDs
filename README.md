# 🔴🔵 ESP32 FreeRTOS Multitasking LED Blink 💡⚡

A simple ESP32 project demonstrating FreeRTOS multitasking by blinking two LEDs at different intervals using ESP-IDF.

## 📌 Required Components
- ESP32 (38-pin) NodeMCU Development Board
- LEDs (2x, any color)
- Resistors (220Ω)
- Jumper Wires
- Breadboard
- **ESP-IDF FreeRTOS Software**

## 🔧 Wiring Diagram
| ESP32 GPIO Pin | Component |
|--------------|-----------|
| GPIO 18      | LED 1 (+) |
| GPIO 19      | LED 2 (+) |
| GND         | LED 1 & LED 2 (-) via resistors |

## 📝 Code
The FreeRTOS-based code creates two independent tasks that blink LEDs at different intervals.

```c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED1_GPIO 18
#define LED2_GPIO 19

void blink_task_1(void *pvParameter) {
    gpio_pad_select_gpio(LED1_GPIO);
    gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED1_GPIO, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(LED1_GPIO, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void blink_task_2(void *pvParameter) {
    gpio_pad_select_gpio(LED2_GPIO);
    gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED2_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED2_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main() {
    xTaskCreate(&blink_task_1, "Blink LED 1", 1024, NULL, 5, NULL);
    xTaskCreate(&blink_task_2, "Blink LED 2", 1024, NULL, 5, NULL);
}
```

## 🚀 How to Run
1. Install **ESP-IDF** and set up the development environment.
2. Clone this repository and navigate to the project folder.
3. Build and flash the code using:
   ```sh
   idf.py build
   idf.py flash
   idf.py monitor
   ```
4. Observe the LEDs blinking at different intervals!

## 📽️ Demo Video
[![Watch the demo](wait)

## 🛠️ License
This project is open-source and available under the MIT License.

---
✨ Happy coding with ESP32 & FreeRTOS! 🚀
