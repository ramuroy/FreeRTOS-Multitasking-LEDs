#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_rom_gpio.h"

#define LED1_GPIO GPIO_NUM_18  // LED 1 on GPIO 18
#define LED2_GPIO GPIO_NUM_19  // LED 2 on GPIO 19

void blink_task_1(void *pvParameter) {
    while (1) {
        gpio_set_level(LED1_GPIO, 1);  // Turn LED 1 on
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(LED1_GPIO, 0);  // Turn LED 1 off
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void blink_task_2(void *pvParameter) {
    while (1) {
        gpio_set_level(LED2_GPIO, 1);  // Turn LED 2 on
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED2_GPIO, 0);  // Turn LED 2 off
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main(void) {
    esp_rom_gpio_pad_select_gpio(LED1_GPIO); // Updated function
    esp_rom_gpio_pad_select_gpio(LED2_GPIO); // Updated function
    gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);

    xTaskCreate(&blink_task_1, "blink_task_1", 2048, NULL, 5, NULL);
    xTaskCreate(&blink_task_2, "blink_task_2", 2048, NULL, 5, NULL);
}