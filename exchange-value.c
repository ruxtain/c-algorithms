// @Date:   2018-09-30 18:24:38
#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
    int a = 1;
    int b = 2;
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}