#include <stdlib.h>
#include <string.h>

#include "../include/stryx.h"
#include "../internal/_string_internal.h"

bool string_append(String* str, const char* text) {
    if (_is_invalid(str)) return false;

    _append_chars(str, text, strlen(text));
    return true;
}

bool string_append_char(String* str, char c) {
    if (_is_invalid(str)) return false;

    _append_char(str, c);
    return true;
}

void string_clear(String** str) {
    if (str != NULL && *str != NULL) {
        string_destroy(*str);
        *str = string_create_empty();
    }
}

bool string_insert(String* str, size_t pos, const char* text) {
    if (_is_invalid(str)) return false;
    if (text == NULL) return false;

    if (pos > str->length) return false;

    if (pos == str->length) {
        return string_append(str, text);
    }

    size_t len = strlen(text);

    if (pos + strlen(text) + 1 >= str->capacity) {
        bool result = _set_string_capacity(str, _calc_new_capacity(str->capacity, len));
        if (!result) return false;
    }

    memmove(str->data + pos + len, str->data + pos, str->length - pos);
    memcpy(str->data + pos, text, len);
    str->length += len;
    str->data[str->length] = NULL_CHAR;
    return true;
}

void string_reverse(String* str) {
    if (_is_invalid(str)) return;

    for (size_t i = 0; i < str->length / 2; i++) {
        const char tmp = str->data[i];
        const size_t inverted_i = str->length - i - 1;
        str->data[i] = str->data[inverted_i];
        str->data[inverted_i] = tmp;
    }
}

void string_to_upper(String* str) {}
void string_replace_char(String* str, char old_char, char new_char) {
    if (_is_invalid(str)) return;

    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == old_char) {
            str->data[i] = new_char;
        }
    }
}
