#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/stryx.h"
#include "../internal/_string_internal.h"

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

size_t string_find(const String* str, const char* substr) {
    size_t amount_of_substr_chars_found = 0;
    size_t substr_length = strlen(substr);

    for (size_t i = 0; i < str->capacity; i++) {
        if (str->data[i] == substr[amount_of_substr_chars_found]) {
            if (amount_of_substr_chars_found == substr_length) {
                return i - amount_of_substr_chars_found;
            }
            amount_of_substr_chars_found++;
        } else {
            amount_of_substr_chars_found = 0;
        }
    }
    //TODO: use custom response struct
}

bool string_equals(const String* a, const String* b) {
    if (_is_invalid(a) || _is_invalid(b)) return false;

    if (a->length != b->length) return false;

    if (a->length != b->length) return false;

    return memcmp(a->data, b->data, a->length) == 0;
}

size_t string_count_char(const String* str, char c) {
    if (_is_invalid(str)) return 0;

    if (str->length == 0) return 0;

    int char_counter = 0;

    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == c) char_counter++;
    }
    return char_counter;
}