#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_record();
void display_Property();
void search_record();
void buySell();
void edit_record();
void delete_record();


// structure for storing property details
struct property
{
    char property_type[20];
    char property_location[50];
    int bhk;
    int area;
    float price;
};

// main function
int main() {
    int choice, count=0;
    struct property prop[100];
    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Add New Property Record\n");
        printf("2. Display Available Properties\n");
        printf("3. Search Properties\n");
        // printf("4 
         printf("5. Buy/Sell Property\n");
        printf("6. Edit Property Record\n");
        printf("7. Delete Property Record\n");
        printf("8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record(prop, &count);
                break;
            case 2:
                display_Property(prop, count);
                break;
            case 3:
                search_record(prop, count);
                break;
            case 4:
                buySell(prop, &count);
                break;
            // case 5:
            //     buy_sell_record(prop, &count);
            //     break;
            case 6:
                edit_record(prop, count);
                break;
            case 7:
                delete_record(prop, &count);
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}
// function to add new property record

// Function to add a new record
void add_record(struct property prop[], int *count) {
    printf("\nEnter property details:\n");
    printf("Property Type: ");
    scanf("%s", prop[*count].property_type);
    printf("Property Location: ");
    scanf("%s", prop[*count].property_location);
    printf("BHK: ");
    scanf("%d", &prop[*count].bhk);
    printf("Area (in sq. ft.): ");
    scanf("%d", &prop[*count].area);
    printf("Price (in lakhs): ");
    scanf("%f", &prop[*count].price);
    (*count)++;
    printf("\nRecord added successfully.\n");
}

// function to display all available properties
void display_Property(struct property *prop, int count) {
    if(count == 0) {
        printf("\nNo properties available.\n");
        return;
    }
    printf("\nAvailable Properties:\n");
    printf("----------------------------------------------------------------------\n");
    printf("Property Type\tLocation\t\tBHK\tArea (sq.ft)\tPrice (in lakhs)\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%s\t\t%s\t\t%d\t%d\t\t%.2f\n", prop[i].property_type, prop[i].property_location, prop[i].bhk, prop[i].area, prop[i].price);
    }
}


void buySell(struct property prop[], int *count) {
    int choice, id;
    printf("\nEnter 1 to buy a property or 2 to sell a property: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nAvailable Properties:\n");
            display_Property(prop, count);

            printf("\nEnter Property ID to buy: ");
            scanf("%d", &id);
            if (id <= 0 || id > *count) {
                printf("\nInvalid Property ID.\n");
                return;
            }

            printf("\nYou have selected the following property:\n");
            printf("------------------------------------------------------------\n");
            printf("| %-15s | %-20s | %-3s | %-7s | %-8s |\n", "Property Type", "Property Location", "BHK", "Area", "Price");
            printf("------------------------------------------------------------\n");
            printf("| %-15s | %-20s | %-3d | %-7d | %-8.2f |\n", prop[id-1].property_type, prop[id-1].property_location, prop[id-1].bhk, prop[id-1].area, prop[id-1].price);
            printf("------------------------------------------------------------\n");

            printf("\nEnter your details:\n");
            char name[50], contact[20];
            printf("Name: ");
            scanf("%s", name);
            printf("Contact Number: ");
            scanf("%s", contact);

            printf("\nCongratulations %s, you have successfully bought the property!\n", name);

            // Delete the property from the database
            for (int i = id-1; i < *count-1; i++) {
                prop[i] = prop[i+1];
            }
            (*count)--;
            break;
        case 2:
            printf("\nEnter details of the property to sell:\n");
            printf("Property Type: ");
            scanf("%s", prop[*count].property_type);
            printf("Property Location: ");
            scanf("%s", prop[*count].property_location);
            printf("BHK: ");
            scanf("%d", &prop[*count].bhk);
            printf("Area (in sq. ft.): ");
            scanf("%d", &prop[*count].area);
            printf("Price: ");
            scanf("%f", &prop[*count].price);

            printf("\nYour property has been added to the database with the following details:\n");
            printf("------------------------------------------------------------\n");
            printf("| %-15s | %-20s | %-3s | %-7s | %-8s |\n", "Property Type", "Property Location", "BHK", "Area", "Price");
            printf("------------------------------------------------------------\n");
            printf("| %-15s | %-20s | %-3d | %-7d | %-8.2f |\n", prop[*count].property_type, prop[*count].property_location, prop[*count].bhk, prop[*count].area, prop[*count].price);
            printf("------------------------------------------------------------\n");
            (*count)++;
            break;
        default:
            printf("\nInvalid Choice!\n");
    }
}


// function to edit property details
void edit_record(struct property *prop, int count) {
    int index;
    printf("\nEnter index of property to edit: ");
    scanf("%d", &index);
    if(index >= 0 && index < count) {
        printf("\nEnter new property details:\n");
        printf("Property Type: ");
        scanf("%s", prop[index].property_type);
        printf("Property Location: ");
        scanf(" %[^\n]", prop[index].property_location);
        printf("BHK: ");
        scanf("%d", &prop[index].bhk);
        printf("Area (in sq.ft): ");
        scanf("%d", &prop[index].area);
        printf("Price (in lakhs): ");
        scanf("%f", &prop[index].price);
        printf("\nRecord updated successfully!\n");
    } else {
        printf("\nInvalid index.\n");
    }
}

// function to delete property record
void delete_record(struct property *prop, int *count) {
    int index;
    printf("\nEnter index of property to delete: ");
    scanf("%d", &index);
    if(index >= 0 && index < *count) {
        for(int i=index; i<*count-1; i++) {
            prop[i] = prop[i+1];
        }
        (*count)--;
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nInvalid index.\n");
    }
}