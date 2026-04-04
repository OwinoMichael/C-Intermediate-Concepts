#include <stdio.h>
#include <stdlib.h>

// allows for usecases where a function can be used with different types e.g. malloc, calloc, qsort

int compar(const void *a, const void *b){
    return *(int *)a - *(int *)b; 
}

int main(){

    int arr[] = {10, 5, 2, 8, 4, 9, 1, 3};
    int len = sizeof(arr) / sizeof(arr[1]);
    printf("%d\n", len);

    qsort(arr, len, sizeof(int), compar);

    for(int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

// 1. Dynamically allocated (heap)
void *return_malloc() {
    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    return ptr;  // OK - heap memory persists
}

// 2. Static local variable
void *return_static() {
    static int x = 100;
    return &x;  // OK - static lasts forever
}

// 3. Global variable
int global_x = 999;
void *return_global() {
    return &global_x;  // OK - global lasts forever
}

// 4. Parameter passed in
void *return_parameter(void *incoming) {
    return incoming;  // OK - caller owns the memory
}