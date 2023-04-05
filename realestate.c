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