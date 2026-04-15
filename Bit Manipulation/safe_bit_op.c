#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/*

    Never assume. Always validate shift amounts, bit positions, and endianness.

    In networking, you're parsing data from potentially malicious sources. 
    A single invalid shift or out-of-range bit access can crash your entire system.

*/

// Safe for any unsigned type
#define BITS_IN_TYPE(type) (sizeof(type) * CHAR_BIT)

// Set bit with bounds checking
#define SAFE_SET_BIT(word, n) do { \
    if ((n) >= 0 && (n) < BITS_IN_TYPE(*(word))) { \
        *(word) |= (1ULL << (n)); \
    } \
} while(0)

// Clear bit with bounds checking
#define SAFE_CLEAR_BIT(word, n) do { \
    if ((n) >= 0 && (n) < BITS_IN_TYPE(*(word))) { \
        *(word) &= ~(1ULL << (n)); \
    } \
} while(0)

// Toggle bit with bounds checking
#define SAFE_TOGGLE_BIT(word, n) do { \
    if ((n) >= 0 && (n) < BITS_IN_TYPE(*(word))) { \
        *(word) ^= (1ULL << (n)); \
    } \
} while(0)

// Read bit (returns false for out-of-range)
#define SAFE_READ_BIT(word, n) \
    ((n) >= 0 && (n) < BITS_IN_TYPE(word) ? ((word) >> (n)) & 1 : 0)

// Safe shift (returns 0 for out-of-range shifts)
uint32_t safe_left_shift(uint32_t value, int shift) {
    if (shift <= 0) return value;
    if (shift >= 32) return 0;
    return value << shift;
}

// Endian-safe network functions
uint16_t read_network_uint16(const uint8_t *data) {
    return ((uint16_t)data[0] << 8) | data[1];
}

void write_network_uint16(uint8_t *data, uint16_t value) {
    data[0] = (value >> 8) & 0xFF;
    data[1] = value & 0xFF;
}

// Test all edge cases
int main() {
    printf("=== Edge Case Testing ===\n\n");
    
    // 1. Shift by width
    uint32_t test = 1;
    printf("Shift by 32: %u\n", safe_left_shift(test, 32));  // 0
    
    // 2. Signed shift
    int8_t signed_test = -1;
    printf("Signed -1 >> 1 = %d (expect -1 or 127?)\n", signed_test >> 1);
    
    uint8_t unsigned_test = 0xFF;
    printf("Unsigned 255 >> 1 = %u (expect 127)\n", unsigned_test >> 1);
    
    // 3. Out-of-range bit operations
    uint32_t flags = 0;
    SAFE_SET_BIT(&flags, 100);  // Does nothing
    printf("After safe set bit 100: 0x%X\n", flags);  // Still 0
    
    // 4. Endianness example
    uint16_t port = 8080;
    uint8_t network_buffer[2];
    write_network_uint16(network_buffer, port);
    printf("Port %d in network order: 0x%02X%02X\n", 
           port, network_buffer[0], network_buffer[1]);
    
    // 5. Logical vs bitwise trap
    uint8_t a = 0x0F, b = 0x0F;
    if (a & 0x10) printf("Bitwise: bit 4 not set\n");
    if (a && 0x10) printf("Logical: always true!\n");  // This prints!
    
    return 0;
}