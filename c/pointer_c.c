#include <stdio.h>
void reverse(int *ptr, int n){
    int temp;
    for(int i = 0; i < n/2; i++){
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + n - i - 1);
        *(ptr + n - i - 1) = temp;
    }
}
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    reverse(arr, n);
    printf("Reversed array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}