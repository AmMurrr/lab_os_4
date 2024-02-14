#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

float E(int x) {
    float ae;
    ae = 1 + 1.0/x;
    return pow(ae,x);
}

char* transition(long x) {
    char* binary = (char*)malloc(33);
    int ind = 0;

    while(x > 0) {
        binary[ind] = (x%2) + '0';
        x /= 2;
        ind++;
    }
    binary[ind] = '\0';

    int j,i;
    for(i = 0, j = ind - 1;i < j;i++,j--) {
        char temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }

    return binary;
}