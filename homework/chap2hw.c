#include <stdbool.h>
#include <stdio.h>

bool is_little_endian(){
    int x = 1;
    return (*((char*)&x)) == 1;
}

int mix_xlow_and_yhigh(int x, int y){
    int x_low = x & 0xFF;
    int y_high = y & (~0xFF);
    return x_low + y_high;
}

int replace_byte(unsigned x, int i, unsigned char b){
    int cover = ~(0xFF << (i * 8));
    int ret = x & cover;
    int add = ((unsigned) b) << (i * 8);
    return ret + add;    
}

/**
 * get the highest byte of x
 */
int get_msb(int x){
    int operated = x >> ((sizeof(int) - 1) << 3);
    int ret = operated & 0xFF;
    printf("get_msb(%d): %d\n", x, ret);
    return ret;
}

/**
 * problem 2.61
 */
int problem2_61(int x){
    return x == 0 || (~x) == 0 || (~(x & 0xFF)) == 0 || get_msb(x) == 0;
}

/**
 * problem 2.62
 */
bool int_shifts_are_arithmetic(){
    int test_num = ~0;
    int offset = sizeof(int) << 3 - 1;
    int test_result = test_num >> offset;
    return test_result != 1;
}


int main(){
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}