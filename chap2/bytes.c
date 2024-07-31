#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    for(size_t i = 0; i < len; i++){
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void show_integer(int a){
    show_bytes((byte_pointer) &a, sizeof(int));
}

void show_pointer(void* pointer){
    show_bytes((byte_pointer) &pointer, sizeof(void *));
}

void main(){
    int a = 1;
    show_integer(a);
    show_pointer(&a);
}