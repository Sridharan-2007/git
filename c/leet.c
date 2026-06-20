#include <stdio.h>
#include <string.h>
union Result {
    float marks;
    char grade[2]; 
};
int main() {
    union Result o;
    int choice;
    printf("Enter the choice 1: marks or 2: grade: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter marks: ");
        scanf("%f", &o.marks);
        printf("marks is: %f\n", o.marks);
    } 
    if (choice == 2) {
        printf("Enter grade: ");
        scanf("%s", o.grade);
        printf("Grade is: %s\n", o.grade);
    } 
    else if (choice != 1 && choice != 2) {
        printf("Invalid input for choice\n");
    }
    return 0;
}
