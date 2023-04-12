#include <stdio.h>
#include <string.h>

#define MAX_TAXPAYERS 100

struct taxpayer {
    char name[50];
    float income;
    float tax;
};