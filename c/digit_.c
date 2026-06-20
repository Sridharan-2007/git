#include<stdio.h>
int main(){
    int k=0,a,dig,rem,i,sum=0;
    printf("Enter a number: ");
    scanf("%d",&a);
    dig=a;
    while(dig!=0){
        rem=dig%10;
        k++;
        dig=dig/10;
        if (k%2!=0){
            continue;
        }
        else{
            sum=sum+rem;
        }
        
    }
    printf("Sum of digits: %d\n",sum);
    return 0;
}