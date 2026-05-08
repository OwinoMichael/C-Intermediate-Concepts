#include <stdio.h>
#include <unistd.h>

/*
    What if you want to run a new process when the instructions are not in the calling programs?
    - That is when we use "exec"
    - execl -> we pass a list into args i.e. ("prog1", "prog2", "prog3", NULL)
    - execv -> we pass a vector i.e. something that contains a list
    - execlp -> p is for path, it will for the path of the file, WITHOUT it we need the exact program path
    - execle -> e is for .env variables, without it, the programs takes .env from the call
    - exec has to NULL terminated so to know when there are no arguments
*/

int main(){

    if (fork() == 0){
        execlp("ls", "ls", NULL);
        printf("Parent msg");
    }else{
        printf("I am a parent and my child id is : %d\n", getpid());
    }

    

    return 0;
}