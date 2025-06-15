#ifndef STRING_INTERNAL_H
#define STRING_INTERNAL_H

#include "../include/stryx.h"

struct String {
    char *data;
    size_t length;
    size_t capacity;
};

bool _is_invalid(const String *str);
bool _set_string_capacity(String *str, size_t new_capacity);
void _append_char(String *str, char c);
void _append_chars(String *str, char const *text, size_t length);
void _grow(String *str, int amount);
void _grow_append(String *str, const char *text, const int length);
int _calc_new_capacity(size_t current_capacity, size_t new_space_needed);

#define NULL_CHAR '\0'
#define STARTING_STRING_LENGTH 64

#endif
