#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *char_ptr; // A char pointer
    int *int_ptr;   // An integer pointer
    int mem_size;

    if (argc < 2) // If there aren't command-line arguments,
        mem_size = 50; // use 50 as the default value.
    else
        mem_size = atoi(argv[1]);

    printf("\t[+] allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) malloc(mem_size); // Allocating heap memory
    if (char_ptr == NULL) { // Error checking, in case malloc() fails
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(char_ptr, "This memory is located on the heap.");
    printf("char_ptr (%p) --> '%s'\n", (void *)char_ptr, char_ptr);

    printf("\t[+] allocating %zu bytes of memory on the heap for int_ptr\n", sizeof(int));
    int_ptr = (int *) malloc(sizeof(int)); // Allocating heap memory for int
    if (int_ptr == NULL) { // Error checking, in case malloc() fails
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        free(char_ptr); // Free previously allocated memory before exiting
        exit(EXIT_FAILURE);
    }
    *int_ptr = 31337; // Put the value of 31337 where int_ptr is pointing.
    printf("int_ptr (%p) --> %d\n", (void *)int_ptr, *int_ptr);

    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(char_ptr); // Freeing heap memory

    printf("\t[+] allocating another 15 bytes for char_ptr\n");
    char_ptr = (char *) malloc(15); // Allocating more heap memory
    if (char_ptr == NULL) { // Error checking, in case malloc() fails
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        free(int_ptr); // Free previously allocated memory before exiting
        exit(EXIT_FAILURE);
    }
    strcpy(char_ptr, "new memory");
    printf("char_ptr (%p) --> '%s'\n", (void *)char_ptr, char_ptr);

    printf("\t[-] freeing int_ptr's heap memory...\n");
    free(int_ptr); // Freeing heap memory

    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(char_ptr); // Freeing the other block of heap memory

    return 0;
}
