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