#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_leak()
{
    char *data = malloc(100);

    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(data, "Hello Embedded Linux Lab 3");

    printf("Data: %s\n", data);

free(data);
data = NULL;
}

int main()
{
    printf("=== Memory Leak Test ===\n");

    create_leak();

    printf("Program finished.\n");

    return 0;
}
