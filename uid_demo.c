#include <stdio.h>
#include <unistd.h> // Include the header for getuid() and geteuid()

int main() {
    printf("real uid: %d\n", getuid());    // Print real user ID
    printf("effective uid: %d\n", geteuid()); // Print effective user ID
    return 0;
}
