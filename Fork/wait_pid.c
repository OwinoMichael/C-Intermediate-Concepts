#include<stdio.h>
#include<sys/wait.h>

/*
    with waitpid() we can pass args such as pid, &status, behavior

    // Wait for any child, don't block
    waitpid(-1, &status, WNOHANG);

    // Wait for specific child PID, block
    waitpid(child_pid, &status, 0);

    // Wait for any child in same process group
    waitpid(0, &status, 0);
    
    // Wait for any child with specific pid of 200
    waitpid(-200, &status, 0);

    Third Argument (options):
        Option	        Behavior
        0	            Block until child exits (default)
        WNOHANG	        Don't block - return immediately if no child exited
        WUNTRACED	    Also return if child stopped (not just exited)
        WCONTINUED	    Also return if stopped child resumed

*/

int main(){
    if (fork() == 0){
        execlp("ls", "ls", NULL);
        printf("Parent msg");
    }else{
        waitpid(0, NULL, WNOHANG);
        printf("I am a parent and my child id is : %d\n", getpid());
    }

    return 0;
};