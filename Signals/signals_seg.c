#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>


void signal_handler(int num){
    const char msg[] = "\n Segfault signal, out of bounds";
    write(STDOUT_FILENO, msg, sizeof(msg)-1);
    exit(13);
}

int main(){
    // 1. REGISTER THE HANDLER FIRST
    signal(SIGSEGV, signal_handler);

    // 2. FORCIBLY TRIGGER A GENUINE SEGFAULT
    int *bad_ptr = NULL;
    printf("The number accessed is: %d\n", *bad_ptr); 

    return 0;
}