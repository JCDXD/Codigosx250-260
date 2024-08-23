#include <stdio.h>
#include <fcntl.h>

void display_flags(const char *, unsigned int);
void binary_print(unsigned int);

int main(int argc, char *argv[]) {
    display_flags("O_RDONLY\t\t", O_RDONLY);
    display_flags("O_WRONLY\t\t", O_WRONLY);
    display_flags("O_RDWR\t\t\t", O_RDWR);
    printf("\n");
    display_flags("O_APPEND\t\t", O_APPEND);
    display_flags("O_TRUNC\t\t\t", O_TRUNC);
    display_flags("O_CREAT\t\t\t", O_CREAT);
    printf("\n");
    display_flags("O_WRONLY|O_APPEND|O_CREAT", O_WRONLY | O_APPEND | O_CREAT);
}

void display_flags(const char *label, unsigned int value) {
    printf("%s\t: %u\t:", label, value);
    binary_print(value);
    printf("\n");
}

void binary_print(unsigned int value) {
    unsigned int mask = 0x80000000; // Mask for the highest bit.
    for (int i = 0; i < 32; i++) {  // Print all 32 bits.
        if (value & mask) // Check if the bit is set.
            printf("1");
        else
            printf("0");
        mask >>= 1; // Shift mask right by 1 bit.
        if (i % 8 == 7) // Add a space every 8 bits for readability.
            printf(" ");
    }
}
