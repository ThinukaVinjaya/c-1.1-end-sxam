#include <stdio.h>

int main() {
    int n = 4;

    // Upper part
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("*");

        for(int j = 1; j <= 2*(n-i); j++)
            printf(" ");

        for(int j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }

    // Lower part
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++)
            printf("*");

        for(int j = 1; j <= 2*(n-i); j++)
            printf(" ");

        for(int j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}
