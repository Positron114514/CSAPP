/**
 * E3.5
 */
void decode1(long* xp, long* yp, long* zp){
    long a = *xp, b = *yp, c = *zp;
    *yp = a;
    *zp = b;
    *xp = c;
}

