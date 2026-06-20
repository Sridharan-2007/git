#include <stdio.h>
int main() {
    int num , rev = 0,dig;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    while (num >0){
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    printf("Number is: %d\n", rev);
    return 0;
}
    