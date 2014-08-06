#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int sum = 0;
    int N;
    while (scanf("%d", &N)) {
        sum += N;
    }
    printf("the sum is %d\n", sum);
    return 0;
}
