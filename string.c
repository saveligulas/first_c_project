//
// Created by savel on 14/06/2025.
//

#include "string.h"

#include <stdlib.h>

void append_str(String *self, String const *str) {
    if (self == NULL) {
        printf("String is NULL\n");
        return;
    }

    if (str == NULL) {
        printf("String to append is NULL\n");
        return;
    }

    if (self->length < 0) {
        printf("String length is smaller than 0\n");
        return;
    }

    if (str->length <= 0) {
        printf("String to append length is 0\n");
        return;
    }

    if (self->capacity < self->length + str->length) {
        printf("String to append is too large to be added\n");
        return;
    }

    memcpy(self->data + self->length, str->data, str->length);
    self->length += str->length;
    self->data[self->length] = NULL_CHAR;
}

void append_char(String *self, const char *text, int length) {
    if (self == NULL) {
        printf("String is NULL\n");
        return;
    }

    if (self->length < 0) {
        printf("String length is smaller than 0\n");
        return;
    }

    if (self->capacity < self->length + length) {
        printf("String to append is too large to be added\n");
        return;
    }

    memcpy(self->data + self->length, text, length);
    self->length += length;
    self->data[self->length] = NULL_CHAR;
}

void print(String const *self) {
    printf("%.*s\n", self->length, self->data);
}

String *string_create(const int capacity) {
    int capacity_with_null = capacity + 1;
    String temp = { NULL, 0, capacity};
    String *self = malloc(sizeof(String));

    if (self != NULL) {
        *self = temp;
        self->data = malloc(capacity_with_null * sizeof(char));
        self->data[0] = NULL_CHAR;
    }

    return self;
}

void destroy_string(String *self) {
    free(self->data);
    free(self);
}
