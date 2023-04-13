#include <stdio.h>
#include <string.h>

#define MAX_TAXPAYERS 100

struct taxpayer {
    char name[50];
    float income;
    float tax;
};

struct taxpayer taxPayers[MAX_TAXPAYERS];
int numTaxPayers = 0;

void addRecord() {
    struct taxpayer tp;
    printf("\nEnter taxpayer name: ");
    scanf("%s", tp.name);
    printf("Enter taxpayer income: ");
    scanf("%f", &tp.income);
    if (tp.income <= 250000) {
        tp.tax = 0;
    } else if (tp.income > 250000 && tp.income <= 500000) {
        tp.tax = (tp.income - 250000) * 0.05;
    } else if (tp.income > 500000 && tp.income <= 1000000) {
        tp.tax = 12500 + (tp.income - 500000) * 0.2;
    } else {
        tp.tax = 112500 + (tp.income - 1000000) * 0.3;
    }
    taxPayers[numTaxPayers++] = tp;
    printf("Record added successfully.\n");

    
}void listRecords() {
    if (numTaxPayers == 0) {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nTax Payer Records:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-20s %-20s\n", "Name", "Income", "Income Tax");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numTaxPayers; i++) {
        struct taxpayer tp = taxPayers[i];
        printf("%-20s %-20.2f %-20.2f\n", tp.name, tp.income, tp.tax);
    }
}