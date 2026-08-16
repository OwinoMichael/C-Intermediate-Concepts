#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_hanlder(int num){

    write(STDOUT_FILENO, "Hello Sig \n", 11);
    _exit(13);
}

int main(){

    struct sigaction sa;

    sa.sa_handler = signal_hanlder; // Assign the basic callback function
    sigemptyset(&sa.sa_mask); // Clear the mask (block no extra signals)
    sa.sa_flags = 0;  // 0 = Default, normal behavior

    sigaction(SIGINT, &sa, NULL); // Register and Intercept Ctrl+C

    while(1){

        printf("%d\n", getpid());

        sleep(10);
    }

    return 0;
}
