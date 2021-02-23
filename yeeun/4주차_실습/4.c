#include <stdio.h>

int main(void) {
    int x, a, b, c;
    int result;

    printf("Input a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Input x: ");
    scanf("%d", &x);

    result = a*(x*x) + b*(x) + c;

    printf("f(%d) = %d", x, result);

    return 0;
}