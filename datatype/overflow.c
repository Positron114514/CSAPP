int tadd_ok(int a, int b){
    int x = a + b;
    return !(a > 0 && b > 0 && x < 0) && !(a < 0 && b < 0 && x > 0); 
}

int tmult_ok(int a, int b){
    int x = a * b;
    return a == 0 || x / a == b;
}

