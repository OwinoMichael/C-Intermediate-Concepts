#include<stdio.h>
#include <unistd.h>

/*
  - All processes in Unix are started by one single process i.e. init/Systemmd/Systemctl..
  - Processes have a parent-child structure
  - Processes can be creating by launching a program, BUT they can also be born out of other processes
  - That's where fork() comes in, which clones process
  - In UNIX systems, fork() returns PID of child to parent, and returns 0 to the child
  - "-1" is returned meaning the system call failed

*/

int main(){

    if(fork() == 0){
        printf("I am the child \n");
    }else{
        printf("I am the parent! %d\n", getpid());
    }
    
    return 0;
}