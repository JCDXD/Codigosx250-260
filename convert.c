#include <stdio.h>
#include <stdlib.h> // For exit() and atoi()

void usage(char *program_name) {
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    int i, count;

    // Check if the number of arguments is correct
    if (argc < 3) {
        usage(argv[0]); // Display usage message and exit
    }

    // Convert the second argument to an integer
    count = atoi(argv[2]);
    
    // Basic validation for count
    if (count <= 0) {
        printf("Error: The number of times to repeat must be a positive integer.\n");
        usage(argv[0]); // Display usage message and exit
    }

    printf("Repeating %d times..\n", count);
    for (i = 0; i < count; i++) {
        printf("%3d - %s\n", i, argv[1]); // Print the first argument
    }

    return 0; // Indicate successful completion
}

