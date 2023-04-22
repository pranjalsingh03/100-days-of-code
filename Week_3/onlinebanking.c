#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for bank account details

#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_ACCOUNT_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 10
#define MAX_PAYEE 10
#define MAX_ACCOUNTS 100 
#define MAX_NAME_LENGTH 50

typedef struct {
    char date[20]; // or any other desired length
    char type[MAX_TRANSACTION_TYPE_LENGTH + 1]; // add 1 for null terminator
    float amount;
    float balance;
} Transaction;
typedef struct {
    // char account_number[20];
    // char account_name[50];
    float balance;
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH + 1];
    char account_name[MAX_ACCOUNT_NAME_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    // char payee[MAX_PAYEE][MAX_NAME_LENGTH + 1];
    int num_payee;
    Transaction transactions[100];
    int num_transactions;
    int transactions;
    
} BankAccount;

// Function prototypes
void display_menu();
void view_account_status(BankAccount *account);
void open_account(BankAccount *account);
void change_password(BankAccount *account);
void manage_payee(BankAccount *account);
void view_statement(BankAccount *account);
void add_payee(BankAccount *account)

// Sample main function
int main() {
    // Create a bank account object
    // BankAccount accounts[MAX_ACCOUNTS]; // declare an array of BankAccount objects
    // int num_accounts = 0;
    BankAccount account;
    // strcpy(account.account_number, "1234567890");
    // strcpy(account.account_name, "John Doe");
    // account.balance = 5000.0;

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

void change_password(BankAccount *account) {
    printf("\n-----------------------------\n");
    printf("Change Password\n");
    printf("-----------------------------\n");

    // Get the old password from the user
    printf("Enter Old Password: ");
    char old_password[MAX_PASSWORD_LENGTH];
    scanf("%s", old_password);

    // Compare the old password with the stored password
    if (strcmp(old_password, account->password) != 0) {
        printf("Incorrect Password. Please try again.\n");
        return;
    }

    // Get the new password from the user
    printf("Enter New Password: ");
    char new_password[MAX_PASSWORD_LENGTH];
    scanf("%s", new_password);

    // Store the new password in the account object
    strcpy(account->password, new_password);

    printf("Password Changed Successfully!\n");
}

void add_payee(BankAccount *account) {
    printf("Enter the payee name: ");
    char payee_name[100]; // or any other desired maximum length
    scanf("%s", payee_name);
    
    printf("Enter the payee account number: ");
    char payee_account_number[MAX_ACCOUNT_NUMBER_LENGTH + 1]; // add 1 for null terminator
    scanf("%s", payee_account_number);
    
    Payee new_payee = {payee_name, payee_account_number};
    
    account->payees[account->num_payees] = new_payee;
    account->num_payees++;
    
    printf("Payee added successfully.\n");
}

void manage_payee(BankAccount *account) {
    printf("\n-----------------------------\n");
    printf("Manage Payees\n");
    printf("-----------------------------\n");

    // Prompt the user to add or remove a payee
    printf("Do you want to add or remove a payee?\n");
    printf("Enter '1' to add a payee or '2' to remove a payee: ");
    int choice;
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
        case 1:
            // Add a new payee
            printf("Enter Payee Name: ");
            char payee_name[MAX_NAME_LENGTH];
            scanf("%s", payee_name);
            printf("Enter Payee Account Number: ");
            char payee_account_number[MAX_ACCOUNT_NUMBER_LENGTH];
            scanf("%s", payee_account_number);
            add_payee(account, payee_name, payee_account_number);
            break;
        case 2:
            // Remove an existing payee
            printf("Enter Payee Name: ");
            char payee_name_to_remove[MAX_NAME_LENGTH];
            scanf("%s", payee_name_to_remove);
            remove_payee(account, payee_name_to_remove);
            break;
        default:
            printf("Invalid Choice. Please try again.\n");
            break;
    }
}


void view_statement(BankAccount *account) {
    printf("\n-----------------------------\n");
    printf("View Statement\n");
    printf("-----------------------------\n");

    // Print the account details
    printf("Account Number: %s\n", account->account_number);
    printf("Account Name: %s\n", account->account_name);
    printf("Current Balance: %.2f\n", account->balance);

    // Print the transaction history
    printf("Transaction History:\n");
    printf("Date\t\tType\tAmount\tBalance\n");
    for (int i = 0; i < account->num_transactions; i++) {
        printf("%s\t%s\t%.2f\t%.2f\n", account->transactions[i].date, account->transactions[i].type,
               account->transactions[i].amount, account->transactions[i].balance);
    }
}