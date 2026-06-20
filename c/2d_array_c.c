#include <stdio.h>

int main() {
    int a,b,i,j;
    printf("Enter number of rows: ");
    scanf("%d",&a);
    printf("Enter number of columns: ");
    scanf("%d",&b);
    int array[a][b];
    int ary2[a][b]; 
    
    printf("Enter elements for first 2D array:\n");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("Enter element [%d][%d]: ",i,j);
            scanf("%d",&array[i][j]);
        }
        printf("\n");
    }

    printf("The 1st 2D array is:\n");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("%d ",array[i][j]);  
        }
        printf("\n");
    }

    printf("Enter elements for second 2D array:\n");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("Enter element [%d][%d]: ",i,j);
            scanf("%d",&ary2[i][j]);
        }
        printf("\n");
    }

    printf("The 2nd 2D array is:\n");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("%d ",ary2[i][j]);  
        }
        printf("\n");
    }

    for (i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("Sum of element [%d][%d]: %d\n",i,j,array[i][j]+ary2[i][j]);
        }
    }       

    printf("The sum of the two 2D arrays is:\n");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("%d ",array[i][j]+ary2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
    
