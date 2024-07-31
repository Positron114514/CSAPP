#include <stdio.h>
#include <stdint.h>

#define POS_INFINITY 1e400 
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0 / POS_INFINITY)

/**
 * without multiply, if, etc
 * if x < 0, then (x >> 31) & 15 = b1111 = 16 - 1
 * else (x >> 31) & 15 = 0
 */
int div16(int x){
    return (x + ((x >> 31) & 15)) >> 4; 
}



int main(){
    printf("%d\n%d\n", div16(16), div16(-32));
    return 0;
}