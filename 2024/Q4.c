#include <stdio.h>

int main() {
    int i, j, z;

    for(i = 1; i <= 5; i++) {
        for(j = 5-i; j >= 0; j--) {
            printf(" ");
        }
        for(z=1; z<=i; z++){
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
