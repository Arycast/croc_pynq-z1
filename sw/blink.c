#include "timer.h"
#include "gpio.h"

int main() {

    // Set GPIO[0] as output
    gpio_set_direction(0xFFFF, 0x0001);
    gpio_enable(0x0001);

    while (1) {
        gpio_write(0x1);   // LED ON
        sleep_ms(200);

        gpio_write(0x0);   // LED OFF
        sleep_ms(200);
    }

    return 0;
}