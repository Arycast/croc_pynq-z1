#include "timer.h"
#include "gpio.h"
#include "uart.h"
#include "print.h"
#include "util.h"

int main() {
    uart_init(); // setup the uart peripheral
    printf("\rTest LED Blink 123456789\n\r");
    uart_write_flush(); // wait until uart has finished sending

    // Set GPIO[0] as output
    gpio_set_direction(0xFFFF, 0x0001);
    gpio_enable(0x0001);

    int idx = 0;
    uint16_t delay = 200;

    while (idx < 100) {
        gpio_write(0x1);   // LED ON
        sleep_ms(delay);

        gpio_write(0x0);   // LED OFF
        sleep_ms(delay);

        idx++;
    }
    printf("LED Blink Test Finish\n\r");
    uart_write_flush(); // wait until uart has finished sending

    return 1;
}