#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <stddef.h>
#include <stdbool.h>

typedef struct String String;

String* string_create_empty();
String* string_create(const char* initial);
String *string_create_explicit(const int capacity);
void    string_destroy(String* str);
const char* string_cstr(const String* str);
size_t  string_length(const String* str);
void string_print(const String *str);

bool    string_append(String* str, const char* text);
bool    string_append_char(String* str, char c);
String* string_clone(const String* str);
void    string_clear(String** str);

bool    string_insert(String* str, size_t pos, const char* text);
int     string_find(const String* str, const char* substr);
bool    string_equals(const String* a, const String* b);
String* string_substring(const String* str, size_t start, size_t len);

void    string_reverse(String* str);
void    string_to_upper(String* str);
void    string_replace_char(String* str, char old_char, char new_char);
size_t  string_count_char(const String* str, char c);

#endif