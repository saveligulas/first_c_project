#include <stdlib.h>
#include <string.h>

#include "../include/stryx.h"
#include "../internal/_string_internal.h"

String *string_create_empty() {
    String *self = malloc(sizeof(String));
    if (self != NULL) {
        self->length = 0;
        self->data = malloc(STARTING_STRING_LENGTH * sizeof(char));
        self->data[0] = NULL_CHAR;
        self->capacity = STARTING_STRING_LENGTH;
    }
    return self;
}

String* string_create(const char* initial) {
    if (initial == NULL) return NULL;

    int length = strlen(initial);
    if (STARTING_STRING_LENGTH >= length) {
        String *str = string_create_empty();
        _append_chars(str, initial, length);
        return str;
    } else {
        String *str = string_create_explicit(_calc_new_capacity(STARTING_STRING_LENGTH, length));
        memcpy(str->data, initial, length);
        str->data[length] = NULL_CHAR;
        return str;
    }
}

String *string_create_explicit(const int capacity) {
    String *self = malloc(sizeof(String));

    if (self != NULL) {
        self->data = malloc(capacity + 1);
        if (self->data != NULL) {
            self->data[0] = '\0';
            self->length = 0;
            self->capacity = capacity;
            return self;
        }
        free(self);
    }

    return NULL;
}

void string_destroy(String *self) {
    free(self->data);
    free(self);
}

String* string_clone(const String* str) {
    if (_is_invalid(str)) return NULL;

    String *copy = string_create_explicit(str->capacity);
    if (copy != NULL) {
        memcpy(copy->data, str->data, str->length);
        copy->length = str->length;
        return copy;
    }
    return NULL;
}