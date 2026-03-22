#include <stdio.h>

float calculateBill(float total, char method)
{
    float discount = 0;

    if(total >= 1000)
        discount = discount + 10;

    if(method == 'C')
        discount = discount + 5;

    float finalBill = total - (total * discount / 100);

    printf("Total Bill: %.2f\n", total);
    printf("Discount: %.2f%%\n", discount);
    printf("Final Bill: %.2f\n", finalBill);

    return finalBill;
}

void saveBill(float bill)
{
    FILE *fp;
    fp = fopen("bill.txt","w");

    fprintf(fp,"Final Bill = %.2f",bill);

    fclose(fp);
}

int main()
{
    float item1=100, item2=40;
    int q1,q2;
    char method;
    float total, finalBill;

    printf("Enter quantity of item1: ");
    scanf("%d",&q1);

    printf("Enter quantity of item2: ");
    scanf("%d",&q2);

    printf("Payment Method (M=Cash, C=Card): ");
    scanf(" %c",&method);

    total = (q1*item1) + (q2*item2);

    finalBill = calculateBill(total,method);

    saveBill(finalBill);

    return 0;
}
