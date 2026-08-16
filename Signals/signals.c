#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 *  A signal is a software-generated interrupt sent to a process by the OS 
 *  when the user presses Ctrl-C 
 *  or another process sends a signal to this process
 * 
 *  SIGINT - Interrupt signal (sent when Ctrl+C is pressed by the user)
 *  SIGTERM - Termination signal (request to terminate the process
 *  SIGKILL - Kill signal (forceful termination of a process). OS Bypass
 *  SIGSEGV - Segmentation fault (invalid memory access).
 */

void signal_handler(int num){
    const char message[] = "I am terminating, SIGINT CAUGHT!!!\n";

    write(STDOUT_FILENO, message, sizeof(message)-1);
    _exit(13); // Dont forget to exit: _exit() immediate, exit() closes & flushes before exiting
} 

int main(){

    signal(SIGINT, signal_handler);

    while(1){
        printf("Cycles wasted: %d\n", getpid());

        sleep(2);
    }
    return 0;
}