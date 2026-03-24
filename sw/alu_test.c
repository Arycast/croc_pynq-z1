#include "uart.h"
#include "print.h"
#include "timer.h"
#include "gpio.h"
#include "util.h"
#include "simple_alu.h"

int main() {
    uart_init(); // setup the uart peripheral
    printf("Starting ALU Fixed-Point in User Domain\n");
    uart_write_flush(); // wait until uart has finished sending
    int16_t a = 0x0200; // 1.0
    int16_t b = 0x0100; // 2.0

    int32_t hw, sw;

    hw = add_hw(a,b);
    sw = add_sw(a,b);
    printf("HW Add: 0x%x, SW: 0x%x\n", hw, sw);
    // uart_write_flush();

    hw = sub_hw(a,b);
    sw = sub_sw(a,b);
    printf("HW Sub: 0x%x, SW: 0x%x\n", hw, sw);
    // uart_write_flush();

    hw = mult_hw(a,b);
    sw = mult_sw(a,b);
    printf("HW Mult: 0x%x, SW: 0x%x\n", hw, sw);
    // uart_write_flush();

    hw = div_hw(a,b);
    sw = div_sw(a,b);
    printf("HW Div: 0x%x, SW: 0x%x\n", hw, sw);
    // uart_write_flush();

    return 1;
}