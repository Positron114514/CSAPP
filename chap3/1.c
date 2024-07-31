#include <stdio.h>

int overflow(int a, int b){
    int ans = a + b;
    return ans;
}

int main(){
    int of1 = overflow(1, 2);
    int of2 = overflow(101100101, 999999999);

    printf("%d\n%d\n", of1, of2);
    return 0;
}