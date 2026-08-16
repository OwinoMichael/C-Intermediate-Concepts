#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Note the 3 arguments instead of 1 when altering behavior with SA_SIGINFO
void advanced_handler(int sig, siginfo_t *info, void *context) {
    const char msg[] = "Segfault occurred!\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    
    // info->si_addr contains the exact address that caused the crash
    printf("Faulty memory address accessed: %p\n", info->si_addr);
    
    exit(13);
}

int main() {
    struct sigaction sa;
    
    sa.sa_sigaction = advanced_handler; // Use sa_sigaction instead of sa_handler
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;          // Alter behavior to request extra metadata

    sigaction(SIGSEGV, &sa, NULL);     // Intercept Segfaults

    // Trigger a crash at a specific address (0xDEADBEEF)
    int *bad_ptr = (int *)0xDEADBEEF;
    *bad_ptr = 42; 

    return 0;
}