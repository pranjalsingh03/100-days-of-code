// Randome number generator


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    srand(time(0)); // Seed the random number generator with current time
    num = rand(); // Generate a random number
    printf("%d", num);
    return 0;
}