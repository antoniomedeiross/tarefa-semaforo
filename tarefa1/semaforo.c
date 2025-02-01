#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

volatile int state = 0;

bool semaforo_callback(struct repeating_timer *t) {
    gpio_put(LED_RED, state == 0);
    gpio_put(LED_YELLOW, state == 1);
    gpio_put(LED_GREEN, state == 2);
    
    state = (state + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, semaforo_callback, NULL, &timer);
    
    while (1) {
        printf("Sistema rodando...\n");
        sleep_ms(1000);
    }
}

