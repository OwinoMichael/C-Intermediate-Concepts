#include<stdio.h>

/**
 * Converts a hexadecimal value to decimal by splitting it into two halves.
 *
 * Method:
 *  1. Partition the hex value into a left half and a right half.
 *  2. Convert each half independently using the hexadecimal dot product:
 *
 *         digit_n × 16^n + ... + digit_1 × 16^1 + digit_0 × 16^0
 *
 *  3. Multiply the decimal value of the left half by
 *
 *         16^(number of digits in the right half)
 *
 *  4. Add the decimal value of the right half.
 *
 * Examples:
 *
 *   0xFF
 *   = (F × 16^1 + F × 16^0)
 *   = (15 × 16) + (15 × 1)
 *   = 240 + 15
 *   = 255
 *
 *   0xAFFF
 *   Partition: AF | FF
 *
 *   AF = (10 × 16) + 15 = 175
 *   FF = (15 × 16) + 15 = 255
 *
 *   0xAFFF
 *   = (175 × 16^2) + 255
 *   = (175 × 256) + 255
 *   = 44800 + 255
 *   = 45055
 *
 * This approach avoids expanding every hexadecimal digit individually
 * and is especially useful for larger hexadecimal values.
 */


int main(int *argc, char *argv[]){



    return 0;
}