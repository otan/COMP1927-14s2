#include <stdio.h>

int main(void) {
    int password = 0;
    char buf[12];
    int password2 = 0;
    scanf("%s", buf);
    if (strcmp(buf, "password") == 0) {
        password = 1;
        password2 = 1;
    }
    if (password || password2) {
        printf("your credit card pin is XXXX\n");
    } else {
        printf("fuck off\n");
    }
    return 0;
}
