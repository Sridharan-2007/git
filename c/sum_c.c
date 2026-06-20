//swapping two variables using pointers without using third variable
#include <stdio.h>
void swap(int *a, int *b) {
    *a = *a + *b; // Step 1: a now holds the sum of a and b
    *b = *a - *b; // Step 2: b now holds the original value of a
    *a = *a - *b; // Step 3: a now holds the original value of b
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    swap(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}