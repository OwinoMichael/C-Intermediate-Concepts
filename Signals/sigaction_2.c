#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void shutdown_handler(int sig) {
    const char msg1[] = "[1/2] Critical shutdown started. Ctrl+C is currently blocked...\n";
    write(STDOUT_FILENO, msg1, sizeof(msg1) - 1);
    
    // Simulate a slow cleanup process (e.g., flushing logs, saving state)
    sleep(5); 
    
    const char msg2[] = "[2/2] Shutdown complete. Exiting.\n";
    write(STDOUT_FILENO, msg2, sizeof(msg2) - 1);
    exit(0);
}

int main() {
    struct sigaction sa;
    
    sa.sa_handler = shutdown_handler;
    sa.sa_flags = 0; 
    
    // 1. Initialize the mask to be completely empty
    sigemptyset(&sa.sa_mask);
    
    // 2. Add SIGINT (Ctrl+C) to the mask. 
    // This blocks Ctrl+C ONLY while shutdown_handler is running.
    sigaddset(&sa.sa_mask, SIGINT);

    // Register the handler for SIGTERM (kill [PID])
    sigaction(SIGTERM, &sa, NULL);

    printf("Program running. Process ID: %d\n", getpid());
    printf("Send SIGTERM from another terminal using: kill %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}