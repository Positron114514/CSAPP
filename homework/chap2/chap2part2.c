/**
 * CSAPP Chapter 2 homework
 * P2.71 - P2.XX
 * 
 * By Positron114514 on 2024/7/30
 * Wrote on Ubuntu 22.04.3 LTS
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * P2.71
 */
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum){
    int left_cutted = word << ((3 - bytenum) << 3);
    return left_cutted >> 24;
}

/**
 * P2.72
 */
void copy_int(int val, void* buf, int maxbytes){
    // size_t -> int
    if(maxbytes - (int)sizeof(val) >= 0){
        memcpy(buf, (void*) val, sizeof(val));
    }
}

/**
 * P2.73
 */
int saturating_add(int x, int y){
    int ans = x + y;
    int sz_of_int = sizeof(int) << 8;
    unsigned sig_mask = 1 << (sz_of_int - 1);
    
    // neg = 1000...0 -> x < 0, y < 0, not overflow: ans <= 0, sig_ans = 100...0
    // pos = 1000...0 -> x > 0, y > 0, not overflow: ans >= 0, sig_ans = 000...0
    unsigned neg = (x & y) & sig_mask, pos = (x | y) | (~sig_mask);
    unsigned ans_sig = ans & sig_mask;
    int ret = ans;
    // ~000...1 + 1 = 111...1, ~000...0 + 1 = 000...0
    ret = ret & (~(neg == ans_sig) + 1);
    ret = ret & (~(pos != ans_sig) + 1);
    return ret;
}

/**
 * P2.74
 */
int tsub_ok(int x, int y){
    // same_sig(x, y) == 0 && same_sig(x - y, x) == 0;
    int ans = x - y;
    unsigned not_same_sig = (x ^ y) >> ((sizeof(int) << 3) - 1);

    return !not_same_sig || ((~(ans ^ x)) >> ((sizeof(int) << 3) - 1));
}

// shitty things. 
// if i continue to write these hw, i'll smash my pc offffffffff

/**
 * P2.75
 */


int main(){
    packed_t num = 0x13141516;

    printf("%d\n", tsub_ok(1, -1));

    return 0;
}