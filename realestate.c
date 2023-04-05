#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for storing property details
struct property {
    char property_type[20];
    char property_location[50];
    int bhk;
    int area;
    float price;
};