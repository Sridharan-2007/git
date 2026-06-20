#include <stdio.h>

int main() {
    int customerID, units, billCount = 0;
    char customerType, choice;
    float rate, totalBill;

    printf("--- Electricity Bill Generator ---\n");

    do {
        
        printf("\nEnter Customer ID (Positive Integer): ");
        scanf("%d", &customerID);
        
        
        if (customerID <= 0) {
            printf("Invalid ID. Please enter a positive number.\n");
            continue; 
        }

       
        printf("Enter Customer Type (D for Domestic, C for Commercial): ");
        scanf(" %c", &customerType);

        
        printf("Enter Units Consumed: ");
        scanf("%d", &units);

       
        if (customerType == 'D' || customerType == 'd') {
            if (units <= 100) {
                rate = 3.00;
            } else if (units <= 200) {
                rate = 4.00;
            } else {
                rate = 5.00;
            }
            customerType = 'D'; 
        } 
        else if (customerType == 'C' || customerType == 'c') {
            rate = 7.00; 
            customerType = 'C'; 
        } 
        else {
            printf("Invalid Customer Type! Skipping this entry.\n");
            continue;
        }

        
        totalBill = (float)units * rate;
        billCount++;

        
        printf("\n--------------------------\n");
        printf("Bill #%d\n", billCount);
        printf("Customer ID   : %d\n", customerID);
        printf("Customer Type : %c\n", customerType);
        printf("Units Consumed: %d\n", units);
        printf("Rate per Unit : ₹%.2f\n", rate);
        printf("Total Amount  : ₹%.2f\n", totalBill);
        printf("--------------------------\n");

        
        printf("Process another customer? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    
    printf("\nProgram Terminated.");
    printf("\nTotal number of bills processed: %d\n", billCount);

    return 0;
}