#include <stdio.h>
#include <stdint.h> // In a header file (types.h)


#define u64 uint64_t
#define i64 int64_t
#define u32 uint32_t
#define i32 int32_t
#define u16 uint16_t
#define i16 int16_t
#define u8 uint8_t
#define i8 int8_t

typedef uint64_t u64;
typedef int64_t  i64;
typedef uint32_t u32;
typedef int32_t  i32;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint8_t  u8;
typedef int8_t   i8;

typedef double   f64;
typedef float    f32;

int main(){
    u64 b = 762836489;

    printf("%lu\n", sizeof(b));

    return 0;
}