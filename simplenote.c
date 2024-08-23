#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h> // For close()

void usage(const char *prog_name, const char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(EXIT_SUCCESS);
}

void fatal(const char *message); // A function for fatal errors
void *ec_malloc(size_t size);     // An error-checked malloc() wrapper

int main(int argc, char *argv[]) {
    int fd; // file descriptor
    char *buffer, *datafile;
    size_t buffer_size = 100;

    // Allocate memory
    buffer = (char *) ec_malloc(buffer_size);
    datafile = (char *) ec_malloc(20);

    // Set file path
    strncpy(datafile, "/tmp/notes", 19);
    datafile[19] = '\0'; // Ensure null-termination

    if (argc < 2) {
        usage(argv[0], datafile); // display usage message and exit.
    }

    // Copy command-line argument into buffer
    strncpy(buffer, argv[1], buffer_size - 1);
    buffer[buffer_size - 1] = '\0'; // Ensure null-termination

    printf("[DEBUG] buffer @ %p: '%s'\n", (void *)buffer, buffer);
    printf("[DEBUG] datafile @ %p: '%s'\n", (void *)datafile, datafile);

    // Ensure there's enough space before appending
    size_t current_length = strlen(buffer);
    if (current_length < buffer_size - 1) {
        strncat(buffer, "\n", buffer_size - current_length - 1);
    } else {
        fprintf(stderr, "Error: not enough space to append newline.\n");
        free(buffer);
        free(datafile);
        exit(EXIT_FAILURE);
    }

    // Open file
    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        fatal("in main() while opening file");
    }

    printf("[DEBUG] file descriptor is %d\n", fd);

    // Write data
    if (write(fd, buffer, strlen(buffer)) == -1) {
        fatal("in main() while writing buffer to file");
    }

    // Close file
    if (close(fd) == -1) {
        fatal("in main() while closing file");
    }

    printf("Note has been saved.\n");

    // Free allocated memory
    free(buffer);
    free(datafile);

    return EXIT_SUCCESS;
}

// A function to display an error message and then exit
void fatal(const char *message) {
    char error_message[100] = "[!!] Fatal Error: ";
    strncat(error_message, message, sizeof(error_message) - strlen(error_message) - 1);
    perror(error_message);
    exit(EXIT_FAILURE);
}

// An error-checked malloc() wrapper function
void *ec_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fatal("in ec_malloc() on memory allocation");
    }
    return ptr;
}
