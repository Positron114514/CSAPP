/**
 * CSAPP Chapter 2 homework
 * P2.61 - P2.70 and some exercises
 * 
 * By Positron114514 on 2024/7/30
 * Wrote on Ubuntu 22.04.3 LTS
 */

#include <stdbool.h>
#include <stdio.h>

int size_of_integer(){
    return sizeof(int) << 3;
}

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

/**
 * problem 2.63-1
 */
unsigned srl(unsigned x, int k){
    unsigned xsra = (int) x >> k;
    // create a number of k zeros and (sizeof(int) - k) ones
    unsigned cover_code = (1 << ((sizeof(int) << 3) - k + 1)) - 1; 
    return xsra & cover_code;
}

/**
 * problem 2.63-2
 */
int sra(int x, int k){
    int xsrl = (unsigned) x >> k;
    // get +/-
    int pos_or_neg = x & (1 << ((sizeof(int) << 3) - 1));
    // add ones before neg number
    int offset = (pos_or_neg << ((sizeof(int) << 3) - k + 1)) - pos_or_neg;
    return xsrl | offset;
}

/**
 * P2.64
 */
int any_odd_one(unsigned x){
    unsigned exam = 0x55555555;
    return (x & exam) != 0;
}

/**
 * p2.65
 */
int odd_ones(unsigned x){
    // calculate a ^ b until left one num
    x = x & (x >> 16);
    x = x & (x >> 8);
    x = x & (x >> 4);
    x = x & (x >> 2);
    x = x & (x >> 1);
    return x & 1;
}

/**
 * p 2.66
 */
int leftmost_one(unsigned x){
    // x -> [00...111...1] >> 1
    unsigned mask = x >> 1;
    mask = mask | (mask >> 2);
    mask = mask | (mask >> 4);
    mask = mask | (mask >> 8);
    mask = mask | (mask >> 16);
    // if x != 0, then ret = [00...111...1] + 1 
    // else ret = 0
    return (mask + 1) & x;
}

/**
 * p 2.67
 */
int int_size_is_32(){
    // examine 16
    int is_16 = ((1 << 15) >> 15) != 1;
    // 32
    int is_32 = ((1 << 31) >> 31) != 1;
    return is_32 && !is_16;
}

/**
 * p2.68
 */
int lower_one_mask(int n){
    // 111...11 >> (int_size - n)
    unsigned x = ~0;
    return x >> (size_of_integer() - n);
}

/**
 * p2.69
 */
unsigned rotate_left(unsigned x, int n){
    // if n == 0, left = 0
    // else left = left of x 
    unsigned left = (x >> (size_of_integer() - n)) && n; 
    return (x << n) + left;
}

/**
 * p2.70
 */
int fits_bits(int x, int n){
    // get bits beyond n
    unsigned mask = (~0) << n;
    unsigned addr = x & mask;
    // get symbol bit in n-bit
    unsigned symbol = (1 << (n - 1)) & x;
    // if addr == 0 and symbol == 0(> 0), then correct
    // else if addr == mask (111...1) and symbol != 0(<0), then correct
    return (addr == 0 && symbol == 0) || ((addr == mask) && (symbol != 0));
}

int main(){
    printf("%d\n", fits_bits(6, 3));
    return 0;
}