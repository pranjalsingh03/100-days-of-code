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
    struct Package package;
    FILE *fp;    //Give the file path to save the data input from the user

    printf("\nEnter package ID: ");
    scanf("%s", package.id);
    printf("Enter sender name: ");
    scanf(" %[^\n]", package.sender);
    printf("Enter receiver name: ");
    scanf(" %[^\n]", package.receiver);
    printf("Enter delivery address: ");
    scanf(" %[^\n]", package.address);
    printf("Enter package weight: ");
    scanf("%f", &package.weight);
    strcpy(package.status, "In Transit");

    fp = fopen("packages.dat", "ab");
    if(fp == NULL) {
        printf("Error opening file!");
        return;
    }

    fwrite(&package, sizeof(package), 1, fp);

    printf("\nPackage added successfully!\n");

    fclose(fp);
}


void search_package() {
    //Code to search for a package by ID, sender, or receiver
    char id[10], name[50];
    int option, found = 0;
    struct Package package;
    FILE *fp;

    printf("\nSearch Package\n");
    printf("1. Search by ID\n");
    printf("2. Search by Sender Name\n");
    printf("3. Search by Receiver Name\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nEnter package ID: ");
            scanf("%s", id);
            break;
        case 2:
            printf("\nEnter sender name: ");
            scanf(" %[^\n]", name);
            break;
        case 3:
            printf("\nEnter receiver name: ");
            scanf(" %[^\n]", name);
            break;
        default:
            printf("\nInvalid choice!\n");
            return;
    }

    fp = fopen("packages.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!");
        return;
    }

    while(fread(&package, sizeof(package), 1, fp)) {
        switch(option) {
            case 1:
                if(strcmp(package.id, id) == 0) {
                    found = 1;
                }
                break;
            case 2:
                if(strcmp(package.sender, name) == 0) {
                    found = 1;
                }
                break;
            case 3:
                if(strcmp(package.receiver, name) == 0) {
                    found = 1;
                }
                break;
        }

        if(found) {
            printf("\nPackage Found\n");
            printf("Package ID: %s\n", package.id);
            printf("Sender Name: %s\n", package.sender);
            printf("Receiver Name: %s\n", package.receiver);
            printf("Delivery Address: %s\n", package.address);
            printf("Package Weight: %.2f kg\n", package.weight);
            printf("Package Status: %s\n", package.status);
            break;
        }
    }

    if(!found) {
        printf("\nPackage Not Found\n");
    }

    fclose(fp);
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