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