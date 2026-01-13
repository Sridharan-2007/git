#include<stdio.h>
int main() {
    int a;
    printf("Enter no of elements in array: ");
    scanf("%d", &a);
    int arr[a];
    
    for (int i = 0; i < a; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, k;


    for (i = 0; i < n-1; i++) {
        for (j = 0; j<n-i-1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}