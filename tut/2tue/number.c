#include <stdio.h>

typedef unsigned int Word;

int main(void) {
    Word a = 4;
    int i;
    for (i = (sizeof(Word) * 8) - 1; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
    return 0;
}
