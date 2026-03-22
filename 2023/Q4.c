#include <stdio.h>

int main()
{
    int amount;

    printf("Enter amount: ");
    scanf("%d",&amount);

    if(amount > 50000)
    {
        printf("Maximum withdrawal is 50000");
        return 0;
    }

    printf("5000 notes = %d\n", amount/5000);
    amount %= 5000;

    printf("1000 notes = %d\n", amount/1000);
    amount %= 1000;

    printf("500 notes = %d\n", amount/500);
    amount %= 500;

    printf("100 notes = %d\n", amount/100);
    amount %= 100;

    printf("50 notes = %d\n", amount/50);
    amount %= 50;

    printf("20 notes = %d\n", amount/20);

    return 0;
}
