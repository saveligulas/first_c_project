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

    void (*append_str)(String *self, String *str);
    void (*append_char)(String *self, const char *text, int length);
    void (*print)(String *self);
};

String* string_create(const int capacity);
void destroy_string(String *self);

void append_str(String *self, String const *str);
void append_char(String *self, const char *text, int length);
void print(const String *self);


#define str_append(self, str) (self)->append_str(self, str)
#define str_append_char(str, text) (str)->append_char(text, strlen(text))

#define NULL_CHAR '\0'

#endif //STRING_H
