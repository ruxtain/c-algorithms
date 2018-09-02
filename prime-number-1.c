// @Date:   2018-09-02 14:56:00
#include <stdio.h>

int isPrime(int);

int main(void) {
    const int total = 30000;
    int primes[30000] = {2};
    int count = 0;
    int i = 3;
    while (count < total) {
        if (isPrime(i)==1) {
            primes[count++] = i;
        }
        i++;
    };

    for (int i=0; i<total; i++) {
        printf("%d\t", primes[i]);
    };
    printf("\n");
    return 0;
}


int isPrime(int x) {
    int ret = 1; // 1 for true
    int i;
    // 非2的偶数直接可以确定不是素数，提高效率
    if (x == 1 || (x%2 == 0 && x != 2))
    {
        ret = 0;
    } 
    else {
        for (i=3; i<x; i+=2) {
            if (x % i == 0) {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}