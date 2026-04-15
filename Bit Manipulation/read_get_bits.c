#include <stdio.h>
#include <stdint.h>

// Simulate receiving raw network data
void parse_unknown_protocol(uint8_t *data, size_t len) {
    printf("Received %zu bytes\n", len);
    
    // PROBLEM: Without knowing the protocol, you can't parse!
    // Is the first byte:
    // - A 4-bit version + 4-bit header length? (IP)
    // - A single 8-bit command? (Custom protocol)
    // - Two 4-bit fields? (Another protocol)
    
    // You MUST know ahead of time what format to expect
}

// Example: You DO know it's an IP packet (standard)
void parse_ip_packet(uint8_t first_byte) {
    // Because you know IP uses:
    // bits 4-7: version (4 bits)
    // bits 0-3: IHL (4 bits)
    
    uint8_t version = (first_byte >> 4) & 0x0F;
    uint8_t ihl = first_byte & 0x0F;
    
    printf("IP Packet: Version %d, Header %d bytes\n", version, ihl * 4);
}

// Example: You DO know it's a custom embedded protocol
void parse_custom_protocol(uint8_t command_byte) {
    // Because YOU designed it:
    // bit 7: flags (1 bit)
    // bits 4-6: command type (3 bits)
    // bits 0-3: length (4 bits)
    
    uint8_t has_flags = (command_byte >> 7) & 0x01;
    uint8_t cmd_type = (command_byte >> 4) & 0x07;
    uint8_t length = command_byte & 0x0F;
    
    printf("Custom: Flags=%d, Cmd=%d, Len=%d\n", has_flags, cmd_type, length);
}

int main() {
    uint8_t ip_byte = 0x45;
    uint8_t custom_byte = 0b10110010;  // 1, 011, 0010
    
    printf("Same byte value 0x%02X means different things:\n\n", custom_byte);
    
    parse_ip_packet(ip_byte);           // Works because we know it's IP
    parse_custom_protocol(custom_byte); // Works because we know the format
    
    return 0;
}