#include <stdio.h>
#include <stdlib.h>

#include "../include/stringlib.h"
#include "../internal/string_internal.h"

const char* string_cstr(const String* str) {
    const char *cstr = str->data;
    return cstr;
}

size_t  string_length(const String* str) {
    return str->length;
}

void string_print(const String *str) {
    printf("%.*s\n", str->length, str->data);
}