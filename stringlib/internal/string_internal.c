
#include "string_internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool _is_invalid(const String *str) {
    if (str == NULL) {
        printf("String(%p) is NULL\n", (void*)str);
        return true;
    }

    bool found_invalid_state = false;

    if (str->data == NULL) {
        printf("String(%p) data is NULL\n", (void*)str);
        found_invalid_state = true;
    }

    if (str->length < 0) {
        printf("String(%p) length is negative: %d\n", (void*)str, str->length);
        found_invalid_state = true;
    }

    if (str->capacity < 0) {
        printf("String(%p) capacity is negative: %d\n", (void*)str, str->capacity);
        found_invalid_state = true;
    }

    if (!found_invalid_state && str->length > str->capacity) {
        printf("String(%p) length(%d) > capacity(%d)\n", (void*)str, str->length, str->capacity);
        found_invalid_state = true;
    }

    if (str->data[str->length] != '\0') {
        printf("String(%p) does not end with '\\0' at %llu\n", (void*)str, str->length);
        found_invalid_state = true;
    }

    return found_invalid_state;
}

bool _set_string_capacity(String *str, size_t new_capacity) {
    if (_is_invalid(str)) return false;

    if (str->capacity >= new_capacity) {
        printf("String capacity(%llu) >= new_capacity(%llu)\n", str->capacity, new_capacity);
        return false;
    }

    char *new_data = realloc(str->data, new_capacity + 1);
    if (new_data == NULL) return false;
    str->data = new_data;
    str->capacity = new_capacity;
    return true;
}

void _append_char(String *str, char c) {
    if (_is_invalid(str)) return;

    if (str->length >= str->capacity) {
        _grow(str, 1);
        str->data[str->length] = c;
        str->data[str->length + 1] = NULL_CHAR;
        str->length++;
    }
}

void _append_chars(String *str, char const *text, size_t length) {
    if (_is_invalid(str)) return;

    memcpy(str->data + str->length, text, length);
    str->length += length;
    str->data[str->length] = NULL_CHAR;
}

void _grow(String *str, int amount) {
    if (_is_invalid(str)) return;

    _set_string_capacity(str, str->capacity + amount);
}

void _grow_append(String *str, const char *text, const int length) {
    if (_is_invalid(str)) return;

    if (str->length + length > str->capacity) {
        int new_capacity = _calc_new_capacity(str->capacity, length);
        if (!_set_string_capacity(str, new_capacity)) {
            printf("Appending of Chars failed!");
            return;
        }
    }

    _append_chars(str, text, length);
}

int _calc_new_capacity(size_t current_capacity, size_t new_space_needed) {
    int new_capacity = current_capacity + (current_capacity >> 1);
    if (new_capacity < new_space_needed + current_capacity) {
        new_capacity += new_space_needed;
    }
    return new_capacity;
}