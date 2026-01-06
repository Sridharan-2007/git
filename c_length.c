#include <stdio.h>

int main() {
    int array[]={1,2,3,4,5};
    int length=sizeof(array)/sizeof(array[0]);
    int ary[length];
    for (int i=0;i<length;i++){
        ary[i]=array[length-i-1];
        printf("%d\n",ary[i]);
    }


    return 0;
}