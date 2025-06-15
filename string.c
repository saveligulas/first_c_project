//
// Created by savel on 14/06/2025.
//

#include "string.h"

#include <stdbool.h>
#include <stdlib.h>

static bool is_invalid(const String *str) {
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

    return found_invalid_state;
}

static bool set_string_capacity(String *str, const int new_capacity) {
    if (is_invalid(str)) return false;

    if (str->capacity >= new_capacity) {
        printf("String capacity(%d) >= new_capacity(%d)\n", str->capacity, new_capacity);
        return false;
    }

    char *new_data = realloc(str->data, new_capacity + 1);
    if (new_data == NULL) return false;
    str->data = new_data;
    str->capacity = new_capacity;
    return true;
}

static void append_chars(String *str, char const *text, int length) {
    if (is_invalid(str)) return;

    memcpy(str->data + str->length, text, length);
    str->length += length;
    str->data[str->length] = NULL_CHAR;
}

static void grow_append(String *str, const char *text, const int length) {
    if (is_invalid(str)) return;

    if (str->length + length > str->capacity) {
        int new_capacity = str->capacity + (str->capacity >> 1) + length;
        if (!set_string_capacity(str, new_capacity)) {
            printf("Appending of Chars failed!");
            return;
        }
    }

    append_chars(str, text, length);
}

void string_append_str(String *self, String const *str) {
    if (is_invalid(self) || is_invalid(str)) return;

    grow_append(self, str->data, str->length);
}

void string_append_chars(String *self, const char *text) {
    if (is_invalid(self)) return;
    if (text == NULL) {
        printf("Char array is NULL\n");
        return;
    }

    grow_append(self, text, strlen(text));
}

void string_append_chars_explicit(String *self, const char *text, int length) {
    if (is_invalid(self)) return;

    grow_append(self, text, length);
}

void string_print(String const *self) {
    printf("%.*s\n", self->length, self->data);
}

String *string_create_w_cap(const int capacity) {
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

String *string_create() {
    String *self = malloc(sizeof(String));
    if (self != NULL) {
        self->length = 0;
        self->data = malloc(STARTING_STRING_LENGTH * sizeof(char));
        self->data[0] = NULL_CHAR;
        self->capacity = STARTING_STRING_LENGTH;
    }
    return self;
}

void string_destroy(String *self) {
    free(self->data);
    free(self);
}
