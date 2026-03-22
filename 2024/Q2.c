#include <stdio.h>

// Function for cube
float cubeVolume(float length) {
    return length * length * length;
}

// Function for cylinder
float cylinderVolume(float radius, float height) {
    return 3.14 * radius * radius * height;
}

int main() {
    int choice;
    float length, radius, height;

    printf("1. Volume of Cube\n");
    printf("2. Volume of Cylinder\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter length: ");
        scanf("%f", &length);
        printf("Volume of cube = %.2f\n", cubeVolume(length));
    }
    else if(choice == 2) {
        printf("Enter radius: ");
        scanf("%f", &radius);
        printf("Enter height: ");
        scanf("%f", &height);
        printf("Volume of cylinder = %.2f\n", cylinderVolume(radius, height));
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
