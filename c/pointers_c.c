#include <stdio.h>
int main (){
    int a =5;
    int *p=&a;
    printf("Value of a: %d\n",a);
    printf("Address of a: %p\n",&a);
    printf("Value of p (Address of a): %p\n",p);
}