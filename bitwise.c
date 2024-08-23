#include <stdio.h>

int main() {
    int i, bit_a, bit_b;

    // Display the bitwise OR operator
    printf("bitwise OR operator |\n");
    for (i = 0; i < 4; i++) {
        bit_a = (i & 2) / 2; // Get the second bit (binary: 10)
        bit_b = (i & 1);    // Get the first bit (binary: 01)
        printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
    }

    printf("\nbitwise AND operator &\n");
    for (i = 0; i < 4; i++) {
        bit_a = (i & 2) / 2; // Get the second bit (binary: 10)
        bit_b = (i & 1);    // Get the first bit (binary: 01)
        printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
    }

    return 0;
}
