#include <stdio.h>
#include <stdbool.h>

/*
WORD single unit of bits/ a processor can handle 
e.g 16 bit systems = a word of size 16 bits

BITWISE OPERATIONS

1. Bitwise AND    ->    let res = a & b;
2. Bitwise OR     ->    let res = a | b;  
3. Bitwise XOR    ->    let res = a ^ b;
4. Bitwise NOT    ->    let res = !a;

BIT SHIFT OPERATION

5. Left shift     ->    let res = a << 1;
6. Right shift    ->    let res = a >> 1;


*/

// 1. Set a specific bit (make it 1) at a given position
void set_bit(unsigned int *word, int n);

// 2. Clear a specific bit (make it 0) at a given position
void clear_bit(unsigned int *word, int n);

// 3. Toggle a specific bit (flip it) at a given position
void toggle_bit(unsigned int *word, int n);

// 4. Check if a bit at a given position is set
bool is_bit_set(unsigned int word, int n);

// 5. Count the number of set bits (1s) in an integer (Hamming Weight)
int count_set_bits(unsigned int word);


// --- Implementations ---
void set_bit(unsigned int *word, int n) {// e.g. n = 4; let mask = 1 << n; word = word | mask;
    *word = *word | (1U << n);
}

void clear_bit(unsigned int *word, int n) { // e.g. n = 4; let mask = 1 << 4; mask = !(1 << 4); 
    *word = *word & ~(1U << n);
}

void toggle_bit(unsigned int *word, int n) { // e.g. n = 4; let mask = 1 << 4; word = word ^ mask
    *word = *word ^ (1U << n);
}

int read_bit(unsigned int *word, int n) { // shift to pos 0 amd AND to 1
    return (*word >> n) & 1U;
}

bool is_bit_set(unsigned int word, int n) {
    return (word >> n) & 1U;
}

int count_set_bits(unsigned int word) {
    return __builtin_popcount(word);
}


// --- Test Harness Logic ---

void run_test(const char* test_name, unsigned int actual, unsigned int expected) {
    if (actual == expected) {
        printf("[PASS] %s: Result 0x%X\n", test_name, actual);
    } else {
        printf("[FAIL] %s: Expected 0x%X, but got 0x%X\n", test_name, expected, actual);
    }
}


int main() {
    printf("Starting Bit Manipulation Tests...\n\n");

    unsigned int data = 0x00; // Binary: 0000 0000

    // Test 1: Set Bit
    set_bit(&data, 3); // Should be 0000 1000 (0x08)
    run_test("Set Bit (pos 3)", data, 0x08);

    // Test 2: Toggle Bit
    toggle_bit(&data, 0); // Should be 0000 1001 (0x09)
    run_test("Toggle Bit (pos 0)", data, 0x09);

    // Test 3: Check Bit
    bool is_set = is_bit_set(data, 3);
    run_test("Is Bit Set (pos 3)", is_set, true);

    // Test 4: Clear Bit
    clear_bit(&data, 3); // Should be 0000 0001 (0x01)
    run_test("Clear Bit (pos 3)", data, 0x01);

    // Test 5: Count Bits
    unsigned int test_val = 0xF; // Binary: 1111 (4 bits set)
    int count = count_set_bits(test_val);
    run_test("Count Set Bits (0xF)", count, 4);

    printf("\nTesting Complete.\n");
    return 0;
}