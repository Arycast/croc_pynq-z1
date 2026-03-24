#include "simple_alu.h"

int32_t add_sw(int16_t num1, int16_t num2) {
    // (Q8.8 + Q8.8) -> Q8.8 -> shift to Q16.16
    return ((int32_t)(num1 + num2)) << 8;
}

int32_t sub_sw(int16_t num1, int16_t num2) {
    // (Q8.8 - Q8.8) -> Q8.8 -> shift to Q16.16
    return ((int32_t)(num1 - num2)) << 8;
}

int32_t mult_sw(int16_t num1, int16_t num2) {
    // Q8.8 * Q8.8 = Q16.16
    return (int32_t)num1 * (int32_t)num2;
}

int32_t div_sw(int16_t num1, int16_t num2) {
    if (num2 == 0) {
        return 0xCAFEF00D;  // match RTL    
    }
    // (Q8.8 << 8) / Q8.8 = Q16.16
    return ((int32_t)num1 << 8) / num2;
}