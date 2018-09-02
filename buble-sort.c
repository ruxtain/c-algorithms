// @Date:   2018-09-02 14:32:41
// 冒泡排序

#include <stdio.h>
#define len(a) sizeof(a)/sizeof(a[0])

int main(void) {
    int a[] = {2,4,32,1,12,3,6,79,0};
    for (int n=len(a); n>0; n--) {
        for (int i=0; i<len(a)-1; i++) {
            if (a[i] > a[i+1]) {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }

    for (int i = 0; i < len(a); ++i) {
        printf("%d\n", a[i]);
    }
    return 0;
}