// @Date:   2018-07-29 21:53:26
// the gcd of 12 and 18 is 6
// a   b   tmp
// 12  18  (12%18)=12
//  <-------
// 18  12  (18%12)=6
//  <-------
// 12  6   (12%6)=0
//  <-------
// 6   0    (end)

#include <stdio.h>

int main(void) {
    int a = 18; 
    int b = 27;
    int org_a = a; // save the original values
    int org_b = b;
    int tmp;
    
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    
    printf("gcd(%d, %d) = %d\n", org_a, org_b, a);
    return 0;
}