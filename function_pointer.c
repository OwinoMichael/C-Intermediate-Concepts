#include<stdio.h>

int add(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b; 
}

void print_result(int a, int b, int (*fptr)(int a, int b)){
    printf("The res is : %d\n", fptr(a, b));
}



int main(){

    int (*fptr)(int a, int b); // basic function pointer
    fptr = &add;
    printf("The sum is : %d\n", fptr(10, 20));
    
    print_result(10, 20, &add); //function pointer passed as an argument
    print_result(20, 10, &sub);

    int (*fptr2[])(int a, int b) = {add, sub}; // function pointer as an array of functions 

    // Create a Rectangle object
    Rect r;
    constructRect(&r);

    // Use r as a Rectangle
    r.set(&r, 10, 5);
    r.show(&r);
    printf("Rectangle Area: %d", r.area(&r));
    
    return 0;
}

typedef struct Rect {
    int w, h;
    void (*set)(struct Rect*, int, int);
    int (*area)(struct Rect*);
    void (*show)(struct Rect*);
} Rect;

// Function to find the area
int area(Rect* r) {
    return r->w * r->h;
}

// Function to print the dimensions
void show(Rect* r) {
    printf("Rectangle's Width: %d, " 
          "Height: %d\n", r->w, r->h);
}

// Function to set width 
// and height (setter)
void set(Rect* r, int w, int h) {
    r->w = w;
    r->h = h;
}

// Initializer/constructor 
// for Rectangle
void constructRect(Rect* r) {
    r->w = 0;
    r->h = 0;
    r->set = set;
    r->area = area;
    r->show = show;
}