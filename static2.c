#include <stdio.h>

void function() { // An example function, with its own context
    int var = 5; // Local variable
    static int static_var = 5; // Static variable initialization

    printf("\t[in function] var @ %p = %d\n", (void *)&var, var);
    printf("\t[in function] static_var @ %p = %d\n", (void *)&static_var, static_var);

    var++; // Add 1 to var.
    static_var++; // Add 1 to static_var.
}

int main() { // The main function, with its own context
    int i;
    static int static_var = 1337; // Another static, in a different context

    for(i = 0; i < 5; i++) { // Loop 5 times
        printf("[in main] static_var @ %p = %d\n", (void *)&static_var, static_var);
        function(); // Call the function.
    }

    return 0; // Indicate successful completion
}

