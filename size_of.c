#include <stdio.h>

int main(void){
    int a = 1;
    int xs[] = {1, 2, 3, 4, 5, 6,7, 8};
    int *xs_ptr = xs;

    printf("%zu\n", sizeof a);
    printf("%zu\n", sizeof xs);
    printf("%zu\n", sizeof xs_ptr);
}