#include <stdio.h>

// Function to calculate discount
float calculateDiscount(float total, char method) {
    float discount = 0;

    if(total >= 1000) {
        discount += 0.10 * total; // 10%
    }

    if(method == 'C' || method == 'c') {
        discount += 0.05 * total; // extra 5%
    }

    return discount;
}

// Function to write bill to file
void saveToFile(float total, float discount, float finalAmount, int q1, int q2) {
    FILE *fp = fopen("bill.txt", "w");

    fprintf(fp, "Item 1 Quantity: %d\n", q1);
    fprintf(fp, "Item 2 Quantity: %d\n", q2);
    fprintf(fp, "Total: %.2f\n", total);
    fprintf(fp, "Discount: %.2f\n", discount);
    fprintf(fp, "Final Amount: %.2f\n", finalAmount);

    fclose(fp);
}

int main() {
    int q1, q2;
    float price1 = 80.0, price2 = 65.0;
    float total, discount, finalAmount;
    char method;

    printf("Enter quantity of item 1: ");
    scanf("%d", &q1);

    printf("Enter quantity of item 2: ");
    scanf("%d", &q2);

    total = (q1 * price1) + (q2 * price2);

    printf("Enter payment method (M for Cash, C for Credit): ");
    scanf(" %c", &method);

    discount = calculateDiscount(total, method);
    finalAmount = total - discount;

    printf("\nTotal Bill: %.2f\n", total);
    printf("Discount: %.2f\n", discount);
    printf("Final Bill: %.2f\n", finalAmount);

    saveToFile(total, discount, finalAmount, q1, q2);

    return 0;
}
