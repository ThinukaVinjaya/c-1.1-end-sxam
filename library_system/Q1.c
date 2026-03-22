#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_NAME_LENGTH 100

// Global variables
char books[MAX_BOOKS][MAX_NAME_LENGTH];
int books_count = 0;

// Function declarations
void booksManagement();
void calculateBooksPrice();
void manageUserDetails();
char fineLevel(float fine);

// MAIN FUNCTION
int main() {
    int choice;

    while (1) {
        printf("\n===== Library Menu =====\n");
        printf("1. Add and View Books\n");
        printf("2. Calculate Total Books Price\n");
        printf("3. Input and Display Library Users Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                booksManagement();
                break;
            case 2:
                calculateBooksPrice();
                break;
            case 3:
                manageUserDetails();
                break;
            case 4:
                printf("Good Bye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// FUNCTION 1
void booksManagement() {
    printf("\nEnter number of books: ");
    scanf("%d", &books_count);
    getchar();

    for (int i = 0; i < books_count; i++) {
        printf("Enter name of book %d: ", i + 1);
        fgets(books[i], MAX_NAME_LENGTH, stdin);
        books[i][strcspn(books[i], "\n")] = 0; // remove newline
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < books_count; i++) {
        printf("%d. %s\n", i + 1, books[i]);
    }
}

//FUNCTION 2
void calculateBooksPrice() {
    if (books_count == 0) {
        printf("No books available. Add books first.\n");
        return;
    }

    float prices[books_count];
    float total = 0;

    for (int i = 0; i < books_count; i++) {
        printf("Enter price for \"%s\": ", books[i]);
        scanf("%f", &prices[i]);
        total += prices[i];
    }

    printf("\n--- Book Prices ---\n");
    for (int i = 0; i < books_count; i++) {
        printf("%s : Rs. %.2f\n", books[i], prices[i]);
    }

    printf("Total Price: Rs. %.2f\n", total);
}

//FUNCTION 3
struct Details {
    char name[50];
    char reg_no[20];
    float fine_balance;
    char fine_category;
};

void manageUserDetails() {
    struct Details users[5];

    for (int i = 0; i < 5; i++) {
        printf("\nEnter details for user %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", users[i].name);

        printf("Registration No: ");
        scanf(" %[^\n]", users[i].reg_no);

        printf("Fine Balance: ");
        scanf("%f", &users[i].fine_balance);

        users[i].fine_category = fineLevel(users[i].fine_balance);
    }

    printf("\n--- User Details ---\n");
    printf("Name\t\tReg No\t\tFine\tCategory\n");

    for (int i = 0; i < 5; i++) {
        printf("%s\t\t%s\t\t%.2f\t\t%c\n",
               users[i].name,
               users[i].reg_no,
               users[i].fine_balance,
               users[i].fine_category);
    }
}

//FUNCTION 4
char fineLevel(float fine) {
    if (fine >= 750) return 'E';
    else if (fine >= 500) return 'H';
    else if (fine >= 100) return 'M';
    else if (fine >= 10) return 'L';
    else return 'S';
}
