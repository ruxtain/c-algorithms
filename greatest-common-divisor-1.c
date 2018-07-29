// @Date:   2018-07-29 21:53:26
// the gcd of 12 and 18 is 6

#include <stdio.h>

int main(void) {
    int a = 12; 
    int b = 18;
    int min;
    int i;
    
    if (a > b) {
        min = b;
    } else {
        min = b;
    }

    for (i=min; i>=1; i--) {
        if (a%i == 0 && b%i == 0) {
            break; // end loop with the biggest qualified i
        }
    }
    printf("gcd(%d, %d) = %d\n", a, b, i);
    return 0;
}