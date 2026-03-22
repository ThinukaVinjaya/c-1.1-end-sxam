#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void viewFoodPrice();
void placeOrder();
void bookTable();

char table[4][8];

int main(){

  int choice;

  while(1){
    printf("\n1.\tView Food Prices\n");
    printf("2.\tPlace an Order/View Final Bill\n");
    printf("3.\tBook a Table\n");
    printf("4.\tExit\n\n");

    printf("Enter Your Choice:");
    scanf("%d", &choice);

    switch(choice){
      case(1):
         viewFoodPrice();
         break;
      case(2):
         placeOrder();
         break;
      case(3):
         bookTable();
         break;
      case(4):
         printf("Have a nice Day!");
         exit(0);
    }
  }
  return 0;

}

void viewFoodPrice(){
    char food[10];
    float price;

    FILE * fp;
    fp = fopen("foods.txt","r");

    printf("Food Item\tPrice\n");
    printf("==========================\n");

    while(fscanf(fp,"%s %f",&food, &price) != EOF){
        printf("%s\t\t%.2f\n",food, price);
    }

    fclose(fp);

}

void placeOrder(){

    char food[4][10];
    float price[4];
    int quantity[4];
    float total = 0;

    FILE * fp;
    FILE * bill;
    fp = fopen("foods.txt","r");
    bill = fopen("bill.txt","w");


    for(int i=0; i<=3 ; i++){
        fscanf(fp,"%s", &food[i]);
        fscanf(fp,"%f", &price[i]);
        printf("Enter quantity of %s:", food[i]);
        scanf("%d", &quantity[i]);
    }

    printf("\nFood Item\tQuantity\tUnit Price\tSub Total\n");
    printf("========================================================\n");

    for(int i=0; i<=3 ; i++){
        printf("%s\t\t", food[i]);
        printf("%d\t\t", quantity[i]);
        printf("%.2f\t\t", price[i]);
        printf("%.2f\t\t\n", price[i]*quantity[i]);
        total += (price[i]*quantity[i]);
    }
    printf("Total\t\t\t\t\t\t%.2f\n", total);

    fprintf(fp,"\nFood Item\tQuantity\tUnit Price\tSub Total\n");
    fprintf(fp,"========================================================\n");

    for(int i=0; i<=3 ; i++){
        fprintf(bill,"%s\t\t", food[i]);
        fprintf(bill,"%d\t\t", quantity[i]);
        fprintf(bill,"%.2f\t\t", price[i]);
        fprintf(bill,"%.2f\t\t\n", price[i]*quantity[i]);
    }
    fprintf(bill,"Total\t\t\t\t\t\t%.2f\n\n", total);

    printf("Bill save to bill.txt successfully\n");

    fclose(fp);
    fclose(bill);
}


void bookTable(){
   int row_number,column_number;

   printf("\n===Available Tables of the Restaurant===\n\n");
   for(int i=0; i<=3; i++){
    for(int j=0; j<=7; j++){
        table[i][j]='O';
        printf("%c ", table[i][j]);
    }
    printf("\n");
   }

   printf("\nAvailable Tables-O\n");
   printf("Not Available Table-X\n");

   printf("\n===Enter Booking seat position===\n");
   printf("row:");
   scanf("%d", &row_number);
   printf("column:");
   scanf("%d", &column_number);

   if(row_number<=4 && column_number<=8){

   table[row_number-1][column_number-1]='X';

   printf("\n");

   for(int i=0; i<=3; i++){
    for(int j=0; j<=7; j++){
        printf("%c ",table[i][j]);
    }
    printf("\n");
   }

   printf("\nAvailable Tables-O\n");
   printf("Not Available Table-X\n");
   }else{
     printf("\nEnter Valid Row and Column number");
   }

}

