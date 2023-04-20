#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for bank account details
typedef struct {
    char account_number[20];
    char account_name[50];
    float balance;
} BankAccount;

// Function prototypes
void display_menu();
void view_account_status(BankAccount *account);
void open_account(BankAccount *account);
void change_password(BankAccount *account);
void manage_payee(BankAccount *account);
void view_statement(BankAccount *account);

// Sample main function
int main() {
    // Create a bank account object
    BankAccount account;
    strcpy(account.account_number, "1234567890");
    strcpy(account.account_name, "John Doe");
    account.balance = 5000.0;

    // Display the main menu and get the user's choice
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_account_status(&account);
                break;
            case 2:
                open_account(&account);
                break;
            case 3:
                change_password(&account);
                break;
            case 4:
                manage_payee(&account);
                break;
            case 5:
                view_statement(&account);
                break;
            case 6:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}


void display_menu() {
    printf("\n-----------------------------\n");
    printf("Online Banking System\n");
    printf("-----------------------------\n");
    printf("1. View Account Status\n");
    printf("2. Open Account\n");
    printf("3. Change Password\n");
    printf("4. Manage Payee\n");
    printf("5. View Statement\n");
    printf("6. Exit\n");
}

// Define the view_account_status function
void view_account_status(BankAccount *account) {
    printf("\n-----------------------------\n");
    printf("Account Status\n");
    printf("-----------------------------\n");
    printf("Account Number: %s\n", account->account_number);
    printf("Account Name: %s\n", account->account_name);
    printf("Account Balance: $%.2f\n", account->balance);
}


void open_account(BankAccount *account) {
    printf("\n-----------------------------\n");
    printf("Open Account\n");
    printf("-----------------------------\n");

    // Get the account number from the user
    printf("Enter Account Number: ");
    scanf("%s", account->account_number);

    // Get the account name from the user
    printf("Enter Account Name: ");
    scanf("%s", account->account_name);

    // Set the initial balance to zero
    account->balance = 0.0;

    printf("Account Created Successfully!\n");
}