// @Date:   2018-07-29 20:36:25
// Requirement: Convert an integer such as 123 to 1 2 3

#include <stdio.h>
#include <math.h>

int main(void) {
    int n = 1236600; // the int to be separated
    int out;
    int temp = n;
    int mask = 1;

    while (temp > 0) {
        temp /= 10;
        mask *= 10;
    }

    mask /= 10;

    while (mask > 0) {
        out = n / mask;
        printf("%d ", out);
        n -= out * mask;     // n %= mask; works too
        mask /= 10;
    }
    printf("\n");
    return 0;
}

