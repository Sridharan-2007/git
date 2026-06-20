#include <stdio.h>
int main(){
    int a,i,d=1;
    int b=1,c=0;
    printf("Enter upto number of terms :");
    scanf("%d",&a);
    printf("%d",0);
    for (i=0;i<a;i++){
        printf("%d",d);
        d=b+c;
        c=b;
        b=d;

    }
}