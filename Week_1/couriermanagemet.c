//Courier management system using c language.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Data Structures
struct Package {
    char id[10];
    char sender[50];
    char receiver[50];
    char address[100];
    char status[20];
    float weight;
};

void add_package();
void search_package();
void update_package();
void delete_package();
void display_packages();

//Main Function
int main() {
    int choice;
    while(1) {
        printf("\nCourier Management System\n");
        printf("1. Add Package\n");
        printf("2. Search Package\n");
        printf("3. Update Package\n");
        printf("4. Delete Package\n");
        printf("5. Display All Packages\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_package();
                break;
            case 2:
                search_package();
                break;
            case 3:
                update_package();
                break;
            case 4:
                delete_package();
                break;
            case 5:
                display_packages();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

//Function Definitions

void add_package() {
    //Code to add a new package
}

void search_package() {
    //Code to search for a package by ID, sender, or receiver
}

void update_package() {
    //Code to update the status of a package
}

void delete_package() {
    //Code to delete a package
}

void display_packages() {
    //Code to display all packages in the system
}