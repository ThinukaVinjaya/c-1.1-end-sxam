#include<stdio.h>
#include<stdlib.h>

struct fruit {
    char fname[20];
    float fprice;
    int quntity;
}f[4];

void unitPrices();
void totalBill();


int main(){

   int choice;

   while(1){
    printf("\nPress1: Display the unit Prices\n");
    printf("Press2: Calculate the total bill\n");
    printf("Press3: Exit the programe\n\n");
    printf("Select an option:");
    scanf("%d", &choice);

    switch(choice){
        case 1:
          unitPrices();
          break;
        case 2:
            totalBill();
            break;
        case 3:
            printf("Good Bye!");
            exit(0);
            break;
        default:
            printf("Invalid Option");
    }
   }

}

void unitPrices(){

  FILE *fp;
  fp = fopen("fruit.txt","r");

  for(int i=1; i<=4; i++){
    fscanf(fp,"%s", &f[i].fname);
    fscanf(fp,"%f",&f[i].fprice);
  }

  fclose(fp);

  printf("\n--------------------- Unit Prices --------------------------\n\n");
  for(int i=1; i<=4; i++){
    printf("%s\t",f[i].fname);
    printf("%.2f\t\n",f[i].fprice);
  }

}

void totalBill(){

   float total;

   FILE *fp;
  fp = fopen("fruit.txt","r");

  for(int i=1; i<=4; i++){
    fscanf(fp,"%s", &f[i].fname);
    fscanf(fp,"%f",&f[i].fprice);
  }

  fclose(fp);

   for(int i=1; i<=4; i++){
    printf("Enter the quantity of %s:", f[i].fname);
    scanf("%d", &f[i].quntity);
    total += f[i].fprice * f[i].quntity;
   }

   printf("\n\nThe total is:%.2f\n", total);

   FILE * bill;
   bill = fopen("Bill.txt","w");

   fprintf(bill,"------------------------ ABC Shop  - Final Bill --------------------\n\n");
   fprintf(bill,"Item\t\tUnit Price\tQuantity\tTotal\n\n");

   for(int i=1; i<=4; i++){
    fprintf(bill,"%s\t\t%.2f\t\t%d\t\t%.2f\n",f[i].fname, f[i].fprice, f[i].quntity, f[i].fprice * f[i].quntity);
   }

   fprintf(bill,"\n\nThe total is:\t\t\t\t\t%.2f\n", total);
   fclose(bill);

   printf("Bill.txt file saved Successfully\n\n");

}
