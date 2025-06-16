#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "string.h"
#include "stryx/include/stryx.h"

int main() {
    printf("=== String Double-Free Demonstration ===\n");

    String* a = string_create("Hello, world!");
    printf("\nCreated string 'a':\n");
    string_print(a);

    String* b = a;  // Shallow copy
    printf("\nPointer b = a (shallow copy):\n");
    string_print(b);

    printf("\nCalling string_clear(&a)...\n");
    string_clear(&a);  // Frees the memory a and b both pointed to

    printf("\nNow calling string_destroy(b)...\n");
    string_destroy(b);  // ❌ Double free here

    printf("\nDone.\n");
    return 0;
}
