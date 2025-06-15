#include <stdlib.h>
#include <string.h>

#include "../include/stryx.h"
#include "../internal/_string_internal.h"

String* string_substring(const String* str, size_t start, size_t len) {
    if (_is_invalid(str)) return NULL;

    if (start >= str->length) return NULL;

    if (start + len > str->length) return NULL;

    char* substr_data = malloc(len);
    memcpy(substr_data, str->data + start, len);
    String* substr = string_create(substr_data);
    return substr;
}