#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for storing property details
struct property
{
    char property_type[20];
    char property_location[50];
    int bhk;
    int area;
    float price;
};

// function to add new property record

void add_record(struct property *prop, int *count)
{
    printf("\nEnter Property Details:\n");
    printf("Property Type: ");
    scanf("%s", prop[*count].property_type);
    printf("Property Location: ");
    scanf(" %[^\n]", prop[*count].property_location);
    printf("BHK: ");
    scanf("%d", &prop[*count].bhk);
    printf("Area (in sq.ft): ");
    scanf("%d", &prop[*count].area);
    printf("Price (in lakhs): ");
    scanf("%f", &prop[*count].price);
    (*count)++;
    printf("\nRecord added successfully!\n");
}

// function to display all available properties
void display_properties(struct property *prop, int count) {
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

// function to search properties based on user inputs
void search_properties(struct property *prop, int count) {
    char location[50];
    int bhk, min_area;
    float max_price;
    printf("\nEnter search criteria:\n");
    printf("Location: ");
    scanf(" %[^\n]", location);
    printf("BHK: ");
    scanf("%d", &bhk);
    printf("Minimum Area (in sq.ft): ");
    scanf("%d", &min_area);
    printf("Maximum Price (in lakhs): ");
    scanf("%f", &max_price);
    printf("\nSearch Results:\n");
    printf("----------------------------------------------------------------------\n");
    printf("Property Type\tLocation\t\tBHK\tArea (sq.ft)\tPrice (in lakhs)\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        if(strcmp(prop[i].property_location, location) == 0 && prop[i].bhk == bhk && prop[i].area >= min_area && prop[i].price <= max_price) {
            printf("%s\t\t%s\t\t%d\t%d\t\t%.2f\n", prop[i].property_type, prop[i].property_location, prop[i].bhk, prop[i].area, prop[i].price);
        }
    }
}

// function to buy or sell property
void buy_or_sell(struct property *prop, int count) {
    int choice, index;
    char location[50];
    float price;
    printf("\nEnter your choice:\n");
    printf("1. Buy Property\n");
    printf("2. Sell Property\n");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("\nEnter property details to buy:\n");
        printf("Location: ");
        scanf(" %[^\n]", location);
        printf("Price (in lakhs): ");
        scanf("%f", &price);
        for(int i=0; i<count; i++) {
            if(strcmp(prop[i].property_location, location) == 0 && prop[i].price == price) {
                printf("\nCongratulations! You have bought the following property:\n");
                printf("%s\t\t%s\t\t%d\t%d\t\t%.2f\n", prop[i].property_type, prop[i].property_location, prop[i].bhk, prop[i].area, prop[i].price);
                return;
            }
        }
        printf("\nSorry, property not found.\n");
    } else if(choice == 2) {
        printf("\nEnter property details to sell:\n");
        printf("Location: ");
        scanf(" %[^\n]", location);
        printf("Price (in lakhs): ");
        scanf("%f", &price);
        for(int i=0; i<count; i++) {
            if(strcmp(prop[i].property_location, location) == 0 && prop[i].price == price) {
                printf("\nCongratulations! You have sold the following property:\n");
                printf("%s\t\t%s\t\t%d\t%d\t\t%.2f\n", prop[i].property_type, prop[i].property_location, prop[i].bhk, prop[i].area, prop[i].price);
                // delete record
                for(int j=i; j<count-1; j++) {
                    prop[j] = prop[j+1];
                }
                (*count)--;
                return;
            }
        }
        printf("\nSorry, property not found.\n");
    } else {
        printf("\nInvalid choice.\n");
    }
}