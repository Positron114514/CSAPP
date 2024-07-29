#include <stdio.h>

float sum_float(float* nums, unsigned len){
    int i;
    float result;
    unsigned x = len - 1;
    for(int i = 0; i <= len - 1; i++){
        // printf("1");
        result += nums[i];
    }
    return result;
}

int main(){
    float nums[1] = {1};
    sum_float(nums, 0);
}