#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const unsigned char MATRIX[10][10] = {
    {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
    {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
    {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
    {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
    {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
    {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
    {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
    {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
    {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
    {2, 5, 8, 1, 4, 3, 6, 7, 9, 0}
};

unsigned char damm_checksum(unsigned int n) {
    int accum = 0;
    unsigned int ndigits = (unsigned int)floor(log10(n) + 1);
    unsigned int k = (unsigned int)pow(10, ndigits - 1);
    unsigned int i;
    if(n < 10)
        return MATRIX[accum][n];
    for(i=0;i < ndigits; i++) {
        int digit = n / k;
        accum = MATRIX[accum][digit];
        n -= digit * k;
        k /= 10;
    }
    return accum;
}

int main(int argc, char* argv[]) {
    int i, n;
    char *end;
    for(i=1; i < argc; i++) {
        n = strtol(argv[i], &end, 10);
        if((end - argv[i]) < strlen(argv[i]))
            continue;
        printf("n: %d, checksum: %d\n", n, damm_checksum(n));
    }
    return 0;
}
