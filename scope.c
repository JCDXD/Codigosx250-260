#include <stdio.h>

int j = 42; // j is a global variable.

void func3() {
    int i = 11, j = 999; // Here, j is a local variable of func3().
    printf("\t\t\t[in func3] i @ %p = %d\n", (void *)&i, i);
    printf("\t\t\t[in func3] j @ %p = %d\n", (void *)&j, j);
}

void func2() {
    int i = 7;
    printf("\t\t[in func2] i @ %p = %d\n", (void *)&i, i);
    printf("\t\t[in func2] j @ %p = %d\n", (void *)&j, j);
    printf("\t\t[in func2] setting j = 1337\n");
    j = 1337; // Writing to the global j
    func3();
    printf("\t\t[back in func2] i @ %p = %d\n", (void *)&i, i);
    printf("\t\t[back in func2] j @ %p = %d\n", (void *)&j, j);
}

void func1() {
    int i = 5;
    printf("\t[in func1] i @ %p = %d\n", (void *)&i, i);
    printf("\t[in func1] j @ %p = %d\n", (void *)&j, j);
    func2();
    printf("\t[back in func1] i @ %p = %d\n", (void *)&i, i);
    printf("\t[back in func1] j @ %p = %d\n", (void *)&j, j);
}

int main() {
    int i = 3;
    printf("[in main] i @ %p = %d\n", (void *)&i, i);
    printf("[in main] j @ %p = %d\n", (void *)&j, j);
    func1();
    printf("[back in main] i @ %p = %d\n", (void *)&i, i);
    printf("[back in main] j @ %p = %d\n", (void *)&j, j);
    
    return 0; // Indicate successful completion
}

