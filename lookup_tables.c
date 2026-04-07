#include <stdio.h>

enum foo{
    foo_2 = 0,
    foo_3,
    foo_4
};

static int squares[] = {
    [foo_3] = 9,
    [foo_2] = 4,
    [foo_4] = 16,
};

int main(){
    printf("%d\n", squares[foo_2]);
    printf("%d\n", squares[foo_3]);
    printf("%d\n", squares[foo_4]);

    return 0;
}