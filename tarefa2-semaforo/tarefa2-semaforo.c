#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13
#define BUTTON 5

volatile bool button_pressed = false;

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    int led = *(int *)user_data;
    gpio_put(led, 0);
    return 0;
}

void gpio_callback(uint gpio, uint32_t events) {
    if (!button_pressed) {
        button_pressed = true;
        gpio_put(LED_RED, 1);
        gpio_put(LED_YELLOW, 1);
        gpio_put(LED_GREEN, 1);

        static int red = LED_RED;
        static int yellow = LED_YELLOW;
        static int green = LED_GREEN;
        add_alarm_in_ms(3000, turn_off_callback, &red, false);
        add_alarm_in_ms(6000, turn_off_callback, &yellow, false);
        add_alarm_in_ms(9000, turn_off_callback, &green, false);
    }
}

void initGpios() {
        stdio_init_all();
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
}

int main() {
    initGpios();

    while (1) {
        if (!gpio_get(LED_RED) && !gpio_get(LED_YELLOW) && !gpio_get(LED_GREEN)) {
            button_pressed = false;
        }
        sleep_ms(100);
    }
}
