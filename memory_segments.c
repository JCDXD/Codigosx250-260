#include <stdio.h>
#include <stdlib.h> // Include this header for malloc and free

int global_var;
int global_initialized_var = 5;

void function() {
    int stack_var; // This variable has the same name as the one in main()
    printf("the function's stack_var is at address 0x%016lx\n", (unsigned long)&stack_var);
}

int main() {
    int stack_var; // Same name as the variable in function()
    static int static_initialized_var = 5;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *) malloc(4); // Allocate memory
    if (heap_var_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Print addresses
    printf("global_initialized_var is at address 0x%016lx\n", (unsigned long)&global_initialized_var);
    printf("static_initialized_var is at address 0x%016lx\n\n", (unsigned long)&static_initialized_var);
    printf("static_var is at address 0x%016lx\n", (unsigned long)&static_var);
    printf("global_var is at address 0x%016lx\n\n", (unsigned long)&global_var);
    printf("heap_var is at address 0x%016lx\n\n", (unsigned long)heap_var_ptr);
    printf("stack_var is at address 0x%016lx\n", (unsigned long)&stack_var);

    function();

    free(heap_var_ptr); // Free allocated memory

    return 0;
}
