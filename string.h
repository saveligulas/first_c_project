//
// Created by savel on 14/06/2025.
//

#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <string.h>

typedef struct String String;

struct String {
    char *data;
    int length;
    int capacity;
};

String* string_create_w_cap(const int capacity);
String* string_create();
void string_destroy(String *self);

void string_append_str(String *self, String const *str);
void string_append_chars(String *self, const char *text);
void string_append_chars_explicit(String *self, const char *text, int length);
void string_print(const String *self);

#define NULL_CHAR '\0'
#define STARTING_STRING_LENGTH 64

#endif //STRING_H
