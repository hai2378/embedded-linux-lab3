#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FIX 1: Array out-of-bounds */
void process_data(int *data, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += data[i];
    }

    printf("Sum = %d\n", sum);
}

/* FIX 2: Use after free */
char *create_message(const char *text)
{
    char *buf = malloc(strlen(text) + 1);

    if (buf == NULL) {
        return NULL;
    }

    strcpy(buf, text);

    return buf;
}

/* FIX 3: Integer overflow */
long long calculate(int a, int b)
{
    long long result = (long long)a * b;

    printf("calculate(%d, %d) = %lld\n",
           a, b, result);

    return result;
}

int main(void)
{
    printf("=== Fixed App - LAB 03 ===\n");

    /* Test 1 */
    int arr[5] = {10, 20, 30, 40, 50};

    printf("[TEST1] Processing array\n");
    process_data(arr, 5);

    /* Test 2 */
    printf("[TEST2] Creating message\n");

    char *msg = create_message("Hello Embedded Linux");

    if (msg != NULL) {
        printf("Message: %s\n", msg);
        free(msg);
    }

    /* Test 3 */
    printf("[TEST3] Integer calculation\n");

    calculate(100000, 100000);

    printf("Done.\n");

    return 0;
}
