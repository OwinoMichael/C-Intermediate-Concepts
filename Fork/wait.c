#include<stdio.h>
#include<sys/wait.h>

/*
    exec* does not return a value unless we have an error
    so if it never return we have a "Zombie" process
    if there are many zombies, they might eat up much resources

    "wait()" alerts the parent process the child is done

*/

int main(){
    if (fork() == 0){
        execlp("ls", "ls", NULL);
        printf("Parent msg");
    }else{
        wait(NULL);
        printf("I am a parent and my child id is : %d\n", getpid());
    }

    return 0;
};