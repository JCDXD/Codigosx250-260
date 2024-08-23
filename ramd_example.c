#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Include time.h for the time() function

int main() {
    int i;
    printf("RAND_MAX is %d\n", RAND_MAX);  // Use %d for integers
    srand(time(NULL));  // Seed the random number generator with current time

    printf("Random values from 0 to RAND_MAX:\n");
    for (i = 0; i < 8; i++)
        printf("%d\n", rand());

    printf("Random values from 1 to 20:\n");
    for (i = 0; i < 8; i++)
        printf("%d\n", (rand() % 20) + 1);

    return 0;
}
