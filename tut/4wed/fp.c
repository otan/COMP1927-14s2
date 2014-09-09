#include <stdio.h>
#include <stdlib.h>

int add(int n1, int n2) {
    return n1 + n2;
}

int subtract(int n1, int n2) {
    return n1 - n2;
}

int main(void) {
    int (*fn)(int,int) = &add;
    printf("%d\n", (*fn)(2,4));
    return 0;
}
