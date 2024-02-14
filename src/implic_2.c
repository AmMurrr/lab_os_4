#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

long long factorial(int n) {
    long long ans = 1;
    for(int j = 2; j <= n;j++)
        ans *= j;
    return ans;
}

float E(int x) {
    float e = 1.0;

    for(int i = 1; i <= x; i++)
        e += 1.0 / factorial(i);
    return e;

}

char* transition(long x) {
    char* binary = (char*)malloc(33);
    int ind = 0;

    while(x > 0) {
        binary[ind] = (x%3) + '0';
        x /= 3;
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