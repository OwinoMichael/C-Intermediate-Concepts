#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Ethernet frame parsing (simplified)
struct ethernet_header {
    uint8_t dest_mac[6];
    uint8_t src_mac[6];
    uint16_t ethertype;
} __attribute__((packed));

// IP header first 20 bytes
struct ip_header {
    uint8_t  ver_ihl;      // Version (4 bits) + IHL (4 bits)
    uint8_t  tos;
    uint16_t total_len;
    uint16_t id;
    uint16_t frag_off;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t checksum;
    uint32_t src_ip;
    uint32_t dst_ip;
} __attribute__((packed));

// Parse functions using your bit manipulation skills
uint8_t get_ip_version(uint8_t ver_ihl) {
    return (ver_ihl >> 4) & 0x0F;
}

uint8_t get_ip_header_length(uint8_t ver_ihl) {
    return (ver_ihl & 0x0F) * 4;  // IHL is in 32-bit words
}

int main() {
    // Simulate received packet first byte
    uint8_t ip_first_byte = 0x45;  // Version 4, IHL 5
    
    printf("IP Version: %u\n", get_ip_version(ip_first_byte));
    printf("IP Header Length: %u bytes\n", get_ip_header_length(ip_first_byte));
    
    // Test your fixed functions
    uint32_t flags = 0;
    set_bit(&flags, 3);
    set_bit(&flags, 7);
    printf("Flags after setting bits 3 and 7: 0x%X\n", flags);
    
    clear_bit(&flags, 3);
    printf("Flags after clearing bit 3: 0x%X\n", flags);
    
    return 0;
}