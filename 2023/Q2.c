#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int length, i;
    int isPalindrome = 1; // 1 represents True, 0 represents False

    printf("Enter a word (English letters only): ");
    scanf("%s", word);

    // a. Count and display the number of letters
    length = strlen(word);
    printf("\na. Number of letters: %d\n", length);

    // b. Display all the vowels present in that word
    printf("b. Vowels in the word: ");
    int vowelFound = 0;
    for (i = 0; i < length; i++) {
        char c = word[i];
        // Checking both uppercase and lowercase manually
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            printf("%c ", word[i]);
            vowelFound = 1;
        }
    }
    if (!vowelFound) printf("None");
    printf("\n");

    // c. Check if the given string is a Palindrome
    // Logic: Compare the character at index i with the character at (length - 1 - i)
    for (i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            isPalindrome = 0; // It's not a palindrome
            break;
        }
    }

    if (isPalindrome) {
        printf("c. The word is a Palindrome.\n");
    } else {
        printf("c. The word is NOT a Palindrome.\n");
    }

    // d. Store only the palindrome words into a text file
    if (isPalindrome) {
        FILE *fptr = fopen("palindromes.txt", "a");
        if (fptr != NULL) {
            fprintf(fptr, "%s\n", word);
            fclose(fptr);
            printf("d. Palindrome word stored in 'palindromes.txt'.\n");
        } else {
            printf("d. Error: Could not open file.\n");
        }
    } else {
        printf("d. Word was not a palindrome, skipped file storage.\n");
    }

    return 0;
}
