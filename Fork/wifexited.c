#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        //in the child process
        printf("child process started ... ");
        printf("child process exiting ... ");

        exit(42);
    }else{
        int status;

        // block parent until child process finishes
        waitpid(pid, &status, 0);

        //check if the child finieshed ok
        if(WIFEXITED(status)){

            int exit_code = WEXITSTATUS(status);
            printf("Child exited normally");
        }else{
            printf("child terminated abnomarlly");
        }


    }

    return 0;
}