#include <stdio.h>
int main() {
    int a,b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    a>b ? printf("a is greater") : printf("b is greater");
  return 0;
}
    