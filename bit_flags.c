#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

typedef unsigned int t_flag;
#define FLAG_A ( 1 << 0)
#define FLAG_B (  1 << 1)
#define FLAG_C ( 1 << 2)

// typedef enum {
//     FLAG_A = ( 1 << 0 ),
//     FLAG_B = ( 1 << 1 ),
//     FLAG_C = ( 1 << 2 )
// } t_flag;

int is_flag(int x, t_flag flags){
    
    if(flags & FLAG_A) x += x;
    if(flags & FLAG_B) x *= x;
    if(flags & FLAG_C) x = x;
    
    return x;
}

int main(void){

    printf("%d\n", is_flag(1234, 0));
    printf("%d\n", is_flag(1234, FLAG_A));
    printf("%d\n", is_flag(1234, FLAG_B | FLAG_C));

    SDL_Window *window;    // real life example, SDL library
    SDL_Init(SDL_INIT_VIDEO);   

    window = SDL_CreateWindow(
        "An SDL3 window",                  // window title
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSVCREEN                 // flags - see below
    );


    return 0;
}