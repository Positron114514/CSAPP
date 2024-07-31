#include <stdio.h>

int bis(int x, int m){
    return x | m;
}

int bic(int x, int m){
    return x & (~m);
}

int or(int a, int b){
    return bis(a, b);
}


int xor(int a, int b){
    return bis(bic(a, b), bic(b, a));
}

int main(){
    unsigned x = 0;
    printf("%d\n", x - 1);
}