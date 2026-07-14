#include <stdio.h>
#include <stdlib.h>

// System() functions enables us to run commands in the shell(terminal)

int main(){

    int status = system("a");

    if(status == -1){
        fprintf(stderr, "Error occured");
        return 1;
    }

    printf("success \n");

    return 0;
}