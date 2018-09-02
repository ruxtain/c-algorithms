// @Date:   2018-09-02 14:56:00
#include <stdio.h>

int isPrime(int, int[], int);

int main(void) {
    const int total = 30000;
    int primes[30000] = {2};
    int count = 1;
    int i = 3;
    while (count < total) {
        if (isPrime(i, primes, count)) {
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

// 仅仅和已有的素数相除来比较，效率大大提升
int isPrime(int x, int knownPrimes[], int lenOfKnownPrimes) {
    int ret = 1; // 1 for true
    int i;
    for (i=0; i<lenOfKnownPrimes; i++) {
        if (x % knownPrimes[i] == 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}