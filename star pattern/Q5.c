#include <stdio.h>

int main() {
    int n = 5;
    int coef;

    for(int i = 0; i < n; i++) {
        coef = 1;

        // spaces
        for(int j = 0; j < n - i; j++)
            printf(" ");

        // numbers
        for(int j = 0; j <= i; j++) {
            printf("%d ", coef);
            coef = coef * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}
